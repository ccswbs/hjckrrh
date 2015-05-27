<?php
/**
 * @file
 * ug_tags.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_tags_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
