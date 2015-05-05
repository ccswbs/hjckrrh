<?php
/**
 * @file
 * ug_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ug_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'p1';
  $view->description = 'Provides a listing of all profiles.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'P1 - Listing page for multiple people profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
  $handler->display->display_options['relationships']['profile_1']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_1']['label'] = 'Faculty';
  $handler->display->display_options['relationships']['profile_1']['bundle_types'] = array(
    'faculty' => 'faculty',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_profile_email']['id'] = 'field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['table'] = 'field_data_field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['field'] = 'field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['relationship'] = 'profile';
  /* Field: Profile: Feature image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'url_type' => '0',
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_profile_lastname']['id'] = 'field_profile_lastname';
  $handler->display->display_options['fields']['field_profile_lastname']['table'] = 'field_data_field_profile_lastname';
  $handler->display->display_options['fields']['field_profile_lastname']['field'] = 'field_profile_lastname';
  $handler->display->display_options['fields']['field_profile_lastname']['relationship'] = 'profile';
  /* Field: Profile: Phone number */
  $handler->display->display_options['fields']['field_profile_telephonenumber']['id'] = 'field_profile_telephonenumber';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['table'] = 'field_data_field_profile_telephonenumber';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['field'] = 'field_profile_telephonenumber';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['relationship'] = 'profile';
  /* Field: Profile: Position/title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['relationship'] = 'profile';
  /* Field: Profile: Preferred name */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'profile';
  /* Field: Profile: Unit */
  $handler->display->display_options['fields']['field_profile_unit']['id'] = 'field_profile_unit';
  $handler->display->display_options['fields']['field_profile_unit']['table'] = 'field_data_field_profile_unit';
  $handler->display->display_options['fields']['field_profile_unit']['field'] = 'field_profile_unit';
  $handler->display->display_options['fields']['field_profile_unit']['relationship'] = 'profile';
  /* Sort criterion: Profile: Last name (field_profile_lastname) */
  $handler->display->display_options['sorts']['field_profile_lastname_value']['id'] = 'field_profile_lastname_value';
  $handler->display->display_options['sorts']['field_profile_lastname_value']['table'] = 'field_data_field_profile_lastname';
  $handler->display->display_options['sorts']['field_profile_lastname_value']['field'] = 'field_profile_lastname_value';
  $handler->display->display_options['sorts']['field_profile_lastname_value']['relationship'] = 'profile';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Profile: Role (field_profile_role) */
  $handler->display->display_options['filters']['field_profile_role_tid']['id'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['table'] = 'field_data_field_profile_role';
  $handler->display->display_options['filters']['field_profile_role_tid']['field'] = 'field_profile_role_tid';
  $handler->display->display_options['filters']['field_profile_role_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_profile_role_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_role_tid']['expose']['operator_id'] = 'field_profile_role_tid_op';
  $handler->display->display_options['filters']['field_profile_role_tid']['expose']['label'] = 'Search for people by role';
  $handler->display->display_options['filters']['field_profile_role_tid']['expose']['operator'] = 'field_profile_role_tid_op';
  $handler->display->display_options['filters']['field_profile_role_tid']['expose']['identifier'] = 'r';
  $handler->display->display_options['filters']['field_profile_role_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_profile_role_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_profile_role_tid']['vocabulary'] = 'profile_role';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['p1'] = $view;

  $view = new view();
  $view->name = 'p2';
  $view->description = 'Provides all details for a single person profile.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'P2 - Detail page for single person profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['label'] = 'Main profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
  $handler->display->display_options['relationships']['profile_1']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_1']['label'] = 'Faculty profile';
  $handler->display->display_options['relationships']['profile_1']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile_1']['bundle_types'] = array(
    'faculty' => 'faculty',
  );
  /* Field: Profile: Preferred name */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_profile_lastname']['id'] = 'field_profile_lastname';
  $handler->display->display_options['fields']['field_profile_lastname']['table'] = 'field_data_field_profile_lastname';
  $handler->display->display_options['fields']['field_profile_lastname']['field'] = 'field_profile_lastname';
  $handler->display->display_options['fields']['field_profile_lastname']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_lastname']['label'] = '';
  $handler->display->display_options['fields']['field_profile_lastname']['element_label_colon'] = FALSE;
  /* Field: Profile: Feature image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'url_type' => '0',
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Profile: Position/title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_title']['label'] = '';
  $handler->display->display_options['fields']['field_profile_title']['element_label_colon'] = FALSE;
  /* Field: Profile: Unit */
  $handler->display->display_options['fields']['field_profile_unit']['id'] = 'field_profile_unit';
  $handler->display->display_options['fields']['field_profile_unit']['table'] = 'field_data_field_profile_unit';
  $handler->display->display_options['fields']['field_profile_unit']['field'] = 'field_profile_unit';
  $handler->display->display_options['fields']['field_profile_unit']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_unit']['label'] = '';
  $handler->display->display_options['fields']['field_profile_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_unit']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Profile: Sub-unit */
  $handler->display->display_options['fields']['field_profile_subunit']['id'] = 'field_profile_subunit';
  $handler->display->display_options['fields']['field_profile_subunit']['table'] = 'field_data_field_profile_subunit';
  $handler->display->display_options['fields']['field_profile_subunit']['field'] = 'field_profile_subunit';
  $handler->display->display_options['fields']['field_profile_subunit']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_subunit']['label'] = '';
  $handler->display->display_options['fields']['field_profile_subunit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_subunit']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Profile: Building */
  $handler->display->display_options['fields']['field_profile_building']['id'] = 'field_profile_building';
  $handler->display->display_options['fields']['field_profile_building']['table'] = 'field_data_field_profile_building';
  $handler->display->display_options['fields']['field_profile_building']['field'] = 'field_profile_building';
  $handler->display->display_options['fields']['field_profile_building']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_building']['label'] = '';
  $handler->display->display_options['fields']['field_profile_building']['element_label_colon'] = FALSE;
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_profile_email']['id'] = 'field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['table'] = 'field_data_field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['field'] = 'field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_email']['label'] = '';
  $handler->display->display_options['fields']['field_profile_email']['element_label_colon'] = FALSE;
  /* Field: Profile: Fax */
  $handler->display->display_options['fields']['field_profile_faxnumber']['id'] = 'field_profile_faxnumber';
  $handler->display->display_options['fields']['field_profile_faxnumber']['table'] = 'field_data_field_profile_faxnumber';
  $handler->display->display_options['fields']['field_profile_faxnumber']['field'] = 'field_profile_faxnumber';
  $handler->display->display_options['fields']['field_profile_faxnumber']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_faxnumber']['label'] = '';
  $handler->display->display_options['fields']['field_profile_faxnumber']['element_label_colon'] = FALSE;
  /* Field: Profile: Lab */
  $handler->display->display_options['fields']['field_profile_lab']['id'] = 'field_profile_lab';
  $handler->display->display_options['fields']['field_profile_lab']['table'] = 'field_data_field_profile_lab';
  $handler->display->display_options['fields']['field_profile_lab']['field'] = 'field_profile_lab';
  $handler->display->display_options['fields']['field_profile_lab']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_lab']['label'] = '';
  $handler->display->display_options['fields']['field_profile_lab']['element_label_colon'] = FALSE;
  /* Field: Profile: Phone number */
  $handler->display->display_options['fields']['field_profile_telephonenumber']['id'] = 'field_profile_telephonenumber';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['table'] = 'field_data_field_profile_telephonenumber';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['field'] = 'field_profile_telephonenumber';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['label'] = '';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['element_label_colon'] = FALSE;
  /* Field: Profile: Room */
  $handler->display->display_options['fields']['field_profile_room']['id'] = 'field_profile_room';
  $handler->display->display_options['fields']['field_profile_room']['table'] = 'field_data_field_profile_room';
  $handler->display->display_options['fields']['field_profile_room']['field'] = 'field_profile_room';
  $handler->display->display_options['fields']['field_profile_room']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_room']['label'] = '';
  $handler->display->display_options['fields']['field_profile_room']['element_label_colon'] = FALSE;
  /* Field: Profile: Website link */
  $handler->display->display_options['fields']['field_profile_website']['id'] = 'field_profile_website';
  $handler->display->display_options['fields']['field_profile_website']['table'] = 'field_data_field_profile_website';
  $handler->display->display_options['fields']['field_profile_website']['field'] = 'field_profile_website';
  $handler->display->display_options['fields']['field_profile_website']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_website']['label'] = '';
  $handler->display->display_options['fields']['field_profile_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_website']['click_sort_column'] = 'url';
  /* Field: Profile: About */
  $handler->display->display_options['fields']['field_profile_about']['id'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['table'] = 'field_data_field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['field'] = 'field_profile_about';
  $handler->display->display_options['fields']['field_profile_about']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_profile_about']['label'] = '';
  $handler->display->display_options['fields']['field_profile_about']['element_label_colon'] = FALSE;
  /* Field: Profile: Education */
  $handler->display->display_options['fields']['field_profile_education']['id'] = 'field_profile_education';
  $handler->display->display_options['fields']['field_profile_education']['table'] = 'field_data_field_profile_education';
  $handler->display->display_options['fields']['field_profile_education']['field'] = 'field_profile_education';
  $handler->display->display_options['fields']['field_profile_education']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_profile_education']['label'] = '';
  $handler->display->display_options['fields']['field_profile_education']['element_label_colon'] = FALSE;
  /* Field: Profile: Research */
  $handler->display->display_options['fields']['field_profile_research']['id'] = 'field_profile_research';
  $handler->display->display_options['fields']['field_profile_research']['table'] = 'field_data_field_profile_research';
  $handler->display->display_options['fields']['field_profile_research']['field'] = 'field_profile_research';
  $handler->display->display_options['fields']['field_profile_research']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_profile_research']['label'] = '';
  $handler->display->display_options['fields']['field_profile_research']['element_label_colon'] = FALSE;
  /* Field: Profile: Publications */
  $handler->display->display_options['fields']['field_profile_publications']['id'] = 'field_profile_publications';
  $handler->display->display_options['fields']['field_profile_publications']['table'] = 'field_data_field_profile_publications';
  $handler->display->display_options['fields']['field_profile_publications']['field'] = 'field_profile_publications';
  $handler->display->display_options['fields']['field_profile_publications']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_profile_publications']['label'] = '';
  $handler->display->display_options['fields']['field_profile_publications']['element_label_colon'] = FALSE;
  /* Field: Profile: File attachments */
  $handler->display->display_options['fields']['field_profile_attachments']['id'] = 'field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['table'] = 'field_data_field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['field'] = 'field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['relationship'] = 'profile_1';
  $handler->display->display_options['fields']['field_profile_attachments']['label'] = '';
  $handler->display->display_options['fields']['field_profile_attachments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_attachments']['delta_offset'] = '0';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'panel',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'User: Uid',
    ),
  );
  $export['p2'] = $view;

  return $export;
}
