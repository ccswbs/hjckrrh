<?php
/**
 * @file
 * ug_banner.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ug_banner_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'b1';
  $view->description = 'The image slider can feature up to 5 pieces of content.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'B1 - Image slider (Banner)';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_banner_image']['id'] = 'field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['table'] = 'field_data_field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['field'] = 'field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['label'] = '';
  $handler->display->display_options['fields']['field_banner_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_banner_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_banner_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_banner_image']['settings'] = array(
    'url_type' => '1',
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Headline */
  $handler->display->display_options['fields']['field_banner_headline']['id'] = 'field_banner_headline';
  $handler->display->display_options['fields']['field_banner_headline']['table'] = 'field_data_field_banner_headline';
  $handler->display->display_options['fields']['field_banner_headline']['field'] = 'field_banner_headline';
  $handler->display->display_options['fields']['field_banner_headline']['label'] = '';
  $handler->display->display_options['fields']['field_banner_headline']['element_label_colon'] = FALSE;
  /* Field: Content: Headline Link */
  $handler->display->display_options['fields']['field_banner_link']['id'] = 'field_banner_link';
  $handler->display->display_options['fields']['field_banner_link']['table'] = 'field_data_field_banner_link';
  $handler->display->display_options['fields']['field_banner_link']['field'] = 'field_banner_link';
  $handler->display->display_options['fields']['field_banner_link']['label'] = '';
  $handler->display->display_options['fields']['field_banner_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_banner_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_banner_link']['type'] = 'link_plain';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_banner_text']['id'] = 'field_banner_text';
  $handler->display->display_options['fields']['field_banner_text']['table'] = 'field_data_field_banner_text';
  $handler->display->display_options['fields']['field_banner_text']['field'] = 'field_banner_text';
  $handler->display->display_options['fields']['field_banner_text']['label'] = '';
  $handler->display->display_options['fields']['field_banner_text']['element_label_colon'] = FALSE;
  /* Field: Content: Alt text */
  $handler->display->display_options['fields']['field_banner_alttext']['id'] = 'field_banner_alttext';
  $handler->display->display_options['fields']['field_banner_alttext']['table'] = 'field_data_field_banner_alttext';
  $handler->display->display_options['fields']['field_banner_alttext']['field'] = 'field_banner_alttext';
  $handler->display->display_options['fields']['field_banner_alttext']['label'] = '';
  $handler->display->display_options['fields']['field_banner_alttext']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Order (field_banner_weight) */
  $handler->display->display_options['sorts']['field_banner_weight_value']['id'] = 'field_banner_weight_value';
  $handler->display->display_options['sorts']['field_banner_weight_value']['table'] = 'field_data_field_banner_weight';
  $handler->display->display_options['sorts']['field_banner_weight_value']['field'] = 'field_banner_weight_value';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Content: Category (field_banner_category) */
  $handler->display->display_options['arguments']['field_banner_category_tid']['id'] = 'field_banner_category_tid';
  $handler->display->display_options['arguments']['field_banner_category_tid']['table'] = 'field_data_field_banner_category';
  $handler->display->display_options['arguments']['field_banner_category_tid']['field'] = 'field_banner_category_tid';
  $handler->display->display_options['arguments']['field_banner_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_banner_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_banner_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_banner_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_banner_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_banner_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_banner_category_tid']['validate_options']['vocabularies'] = array(
    'banner_category' => 'banner_category',
  );
  $handler->display->display_options['arguments']['field_banner_category_tid']['validate_options']['type'] = 'convert';
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
    'banner' => 'banner',
  );

  /* Display: Manual */
  $handler = $view->new_display('panel_pane', 'Manual', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['more_text'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_banner_category_tid' => array(
      'type' => 'user',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Category',
    ),
  );

  /* Display: Autoplay */
  $handler = $view->new_display('panel_pane', 'Autoplay', 'autoplay');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['more_text'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_banner_category_tid' => array(
      'type' => 'user',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Category',
    ),
  );

  /* Display: Block - Manual */
  $handler = $view->new_display('block', 'Block - Manual', 'block_1');

  /* Display: Block - Autoplay */
  $handler = $view->new_display('block', 'Block - Autoplay', 'block_autoplay');
  $export['b1'] = $view;

  return $export;
}
