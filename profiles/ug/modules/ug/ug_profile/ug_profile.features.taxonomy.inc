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
    'profile_category' => array(
      'name' => 'Profile category',
      'machine_name' => 'profile_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_field_headings' => array(
      'name' => 'Profile field headings',
      'machine_name' => 'profile_field_headings',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_research' => array(
      'name' => 'Area of research',
      'machine_name' => 'profile_research',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_role' => array(
      'name' => 'Profile role',
      'machine_name' => 'profile_role',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_subunit' => array(
      'name' => 'Profile sub unit',
      'machine_name' => 'profile_subunit',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_unit' => array(
      'name' => 'Profile unit',
      'machine_name' => 'profile_unit',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
