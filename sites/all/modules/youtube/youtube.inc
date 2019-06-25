<?php

/**
 * @ file
 * YouTube field helper functions.
 */

/**
 * Extracts the video_id from the submitted field value.
 *
 * @param $input
 *   The input submitted to the field.
 *
 * @return
 *   Returns the video_id if available, or FALSE if not.
 */
function youtube_get_video_id($input) {
  // See README.txt for accepted URL formats.
  preg_match("/^(?:http(?:s)?:\/\/)?(?:www\.)?(?:youtu\.be\/|youtube\.com\/(?:(?:watch)?\?(?:.*&)?v(?:i)?=|(?:embed|v|vi|user)\/))([^\?&\"'<> #]+)/", $input, $matches);

  if (!empty($matches[1])) {
    $video_id = $matches[1];
    return $video_id;
  }

  return FALSE;
}

/**
 * Returns a list of YouTube video size options.
 *
 * @return array
 *   An array of options, keyed by machine name with human readable values.
 */
function youtube_size_options() {
  return array(
    '420x315' => '450px by 315px',
    '480x360' => '480px by 360px',
    '640x480' => '640px by 480px',
    '960x720' => '960px by 720px',
    'responsive' => 'responsive (full-width of container)',
    'custom' => 'custom',
  );
}

/**
 * Returns a list of thumbnail link types.
 *
 * @return array
 *   An array of link types, keyed by machine name with human readable values.
 */
function youtube_thumbnail_link_types() {
  $link_types = array(
    'content' => t('Content'),
    'youtube' => t('YouTube'),
  );

  // Allow other modules to add link types.
  drupal_alter('youtube_thumbnail_link_types', $link_types);

  return $link_types;
}

/**
 * Determines the height and width when given a player size.
 *
 * @param string $size
 *   (optional) The machine name of the size from youtube_size_options().
 * @param string $width
 *   (optional) The width input for custom dimensions.
 * @param string $height
 *   (optional) The height input for custom dimensions.
 *
 * @return array
 *   An array keyed by 'width' and 'height' with the values to use when theming
 *   the video player.
 */
function youtube_get_dimensions($size = NULL, $width = NULL, $height = NULL) {
  $dimensions = array();
  if ($size == 'responsive') {
    $dimensions['width'] = '100%';
    $dimensions['height'] = '100%';
  }
  elseif ($size == 'custom') {
    $dimensions['width'] = strstr($width, '%') ? (int) $width . '%' : (int) $width;
    $dimensions['height'] = strstr($height, '%') ? (int) $height . '%' : (int) $height;
  }
  else {
    // Locate the 'x'.
    $strpos = strpos($size, 'x');
    // Width is the first dimension.
    $dimensions['width'] = substr($size, 0, $strpos);
    // Height is the second dimension.
    $dimensions['height'] = substr($size, $strpos + 1, strlen($size));
  }

  return $dimensions;
}

/**
 * Builds the URI to a given thumbnail or the module's thumbnail directory.
 *
 * @param string $video_id
 *   (optional) The video ID to build the thumbnail URI for.
 *
 * @return string
 *   If a $video_id was supplied, the URI to that video's thumbnail. Otherwise
 *   the URI to the module's thumbnail directory.
 */
function youtube_build_thumbnail_uri($video_id = NULL) {
  $scheme = file_default_scheme();
  $youtube_thumb_dir = variable_get('youtube_thumb_dir', 'youtube');
  $youtube_thumb_uri = $scheme . '://' . $youtube_thumb_dir;

  if ($video_id) {
    return $youtube_thumb_uri . '/' . $video_id . '.jpg';
  }

  return $youtube_thumb_uri;
}

/**
 * Retrieves the thumbnail image for a given video from YouTube.
 *
 * @param integer $video_id
 *   The video ID of the particular YouTube video.
 * @param bool $force_small
 *   (optional) When TRUE, this function should return the standard size image
 *   regardless of what the youtube_thumb_hires variable is set to. This is used
 *   should the high resolution image be found to not exist for a particular
 *   video.
 *
 * @return bool|stdClass
 *   Either the Drupal $file object of saved image, or FALSE if the save failed.
 */
