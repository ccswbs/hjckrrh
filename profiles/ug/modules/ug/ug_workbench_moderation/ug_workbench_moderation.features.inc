<?php
/**
 * @file
 * ug_workbench_moderation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_workbench_moderation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
