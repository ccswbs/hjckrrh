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

  // Exported permission: 'access printer-friendly version'.
  $permissions['access printer-friendly version'] = array(
    'name' => 'access printer-friendly version',
    'roles' => array(),
    'module' => 'book',
  );

  // Exported permission: 'add content to books'.
  $permissions['add content to books'] = array(
    'name' => 'add content to books',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'book',
  );

  // Exported permission: 'administer book outlines'.
  $permissions['administer book outlines'] = array(
    'name' => 'administer book outlines',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'book',
  );

  // Exported permission: 'create book content'.
  $permissions['create book content'] = array(
    'name' => 'create book content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create new books'.
  $permissions['create new books'] = array(
    'name' => 'create new books',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'book',
  );

  // Exported permission: 'delete any book content'.
  $permissions['delete any book content'] = array(
    'name' => 'delete any book content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own book content'.
  $permissions['delete own book content'] = array(
    'name' => 'delete own book content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in book_category'.
  $permissions['delete terms in book_category'] = array(
    'name' => 'delete terms in book_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any book content'.
  $permissions['edit any book content'] = array(
    'name' => 'edit any book content',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own book content'.
  $permissions['edit own book content'] = array(
    'name' => 'edit own book content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
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