function youtube_get_remote_image($video_id = NULL, $force_small = FALSE) {
  // This variable is TRUE when higher resolution thumbnails should be saved.
  // The only thumbnail resolution higher than the standard 480 is
  // 'maxresdefault'. This resolution image is not guaranteed to exist. If
  // there's an error retrieving the hi-res image, we try again for small.
  $youtube_thumb_hires = variable_get('youtube_thumb_hires', FALSE);
  // This boolean is TRUE if we're obtaining a hi-res thumbnail.
  $get_hires = ($youtube_thumb_hires && !$force_small);

  if ($get_hires) {
    $src = youtube_build_remote_image_path($video_id, 'maxresdefault');
  }
  else {
    $src = youtube_build_remote_image_path($video_id);
  }

  // Download file and save it as managed Drupal file.
  $image = drupal_http_request($src);
  if ($image->code != 200) {
    // Silently retry for small image if hi-res did not exist, otherwise log an
    // error and return FALSE.
    if ($get_hires) {
      return youtube_get_remote_image($video_id, TRUE);
    }
    watchdog('youtube',
      'HTTP request for video ID %id failed (error code: %err).',
      array('%id', $video_id, '%err', $image->code),
      WATCHDOG_ERROR);
    return FALSE;
  }

  // Set the path to thumbnails, and make sure it's usable.
  $youtube_thumb_uri = youtube_build_thumbnail_uri();
  if (!file_prepare_directory($youtube_thumb_uri, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
    watchdog('youtube',
      'Failed to create YouTube thumbnail directory: %dir',
      array('%dir' => $youtube_thumb_uri),
      WATCHDOG_ERROR);
    return FALSE;
  }
  $destination = youtube_build_thumbnail_uri($video_id);
  // Save the thumbnail and add to Drupal managed files.
  $file = file_save_data($image->data, $destination, FILE_EXISTS_REPLACE);

  if (!$file) {
    watchdog('youtube',
      'Unable to save youtube thumbnail to filesystem for video %id',
      array('%id' => $video_id),
      WATCHDOG_ERROR);
  }

  return $file;
}

/**
 * Submit callback; delete all existing thumbnail image files.
 *
 * @see youtube_settings_form()
 */
function youtube_thumb_delete_all($form, &$form_state) {
  $youtube_thumb_uri = youtube_build_thumbnail_uri();

  if (!file_prepare_directory($youtube_thumb_uri)) {
    return drupal_set_message(t('No files deleted.'));
  }

  $files = file_scan_directory($youtube_thumb_uri, '/^.*\.(jpg|png)$/');

  $legacy_files = FALSE;
  foreach ($files as $raw_file) {
    // Check if file is being managed by Drupal.
    $uri = $youtube_thumb_uri . '/' . $raw_file->filename;
    $managed_file = db_select('file_managed', 'fm')
      ->fields('fm')
      ->condition('uri', '%' . $uri, 'LIKE')
      ->execute()
      ->fetchAssoc();
    if (!$managed_file) {
      // Old files exist before module used managed files, notify user.
      $legacy_files = file_unmanaged_delete($raw_file->uri);
    }
    else {
      $file = file_load($managed_file['fid']);
      // file_delete() invokes hooks to refresh associated image files.
      file_delete($file);
    }
  }

  if ($legacy_files) {
    drupal_set_message(t('Note: Some unmanaged files from an older version of
      the module were deleted. Their associated image style derivatives were not
      deleted. <a href="@imagestyleflush">Image style flush</a> or
      `drush image-flush` can be used for that. New thumbnails will be managed
      files and will not have this issue.',
      array('@imagestyleflush' => 'https://www.drupal.org/project/imagestyleflush')));
  }
}

/**
 * Get YouTube image path by building correctly formed URL.
 *
 * @param $video_id
 *   (optional) The ID of the video to grab the thumbnail from.
 * @param $version
 *   (optional) Which version of the thumbnail to grab.
 *
 * @return string
 *   The youtube.com image path to the specified version/video.
 */
function youtube_build_remote_image_path($video_id = NULL, $version = '0') {
  // The different versions of the image made available by YouTube.
  // http://stackoverflow.com/questions/2068344/how-to-get-thumbnail-of-youtube-video-link-using-youtube-api
  $versions = array(
    '0',
    'hqdefault',
    'mqdefault',
    'maxresdefault',
    'default',
    '1',
    '2',
    '3',
  );

  if (!$video_id || !in_array($version, $versions)) {
    return;
  }

  $version_path = 'http://img.youtube.com/vi/' . $video_id . '/' . $version . '.jpg';
  return url($version_path);
}

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * Adds a target option for YouTube fields to Feeds mapping options.
 */
function youtube_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);

    if (in_array($info['type'], array('youtube'))) {
      $targets[$name] = array(
        'name' => check_plain($instance['label']),
        'callback' => 'youtube_set_target',
        'description' => t('The @label field of the node.', array('@label' => $instance['label'])),
      );
    }
  }
}

