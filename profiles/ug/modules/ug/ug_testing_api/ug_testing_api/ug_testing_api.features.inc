<?php
/**
 * @file
 * ug_testing_api.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_testing_api_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
