<?php
/**
 * @file
 * ug_banner.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_banner_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create banner content'.
  $permissions['create banner content'] = array(
    'name' => 'create banner content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any banner content'.
  $permissions['delete any banner content'] = array(
    'name' => 'delete any banner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own banner content'.
  $permissions['delete own banner content'] = array(
    'name' => 'delete own banner content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in banner_category'.
  $permissions['delete terms in banner_category'] = array(
    'name' => 'delete terms in banner_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any banner content'.
  $permissions['edit any banner content'] = array(
    'name' => 'edit any banner content',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own banner content'.
  $permissions['edit own banner content'] = array(
    'name' => 'edit own banner content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in banner_category'.
  $permissions['edit terms in banner_category'] = array(
    'name' => 'edit terms in banner_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
