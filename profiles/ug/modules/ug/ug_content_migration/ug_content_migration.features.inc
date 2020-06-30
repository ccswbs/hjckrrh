<?php

/**
 * @file
 * ug_content_migration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_content_migration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
