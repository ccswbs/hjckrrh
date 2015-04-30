<?php
/**
 * @file
 * ug_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ug_profile_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_profile2_type().
 */
function ug_profile_default_profile2_type() {
  $items = array();
  $items['faculty'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "faculty",
    "label" : "Faculty profile",
    "weight" : "1",
    "data" : { "registration" : 0 }
  }');
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "main",
    "label" : "Main profile",
    "weight" : "0",
    "data" : { "registration" : 0 }
  }');
  return $items;
}
