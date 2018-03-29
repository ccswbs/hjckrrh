<?php
/**
 * @file
 * ug_a11y.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_a11y_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer siteimprove'.
  $permissions['administer siteimprove'] = array(
    'name' => 'administer siteimprove',
    'roles' => array(),
    'module' => 'siteimprove',
  );

  // Exported permission: 'use siteimprove'.
  $permissions['use siteimprove'] = array(
    'name' => 'use siteimprove',
    'roles' => array(
      'author' => 'author',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
      'site manager' => 'site manager',
    ),
    'module' => 'siteimprove',
  );

  return $permissions;
}
