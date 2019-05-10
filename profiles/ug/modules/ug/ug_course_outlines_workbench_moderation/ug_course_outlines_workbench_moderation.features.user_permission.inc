<?php
/**
 * @file
 * ug_course_outlines_workbench_moderation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_course_outlines_workbench_moderation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any unpublished course_outline content'.
  $permissions['view any unpublished course_outline content'] = array(
    'name' => 'view any unpublished course_outline content',
    'roles' => array(
      'author' => 'author',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
      'site manager' => 'site manager',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
