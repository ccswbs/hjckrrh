<?php
/**
 * @file
 * ug_layout.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_layout_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'site manager' => 'site manager',
    ),
    'module' => 'panels',
  );

  return $permissions;
}
