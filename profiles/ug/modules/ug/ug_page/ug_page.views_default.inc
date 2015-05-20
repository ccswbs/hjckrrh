<?php
/**
 * @file
 * ug_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ug_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'pg1';
  $view->description = 'Provides all details for a single basic page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PG1 - Basic page';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_page_body']['id'] = 'field_page_body';
  $handler->display->display_options['fields']['field_page_body']['table'] = 'field_data_field_page_body';
  $handler->display->display_options['fields']['field_page_body']['field'] = 'field_page_body';
  $handler->display->display_options['fields']['field_page_body']['label'] = '';
  $handler->display->display_options['fields']['field_page_body']['element_label_colon'] = FALSE;
  /* Field: Content: Caption */
  $handler->display->display_options['fields']['field_page_caption']['id'] = 'field_page_caption';
  $handler->display->display_options['fields']['field_page_caption']['table'] = 'field_data_field_page_caption';
  $handler->display->display_options['fields']['field_page_caption']['field'] = 'field_page_caption';
  $handler->display->display_options['fields']['field_page_caption']['label'] = '';
  $handler->display->display_options['fields']['field_page_caption']['element_label_colon'] = FALSE;
  /* Field: Content: File attachments */
  $handler->display->display_options['fields']['field_page_attachments']['id'] = 'field_page_attachments';
  $handler->display->display_options['fields']['field_page_attachments']['table'] = 'field_data_field_page_attachments';
  $handler->display->display_options['fields']['field_page_attachments']['field'] = 'field_page_attachments';
  $handler->display->display_options['fields']['field_page_attachments']['label'] = '';
  $handler->display->display_options['fields']['field_page_attachments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_page_attachments']['type'] = 'file_table';
  $handler->display->display_options['fields']['field_page_attachments']['delta_offset'] = '0';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_page_image']['id'] = 'field_page_image';
  $handler->display->display_options['fields']['field_page_image']['table'] = 'field_data_field_page_image';
  $handler->display->display_options['fields']['field_page_image']['field'] = 'field_page_image';
  $handler->display->display_options['fields']['field_page_image']['label'] = '';
  $handler->display->display_options['fields']['field_page_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_page_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'page' => 'page',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['pg1'] = $view;

  return $export;
}
