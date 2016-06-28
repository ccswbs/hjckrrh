<?php
/**
 * @file
 * ug_course_outlines.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_course_outlines_taxonomy_default_vocabularies() {
  return array(
    'course_outline_academic_level' => array(
      'name' => 'Course outline academic level',
      'machine_name' => 'course_outline_academic_level',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'course_outline_category' => array(
      'name' => 'Course outline category',
      'machine_name' => 'course_outline_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'course_outline_department' => array(
      'name' => 'Course outline academic department',
      'machine_name' => 'course_outline_department',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'course_outline_level' => array(
      'name' => 'Course outline level',
      'machine_name' => 'course_outline_level',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'course_outline_subject' => array(
      'name' => 'Course outline subject',
      'machine_name' => 'course_outline_subject',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'course_outline_term' => array(
      'name' => 'Course outline term',
      'machine_name' => 'course_outline_term',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
