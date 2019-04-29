<?php
/**
 * @file
 * Feeds SFTP Fetcher classes and functions.
 */

/**
 * Fetches data via SFTP.
 */
class FeedsSFTPFetcher extends FeedsFetcher {

  /**
   * Override FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $ftp_password = $this->config['password'];
    $path = $this->config['path'];

    // Connect to the SFTP server.
    $connect = feeds_ftp_fetcher_connection_sftp($this->config, $ftp_password);

    if (!empty($connect)) {
      // Download the remote file.
      $temp_filename = feeds_ftp_fetcher_download_sftp($connect, $path);

      // Get filename from the path
      $file_name = basename($temp_filename);

      if (!$temp_filename) {
        // Close the SFTP connection.
        ssh2_exec($connect, 'exit');
        unset($connect);

        throw new Exception(t('Failed to retrieve %path from remote server', array(
          '%path' => $this->config['path'],
        )));
      }

      // Close the SFTP connection.
      ssh2_exec($connect, 'exit');
      unset($connect);
    }

    // Retrieve the raw data.
    if (isset($temp_filename)) {
      $raw = feeds_sftp_fetcher_get_data($temp_filename);

      // Try to extract gzip (>= php 5.4).
      if (!empty($file_name)) {
        if (strrpos($file_name, '.gz') == strlen($file_name) - 3) {
          $raw = gzdecode($raw);
        }
      }
      return new FeedsFetcherResult($raw);
    }

    return new FeedsFetcherResult($this->config['empty_raw']);
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = array();
    $form['server'] = array(
      '#type' => 'textfield',
      '#title' => t('Server'),
      '#description' => t("Enter a server hostname. Do not include 'sftp://' prefix."),
      '#default_value' => $this->config['server'],
      '#required' => TRUE,
    );

    $form['port'] = array(
      '#type' => 'textfield',
      '#title' => t('Port'),
      '#description' => t('Enter a port to connect on.'),
      '#default_value' => $this->config['port'],
      '#required' => TRUE,
    );

    $form['username'] = array(
      '#type' => 'textfield',
      '#title' => t('Username'),
      '#description' => t('The username used to connect to the SFTP server.'),
      '#default_value' => $this->config['username'],
      '#required' => TRUE,
    );

    $form['password'] = array(
      '#type' => 'password',
      '#title' => t('Password'),
      '#description' => t('The password used to connect to the SFTP server.'),
      '#default_value' => '',
      '#required' => FALSE,
    );

    $form['path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path to file'),
      '#description' => t("The path on the SFTP server including filename"),
      '#default_value' => $this->config['path'],
      '#required' => TRUE,
    );

    $form['empty_raw'] = array(
      '#type' => 'textfield',
      '#title' => t('Empty result text'),
      '#description' => t('Text to pass as a result when there are no files listed in the remote directory'),
      '#default_value' => $this->config['empty_raw'],
    );

    return $form;
  }

  /**
   * Override parent::sourceForm().
   */
  public function sourceForm($source_config) {
    $form = array();
    $form['sftp'] = array(
      '#title' => t('SFtp settings'),
      '#type' => 'fieldset',
      '#collapsed' => FALSE,
      '#collapsible' => FALSE,
    );

    $text = t('The source file for this import/update process is placed on SFTP server. You have to provide some authentication data to access the file.');
    if ($this->config['server'] && $this->config['path'] && $this->config['username']) {
      $text = t('SFTP server: %server, port: %port, path: %path',
        array(
          '%server' => $this->config['server'],
          '%port' => $this->config['port'],
          '%path' => $this->config['path'],
        ));
    }

    $form['sftp']['info'] = array('#markup' => $text);

    return $form;
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'server' => '',
      'port' => 22,
      'path' => '/',
      'username' => '',
      'password' => '',
      'password_field' => 'config',
      'empty_raw' => '',
    );
  }
}

/**
 * Open a connection to a remote SFTP server and change to directory.
 *
 * @param Array $config
 * @param String $ftp_password
 * @return Bool resource
 * @throws Exception
 */
function feeds_ftp_fetcher_connection_sftp($config, $ftp_password) {
  $connect = array();

  try {
    // trim server name and user name to remove any trailing spaces
    $server_name = trim($config['server']);
    $user_name = trim($config['username']);

    // Connect to SFTP server.
    $connect = feeds_ftp_fetcher_connect_sftp($server_name, $user_name, $ftp_password, $config['port']);
    if (!$connect) {
      throw new Exception(t('Failed to connect to SFTP server: !server', array(
        '!server' => $config['server'],
      )));
    }
  }
  catch (Exception $e) {
    drupal_set_message(t('Error: @message', array(
        '@message' => $e->getMessage(),
      )));
  }

  return $connect;
}

/**
 * Get a file contents as string.
 *
 * @param $temp_file
 * @return string
 */
function feeds_sftp_fetcher_get_data($temp_file) {
  $data = '';
  if ($fp = @fopen($temp_file, 'rb')) {
    while (!feof($fp)) {
      $data .= fread($fp, 4096);
    }
    @fclose($fp);
  }
  return $data;
}

/**
 * Open a connection to a SFTP server.
 *
 * @param $server
 * @param $username
 * @param $password
 * @param $port
 * @return bool|resource
 */
function feeds_ftp_fetcher_connect_sftp($server, $username, $password, $port) {
  if (!function_exists("ssh2_connect"))
    die('Function ssh2_connect does not exist.');

  if ($connect = ssh2_connect($server, $port)) {
    if (ssh2_auth_password($connect, $username, $password)) {
      return $connect;
    }
  }

  return FALSE;
}

/**
 * Download a file from the remote SFTP server.
 *
 * @param $connect
 * @param $file
 * @return bool|string
 */
function feeds_ftp_fetcher_download_sftp($connect, $file) {
  $result = FALSE;

  if ($connect) {
    $file_name = basename($file);
    if (ssh2_scp_recv($connect, $file, file_directory_temp() . '/' . $file_name)) {
      $result = file_directory_temp() . '/' . $file_name;
    }
  }

  return $result;
}
