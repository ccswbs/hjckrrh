<?php
/**
 * @file
 * ug_person.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ug_person_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'p1';
  $view->description = 'Provides a listing of all profiles.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Listing page for multiple people profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['layout'] = 'news';
  $handler->display->display_options['row_options']['regions'] = array(
    'title' => 'right',
    'field_person_picture' => 'left',
    'field_person_title' => 'right',
    'field_person_unit' => 'right',
    'field_person_phone' => 'right',
    'field_person_email' => 'right',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Picture */
  $handler->display->display_options['fields']['field_person_picture']['id'] = 'field_person_picture';
  $handler->display->display_options['fields']['field_person_picture']['table'] = 'field_data_field_person_picture';
  $handler->display->display_options['fields']['field_person_picture']['field'] = 'field_person_picture';
  $handler->display->display_options['fields']['field_person_picture']['label'] = '';
  $handler->display->display_options['fields']['field_person_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_person_picture']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Position/title */
  $handler->display->display_options['fields']['field_person_title']['id'] = 'field_person_title';
  $handler->display->display_options['fields']['field_person_title']['table'] = 'field_data_field_person_title';
  $handler->display->display_options['fields']['field_person_title']['field'] = 'field_person_title';
  $handler->display->display_options['fields']['field_person_title']['label'] = '';
  $handler->display->display_options['fields']['field_person_title']['element_label_colon'] = FALSE;
  /* Field: Content: Unit */
  $handler->display->display_options['fields']['field_person_unit']['id'] = 'field_person_unit';
  $handler->display->display_options['fields']['field_person_unit']['table'] = 'field_data_field_person_unit';
  $handler->display->display_options['fields']['field_person_unit']['field'] = 'field_person_unit';
  $handler->display->display_options['fields']['field_person_unit']['label'] = '';
  $handler->display->display_options['fields']['field_person_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_unit']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_person_phone']['id'] = 'field_person_phone';
  $handler->display->display_options['fields']['field_person_phone']['table'] = 'field_data_field_person_phone';
  $handler->display->display_options['fields']['field_person_phone']['field'] = 'field_person_phone';
  $handler->display->display_options['fields']['field_person_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_person_phone']['element_type'] = '0';
  $handler->display->display_options['fields']['field_person_phone']['element_label_type'] = 'strong';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_person_email']['id'] = 'field_person_email';
  $handler->display->display_options['fields']['field_person_email']['table'] = 'field_data_field_person_email';
  $handler->display->display_options['fields']['field_person_email']['field'] = 'field_person_email';
  $handler->display->display_options['fields']['field_person_email']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_person_email']['element_label_type'] = 'strong';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'person' => 'person',
  );
  /* Filter criterion: Content: Role (field_person_role) */
  $handler->display->display_options['filters']['field_person_role_tid']['id'] = 'field_person_role_tid';
  $handler->display->display_options['filters']['field_person_role_tid']['table'] = 'field_data_field_person_role';
  $handler->display->display_options['filters']['field_person_role_tid']['field'] = 'field_person_role_tid';
  $handler->display->display_options['filters']['field_person_role_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_person_role_tid']['expose']['operator_id'] = 'field_person_role_tid_op';
  $handler->display->display_options['filters']['field_person_role_tid']['expose']['label'] = 'Search for people by role';
  $handler->display->display_options['filters']['field_person_role_tid']['expose']['operator'] = 'field_person_role_tid_op';
  $handler->display->display_options['filters']['field_person_role_tid']['expose']['identifier'] = 'field_person_role_tid';
  $handler->display->display_options['filters']['field_person_role_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_person_role_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_person_role_tid']['vocabulary'] = 'tags';

  /* Display: Default */
  $handler = $view->new_display('panel_pane', 'Default', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: No Images */
  $handler = $view->new_display('panel_pane', 'No Images', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Position/title */
  $handler->display->display_options['fields']['field_person_title']['id'] = 'field_person_title';
  $handler->display->display_options['fields']['field_person_title']['table'] = 'field_data_field_person_title';
  $handler->display->display_options['fields']['field_person_title']['field'] = 'field_person_title';
  $handler->display->display_options['fields']['field_person_title']['label'] = '';
  $handler->display->display_options['fields']['field_person_title']['element_label_colon'] = FALSE;
  /* Field: Content: Unit */
  $handler->display->display_options['fields']['field_person_unit']['id'] = 'field_person_unit';
  $handler->display->display_options['fields']['field_person_unit']['table'] = 'field_data_field_person_unit';
  $handler->display->display_options['fields']['field_person_unit']['field'] = 'field_person_unit';
  $handler->display->display_options['fields']['field_person_unit']['label'] = '';
  $handler->display->display_options['fields']['field_person_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_unit']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_person_phone']['id'] = 'field_person_phone';
  $handler->display->display_options['fields']['field_person_phone']['table'] = 'field_data_field_person_phone';
  $handler->display->display_options['fields']['field_person_phone']['field'] = 'field_person_phone';
  $handler->display->display_options['fields']['field_person_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_person_phone']['element_type'] = '0';
  $handler->display->display_options['fields']['field_person_phone']['element_label_type'] = 'strong';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_person_email']['id'] = 'field_person_email';
  $handler->display->display_options['fields']['field_person_email']['table'] = 'field_data_field_person_email';
  $handler->display->display_options['fields']['field_person_email']['field'] = 'field_person_email';
  $handler->display->display_options['fields']['field_person_email']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_person_email']['element_label_type'] = 'strong';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['p1'] = $view;

  return $export;
}
