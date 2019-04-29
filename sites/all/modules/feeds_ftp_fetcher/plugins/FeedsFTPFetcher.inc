<?php
/**
 * @file
 * Feeds FTP Fetcher classses and functions.
 */

define('FEEDS_FTP_FETCHER_TYPE_ONE', 0);
define('FEEDS_FTP_FETCHER_TYPE_ALL', 1);
define('FEEDS_FTP_FETCHER_TYPE_NEW', 2);
define('FEEDS_FTP_FETCHER_MODE_ACTIVE', 0);
define('FEEDS_FTP_FETCHER_MODE_PASSIVE', 1);

/**
 * Fetches data via FTP.
 */
class FeedsFTPFetcher extends FeedsFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $state = $source->state(FEEDS_FETCH);

    $source_config = $source->getConfigFor($this);
    $ftp_password = ($this->config['password_field'] == 'config') ? $this->config['password'] : $source_config['ftp']['password'];

    // List of files already fetched.
    $fetched = isset($source_config['feed_files_fetched']) ? $source_config['feed_files_fetched'] : array();

    // Check if we have a list of files to process.
    if (!isset($state->files)) {

      // Connect to FTP server.
      $connect = feeds_ftp_fetcher_connection($this->config, $ftp_password);

      // List of files on FTP server.
      $files = feeds_ftp_fetcher_list($connect, $this->config['directory']);
      if ($files === FALSE) {
        @ftp_close($connect);
        throw new Exception(t('Unabled to list remote directory: %directory', array(
          '%directory' => $this->config['directory'],
        )));
      }

      // Simple single file.
      if ($this->config['fetch_type'] == FEEDS_FTP_FETCHER_TYPE_ONE) {
        // Check if the required file exists in FTP server.
        if (in_array($this->config['filename'], $files) !== FALSE) {
          $files = array($this->config['filename']);

          // We already got this one!
          if (isset($fetched[$this->config['filename']])) {
            // So check the sizes.
            $size = feeds_ftp_fetcher_file_size($connect, $this->config['filename']);
            if (!$this->config['skip_hash_check'] && $size == $fetched[$this->config['filename']]['size']) {
              // Remove from files array, no point in processing it again.
              $files = array();
              unset($fetched[$this->config['filename']]);
            }
            else {
              // Size is different so re-fetch.
              $fetched[$this->config['filename']]['fetch'] = TRUE;
            }
          }
        }
        else {
          throw new Exception(t('File does not exist on ftp server: !filename', array(
            '!filename' => $this->config['filename'],
          )));
        }
      }

      // Force fetch all files.
      if ($this->config['fetch_type'] == FEEDS_FTP_FETCHER_TYPE_ALL) {
        if (!empty($files)) {
          foreach ($files as $filename) {
            if (isset($fetched[$filename])) {
              // Remove from list of files already fetched.
              unset($fetched[$filename]);
            }
          }
        }
      }

      // Filter list for new files.
      if ($this->config['fetch_type'] == FEEDS_FTP_FETCHER_TYPE_NEW) {
        if (!empty($files)) {
          foreach ($files as $idx => $filename) {
            if (isset($fetched[$filename])) {
              // We already got this one!
              // so check the sizes.
              $size = feeds_ftp_fetcher_file_size($connect, $filename);
              if ($size == $fetched[$filename]['size']) {
                unset($files[$idx]);
                // And remove from list of files already fetched.
                unset($fetched[$filename]);
              }
              else {
                $fetched[$filename]['fetch'] = TRUE;
              }
            }
          }
        }
      }

      // Entries remaining in $fetched are no longer present on the server.
      if (!empty($fetched)) {
        foreach ($fetched as $filename => $flag) {
          unset($source_config['feed_files_fetched'][$filename]);
        }
        // Save the source configuration.
        $source->setConfigFor($this, $source_config);
      }

      $state->files = $files;
      $state->total = count($files);

      // Make sure that the FTP connection is closed.
      @ftp_close($connect);
    }

    // Check if there are any files to download.
    if (!empty($state->files)) {

      // Download the next file.
      foreach ($state->files as $i => $filename) {

        // If we haven't previously fetched this file, or we need to re-fetch.
        if (!isset($fetched[$filename])
        || isset($fetched[$filename]['fetch'])
        || $this->config['fetch_type'] == FEEDS_FTP_FETCHER_TYPE_ALL) {

          // Connect to FTP server.
          $connect = feeds_ftp_fetcher_connection($this->config, $ftp_password);

          // Download the remote file.
          $temp_filename = feeds_ftp_fetcher_download($connect, $filename);
          if (!$temp_filename) {
            @ftp_close($connect);
            throw new Exception(t('Failed to retrieve %filename from remote directory %directory', array(
              '%directory' => $this->config['directory'],
              '%filename' => $filename,
            )));
          }

          // Record the temp file details in the state.
          $state->last_file = array(
            'name' => $filename,
            'size' => feeds_ftp_fetcher_file_size($connect, $filename),
            'temp' => $temp_filename,
          );

          // Update the saved details for this file in the config.
          $source_config['feed_files_fetched'][$filename] = $state->last_file;
          $source->setConfigFor($this, $source_config);

          // Make sure we close the ftp connection.
          @ftp_close($connect);

          // Remove the last file from the list of files that need to be
          // downloaded.
          unset($state->files[$i]);

          break;
        }

      }

      // Retrieve the raw data from the temp file.
      if (isset($state->last_file['temp'])) {
        $raw = feeds_ftp_fetcher_get_data($state->last_file['temp']);
        $state->progress($state->total, $state->total - count($state->files));
        return new FeedsFetcherResult($raw);
      }
    }

    $state->progress(0, 1);
    return new FeedsFetcherResult($this->config['empty_raw']);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'server' => '',
      'port' => 21,
      'directory' => '/',
      'fetch_type' => FEEDS_FTP_FETCHER_TYPE_ONE,
      'ftp_mode' => FEEDS_FTP_FETCHER_MODE_PASSIVE,
      'filename' => '',
      'username' => '',
      'password' => '',
      'password_field' => 'config',
      'skip_hash_check' => FALSE,
      'empty_raw' => '',
    );
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = array();
    $form['password_field'] = array(
      '#title' => t('Where to provide password field'),
      '#type' => 'select',
      '#default_value' => $this->config['password_field'],
      '#options' => array(
        'config' => t('Config page'),
        'source' => t('Source form'),
      ),
    );

    $form['server'] = array(
      '#type' => 'textfield',
      '#title' => t('Server'),
      '#description' => t("Enter a server hostname. Do not include 'ftp://' prefix."),
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
      '#description' => t('The username used to connect to the FTP server.'),
      '#default_value' => $this->config['username'],
      '#required' => TRUE,
    );

    $form['password'] = array(
      '#type' => 'password',
      '#title' => t('Password'),
      '#description' => t('The password used to connect to the FTP server.'),
      '#default_value' => '',
      '#required' => FALSE,
      '#states' => array(
        'visible' => array(
          ':input[name="password_field"]' => array('value' => 'config'),
        ),
      ),
    );

    $form['directory'] = array(
      '#type' => 'textfield',
      '#title' => t('Directory'),
      '#description' => t("The directory on the FTP server. E.g., '/public_html'"),
      '#default_value' => $this->config['directory'],
      '#required' => TRUE,
    );

    $form['fetch_type'] = array(
      '#type' => 'radios',
      '#title' => t('Fetch type'),
      '#options' => array(
        FEEDS_FTP_FETCHER_TYPE_ALL => t('Fetch all files in the given directory.'),
        FEEDS_FTP_FETCHER_TYPE_NEW => t('Only fetch new files.'),
        FEEDS_FTP_FETCHER_TYPE_ONE => t('Fetch a specific file.'),
      ),
      '#default_value' => $this->config['fetch_type'],
    );

    $form['filename'] = array(
      '#type' => 'textfield',
      '#title' => t('Filename'),
      '#description' => t('The filename in the directory on the FTP server, when only fetching a specific file.'),
      '#default_value' => $this->config['filename'],
      '#states' => array(
        'visible' => array(
          ':input[name=fetch_type]' => array('value' => FEEDS_FTP_FETCHER_TYPE_ONE),
        ),
      ),
    );

    $form['ftp_mode'] = array(
      '#type' => 'radios',
      '#title' => t('Use Active or Passive FTP Connections'),
      '#options' => array(
        FEEDS_FTP_FETCHER_MODE_ACTIVE => t('Use Active FTP Connection'),
        FEEDS_FTP_FETCHER_MODE_PASSIVE => t('Use Passive FTP Connection'),
      ),
      '#default_value' => $this->config['ftp_mode'],
    );

    $form['skip_hash_check'] = array(
      '#type' => 'checkbox',
      '#title' => t('Skip hash check'),
      '#description' => t('Force file download even when file was already processed.'),
      '#default_value' => $this->config['skip_hash_check'],
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
   * Source form.
   */
  public function sourceForm($source_config) {
    $form = array();
    $form['ftp'] = array(
      '#title' => t('Ftp settings'),
      '#type' => 'fieldset',
      '#collapsed' => FALSE,
      '#collapsible' => FALSE,
    );

    $text = t('The source file for this import/update process is placed on ftp server. You have to provide some authentication data to access the file.');
    if ($this->config['server'] && $this->config['directory'] && $this->config['username']) {
      $filename = $this->config['filename'];
      if ($this->config['fetch_type'] == FEEDS_FTP_FETCHER_TYPE_ALL) {
        $filename = t('(all files)');
      }
      elseif ($this->config['fetch_type'] == FEEDS_FTP_FETCHER_TYPE_NEW) {
        $filename = t('(new files)');
      }
      $text = t('Ftp server: %server, port: %port, directory: %dir, file: %file.',
        array(
          '%server' => $this->config['server'],
          '%port' => $this->config['port'],
          '%dir' => $this->config['directory'],
          '%file' => $filename,
        ));

      if ($this->config['password_field'] == 'source') {
        $text .= '<br />' . t('Please provide FTP password here.');
      }
    }

    $form['ftp']['info'] = array('#markup' => $text);

    if ($this->config['password_field'] == 'source') {
      $form['ftp']['password'] = array(
        '#type' => 'password',
        '#title' => t('Password'),
        '#description' => t('The password used to connect to the FTP server.'),
        '#default_value' => '',
        '#maxlength' => NULL,
        '#required' => TRUE,
      );
    }

    if ($this->config['fetch_type'] == FEEDS_FTP_FETCHER_TYPE_NEW) {
      $form['reset'] = array(
        '#type' => 'checkbox',
        '#title' => t('Re-fetch entire directory'),
        '#description' => t('When checked will re-fetch previously imported data.'),
        '#default_value' => FALSE,
      );
    }
    $form['feed_files_fetched'] = array(
      '#type' => 'value',
      '#value' => isset($source_config['feed_files_fetched']) ? $source_config['feed_files_fetched'] : array(),
    );

    return $form;
  }

  /**
   * Validate callback.
   */
  public function sourceFormValidate(&$values) {
    if (!empty($values['reset'])) {
      $values['feed_files_fetched'] = array();
      $values['reset'] = 0;
    }
  }

}

