<?php
/**
 * @file
 * ug_profile_workbench_moderation.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ug_profile_workbench_moderation_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_drafty:admin/config/system/drafty.
  $menu_links['management_drafty:admin/config/system/drafty'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/drafty',
    'router_path' => 'admin/config/system/drafty',
    'link_title' => 'Drafty',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage Drafty settings.',
      ),
      'identifier' => 'management_drafty:admin/config/system/drafty',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_system:admin/config/system',
  );
  // Exported menu link: management_my-workbench:admin/workbench.
  $menu_links['management_my-workbench:admin/workbench'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/workbench',
    'router_path' => 'admin/workbench',
    'link_title' => 'My Workbench',
    'options' => array(
      'attributes' => array(
        'title' => 'My Workbench area',
      ),
      'identifier' => 'management_my-workbench:admin/workbench',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_workbench-email:admin/config/workbench/email.
  $menu_links['management_workbench-email:admin/config/workbench/email'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workbench/email',
    'router_path' => 'admin/config/workbench/email',
    'link_title' => 'Workbench Email',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure email moderation notification.',
      ),
      'identifier' => 'management_workbench-email:admin/config/workbench/email',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_workbench:admin/config/workbench',
  );
  // Exported menu link: management_workbench-moderation:admin/config/workbench/moderation.
  $menu_links['management_workbench-moderation:admin/config/workbench/moderation'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workbench/moderation',
    'router_path' => 'admin/config/workbench/moderation',
    'link_title' => 'Workbench Moderation',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure content moderation.',
      ),
      'identifier' => 'management_workbench-moderation:admin/config/workbench/moderation',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_workbench:admin/config/workbench',
  );
  // Exported menu link: management_workbench:admin/config/workbench.
  $menu_links['management_workbench:admin/config/workbench'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workbench',
    'router_path' => 'admin/config/workbench',
    'link_title' => 'Workbench',
    'options' => array(
      'attributes' => array(
        'title' => 'Workbench',
      ),
      'identifier' => 'management_workbench:admin/config/workbench',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_workflow:admin/config/workflow.
  $menu_links['management_workflow:admin/config/workflow'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow',
    'router_path' => 'admin/config/workflow',
    'link_title' => 'Workflow',
    'options' => array(
      'attributes' => array(
        'title' => 'Content workflow, editorial workflow tools.',
      ),
      'identifier' => 'management_workflow:admin/config/workflow',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Drafty');
  t('My Workbench');
  t('Workbench');
  t('Workbench Email');
  t('Workbench Moderation');
  t('Workflow');

  return $menu_links;
}
