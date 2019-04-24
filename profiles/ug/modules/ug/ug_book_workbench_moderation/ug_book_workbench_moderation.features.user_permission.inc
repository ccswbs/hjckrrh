<?php
/**
 * @file
 * ug_book_workbench_moderation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_book_workbench_moderation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any unpublished book content'.
  $permissions['view any unpublished book content'] = array(
    'name' => 'view any unpublished book content',
    'roles' => array(
      'author' => 'author',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
      'site manager' => 'site manager',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
