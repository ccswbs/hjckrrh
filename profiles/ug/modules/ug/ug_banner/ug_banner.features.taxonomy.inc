<?php
/**
 * @file
 * ug_banner.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_banner_taxonomy_default_vocabularies() {
  return array(
    'banner_category' => array(
      'name' => 'Banner category',
      'machine_name' => 'banner_category',
      'description' => 'Categories related to banners',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
