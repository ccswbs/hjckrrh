<?php
/**
 * @file
 * ug_social.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_social_taxonomy_default_vocabularies() {
  return array(
    'social_media_category' => array(
      'name' => 'Social media category',
      'machine_name' => 'social_media_category',
      'description' => 'Group social media accounts by category',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
