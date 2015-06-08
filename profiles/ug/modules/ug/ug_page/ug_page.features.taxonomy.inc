<?php
/**
 * @file
 * ug_page.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_page_taxonomy_default_vocabularies() {
  return array(
    'page_category' => array(
      'name' => 'Page category',
      'machine_name' => 'page_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
