<?php
/**
 * @file
 * ug_event.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ug_event_user_default_roles() {
  $roles = array();

  // Exported role: events editor.
  $roles['events editor'] = array(
    'name' => 'events editor',
    'weight' => 3,
  );

  return $roles;
}
