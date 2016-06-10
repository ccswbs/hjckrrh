<?php
/**
 * @file
 * ug_course_outlines.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ug_course_outlines_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ug_course_outlines_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ug_course_outlines_node_info() {
  $items = array(
    'course_outline' => array(
      'name' => t('Course outline'),
      'base' => 'node_content',
      'description' => t('Add <em>course outlines</em> to your site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
