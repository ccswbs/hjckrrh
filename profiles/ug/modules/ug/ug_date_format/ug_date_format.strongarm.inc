<?php
/**
 * @file
 * ug_date_format.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ug_date_format_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_short';
  $strongarm->value = 'M j, Y';
  $export['date_format_short'] = $strongarm;

  return $export;
}
