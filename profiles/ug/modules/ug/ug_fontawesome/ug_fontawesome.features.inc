<?php
/**
 * @file
 * ug_fontawesome.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_fontawesome_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
