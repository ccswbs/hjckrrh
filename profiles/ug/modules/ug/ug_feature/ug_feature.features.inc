<?php
/**
 * @file
 * ug_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "linkit" && $api == "linkit_profiles") {
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
function ug_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ug_feature_node_info() {
  $items = array(
    'feature' => array(
      'name' => t('Feature'),
      'base' => 'node_content',
      'description' => t('The Featured Item allows content editors to create a lead-in to any page content on the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
