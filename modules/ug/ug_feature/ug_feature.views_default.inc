<?php
/**
 * @file
 * ug_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ug_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ft1';
  $view->description = 'Provides a lead-in to any page content on the website (e.g. Events, News, Basic Page, People Profiles, etc.) or external URL';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FT1 - Featured item';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Feature';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'thumbnail';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_feature_image']['id'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['table'] = 'field_data_field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['field'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['label'] = '';
  $handler->display->display_options['fields']['field_feature_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_feature_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_feature_image']['settings'] = array(
    'image_style' => 'small',
    'image_link' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_feature_link']['id'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['table'] = 'field_data_field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['field'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['label'] = '';
  $handler->display->display_options['fields']['field_feature_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_feature_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_feature_link']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_feature_link]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'caption';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Content: Category (field_feature_category) */
  $handler->display->display_options['arguments']['field_feature_category_tid']['id'] = 'field_feature_category_tid';
  $handler->display->display_options['arguments']['field_feature_category_tid']['table'] = 'field_data_field_feature_category';
  $handler->display->display_options['arguments']['field_feature_category_tid']['field'] = 'field_feature_category_tid';
  $handler->display->display_options['arguments']['field_feature_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_feature_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate_options']['vocabularies'] = array(
    'feature_category' => 'feature_category',
  );
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate_options']['type'] = 'convert';
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
    'feature' => 'feature',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
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
    'field_feature_category_tid' => array(
      'type' => 'user',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Category',
    ),
  );
  $export['ft1'] = $view;

  $view = new view();
  $view->name = 'ft2';
  $view->description = 'Provides a lead-in to any page content on the website (e.g. Events, News, Basic Page, People Profiles, etc.) or external URL';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FT2 - Listing page for featured item';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'media-listing-page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row media';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_feature_link']['id'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['table'] = 'field_data_field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['field'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['label'] = '';
  $handler->display->display_options['fields']['field_feature_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_feature_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_feature_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_feature_image']['id'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['table'] = 'field_data_field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['field'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['label'] = '';
  $handler->display->display_options['fields']['field_feature_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_feature_image']['element_class'] = 'media-thumbnail';
  $handler->display->display_options['fields']['field_feature_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_feature_image']['element_wrapper_class'] = 'col-sm-4';
  $handler->display->display_options['fields']['field_feature_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_feature_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_feature_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_feature_link]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_feature_text']['id'] = 'field_feature_text';
  $handler->display->display_options['fields']['field_feature_text']['table'] = 'field_data_field_feature_text';
  $handler->display->display_options['fields']['field_feature_text']['field'] = 'field_feature_text';
  $handler->display->display_options['fields']['field_feature_text']['label'] = '';
  $handler->display->display_options['fields']['field_feature_text']['alter']['max_length'] = '255';
  $handler->display->display_options['fields']['field_feature_text']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_feature_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_text']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Category (field_feature_category) */
  $handler->display->display_options['arguments']['field_feature_category_tid']['id'] = 'field_feature_category_tid';
  $handler->display->display_options['arguments']['field_feature_category_tid']['table'] = 'field_data_field_feature_category';
  $handler->display->display_options['arguments']['field_feature_category_tid']['field'] = 'field_feature_category_tid';
  $handler->display->display_options['arguments']['field_feature_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_feature_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate_options']['vocabularies'] = array(
    'feature_category' => 'feature_category',
  );
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate']['fail'] = 'empty';
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
    'feature' => 'feature',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_feature_category_tid' => array(
      'type' => 'panel',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Category',
    ),
  );
  $export['ft2'] = $view;

  $view = new view();
  $view->name = 'ft3';
  $view->description = 'Provides a lead-in to any page content on the website (e.g. Events, News, Basic Page, People Profiles, etc.) or external URL';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FT3 - Featured item teaser list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Features';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More features';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'row media';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'media-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'teaser-list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_feature_image']['id'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['table'] = 'field_data_field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['field'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['label'] = '';
  $handler->display->display_options['fields']['field_feature_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_feature_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_feature_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_feature_link']['id'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['table'] = 'field_data_field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['field'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['label'] = '';
  $handler->display->display_options['fields']['field_feature_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_feature_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_feature_link']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_feature_link]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'media-heading ug-media-heading';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_feature_text']['id'] = 'field_feature_text';
  $handler->display->display_options['fields']['field_feature_text']['table'] = 'field_data_field_feature_text';
  $handler->display->display_options['fields']['field_feature_text']['field'] = 'field_feature_text';
  $handler->display->display_options['fields']['field_feature_text']['label'] = '';
  $handler->display->display_options['fields']['field_feature_text']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_feature_text']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['field_feature_text']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_feature_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_feature_text']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Category (field_feature_category) */
  $handler->display->display_options['arguments']['field_feature_category_tid']['id'] = 'field_feature_category_tid';
  $handler->display->display_options['arguments']['field_feature_category_tid']['table'] = 'field_data_field_feature_category';
  $handler->display->display_options['arguments']['field_feature_category_tid']['field'] = 'field_feature_category_tid';
  $handler->display->display_options['arguments']['field_feature_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_feature_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate_options']['vocabularies'] = array(
    'feature_category' => 'feature_category',
  );
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate']['fail'] = 'empty';
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
    'feature' => 'feature',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['link_url'] = 'features';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['more_text'] = 'more_text';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_feature_category_tid' => array(
      'type' => 'user',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Category',
    ),
  );

  /* Display: Random */
  $handler = $view->new_display('panel_pane', 'Random', 'panel_pane_2');
  $handler->display->display_options['link_url'] = 'features';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['more_text'] = 'more_text';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_feature_category_tid' => array(
      'type' => 'user',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Category',
    ),
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'featured_item_feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Category (field_feature_category) */
  $handler->display->display_options['arguments']['field_feature_category_tid']['id'] = 'field_feature_category_tid';
  $handler->display->display_options['arguments']['field_feature_category_tid']['table'] = 'field_data_field_feature_category';
  $handler->display->display_options['arguments']['field_feature_category_tid']['field'] = 'field_feature_category_tid';
  $handler->display->display_options['arguments']['field_feature_category_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_feature_category_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_feature_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_feature_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_feature_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate_options']['vocabularies'] = array(
    'feature_category' => 'feature_category',
  );
  $handler->display->display_options['arguments']['field_feature_category_tid']['validate']['fail'] = 'empty';
  $handler->display->display_options['path'] = 'featured/%/feed';
  $handler->display->display_options['displays'] = array(
    'panel_pane_1' => 'panel_pane_1',
    'panel_pane_2' => 'panel_pane_2',
    'default' => 0,
  );
  $export['ft3'] = $view;

  return $export;
}
