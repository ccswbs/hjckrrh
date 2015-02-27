<?php
/**
 * @file
 * ug_podcast.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_podcast_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
}
