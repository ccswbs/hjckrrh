<?php
/**
 * @file
 * ug_workbench_moderation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ug_workbench_moderation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_email_queue_mail';
  $strongarm->value = 0;
  $export['workbench_email_queue_mail'] = $strongarm;

  return $export;
}
