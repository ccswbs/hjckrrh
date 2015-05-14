<?php
/**
 * @file
 * ug_page.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ug_page_user_default_roles() {
  $roles = array();

  // Exported role: page author.
  $roles['page author'] = array(
    'name' => 'page author',
    'weight' => 7,
  );

  // Exported role: page editor.
  $roles['page editor'] = array(
    'name' => 'page editor',
    'weight' => 6,
  );

  return $roles;
}
