<?php
/**
 * @file
 * ug_faq.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_faq_taxonomy_default_vocabularies() {
  return array(
    'faq_category' => array(
      'name' => 'FAQ category',
      'machine_name' => 'faq_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
