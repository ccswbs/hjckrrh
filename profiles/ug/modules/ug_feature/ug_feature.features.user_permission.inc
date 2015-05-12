<?php
/**
 * @file
 * ug_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create feature content'.
  $permissions['create feature content'] = array(
    'name' => 'create feature content',
    'roles' => array(
      'feature editor' => 'feature editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any feature content'.
  $permissions['delete any feature content'] = array(
    'name' => 'delete any feature content',
    'roles' => array(
      'feature editor' => 'feature editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own feature content'.
  $permissions['delete own feature content'] = array(
    'name' => 'delete own feature content',
    'roles' => array(
      'feature editor' => 'feature editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any feature content'.
  $permissions['edit any feature content'] = array(
    'name' => 'edit any feature content',
    'roles' => array(
      'feature editor' => 'feature editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own feature content'.
  $permissions['edit own feature content'] = array(
    'name' => 'edit own feature content',
    'roles' => array(
      'feature editor' => 'feature editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
