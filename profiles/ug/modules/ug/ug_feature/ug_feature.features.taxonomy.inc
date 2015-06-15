<?php
/**
 * @file
 * ug_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_feature_taxonomy_default_vocabularies() {
  return array(
    'feature_category' => array(
      'name' => 'Feature category',
      'machine_name' => 'feature_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
