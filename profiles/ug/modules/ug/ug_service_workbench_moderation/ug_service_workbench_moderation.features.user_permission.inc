<?php
/**
 * @file
 * ug_service_workbench_moderation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_service_workbench_moderation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any unpublished service content'.
  $permissions['view any unpublished service content'] = array(
    'name' => 'view any unpublished service content',
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