/**
 * Callback to set the Feeds target for a YouTube field.
 *
 * @param $source
 *   Field mapper source settings.
 * @param $entity
 *   An entity object, for instance a node object.
 * @param $target
 *   A string identifying the target on the node.
 * @param $value
 *   The value to populate the target with.
 * @param $mapping
 *   Associative array of the mapping settings from the per mapping
 *   configuration form.
 */
function youtube_set_target($source, $entity, $target, $value, $mapping) {
  if (empty($value)) {
    return;
  }

  if (!is_array($value)) {
    $value = array($value);
  }

  $info = field_info_field($target);
  $field = isset($entity->$target) ? $entity->$target : array(LANGUAGE_NONE => array());

  // Allow for mappings to a multi-value field on the same target.
  $delta = count($field[LANGUAGE_NONE]);

  foreach ($value as $v) {
    if ($info['cardinality'] == $delta) {
      break;
    }

    if (is_object($v) && ($v instanceof FeedsElement)) {
      $v = $v->getValue();
    }

    if (is_scalar($v)) {
      $video_id = youtube_get_video_id($v);
      if ($video_id) {
        $entity->{$target}[LANGUAGE_NONE][$delta] = array(
          'input' => $v,
          'video_id' => $video_id,
        );
        $delta++;
      }
    }
  }
}

/**
 * Implements hook_token_info_alter().
 *
 * Alters and adds tokens for each youtube field.
 */
function youtube_token_info_alter(&$data) {
  // Get all youtube fields. Gather entity_type and bundle information.
  $fields = field_info_fields();
  $youtube_fields = array();
  foreach ($fields as $name => $field) {
    if ($field['type'] == 'youtube') {
      foreach ($field['bundles'] as $type => $entity_type) {
        foreach ($entity_type as $bundle) {
          $youtube_fields[] = array(
            'entity_type' => $type,
            'bundle' => $bundle,
            'field_name' => $name,
          );
        }
      }
    }
  }

  foreach ($youtube_fields as $field) {
    $field_info = field_info_instance($field['entity_type'], $field['field_name'], $field['bundle']);
    $field_label = $field_info['label'];

    // Modify the default field token.
    $data['tokens'][$field['entity_type']][$field['field_name']] = array(
      'name' => $field_label . t(": Default"),
      'description' => t("The YouTube video field value's Default (or Token if exists) view mode output."),
    );

    // Add two new tokens.
    $data['tokens'][$field['entity_type']][$field['field_name'] . '__youtube_video_url'] = array(
      'name' => $field_label . t(": Video URL"),
      'description' => t("The YouTube video field value's youtube.com URL."),
    );
    $data['tokens'][$field['entity_type']][$field['field_name'] . '__youtube_image_url'] = array(
      'name' => $field_label . t(": Image URL"),
      'description' => t("The YouTube video field value's local image URL."),
    );
  }
}

/**
 * Implements hook_tokens().
 *
 * @see youtube_tokens_info_alter()
 */
function youtube_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $base_url;
  global $base_path;

  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }
  $sanitize = !empty($options['sanitize']);

  $replacements = array();

  if ($type == 'node' && !empty($data['node'])) {
    $node = $data['node'];

    foreach ($tokens as $name => $original) {
      if (!strpos($name, '__youtube_')) {
        // This isn't a YouTube Field token!
        continue;
      }

      $token_pieces = explode('__', $name);
      if (count($token_pieces) != 2) {
        continue;
      }

      $field_name = $token_pieces[0];
      $token_name = $token_pieces[1];

      switch ($token_name) {
        case 'youtube_video_url':
          $replacements[$original] = '';

          if ($field_value = field_get_items('node', $node, $field_name)) {
            $replacements[$original] = 'http://www.youtube.com/watch?v=' . $field_value[0]['video_id'];
          }
          break;

        case 'youtube_image_url':
          $replacements[$original] = '';

          if ($field_value = field_get_items('node', $node, $field_name)) {
            $video_id = $field_value[0]['video_id'];
            $file_uri = youtube_build_thumbnail_uri($video_id);
            $file_url = file_create_url($file_uri);
            if (file_exists($file_url) || youtube_get_remote_image($video_id)) {
              $replacements[$original] = $file_url;

              if ($style_name = variable_get('youtube_thumb_token_image_style', NULL)) {
                $derivative_uri = image_style_path($style_name, $file_uri);
                if (!file_exists($derivative_uri)) {
                  $image_style = image_style_load($style_name);
                  image_style_create_derivative($image_style, $file_uri, $derivative_uri);
                }
                $replacements[$original] = file_create_url($derivative_uri);
              }
            }
          }
          break;
      }
    }
  }

  return $replacements;
}
