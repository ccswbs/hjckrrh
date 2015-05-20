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

  // Exported format: Advanced HTML.
  $formats['advanced_html'] = array(
    'format' => 'advanced_html',
    'name' => 'Advanced HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  // Exported format: Basic HTML.
  $formats['basic_html'] = array(
    'format' => 'basic_html',
    'name' => 'Basic HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
