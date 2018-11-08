<?php
/**
 * @file
 * ug_fontawesome.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ug_fontawesome_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fontawesome_external';
  $strongarm->value = array(
    'use_cdn' => 0,
    'external_location' => '',
  );
  $export['fontawesome_external'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fontawesome_method';
  $strongarm->value = 'webfonts';
  $export['fontawesome_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fontawesome_shim';
  $strongarm->value = array(
    'use_shim' => 0,
    'external_location' => '',
  );
  $export['fontawesome_shim'] = $strongarm;

  return $export;
}
