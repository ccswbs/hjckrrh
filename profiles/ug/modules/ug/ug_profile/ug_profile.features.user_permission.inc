<?php
/**
 * @file
 * ug_profile.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_profile_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create profile content'.
  $permissions['create profile content'] = array(
    'name' => 'create profile content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any profile content'.
  $permissions['delete any profile content'] = array(
    'name' => 'delete any profile content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own profile content'.
  $permissions['delete own profile content'] = array(
    'name' => 'delete own profile content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in profile_category'.
  $permissions['delete terms in profile_category'] = array(
    'name' => 'delete terms in profile_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in profile_field_headings'.
  $permissions['delete terms in profile_field_headings'] = array(
    'name' => 'delete terms in profile_field_headings',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in profile_research'.
  $permissions['delete terms in profile_research'] = array(
    'name' => 'delete terms in profile_research',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in profile_role'.
  $permissions['delete terms in profile_role'] = array(
    'name' => 'delete terms in profile_role',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in profile_subunit'.
  $permissions['delete terms in profile_subunit'] = array(
    'name' => 'delete terms in profile_subunit',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in profile_unit'.
  $permissions['delete terms in profile_unit'] = array(
    'name' => 'delete terms in profile_unit',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any profile content'.
  $permissions['edit any profile content'] = array(
    'name' => 'edit any profile content',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own profile content'.
  $permissions['edit own profile content'] = array(
    'name' => 'edit own profile content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in profile_category'.
  $permissions['edit terms in profile_category'] = array(
    'name' => 'edit terms in profile_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in profile_field_headings'.
  $permissions['edit terms in profile_field_headings'] = array(
    'name' => 'edit terms in profile_field_headings',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in profile_research'.
  $permissions['edit terms in profile_research'] = array(
    'name' => 'edit terms in profile_research',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in profile_role'.
  $permissions['edit terms in profile_role'] = array(
    'name' => 'edit terms in profile_role',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in profile_subunit'.
  $permissions['edit terms in profile_subunit'] = array(
    'name' => 'edit terms in profile_subunit',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in profile_unit'.
  $permissions['edit terms in profile_unit'] = array(
    'name' => 'edit terms in profile_unit',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
