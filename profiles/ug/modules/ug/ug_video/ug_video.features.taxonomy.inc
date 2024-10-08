<?php
/**
 * @file
 * ug_video.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_video_taxonomy_default_vocabularies() {
  return array(
    'video_category' => array(
      'name' => 'Video category',
      'machine_name' => 'video_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
