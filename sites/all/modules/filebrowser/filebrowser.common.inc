<?php
/* This file is part of "filebrowser".
 *    Copyright 2009, arNuméral
 *    Author : Yoran Brault
 *    eMail  : yoran.brault@bad_arnumeral.fr (remove bad_ before sending an email)
 *    Site   : http://www.arnumeral.fr
 *
 * "filebrowser" is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * "filebrowser" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with "filebrowser"; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA, or see the FSF site: http://www.fsf.org.
 */

/**
 * @file
 *
 * Misc filebrowser common functions.
 */

define('FILEBROWSER_CREATE_DIRECTORY_LISTING', 'create directory listings');
define('FILEBROWSER_DELETE_OWN_DIRECTORY_LISTINGS', 'delete own directory listings');
define('FILEBROWSER_DELETE_ANY_DIRECTORY_LISTINGS', 'delete any directory listings');
define('FILEBROWSER_EDIT_OWN_DIRECTORY_LISTINGS', 'edit own directory listings');
define('FILEBROWSER_EDIT_ANY_DIRECTORY_LISTINGS', 'edit any directory listings');
define('FILEBROWSER_VIEW_DIRECTORY_LISTINGS', 'view directory listings');
define('FILEBROWSER_UPLOAD', 'upload files to directory misting');
define('FILEBROWSER_CREATE_FOLDER', 'create folders');
define('FILEBROWSER_DOWNLOAD_ARCHIVE', 'download archive files');
define('FILEBROWSER_DOWNLOAD', 'download files');
define('FILEBROWSER_DELETE_FILE', 'delete files');
define('FILEBROWSER_RENAME_FILE', 'rename files');

/**
 * Column identifiers definition.
 */
define('FILEBROWSER_DATA_NAME_ICON', 'icon');
define('FILEBROWSER_DATA_NAME_DISPLAY_NAME', 'display-name');
define('FILEBROWSER_DATA_NAME_SIZE', 'size');
define('FILEBROWSER_DATA_NAME_CREATED', 'created');
define('FILEBROWSER_DATA_NAME_MODIFIED', 'modified');
define('FILEBROWSER_DATA_NAME_TYPE', 'type');
define('FILEBROWSER_DATA_NAME_DESCRIPTION', 'description');

/**
 * Metadata access handler (see hook_menu).
 */
function _filebrowser_metadata_access($fid) {
  //debug  echo '_filebrowser_metadata_access || fid is ; ' . $fid . '<br>';
  $content = _filebrowser_node_content_load($fid);
  $node = node_load($content['nid']);
  return $node->type == 'dir_listing' && node_access("update", $node);
}

/**
 * Helper function to get node folder with correct token replacements. Never
 * use $node->folder_path directly !!!
 * @param $node
 * @return folder path
 */
function _filebrowser_get_node_root(& $node) {
  $result = $node->folder_path;
  // token_replace is in D7 core *** if (module_exists("token")) {
  $result = token_replace($result, array('type' => 'global', 'object' => NULL, 'leading' => '[', $trailing = ']'));
  return $result;
}

/**
 * Prepare node record to be used. This is mainly about default stuff.
 * @param $node node to prepage
 * @param $load is this for loading (TRUE) or inserting/updating (FALSE)
 */
