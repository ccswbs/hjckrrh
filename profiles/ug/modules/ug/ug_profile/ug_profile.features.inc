<?php
/**
 * @file
 * ug_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
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
 * Implements hook_node_info().
 */
function ug_profile_node_info() {
  $items = array(
    'profile' => array(
      'name' => t('Profile'),
      'base' => 'node_content',
      'description' => t('The People Profiles feature allows an authorized user to create and edit an organizational profile.'),
      'has_title' => '1',
      'title_label' => t('Display name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
