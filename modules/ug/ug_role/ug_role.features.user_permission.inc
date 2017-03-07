<?php
/**
 * @file
 * ug_role.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_role_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
      'site manager' => 'site manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'author' => 'author',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'author' => 'author',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'author' => 'author',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
      'site manager' => 'site manager',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'assign author role'.
  $permissions['assign author role'] = array(
    'name' => 'assign author role',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign editor role'.
  $permissions['assign editor role'] = array(
    'name' => 'assign editor role',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign moderator role'.
  $permissions['assign moderator role'] = array(
    'name' => 'assign moderator role',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign publisher role'.
  $permissions['assign publisher role'] = array(
    'name' => 'assign publisher role',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'path',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'editor' => 'editor',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'ug_permit any role'.
  $permissions['ug_permit any role'] = array(
    'name' => 'ug_permit any role',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'ug_permit',
  );

  // Exported permission: 'ug_permit node access'.
  $permissions['ug_permit node access'] = array(
    'name' => 'ug_permit node access',
    'roles' => array(
      'author' => 'author',
      'editor' => 'editor',
    ),
    'module' => 'ug_permit',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'author' => 'author',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'author' => 'author',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'author' => 'author',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
      'site manager' => 'site manager',
    ),
    'module' => 'system',
  );

  return $permissions;
}
