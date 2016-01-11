<?php
/**
 * @file
 * ug_book.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_book_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in book_category'.
  $permissions['delete terms in book_category'] = array(
    'name' => 'delete terms in book_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in book_category'.
  $permissions['edit terms in book_category'] = array(
    'name' => 'edit terms in book_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
