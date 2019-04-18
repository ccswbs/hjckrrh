<?php
/**
 * @file
 * ug_profile_workbench_moderation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_profile_workbench_moderation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any unpublished profile content'.
  $permissions['view any unpublished profile content'] = array(
    'name' => 'view any unpublished profile content',
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
