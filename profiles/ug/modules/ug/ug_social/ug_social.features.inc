<?php
/**
 * @file
 * ug_social.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_social_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ug_social_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ug_social_node_info() {
  $items = array(
    'social' => array(
      'name' => t('Social media account'),
      'base' => 'node_content',
      'description' => t('Allows users to visit social media accounts affiliated with the website.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