function _filebrowser_prepare_record(& $node, $load = TRUE) {
  // Fix trailing slashes
  $node->folder_path = rtrim($node->folder_path, '/');

  // Process uploads
  $node->folder_uploads = (object)$node->folder_uploads;
  _filebrowser_set_default($node->folder_uploads->enabled, FALSE);
  _filebrowser_set_default($node->folder_uploads->allow_overwrite, FALSE);
  _filebrowser_set_default($node->folder_uploads->accepted_uploaded_files, '');

  // Process handlers
  $node->folder_uploads = (object)$node->folder_uploads;
  foreach (module_implements("filebrowser_handler_info") as $module) {
    if (isset($node->$module)) {
      $node->file_handlers->$module = $node->$module;
      unset($node->$module);
    }
    $node->file_handlers = (object)$node->file_handlers;
    $node->file_handlers->$module = (object)($node->file_handlers->$module);
  }

  // Fix rights
  $node->folder_rights = (object)$node->folder_rights;
  unset($node->folder_rights->private_downloads);
  _filebrowser_set_default($node->folder_rights->explore_subdirs, FALSE);
  _filebrowser_set_default($node->folder_rights->create_folders, FALSE);
  _filebrowser_set_default($node->folder_rights->download_archive, FALSE);
  _filebrowser_set_default($node->folder_rights->forbidden_files, "descript.ion\nfile.bbs\n.git\nCSV\n.svn\n");
  _filebrowser_set_default($node->folder_rights->filtered_files, "");
  if (!isset($node->folder_rights->download_manager) || !_filebrowser_externals('download_manager_info', $node->folder_rights->download_manager)) {
    $node->folder_rights->download_manager = 'public';
  }

  // Fix presentation
  $node->folder_presentation = (object)$node->folder_presentation;
  _filebrowser_set_default($node->folder_presentation->encoding, 'UTF8');
  if (!isset($node->folder_presentation->default_view) || !_filebrowser_externals('presentations', $node->folder_presentation->default_view)) {
    $node->folder_presentation->default_view = 'list-view';
  }
  _filebrowser_set_default($node->folder_presentation->hide_extension, FALSE);
  $columns = _filebrowser_externals('metadata_info');
  $node->folder_presentation->visible_columns = _filebrowser_filter_checkboxes_result($node->folder_presentation->visible_columns);
  foreach ($node->folder_presentation->visible_columns as $name => $value) {
    if (!isset($columns[$name])) {
      unset($node->folder_presentation->visible_columns[$name]);
    }
  }
  if (count($node->folder_presentation->visible_columns) == 0) {
    $node->folder_presentation->visible_columns = array(
        FILEBROWSER_DATA_NAME_ICON => 1,
        FILEBROWSER_DATA_NAME_DISPLAY_NAME => 1
    );
  }
  if (!isset($node->folder_presentation->default_sort)) {
    foreach ($node->folder_presentation->visible_columns as $name => $foo) {
      if (isset($columns[$name]['sortable']) && $columns[$name]['sortable']) {
        $node->folder_presentation->default_sort = $name;
        break;
      }
    }
  }
  _filebrowser_set_default($node->folder_presentation->default_sort_order, 'asc');

  // Create serialized properties
  $data = new stdClass();
  $data->folder_rights = $node->folder_rights;
  $data->folder_presentation = $node->folder_presentation;
  $data->folder_uploads = $node->folder_uploads;
  $data->file_handlers = isset($node->file_handlers) ? $node->file_handlers : '';
  $node->properties = serialize($data);
}

/**
 * This function is used to invoke filebrowser_$kind hooks. Difference with a direct
 * module_invoke_all is that result is cached in a static way (for now, real caching
 * perhaps later).
 * @param $kind name of the hook (complete hook will be filebrowser_$kind)
 * @param $name the name of the resource retreived by the hook (used as hook
 * parameter and cache index)
 */
function _filebrowser_externals($kind, $name = NULL) {
  static $externals = array();
  if (!isset($externals[$kind])) {
    $externals[$kind] = module_invoke_all("filebrowser_$kind");
  }
  if (!is_null($name)) {
    return isset($externals[$kind][$name]) ? $externals[$kind][$name] : NULL;
  }
  return $externals[$kind];
}

/**
 * Build an URL with current pager settings.
 * @param $href target href
 * @return URL
 */
function _filebrowser_folder_url($href, $options = array()) {
  $options['query']  = _filebrowser_url_query($options);
  return url($href, $options);
}

