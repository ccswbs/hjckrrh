<?php
/**
 * @file
 * ug_book.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ug_book_taxonomy_default_vocabularies() {
  return array(
    'book_category' => array(
      'name' => 'Book category',
      'machine_name' => 'book_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
