<?php
/**
 * @file
 * ug_service.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_service_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_service_price'.
  $permissions['create field_service_price'] = array(
    'name' => 'create field_service_price',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_service_private'.
  $permissions['create field_service_private'] = array(
    'name' => 'create field_service_private',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create service content'.
  $permissions['create service content'] = array(
    'name' => 'create service content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any service content'.
  $permissions['delete any service content'] = array(
    'name' => 'delete any service content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own service content'.
  $permissions['delete own service content'] = array(
    'name' => 'delete own service content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in service_audience'.
  $permissions['delete terms in service_audience'] = array(
    'name' => 'delete terms in service_audience',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in service_category'.
  $permissions['delete terms in service_category'] = array(
    'name' => 'delete terms in service_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in service_keywords'.
  $permissions['delete terms in service_keywords'] = array(
    'name' => 'delete terms in service_keywords',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in service_private_heading'.
  $permissions['delete terms in service_private_heading'] = array(
    'name' => 'delete terms in service_private_heading',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in service_public_heading'.
  $permissions['delete terms in service_public_heading'] = array(
    'name' => 'delete terms in service_public_heading',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any service content'.
  $permissions['edit any service content'] = array(
    'name' => 'edit any service content',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_service_price'.
  $permissions['edit field_service_price'] = array(
    'name' => 'edit field_service_price',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_service_private'.
  $permissions['edit field_service_private'] = array(
    'name' => 'edit field_service_private',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_service_price'.
  $permissions['edit own field_service_price'] = array(
    'name' => 'edit own field_service_price',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_service_private'.
  $permissions['edit own field_service_private'] = array(
    'name' => 'edit own field_service_private',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own service content'.
  $permissions['edit own service content'] = array(
    'name' => 'edit own service content',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in service_audience'.
  $permissions['edit terms in service_audience'] = array(
    'name' => 'edit terms in service_audience',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in service_category'.
  $permissions['edit terms in service_category'] = array(
    'name' => 'edit terms in service_category',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in service_keywords'.
  $permissions['edit terms in service_keywords'] = array(
    'name' => 'edit terms in service_keywords',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in service_private_heading'.
  $permissions['edit terms in service_private_heading'] = array(
    'name' => 'edit terms in service_private_heading',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in service_public_heading'.
  $permissions['edit terms in service_public_heading'] = array(
    'name' => 'edit terms in service_public_heading',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'view field_service_price'.
  $permissions['view field_service_price'] = array(
    'name' => 'view field_service_price',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_service_private'.
  $permissions['view field_service_private'] = array(
    'name' => 'view field_service_private',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_service_price'.
  $permissions['view own field_service_price'] = array(
    'name' => 'view own field_service_price',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_service_private'.
  $permissions['view own field_service_private'] = array(
    'name' => 'view own field_service_private',
    'roles' => array(
      'author' => 'author',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
