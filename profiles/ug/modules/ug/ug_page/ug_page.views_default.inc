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
  /* Field: Content: File attachments */
  $handler->display->display_options['fields']['field_page_attachments']['id'] = 'field_page_attachments';
  $handler->display->display_options['fields']['field_page_attachments']['table'] = 'field_data_field_page_attachments';
  $handler->display->display_options['fields']['field_page_attachments']['field'] = 'field_page_attachments';
  $handler->display->display_options['fields']['field_page_attachments']['label'] = '';
  $handler->display->display_options['fields']['field_page_attachments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_page_attachments']['type'] = 'file_table';
  $handler->display->display_options['fields']['field_page_attachments']['delta_offset'] = '0';
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
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
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

  $view = new view();
  $view->name = 'pg2';
  $view->description = 'Provides a full listing of basic pages. Items are paged and sorted from newest to oldest.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PG2 - Listing page for multiple pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pages';
  $handler->display->display_options['css_class'] = 'media-listing-page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_page_body']['id'] = 'field_page_body';
  $handler->display->display_options['fields']['field_page_body']['table'] = 'field_data_field_page_body';
  $handler->display->display_options['fields']['field_page_body']['field'] = 'field_page_body';
  $handler->display->display_options['fields']['field_page_body']['label'] = '';
  $handler->display->display_options['fields']['field_page_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_page_body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_page_body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Keywords (field_tags) */
  $handler->display->display_options['arguments']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['arguments']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_tags_tid']['title'] = 'Pages related to %1';
  $handler->display->display_options['arguments']['field_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tags_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_tags_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_tags_tid']['validate_options']['vocabularies'] = array(
    'page_category' => 'page_category',
  );
  /* Contextual filter: Content: Category (field_news_tags) */
  $handler->display->display_options['arguments']['field_news_tags_tid']['id'] = 'field_news_tags_tid';
  $handler->display->display_options['arguments']['field_news_tags_tid']['table'] = 'field_data_field_news_tags';
  $handler->display->display_options['arguments']['field_news_tags_tid']['field'] = 'field_news_tags_tid';
  $handler->display->display_options['arguments']['field_news_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_news_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_news_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_news_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_news_tags_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_news_tags_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_news_tags_tid']['validate_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['field_news_tags_tid']['validate_options']['type'] = 'convert';
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
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Keywords (field_tags) */
  $handler->display->display_options['arguments']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['arguments']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_tags_tid']['title'] = 'Pages related to %1';
  $handler->display->display_options['arguments']['field_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_tags_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_tags_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_tags_tid']['validate_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['field_tags_tid']['validate']['fail'] = 'empty';
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
    'field_tags_tid' => array(
      'type' => 'panel',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Keywords (field_tags)',
    ),
    'field_news_tags_tid' => array(
      'type' => 'user',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Category (field_news_tags)',
    ),
  );

  /* Display: Category */
  $handler = $view->new_display('panel_pane', 'Category', 'panel_pane_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Page category (field_page_category) */
  $handler->display->display_options['arguments']['field_page_category_tid']['id'] = 'field_page_category_tid';
  $handler->display->display_options['arguments']['field_page_category_tid']['table'] = 'field_data_field_page_category';
  $handler->display->display_options['arguments']['field_page_category_tid']['field'] = 'field_page_category_tid';
  $handler->display->display_options['arguments']['field_page_category_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_page_category_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_page_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_page_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_page_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_page_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_page_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_page_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_page_category_tid']['validate_options']['vocabularies'] = array(
    'page_category' => 'page_category',
  );
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
    'field_page_category_tid' => array(
      'type' => 'panel',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Page category (field_page_category)',
    ),
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'all';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = 'Pages related to %1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'page_category' => 'page_category',
    'tags' => 'tags',
  );
  $handler->display->display_options['path'] = 'pages/%/feed';
  $export['pg2'] = $view;

  $view = new view();
  $view->name = 'pg3_page_item_teaser_list';
  $view->description = 'Provides a teaser listing of the most recent pages. Page items are sorted from newest to oldest.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PG3 - Page Item Teaser List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pages';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More pages';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'news';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'media';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'media-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'teaser-list';
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
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Page category (field_page_category) */
  $handler->display->display_options['arguments']['field_page_category_tid']['id'] = 'field_page_category_tid';
  $handler->display->display_options['arguments']['field_page_category_tid']['table'] = 'field_data_field_page_category';
  $handler->display->display_options['arguments']['field_page_category_tid']['field'] = 'field_page_category_tid';
  $handler->display->display_options['arguments']['field_page_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_page_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_page_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_page_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_page_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_page_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_page_category_tid']['validate_options']['vocabularies'] = array(
    'page_category' => 'page_category',
  );
  $handler->display->display_options['arguments']['field_page_category_tid']['validate']['fail'] = 'empty';
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
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_page_item');
  $handler->display->display_options['link_url'] = '/pages';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
    'field_page_category_tid' => array(
      'type' => 'user',
      'context' => 'entity:file.fid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Page category (field_page_category)',
    ),
  );
  $export['pg3_page_item_teaser_list'] = $view;

  return $export;
}
