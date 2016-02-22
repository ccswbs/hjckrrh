<?php
/**
 * @file
 * ug_book_layouts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_book_layouts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
