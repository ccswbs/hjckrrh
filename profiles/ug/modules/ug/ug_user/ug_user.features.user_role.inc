<?php
/**
 * @file
 * ug_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ug_user_user_default_roles() {
  $roles = array();

  // Exported role: content editor.
  $roles['content editor'] = array(
    'name' => 'content editor',
    'weight' => 8,
  );

  return $roles;
}
