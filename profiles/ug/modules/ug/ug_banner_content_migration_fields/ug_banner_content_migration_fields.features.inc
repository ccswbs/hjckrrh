<?php

/**
 * @file
 * ug_banner_content_migration_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_banner_content_migration_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
