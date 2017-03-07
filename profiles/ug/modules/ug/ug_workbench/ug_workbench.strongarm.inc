<?php
/**
 * @file
 * ug_workbench.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ug_workbench_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_access_node_type_page';
  $strongarm->value = 1;
  $export['workbench_access_node_type_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_page';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_page'] = $strongarm;

  return $export;
}
