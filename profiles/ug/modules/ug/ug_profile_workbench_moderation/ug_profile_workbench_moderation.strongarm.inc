<?php
/**
 * @file
 * ug_profile_workbench_moderation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ug_profile_workbench_moderation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_profile';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_profile'] = $strongarm;

  return $export;
}
