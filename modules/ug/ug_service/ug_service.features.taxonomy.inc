<?php
/**
 * @file
 * ug_service.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_service_taxonomy_default_vocabularies() {
  return array(
    'service_audience' => array(
      'name' => 'Service audience',
      'machine_name' => 'service_audience',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'service_category' => array(
      'name' => 'Service category',
      'machine_name' => 'service_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'service_keywords' => array(
      'name' => 'Service keywords',
      'machine_name' => 'service_keywords',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'service_private_heading' => array(
      'name' => 'Service private heading',
      'machine_name' => 'service_private_heading',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'service_public_heading' => array(
      'name' => 'Service public heading',
      'machine_name' => 'service_public_heading',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
