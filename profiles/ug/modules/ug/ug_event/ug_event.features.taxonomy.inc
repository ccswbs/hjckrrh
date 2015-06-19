<?php
/**
 * @file
 * ug_event.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_event_taxonomy_default_vocabularies() {
  return array(
    'event_category' => array(
      'name' => 'Event category',
      'machine_name' => 'event_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'event_heading' => array(
      'name' => 'Event heading',
      'machine_name' => 'event_heading',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
