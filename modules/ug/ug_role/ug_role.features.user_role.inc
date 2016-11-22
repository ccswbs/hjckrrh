<?php
/**
 * @file
 * ug_role.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ug_role_user_default_roles() {
  $roles = array();

  // Exported role: author.
  $roles['author'] = array(
    'name' => 'author',
    'weight' => 9,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 10,
  );

  // Exported role: moderator.
  $roles['moderator'] = array(
    'name' => 'moderator',
    'weight' => 11,
  );

  // Exported role: publisher.
  $roles['publisher'] = array(
    'name' => 'publisher',
    'weight' => 12,
  );

  // Exported role: site manager.
  $roles['site manager'] = array(
    'name' => 'site manager',
    'weight' => 13,
  );

  return $roles;
}
