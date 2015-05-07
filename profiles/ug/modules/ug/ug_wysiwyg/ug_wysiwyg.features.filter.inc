<?php
/**
 * @file
 * ug_wysiwyg.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function ug_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: Basic HTML.
  $formats['basic_html'] = array(
    'format' => 'basic_html',
    'name' => 'Basic HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
