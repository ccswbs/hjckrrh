<?php
/**
 * @file
 * ug_social.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_social_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create social content'.
  $permissions['create social content'] = array(
    'name' => 'create social content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any social content'.
  $permissions['delete any social content'] = array(
    'name' => 'delete any social content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own social content'.
  $permissions['delete own social content'] = array(
    'name' => 'delete own social content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any social content'.
  $permissions['edit any social content'] = array(
    'name' => 'edit any social content',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own social content'.
  $permissions['edit own social content'] = array(
    'name' => 'edit own social content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  return $permissions;
}
