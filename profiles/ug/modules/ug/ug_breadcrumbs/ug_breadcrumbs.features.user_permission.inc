<?php
/**
 * @file
 * ug_breadcrumbs.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_breadcrumbs_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer crumbs'.
  $permissions['administer crumbs'] = array(
    'name' => 'administer crumbs',
    'roles' => array(),
    'module' => 'crumbs',
  );

  return $permissions;
}
