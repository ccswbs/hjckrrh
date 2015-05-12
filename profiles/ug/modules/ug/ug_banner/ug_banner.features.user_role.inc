<?php
/**
 * @file
 * ug_banner.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ug_banner_user_default_roles() {
  $roles = array();

  // Exported role: banner editor.
  $roles['banner editor'] = array(
    'name' => 'banner editor',
    'weight' => 6,
  );

  return $roles;
}