/**
 * Open a connection to a remote FTP server and change to directory.
 *
 * @param array $config
 *   The config array.
 * @param string $ftp_password
 *   The FTP password.
 *
 * @return Bool resource
 *   Returns either TRUE or FALSE wheter the connection succeeded.
 */
function feeds_ftp_fetcher_connection(array $config, $ftp_password) {
  $connect = FALSE;

  try {
    // Trim server name and user name to remove any trailing spaces.
    $server_name = trim($config['server']);
    $user_name = trim($config['username']);
    // Connect to FTP server.
    $connect = feeds_ftp_fetcher_connect($server_name, $user_name, $ftp_password, $config['port'], $config['ftp_mode']);
    if (!$connect) {
      throw new Exception(t('Failed to connect to ftp server: !server', array(
        '!server' => $config['server'],
      )));
    }
    else {
      // Change directory on FTP server.
      if (!feeds_ftp_fetcher_chdir($connect, $config['directory'])) {
        @ftp_close($connect);
        throw new Exception(t('Failed to change FTP directory'));
      }
    }
  }
  catch (Exception $e) {
    drupal_set_message('Error: ' . $e->getMessage());
  }

  return $connect;
}

/**
 * Open a connection to a FTP server.
 *
 * @param string $server
 *   The ftp server.
 * @param string $username
 *   The ftp username.
 * @param string $password
 *   The ftp password.
 * @param int $port
 *   The ftp port.
 *
 * @return bool|resource
 *   Returns TRUE or FALSE.
 */
