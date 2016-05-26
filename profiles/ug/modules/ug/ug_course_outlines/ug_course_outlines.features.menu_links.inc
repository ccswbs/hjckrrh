<?php
/**
 * @file
 * ug_course_outlines.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ug_course_outlines_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-course-outlines_all-course-outlines:course-outlines.
  $menu_links['menu-course-outlines_all-course-outlines:course-outlines'] = array(
    'menu_name' => 'menu-course-outlines',
    'link_path' => 'course-outlines',
    'router_path' => 'course-outlines',
    'link_title' => 'All course outlines',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-course-outlines_all-course-outlines:course-outlines',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-course-outlines_fall-semester:course-outlines.
  $menu_links['menu-course-outlines_fall-semester:course-outlines'] = array(
    'menu_name' => 'menu-course-outlines',
    'link_path' => 'course-outlines',
    'router_path' => 'course-outlines',
    'link_title' => 'Fall semester',
    'options' => array(
      'query' => array(
        'field_course_semester_value' => 'F',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-course-outlines_fall-semester:course-outlines',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: menu-course-outlines_spring-semester:course-outlines.
  $menu_links['menu-course-outlines_spring-semester:course-outlines'] = array(
    'menu_name' => 'menu-course-outlines',
    'link_path' => 'course-outlines',
    'router_path' => 'course-outlines',
    'link_title' => 'Spring semester',
    'options' => array(
      'query' => array(
        'field_course_semester_value' => 'S',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-course-outlines_spring-semester:course-outlines',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: menu-course-outlines_winter-semester:course-outlines.
  $menu_links['menu-course-outlines_winter-semester:course-outlines'] = array(
    'menu_name' => 'menu-course-outlines',
    'link_path' => 'course-outlines',
    'router_path' => 'course-outlines',
    'link_title' => 'Winter semester',
    'options' => array(
      'query' => array(
        'field_course_semester_value' => 'W',
      ),
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-course-outlines_winter-semester:course-outlines',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: navigation_course-outline:node/add/course-outline.
  $menu_links['navigation_course-outline:node/add/course-outline'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/course-outline',
    'router_path' => 'node/add/course-outline',
    'link_title' => 'Course outline',
    'options' => array(
      'attributes' => array(
        'title' => 'Add <em>course outlines</em> to your site.',
      ),
      'identifier' => 'navigation_course-outline:node/add/course-outline',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('All course outlines');
  t('Course outline');
  t('Fall semester');
  t('Spring semester');
  t('Winter semester');

  return $menu_links;
}