function _filebrowser_url_query($options = array()) {
  $query = array();
  foreach ($_GET as $key => $value) {
    if ($key != 'q') {
      $query[$key] = urlencode(filter_xss($value));
    }
  }
  return $query;
}

/**
 * Convert a string from FileSystem encoding to UTF-8.
 *
 * @param $node which provide FileSystem encoding information.
 * @param $source source string
 *
 * @return re-encoded string
 */
function _filebrowser_encoding_from_fs(&$node, $source) {
  // For Drupal 6 filebrowser nodes can have an empty value for encoding
  // So let's cater for that.
  // issue #2660282
  if (!is_string($node->folder_presentation->encoding) || strcasecmp($node->folder_presentation->encoding, 'UTF-8')) {
    return $source;
  }
  else {
    return mb_convert_encoding($source, "UTF-8", $node->folder_presentation->encoding);
  }
}

/**
 * Convert a string from UTF-8 to FileSystem encoding.
 *
 * @param $node which provide FileSystem encoding information.
 * @param $source source string
 *
 * @return re-encoded string
 */
function _filebrowser_encoding_to_fs(&$node, $source) {
  // debug echo 'source : ' . $source . '<br>';
  return strcasecmp($node->folder_presentation->encoding, 'UTF-8') == 0 ? $source : mb_convert_encoding($source, $node->folder_presentation->encoding, "UTF-8");
}

/**
 * remove all content bits from parent node id.
 */