function feeds_ftp_fetcher_connect($server, $username, $password, $port, $ftp_mode) {
  if ($connect = ftp_connect($server, $port)) {
    ftp_login($connect, $username, $password);
    ftp_pasv($connect, (bool) $ftp_mode);
    return $connect;
  }
  return FALSE;
}

/**
 * Change the directory on the remote FTP server.
 *
 * @param resource $connect
 *   The FTP stream (or FALSE).
 * @param string $directory
 *   The string to navigate to.
 *
 * @return bool
 *   TRUE or FALSE
 */
function feeds_ftp_fetcher_chdir($connect, $directory) {
  if ($connect) {
    return @ftp_chdir($connect, $directory);
  }
  return FALSE;
}

/**
 * Get a list of files in a directory on the remote FTP server.
 *
 * @param resource $connect
 *   The FTP stream (or FALSE).
 * @param string $directory
 *   The string to navigate to.
 *
 * @return array
 *   An array with all fles.
 */
function feeds_ftp_fetcher_list($connect, $directory) {
  $files = array();

  if ($connect) {
    $files = @ftp_nlist($connect, $directory);
    if (count($files) > 0) {
      foreach ($files as $idx => &$filename) {
        // Remove the directory name from the filename if present.
        $filename = str_replace($directory . '/', '', $filename);
        // Strip out any file names beginning with a period.
        if (substr($filename, 0, 1) == '.') {
          unset($files[$idx]);
        }

        // Remove 0 byte files and subfolders which has file size = -1.
        if (@ftp_size($connect, $filename) < 1) {
          unset($files[$idx]);
        }
      }
    }
  }

  // Re-index the list of file names before returning it.
  return array_values($files);
}

