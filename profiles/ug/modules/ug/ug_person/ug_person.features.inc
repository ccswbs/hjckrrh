<?php
/**
 * @file
 * ug_person.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_person_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ug_person_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ug_person_node_info() {
  $items = array(
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('Add personal profiles to your site.'),
      'has_title' => '1',
      'title_label' => t('Preferred name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
