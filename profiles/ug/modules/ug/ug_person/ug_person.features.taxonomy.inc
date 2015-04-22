<?php
/**
 * @file
 * ug_person.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_person_taxonomy_default_vocabularies() {
  return array(
    'person_research' => array(
      'name' => 'Area of research',
      'machine_name' => 'person_research',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'person_unit' => array(
      'name' => 'Unit',
      'machine_name' => 'person_unit',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