/**
 * Download a file from the remote FTP server.
 *
 * @param resource $connect
 *   The FTP stream (or FALSE).
 * @param string $file
 *   The filename of the file to download.
 *
 * @return bool|string
 *   Either the file contents or FALSE.
 */
function feeds_ftp_fetcher_download($connect, $file) {
  $result = FALSE;

  if ($connect) {
    $temp_file = file_create_filename($file, file_directory_temp());
    $fp = @fopen($temp_file, 'w');
    if (@ftp_fget($connect, $fp, $file, FTP_BINARY)) {
      $result = $temp_file;
    }
    @fclose($fp);
  }
  return $result;
}

/**
 * Get a file contents as string.
 *
 * @param string $temp_file
 *   The filename of the file to fetch.
 *
 * @return string
 *   The file contents.
 */
function feeds_ftp_fetcher_get_data($temp_file) {
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
 * Get the size of a file in bytes from the remote FTP server.
 *
 * Used to check if the file has changed and should be re-downloaded.
 *
 * @param resource $connect
 *   The FTP stream (or FALSE).
 * @param string $filename
 *   The filename of the file to download.
 *
 * @return int
 *   Returns the size of the given file in bytes.
 */
function feeds_ftp_fetcher_file_size($connect, $filename) {
  if ($connect) {
    return @ftp_size($connect, $filename);
  }
  return FALSE;
}
