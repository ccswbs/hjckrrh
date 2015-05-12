<?php
/**
 * @file
 * ug_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ug_feature_user_default_roles() {
  $roles = array();

  // Exported role: feature editor.
  $roles['feature editor'] = array(
    'name' => 'feature editor',
    'weight' => 5,
  );

  return $roles;
}
