<?php
/**
 * @file
 * ug_social.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ug_social_user_default_roles() {
  $roles = array();

  // Exported role: social media editor.
  $roles['social media editor'] = array(
    'name' => 'social media editor',
    'weight' => 4,
  );

  return $roles;
}
