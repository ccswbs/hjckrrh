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
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any feature content'.
  $permissions['delete any feature content'] = array(
    'name' => 'delete any feature content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own feature content'.
  $permissions['delete own feature content'] = array(
    'name' => 'delete own feature content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in feature_category'.
  $permissions['delete terms in feature_category'] = array(
    'name' => 'delete terms in feature_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any feature content'.
  $permissions['edit any feature content'] = array(
    'name' => 'edit any feature content',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own feature content'.
  $permissions['edit own feature content'] = array(
    'name' => 'edit own feature content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in feature_category'.
  $permissions['edit terms in feature_category'] = array(
    'name' => 'edit terms in feature_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
