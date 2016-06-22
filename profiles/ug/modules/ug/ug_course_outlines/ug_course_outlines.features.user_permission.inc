<?php
/**
 * @file
 * ug_course_outlines.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ug_course_outlines_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create course_outline content'.
  $permissions['create course_outline content'] = array(
    'name' => 'create course_outline content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any course_outline content'.
  $permissions['delete any course_outline content'] = array(
    'name' => 'delete any course_outline content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_outline content'.
  $permissions['delete own course_outline content'] = array(
    'name' => 'delete own course_outline content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in course_outline_category'.
  $permissions['delete terms in course_outline_category'] = array(
    'name' => 'delete terms in course_outline_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_outline_department'.
  $permissions['delete terms in course_outline_department'] = array(
    'name' => 'delete terms in course_outline_department',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in course_outline_subject'.
  $permissions['delete terms in course_outline_subject'] = array(
    'name' => 'delete terms in course_outline_subject',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any course_outline content'.
  $permissions['edit any course_outline content'] = array(
    'name' => 'edit any course_outline content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own course_outline content'.
  $permissions['edit own course_outline content'] = array(
    'name' => 'edit own course_outline content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in course_outline_category'.
  $permissions['edit terms in course_outline_category'] = array(
    'name' => 'edit terms in course_outline_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_outline_department'.
  $permissions['edit terms in course_outline_department'] = array(
    'name' => 'edit terms in course_outline_department',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in course_outline_subject'.
  $permissions['edit terms in course_outline_subject'] = array(
    'name' => 'edit terms in course_outline_subject',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
