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
  $handler->display->display_options['style_options']['row_class'] = 'row media';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
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
  $handler->display->display_options['fields']['field_profile_telephonenumber']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['element_default_classes'] = FALSE;
  /* Field: Profile: Position/title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_title']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_title']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['fields']['field_profile_unit']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_profile_unit']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_unit']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Profile: Image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'small',
    'image_link' => '',
  );
  /* Field: Profile: Image caption */
  $handler->display->display_options['fields']['field_profile_caption']['id'] = 'field_profile_caption';
  $handler->display->display_options['fields']['field_profile_caption']['table'] = 'field_data_field_profile_caption';
  $handler->display->display_options['fields']['field_profile_caption']['field'] = 'field_profile_caption';
  $handler->display->display_options['fields']['field_profile_caption']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_caption']['label'] = '';
  $handler->display->display_options['fields']['field_profile_caption']['element_label_colon'] = FALSE;
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
  /* Field: Profile: Image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'image_style' => 'small',
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
  /* Field: Broken/missing handler */
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
  /* Field: Profile: Attachments */
  $handler->display->display_options['fields']['field_profile_attachments']['id'] = 'field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['table'] = 'field_data_field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['field'] = 'field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_attachments']['label'] = '';
  $handler->display->display_options['fields']['field_profile_attachments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_attachments']['type'] = 'file_table';
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

  $view = new view();
  $view->name = 'profile_attachments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Profile attachments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Relevant Files';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Profile: Attachments */
  $handler->display->display_options['fields']['field_profile_attachments']['id'] = 'field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['table'] = 'field_data_field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['field'] = 'field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['label'] = '';
  $handler->display->display_options['fields']['field_profile_attachments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_attachments']['type'] = 'file_table';
  $handler->display->display_options['fields']['field_profile_attachments']['delta_offset'] = '0';
  /* Contextual filter: Profile: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'profile';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'user' => array(
      'type' => 'panel',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Profile: User uid',
    ),
  );
  $export['profile_attachments'] = $view;

  $view = new view();
  $view->name = 'profile_multipart';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Profile multipart';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Field collection item: Entity with the Profile sections (field_profile_multipart) */
  $handler->display->display_options['relationships']['field_profile_multipart_profile2']['id'] = 'field_profile_multipart_profile2';
  $handler->display->display_options['relationships']['field_profile_multipart_profile2']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_profile_multipart_profile2']['field'] = 'field_profile_multipart_profile2';
  $handler->display->display_options['relationships']['field_profile_multipart_profile2']['required'] = TRUE;
  /* Field: Field collection item: Heading */
  $handler->display->display_options['fields']['field_profile_heading']['id'] = 'field_profile_heading';
  $handler->display->display_options['fields']['field_profile_heading']['table'] = 'field_data_field_profile_heading';
  $handler->display->display_options['fields']['field_profile_heading']['field'] = 'field_profile_heading';
  $handler->display->display_options['fields']['field_profile_heading']['label'] = '';
  $handler->display->display_options['fields']['field_profile_heading']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_profile_heading']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_heading']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_profile_heading']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Content */
  $handler->display->display_options['fields']['field_profile_content']['id'] = 'field_profile_content';
  $handler->display->display_options['fields']['field_profile_content']['table'] = 'field_data_field_profile_content';
  $handler->display->display_options['fields']['field_profile_content']['field'] = 'field_profile_content';
  $handler->display->display_options['fields']['field_profile_content']['label'] = '';
  $handler->display->display_options['fields']['field_profile_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_content']['element_default_classes'] = FALSE;
  /* Contextual filter: Profile: Profile ID */
  $handler->display->display_options['arguments']['pid']['id'] = 'pid';
  $handler->display->display_options['arguments']['pid']['table'] = 'profile';
  $handler->display->display_options['arguments']['pid']['field'] = 'pid';
  $handler->display->display_options['arguments']['pid']['relationship'] = 'field_profile_multipart_profile2';
  $handler->display->display_options['arguments']['pid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['pid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['pid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['pid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['pid']['summary_options']['items_per_page'] = '25';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'pid' => array(
      'type' => 'panel',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Profile: Profile ID',
    ),
  );
  $export['profile_multipart'] = $view;

  return $export;
}
