<?php
/**
 * @file
 * ug_profile.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_profile_taxonomy_default_vocabularies() {
  return array(
    'profile_research' => array(
      'name' => 'Area of research',
      'machine_name' => 'profile_research',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_role' => array(
      'name' => 'Role',
      'machine_name' => 'profile_role',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_subunit' => array(
      'name' => 'Sub unit',
      'machine_name' => 'profile_subunit',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_unit' => array(
      'name' => 'Unit',
      'machine_name' => 'profile_unit',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