function _filebrowser_node_content_delete($node) {
  db_query("
    DELETE
    FROM {node_dir_listing_content}
    WHERE
      nid = :nid", array(':nid' => $node->nid));
}

/**
 * Load a specific node content.
 *
 * @param $fid content fid
 * @return content record
 */
function _filebrowser_node_content_load($fid) {
  static $contents = array();
  if (isset($contents[$fid])) {
    return $contents[$fid];
  }
  $contents[$fid] = (array)db_query("
    SELECT *
    FROM {node_dir_listing_content}
    WHERE fid = :fid", array(':fid' => $fid))-> fetch();
  return $contents[$fid];
}

/**
 * Load data from current path.
 *
 * @param object $node node of type dir-listing
 * @param integer $fid
 * @param bool $rebuild
 * @return mixed
 */
//todo: change all - in var names to _
function _filebrowser_load_files(&$node, $fid = NULL, $rebuild = FALSE) {
  global $user, $base_url;

  // if this is an s3 directory create a s3 client and AwsStreamWrapper
  if (is_s3_filesystem($node-> folder_path)) {
    $client = awssdk_get_client('s3');
    $client-> registerStreamWrapper();
    $is_s3 = true;
  }
  else {
    $is_s3 = false;
  }

  // folder path are node/NID/FID?QUERY
  if (!$fid && (arg(0) == 'node' && is_numeric(arg(2)))) {
    $fid = arg(2);
  }
  //debug:  echo 'fid = : ' . $fid . '<br>';exit();

  // Select current file record according to fid - you are requesting a specific file or subdir: node/23/47
  if ($fid) {
    $content = _filebrowser_node_content_load($fid);
    if (!$content) {
      drupal_goto("node/{$node->nid}");
    }
    $relative_path = $content['path'];
  }
  // you are requesting the basic node like: /node/23
  else {
    $relative_path = '/';
  }
  $is_subdir = $relative_path != '/';
  //debug($is_subdir, '$is_subdir');

  // If we shouldn't be in a subdirectory, redirect to root_dir.
  if ($is_subdir && !_filebrowser_can_explore_subfolders($node)) {
    drupal_set_message(t('You\'re not allowed to browse sub folders.'), 'error');
    return;
  }

  // More advanced check to make sure no parent directories match our files.
  // blacklist
  if (!empty($relative_path)) {
    $dirs = explode('/', $relative_path);
    foreach ($dirs as $dir) {
      if (!empty($dir)) {
        if (_filebrowser_cant_view_file($node, $dir)) {
          drupal_set_message(t("You're not allowed to view '%dir'.", array('%dir' => $dir)), 'error');
          return;
        }
      }
    }
  }
  // If this folder has already been processed, take it result
  static $cache = array();
  $cid = "{$node->nid}::{$relative_path}";
  if ($rebuild) {
    unset($cache[$cid]);
    unset($node->file_listing);
  }
  if (isset($cache[$cid])) {
    return $node->file_listing = $cache[$cid];
  }

  // Load database folder content
  // first time after node creation $db_content = NULL; there is nothing in the DB
  $db_content = array();
  $query = db_query("SELECT * FROM {node_dir_listing_content} where nid = :nid and root = :root", array(':nid' => $node->nid, ':root' => $relative_path));
  foreach ($query as $data) {
    $db_content[$data->path] = (array)$data;
  }
  //debug($db_content, 'loaded from DB');

  // Build full path
  $fs_root = _filebrowser_encoding_to_fs($node, _filebrowser_get_node_root($node));

  if (!$is_s3) {
    $fs_root = realpath($fs_root);  // no realpath in case of s3

  }

  if ($fs_root === FALSE) {
    drupal_set_message(t('Configured folder is not readable or is not a directory.'), 'error');
    return;
  }
  if ($is_s3) {
    $fs_root = $fs_root . _filebrowser_encoding_to_fs($node, $relative_path);
    // FIXME: add end slash if not present. This is hackish!
    $fs_root = (substr($fs_root, -1,1) == '/' ? $fs_root : $fs_root . '/');
  }
  else {
    $fs_root = realpath($fs_root . "/" . _filebrowser_encoding_to_fs($node, $relative_path)) . "/";
   // debug($fs_root, 'Line 350 - after realpath + _fb_encoding to fs');
   // echo($fs_root . ' || Line 350 - after realpath + _fb_encoding to fs <br>');
  }

  // Load meta-data
  $file_metadata = array();                    // CLEANUP: var not in use

  // Iterate over files
  $files = array();
  $files_count = 0;
  $total_size = 0;
  $folder_count = 0;
  if (is_dir($fs_root) && $handler = opendir($fs_root)) {
    while (($fs_filename = readdir($handler)) !== FALSE) {
      //echo 'filename : ' . $fs_filename . "<br>";
      $fs_file_full_path = $fs_root . $fs_filename;
      // Check FS reading rights
      if (!is_readable($fs_file_full_path)) {
        continue;
      }

      // First file filtering
      if ($fs_filename == '.' || $fs_filename == '..') {
        // We are in the root folder, so we don't need an "up" entry
        if ($fs_filename == '..' && !$is_subdir) {
          // file is .. but we are not in a sub directory, so we don't assign it to DB
          continue;
        }
      }
      else {
        // Check subfolder rights
        if (is_dir($fs_file_full_path) && !_filebrowser_can_explore_subfolders($node)) {
          continue;
        }

        // This file is not filtered
        if (is_file($fs_file_full_path) && !_filebrowser_can_view_file($node, $fs_filename)) {

          continue;
        }

        // This file is not allowed
        if (_filebrowser_cant_view_file($node, $fs_filename)) {
          continue;
        }
      }
      // Build file relative path
      $filename = _filebrowser_encoding_from_fs($node, $fs_filename);
      if ($filename == '.') {
        $file_relative_path = $relative_path;
      }
      elseif ($filename == '..') {

        $file_relative_path = _filebrowser_safe_dirname($relative_path);
          $content = (array)db_query("
            SELECT *
            FROM {node_dir_listing_content}
            WHERE nid = :nid and path = :path", array(':nid' => $node-> nid, ':path' => $file_relative_path))-> fetch();
        //echo ('nid : ' . $node-> nid . ' path: ' . $file_relative_path);
        if ($content) {
          $db_content[$file_relative_path] = &$content;
        }
      }
      else {
        $file_relative_path = $relative_path . ($relative_path != '/' ? '/' : '') . $filename;
      }

      // Build database file record
      if (!isset($db_content[$file_relative_path])) {

        $db_content[$file_relative_path] = array(
            'exists' => TRUE,
            'nid' => $node->nid,
            'root' => $relative_path,
            'path' => $file_relative_path
        );
      }
      $db_content[$file_relative_path]['exists'] = TRUE;
      $db_content[$file_relative_path]['display-name'] = $filename;

      $files[$filename] = array(
          'nid' => $node->nid,
          'display-name' => $filename,
          'relative-path' => $file_relative_path,
          'full-path' => rtrim($fs_root, '/') . "/" . $fs_filename,
          'status' => MARK_READ
      );
      $result = module_invoke_all('filebrowser_metadata_get', $files[$filename]);
      if ($result && is_array($result)) {
        $files[$filename] = array_merge($files[$filename], $result);
      }

      if ($files[$filename]['kind'] == 0) {
        $total_size += $files[$filename]['size'];
        $files_count++;
      }
      else {
        if ($fs_filename != '.') {
          $folder_count++;
        }
      }
      if ($user->uid) {
        if ($user->access < $files[$filename]['created']) {
          $files[$filename]['status'] = MARK_NEW;
        }
        elseif ($user->access < $files[$filename]['modified']) {
          $files[$filename]['status'] = MARK_UPDATED;
        }
      }

      if ($fs_filename == '..') {
        $files[$filename]['mime-type'] .= "/parent";
        $files[$filename]['kind'] = 2;
      }

      $file_path = array();
      if ($fs_filename == '..') {
        $parent_folder = dirname($relative_path);
        if ($parent_folder != "/") {
          $file_path['path'] = $parent_folder;
        }
        // echo('fs_filename = ' . $fs_filename . '  |  parent folder = ' . $parent_folder) . '  | file_path[path] = ' .  $file_path['path'] .  "<br>";
      }
      else {
        $file_path['path'] = $relative_path . $fs_filename;
      }

    }

    // Set global folder properties
    $files['.']['size'] = $total_size;
    $files['.']['files_count'] = $files_count;
    $files['.']['folders_count'] = $folder_count;
    $files['.']['relative-path'] = $relative_path;

    // Amazon S3 filesystem does not provide . and .. files. Therefore we will create them manually
    // to maintain same operation as regular FileBrowser FS.
    // FIXME: some properties should be set by function filebrowser_filebrowser_metadata_get()
    if ($is_s3) {
      if ($is_subdir) {
        // Create the .. file data
        $files['..'] = s3_create_subdir($node-> nid, $fs_root);

        // Create the . file data
        s3_create_updir($files['.'], $node-> nid, $fs_root);

        // Set DB content for Up-directory. In this case the '/' folder
        $db_content['/'] = s3_set_db_content_updir($node-> nid);

        //set DB record for current directory (. file)
        // todo: move to s3_fb module
        if (!isset($db_content[$relative_path] )) {
          $db_content[$relative_path] = array(
            'exists' => TRUE,
            'nid' => $node->nid,
            'root' => $relative_path,
            'path' => $relative_path,
            );
        }
        $db_content[$relative_path]['exists'] = true;
        $db_content[$relative_path]['display-name'] = '.';
      }
      else {
        // not a sub dir so we only set the . file and / DB data
        if (!isset($db_content['/'])) {
          $db_content['/'] = array(
            'nid' => $node->nid,
            'root' => '/',
            'path' => '/',
          );
        }
        $db_content['/']['exists'] = true;
        $db_content['/']['display-name'] = '.';

        // changes to the File System Array
        $files['.']['nid'] = $node-> nid;
        $files['.']['display-name'] = '.';
        $files['.']['full-path'] = $fs_root;  // evt eindigen met /.
        $files['.']['status'] = MARK_READ;
        $files['.']['kind'] = 1;
        $files['.']['mime-type'] = 'folder';
      }
    }
    closedir($handler);
  }

  // Synchronize what we seen on filesystem with what is stored in database
  // We also build an access URL for each file as it is why we stored this stuff
  // in DB (have a unique ID for each file and path) to get rid of national character
  // mess in URLS.
  $to_delete = array();

  foreach ($db_content as $path => &$record) {
    //debug($record, 'Path');
    if (!isset($record['exists'])) {
      $to_delete[] = $record['fid'];
    }
    else {
      if (!isset($record['fid'])) {
        drupal_write_record('node_dir_listing_content', $record);
      }

      $key = $record['display-name'];
      $files[$key]['fid'] = $record['fid'];
      if ($files[$key]['kind'] != 0) {
        $files[$key]['url'] = _filebrowser_folder_url(
          "node/{$node->nid}" . ($record['path'] != '/' ? "/{$record['fid']}" : ""), array(
            'absolute' => TRUE
        ));
      }
      else {
        $files[$key]['url'] = url('filebrowser/download/' . $record['fid'], array(
            'absolute' => TRUE
        ));
      }
    }
  }

  // A quick way to drip obsolete records (FIXME not quite sure there is no limit in the number of
  // items in the list
  if (count($to_delete)) {
    db_query("DELETE FROM {node_dir_listing_content} WHERE fid IN (" . implode(",", $to_delete) . ")");
  }

  // Cache update
  // FIXME : what of two nodes point to the same folder ?
  $cache[$relative_path] = & $files;

  // Add all this data to the node
  $node->file_listing = $files;
}

function _filebrowser_read_description($file_path) {
  $base_path = _filebrowser_safe_dirname($file_path);
  $data = _filebrowser_load_description_file($base_path);
  $name = _filebrowser_safe_basename($file_path);
  if (isset($data['data'][$name])) {
    return $data['data'][$name];
  }
  else {
    return '';
  }
}

function _filebrowser_save_description_file($data) {
  $output = array();
  foreach ($data['data'] as $key => $value) {
    $value = str_replace(array(
        "\r\n",
        "\n"
    ), array(
        '\n',
        '\n'
    ), $value);
    $output[] = "\"$key\"\t$value";
  }
  file_put_contents($data['file'], implode("\n", $output));
}

function _filebrowser_load_description_file($path, $replace = NULL) {
  static $descriptions = array();
  if ($replace) {
    $descriptions[$path] = $replace;
  }
  //echo(print_r($descriptions) . '<br> path '. $path . '<br>');
  if (!isset($descriptions[$path])) {
    $descriptions[$path] = array(
      'data' => array()
    );
    $description_file = $path . '/descript.ion';
    if (!file_exists($description_file)) {
      $description_file = $path . '/file.bbs';
    }
  if (file_exists($description_file)) {
      $descriptions[$path]['file'] = $description_file;
      foreach (file($description_file) as $line) {
        if (trim($line) == '' || strpos(trim($line), '#') === 0) {
          continue;
        }
        $matches = array();
        preg_match('/"([^"]+)"\s+(.*)|(\S+)\s+(.*)/', $line, $matches);
        $name = !empty($matches[1]) ? $matches[1] : $matches[3];
        // FIXME JSJ Changed to matches[1] because 4 givers error
        $description = !empty($matches[2]) ? $matches[2] : $matches[1];
        $description = str_replace('\n', "\n", $description);
        if (isset($descriptions[$path][$name])) {
          $descriptions[$path]['data'][$name] .= ' ' . trim($description);
        }
        else {
          $descriptions[$path]['data'][$name] = trim($description);
        }
      }
    }
  }
  return $descriptions[$path];
}

/**
 * Check if user can download ZIP archives.
 */
function _filebrowser_can_download_archive(& $node) {
  return (node_access('view', $node) && $node->folder_rights->download_archive && user_access(FILEBROWSER_DOWNLOAD_ARCHIVE));
}

/**
 * Check if user can download files.
 */
function _filebrowser_can_download_file(& $node) {
  return (node_access('view', $node) && user_access(FILEBROWSER_DOWNLOAD));
}

/**
 * Check if user can view a specific file.
 */
function _filebrowser_can_view_file(& $node, $file) {
  return trim($node->folder_rights->filtered_files) == '' || _filebrowser_match_path($file, $node->folder_rights->filtered_files);
}

/**
 * Check if user should not view a specific file.
 */
function _filebrowser_cant_view_file(& $node, $file) {
  return trim($node->folder_rights->forbidden_files) != '' && _filebrowser_match_path($file, $node->folder_rights->forbidden_files);
}

/**
 * Check if user can explore sub-folders.
 */
function _filebrowser_can_explore_subfolders(& $node) {
  return $node->folder_rights->explore_subdirs;
}

/**
 * Create a thumbnail and the associated XHTML code for a specific file.
 * @param $node source node
 * @param $file source file
 * @return XHTML code
 */
function _filebrowser_thumbnails_generate(& $node, & $file) {
  static $thumbnailers = NULL;
  if (!$thumbnailers) {
    $thumbnailers = module_implements("filebrowser_thumbnailer_get");
  }
  if (count($thumbnailers) != 0) {
    foreach ($thumbnailers as $thumbnailer) {
      if ($node->file_handlers->$thumbnailer->enabled_thumbnailer) {
        $thumbnail = module_invoke($thumbnailer, "filebrowser_thumbnailer_get", $file, $node->file_handlers->$thumbnailer);
        if ($thumbnail) {
          return $thumbnail;
        }
      }
    }
  }
  $main_type = dirname($file['mime-type']);
  $mime_type = str_replace("/", "-", $file['mime-type']);
  $module_path = drupal_get_path("module", "filebrowser") . "/icons/";
  $theme_path = drupal_get_path('theme', $GLOBALS['theme']) . "/filebrowser/";
  $icons = array(
    $theme_path . $mime_type . ".png",
    $theme_path . $main_type . ".png",
    $module_path . $mime_type . ".png",
    $module_path . $main_type . ".png"
  );
  $elligible =  $module_path . "unknown.png";
  foreach ($icons as $icon) {
    if (file_exists($icon)) {
      $elligible = $icon;
      break;
    }
  }
  return theme('image', array('path' => $icon, 'alt' => 'alt text'));
}

/**
 * @param form_state
 * @param i
 * @param path_info_new
 * @param path_info_old
 */
function _filebrowser_build_new_upload_file_name($node, $form_state, $i) {
  $file_name = $_FILES['files']['name']["file_$i"];
  if (!empty($form_state['values']["file_name_$i"])) {
    $path_info_new = pathinfo($form_state['values']["file_name_$i"]);
    $path_info_old = pathinfo($file_name);
    $file_name = $path_info_new['filename'];
    if (isset($path_info_old['extension'])) {
      $file_name .= ".{$path_info_old['extension']}";
    }
  }
  //debug($file_name, 'Line 709 - file name processed by _filebrowser_build_new_upload_file_name');
  _filebrowser_load_files($node);

  $target = _filebrowser_encoding_to_fs($node, $node->file_listing['.']['full-path'] . "/" . $file_name);
  return $target;
}

// JSJ DEBUG HELPER -  REMOVE
function debugPrintCallingFunction () {
  $file = 'n/a';
  $func = 'n/a';
  $line = 'n/a';
  $debugTrace = debug_backtrace();
  if (isset($debugTrace[1])) {
    $file = $debugTrace[1]['file'] ? $debugTrace[1]['file'] : 'n/a';
    $line = $debugTrace[1]['line'] ? $debugTrace[1]['line'] : 'n/a';
  }
    if (isset($debugTrace[2])) $func = $debugTrace[2]['function'] ? $debugTrace[2]['function'] : 'n/a';
    echo "<pre>\n$file, $func, $line\n</pre>";
}
