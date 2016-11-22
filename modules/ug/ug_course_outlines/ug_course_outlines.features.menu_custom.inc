<?php
/**
 * @file
 * ug_course_outlines.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ug_course_outlines_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-course-outlines.
  $menus['menu-course-outlines'] = array(
    'menu_name' => 'menu-course-outlines',
    'title' => 'Course Outlines',
    'description' => 'Navigation menu for single course view',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Course Outlines');
  t('Navigation menu for single course view');

  return $menus;
}
