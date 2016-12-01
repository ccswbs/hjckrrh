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

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(),
    'module' => 'print_pdf',
  );

  // Exported permission: 'access news feeds'.
  $permissions['access news feeds'] = array(
    'name' => 'access news feeds',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'aggregator',
  );

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print',
  );

  // Exported permission: 'administer news feeds'.
  $permissions['administer news feeds'] = array(
    'name' => 'administer news feeds',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'aggregator',
  );

  // Exported permission: 'administer print'.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'print',
  );

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

  // Exported permission: 'delete terms in social_media_category'.
  $permissions['delete terms in social_media_category'] = array(
    'name' => 'delete terms in social_media_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
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

  // Exported permission: 'edit terms in social_media_category'.
  $permissions['edit terms in social_media_category'] = array(
    'name' => 'edit terms in social_media_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'node-specific print configuration'.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'print_ui',
  );

  return $permissions;
}
