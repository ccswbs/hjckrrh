<?php
/**
 * @file
 * ug_demo_export.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ug_demo_export_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'node_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Node export';
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
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_event_body']['id'] = 'field_event_body';
  $handler->display->display_options['fields']['field_event_body']['table'] = 'field_data_field_event_body';
  $handler->display->display_options['fields']['field_event_body']['field'] = 'field_event_body';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_event_category']['id'] = 'field_event_category';
  $handler->display->display_options['fields']['field_event_category']['table'] = 'field_data_field_event_category';
  $handler->display->display_options['fields']['field_event_category']['field'] = 'field_event_category';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  /* Field: Content: Feature image */
  $handler->display->display_options['fields']['field_event_image']['id'] = 'field_event_image';
  $handler->display->display_options['fields']['field_event_image']['table'] = 'field_data_field_event_image';
  $handler->display->display_options['fields']['field_event_image']['field'] = 'field_event_image';
  /* Field: Content: Feature image caption */
  $handler->display->display_options['fields']['field_event_image_caption']['id'] = 'field_event_image_caption';
  $handler->display->display_options['fields']['field_event_image_caption']['table'] = 'field_data_field_event_image_caption';
  $handler->display->display_options['fields']['field_event_image_caption']['field'] = 'field_event_image_caption';
  /* Field: Content: File attachments */
  $handler->display->display_options['fields']['field_event_attachments']['id'] = 'field_event_attachments';
  $handler->display->display_options['fields']['field_event_attachments']['table'] = 'field_data_field_event_attachments';
  $handler->display->display_options['fields']['field_event_attachments']['field'] = 'field_event_attachments';
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  /* Field: Content: Related website */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  /* Field: Content: Sections */
  $handler->display->display_options['fields']['field_event_multipart']['id'] = 'field_event_multipart';
  $handler->display->display_options['fields']['field_event_multipart']['table'] = 'field_data_field_event_multipart';
  $handler->display->display_options['fields']['field_event_multipart']['field'] = 'field_event_multipart';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: News */
  $handler = $view->new_display('views_data_export', 'News', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = ' ';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Attachment */
  $handler->display->display_options['fields']['field_news_attachment']['id'] = 'field_news_attachment';
  $handler->display->display_options['fields']['field_news_attachment']['table'] = 'field_data_field_news_attachment';
  $handler->display->display_options['fields']['field_news_attachment']['field'] = 'field_news_attachment';
  $handler->display->display_options['fields']['field_news_attachment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_attachment']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_news_attachment']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_news_body']['id'] = 'field_news_body';
  $handler->display->display_options['fields']['field_news_body']['table'] = 'field_data_field_news_body';
  $handler->display->display_options['fields']['field_news_body']['field'] = 'field_news_body';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_news_tags']['id'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['table'] = 'field_data_field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['field'] = 'field_news_tags';
  $handler->display->display_options['fields']['field_news_tags']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: External link */
  $handler->display->display_options['fields']['field_news_link']['id'] = 'field_news_link';
  $handler->display->display_options['fields']['field_news_link']['table'] = 'field_data_field_news_link';
  $handler->display->display_options['fields']['field_news_link']['field'] = 'field_news_link';
  $handler->display->display_options['fields']['field_news_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_news_link']['type'] = 'link_plain';
  /* Field: Content: Feature image */
  $handler->display->display_options['fields']['field_news_image']['id'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['table'] = 'field_data_field_news_image';
  $handler->display->display_options['fields']['field_news_image']['field'] = 'field_news_image';
  $handler->display->display_options['fields']['field_news_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_news_image']['settings'] = array(
    'url_type' => '3',
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Feature image caption */
  $handler->display->display_options['fields']['field_news_caption']['id'] = 'field_news_caption';
  $handler->display->display_options['fields']['field_news_caption']['table'] = 'field_data_field_news_caption';
  $handler->display->display_options['fields']['field_news_caption']['field'] = 'field_news_caption';
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Written by */
  $handler->display->display_options['fields']['field_news_writer']['id'] = 'field_news_writer';
  $handler->display->display_options['fields']['field_news_writer']['table'] = 'field_data_field_news_writer';
  $handler->display->display_options['fields']['field_news_writer']['field'] = 'field_news_writer';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'news' => 'news',
  );
  $handler->display->display_options['path'] = 'export/news.csv';

  /* Display: Page */
  $handler = $view->new_display('views_data_export', 'Page', 'views_data_export_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_page_body']['id'] = 'field_page_body';
  $handler->display->display_options['fields']['field_page_body']['table'] = 'field_data_field_page_body';
  $handler->display->display_options['fields']['field_page_body']['field'] = 'field_page_body';
  $handler->display->display_options['fields']['field_page_body']['label'] = 'body';
  /* Field: Content: Page category */
  $handler->display->display_options['fields']['field_page_category']['id'] = 'field_page_category';
  $handler->display->display_options['fields']['field_page_category']['table'] = 'field_data_field_page_category';
  $handler->display->display_options['fields']['field_page_category']['field'] = 'field_page_category';
  $handler->display->display_options['fields']['field_page_category']['label'] = 'category';
  $handler->display->display_options['fields']['field_page_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_page_category']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['path'] = 'export/page.csv';

  /* Display: Event */
  $handler = $view->new_display('views_data_export', 'Event', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = '  ';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_event_body']['id'] = 'field_event_body';
  $handler->display->display_options['fields']['field_event_body']['table'] = 'field_data_field_event_body';
  $handler->display->display_options['fields']['field_event_body']['field'] = 'field_event_body';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_event_category']['id'] = 'field_event_category';
  $handler->display->display_options['fields']['field_event_category']['table'] = 'field_data_field_event_category';
  $handler->display->display_options['fields']['field_event_category']['field'] = 'field_event_category';
  $handler->display->display_options['fields']['field_event_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_date']['alter']['text'] = '[field_event_date-value]';
  $handler->display->display_options['fields']['field_event_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Feature image */
  $handler->display->display_options['fields']['field_event_image']['id'] = 'field_event_image';
  $handler->display->display_options['fields']['field_event_image']['table'] = 'field_data_field_event_image';
  $handler->display->display_options['fields']['field_event_image']['field'] = 'field_event_image';
  $handler->display->display_options['fields']['field_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Feature image caption */
  $handler->display->display_options['fields']['field_event_image_caption']['id'] = 'field_event_image_caption';
  $handler->display->display_options['fields']['field_event_image_caption']['table'] = 'field_data_field_event_image_caption';
  $handler->display->display_options['fields']['field_event_image_caption']['field'] = 'field_event_image_caption';
  /* Field: Content: File attachments */
  $handler->display->display_options['fields']['field_event_attachments']['id'] = 'field_event_attachments';
  $handler->display->display_options['fields']['field_event_attachments']['table'] = 'field_data_field_event_attachments';
  $handler->display->display_options['fields']['field_event_attachments']['field'] = 'field_event_attachments';
  $handler->display->display_options['fields']['field_event_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_attachments']['delta_offset'] = '0';
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  /* Field: Content: Related website */
  $handler->display->display_options['fields']['field_event_link']['id'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['table'] = 'field_data_field_event_link';
  $handler->display->display_options['fields']['field_event_link']['field'] = 'field_event_link';
  $handler->display->display_options['fields']['field_event_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_event_link']['type'] = 'link_plain';
  /* Field: Content: Sections */
  $handler->display->display_options['fields']['field_event_multipart']['id'] = 'field_event_multipart';
  $handler->display->display_options['fields']['field_event_multipart']['table'] = 'field_data_field_event_multipart';
  $handler->display->display_options['fields']['field_event_multipart']['field'] = 'field_event_multipart';
  $handler->display->display_options['fields']['field_event_multipart']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_event_multipart']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'event' => 'event',
  );
  $handler->display->display_options['path'] = 'export/event.csv';

  /* Display: Banner */
  $handler = $view->new_display('views_data_export', 'Banner', 'views_data_export_4');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = ' ';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Alt text */
  $handler->display->display_options['fields']['field_banner_alttext']['id'] = 'field_banner_alttext';
  $handler->display->display_options['fields']['field_banner_alttext']['table'] = 'field_data_field_banner_alttext';
  $handler->display->display_options['fields']['field_banner_alttext']['field'] = 'field_banner_alttext';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_banner_category']['id'] = 'field_banner_category';
  $handler->display->display_options['fields']['field_banner_category']['table'] = 'field_data_field_banner_category';
  $handler->display->display_options['fields']['field_banner_category']['field'] = 'field_banner_category';
  $handler->display->display_options['fields']['field_banner_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Headline */
  $handler->display->display_options['fields']['field_banner_headline']['id'] = 'field_banner_headline';
  $handler->display->display_options['fields']['field_banner_headline']['table'] = 'field_data_field_banner_headline';
  $handler->display->display_options['fields']['field_banner_headline']['field'] = 'field_banner_headline';
  /* Field: Content: Headline Link */
  $handler->display->display_options['fields']['field_banner_link']['id'] = 'field_banner_link';
  $handler->display->display_options['fields']['field_banner_link']['table'] = 'field_data_field_banner_link';
  $handler->display->display_options['fields']['field_banner_link']['field'] = 'field_banner_link';
  $handler->display->display_options['fields']['field_banner_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_banner_link']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_banner_image']['id'] = 'field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['table'] = 'field_data_field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['field'] = 'field_banner_image';
  $handler->display->display_options['fields']['field_banner_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_banner_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_banner_image']['settings'] = array(
    'url_type' => '3',
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Order */
  $handler->display->display_options['fields']['field_banner_weight']['id'] = 'field_banner_weight';
  $handler->display->display_options['fields']['field_banner_weight']['table'] = 'field_data_field_banner_weight';
  $handler->display->display_options['fields']['field_banner_weight']['field'] = 'field_banner_weight';
  $handler->display->display_options['fields']['field_banner_weight']['type'] = 'list_key';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_banner_text']['id'] = 'field_banner_text';
  $handler->display->display_options['fields']['field_banner_text']['table'] = 'field_data_field_banner_text';
  $handler->display->display_options['fields']['field_banner_text']['field'] = 'field_banner_text';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['path'] = 'export/banner.csv';

  /* Display: Feature */
  $handler = $view->new_display('views_data_export', 'Feature', 'views_data_export_5');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = ' ';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_feature_category']['id'] = 'field_feature_category';
  $handler->display->display_options['fields']['field_feature_category']['table'] = 'field_data_field_feature_category';
  $handler->display->display_options['fields']['field_feature_category']['field'] = 'field_feature_category';
  $handler->display->display_options['fields']['field_feature_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_feature_image']['id'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['table'] = 'field_data_field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['field'] = 'field_feature_image';
  $handler->display->display_options['fields']['field_feature_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_feature_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_feature_image']['settings'] = array(
    'url_type' => '3',
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_feature_link']['id'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['table'] = 'field_data_field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['field'] = 'field_feature_link';
  $handler->display->display_options['fields']['field_feature_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_feature_link']['type'] = 'link_absolute';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_feature_text']['id'] = 'field_feature_text';
  $handler->display->display_options['fields']['field_feature_text']['table'] = 'field_data_field_feature_text';
  $handler->display->display_options['fields']['field_feature_text']['field'] = 'field_feature_text';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['path'] = 'export/feature.csv';

  /* Display: FAQ */
  $handler = $view->new_display('views_data_export', 'FAQ', 'views_data_export_6');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = ' ';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Answer */
  $handler->display->display_options['fields']['field_faq_answer']['id'] = 'field_faq_answer';
  $handler->display->display_options['fields']['field_faq_answer']['table'] = 'field_data_field_faq_answer';
  $handler->display->display_options['fields']['field_faq_answer']['field'] = 'field_faq_answer';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_faq_category']['id'] = 'field_faq_category';
  $handler->display->display_options['fields']['field_faq_category']['table'] = 'field_data_field_faq_category';
  $handler->display->display_options['fields']['field_faq_category']['field'] = 'field_faq_category';
  $handler->display->display_options['fields']['field_faq_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'faq' => 'faq',
  );
  $handler->display->display_options['path'] = 'export/faq.csv';

  /* Display: Course outline */
  $handler = $view->new_display('views_data_export', 'Course outline', 'views_data_export_7');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = ' ';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Academic department */
  $handler->display->display_options['fields']['field_course_department']['id'] = 'field_course_department';
  $handler->display->display_options['fields']['field_course_department']['table'] = 'field_data_field_course_department';
  $handler->display->display_options['fields']['field_course_department']['field'] = 'field_course_department';
  $handler->display->display_options['fields']['field_course_department']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Academic level */
  $handler->display->display_options['fields']['field_course_acad_level']['id'] = 'field_course_acad_level';
  $handler->display->display_options['fields']['field_course_acad_level']['table'] = 'field_data_field_course_acad_level';
  $handler->display->display_options['fields']['field_course_acad_level']['field'] = 'field_course_acad_level';
  $handler->display->display_options['fields']['field_course_acad_level']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_course_attachments']['id'] = 'field_course_attachments';
  $handler->display->display_options['fields']['field_course_attachments']['table'] = 'field_data_field_course_attachments';
  $handler->display->display_options['fields']['field_course_attachments']['field'] = 'field_course_attachments';
  $handler->display->display_options['fields']['field_course_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_course_attachments']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_course_attachments']['delta_offset'] = '0';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_course_category']['id'] = 'field_course_category';
  $handler->display->display_options['fields']['field_course_category']['table'] = 'field_data_field_course_category';
  $handler->display->display_options['fields']['field_course_category']['field'] = 'field_course_category';
  $handler->display->display_options['fields']['field_course_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Course code */
  $handler->display->display_options['fields']['field_course_code']['id'] = 'field_course_code';
  $handler->display->display_options['fields']['field_course_code']['table'] = 'field_data_field_course_code';
  $handler->display->display_options['fields']['field_course_code']['field'] = 'field_course_code';
  /* Field: Content: Course instructor */
  $handler->display->display_options['fields']['field_course_instructor']['id'] = 'field_course_instructor';
  $handler->display->display_options['fields']['field_course_instructor']['table'] = 'field_data_field_course_instructor';
  $handler->display->display_options['fields']['field_course_instructor']['field'] = 'field_course_instructor';
  /* Field: Content: Course instructor url */
  $handler->display->display_options['fields']['field_course_instructor_url']['id'] = 'field_course_instructor_url';
  $handler->display->display_options['fields']['field_course_instructor_url']['table'] = 'field_data_field_course_instructor_url';
  $handler->display->display_options['fields']['field_course_instructor_url']['field'] = 'field_course_instructor_url';
  $handler->display->display_options['fields']['field_course_instructor_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_course_instructor_url']['type'] = 'link_absolute';
  /* Field: Content: Course level */
  $handler->display->display_options['fields']['field_course_level']['id'] = 'field_course_level';
  $handler->display->display_options['fields']['field_course_level']['table'] = 'field_data_field_course_level';
  $handler->display->display_options['fields']['field_course_level']['field'] = 'field_course_level';
  $handler->display->display_options['fields']['field_course_level']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Course name */
  $handler->display->display_options['fields']['field_course_name']['id'] = 'field_course_name';
  $handler->display->display_options['fields']['field_course_name']['table'] = 'field_data_field_course_name';
  $handler->display->display_options['fields']['field_course_name']['field'] = 'field_course_name';
  /* Field: Content: Course term */
  $handler->display->display_options['fields']['field_course_term']['id'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['table'] = 'field_data_field_course_term';
  $handler->display->display_options['fields']['field_course_term']['field'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Course Website */
  $handler->display->display_options['fields']['field_course_website']['id'] = 'field_course_website';
  $handler->display->display_options['fields']['field_course_website']['table'] = 'field_data_field_course_website';
  $handler->display->display_options['fields']['field_course_website']['field'] = 'field_course_website';
  $handler->display->display_options['fields']['field_course_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_course_website']['type'] = 'link_absolute';
  /* Field: Content: Details */
  $handler->display->display_options['fields']['field_course_body']['id'] = 'field_course_body';
  $handler->display->display_options['fields']['field_course_body']['table'] = 'field_data_field_course_body';
  $handler->display->display_options['fields']['field_course_body']['field'] = 'field_course_body';
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_course_subject']['id'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['field'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'course_outline' => 'course_outline',
  );
  $handler->display->display_options['path'] = 'export/course.csv';

  /* Display: Profile */
  $handler = $view->new_display('views_data_export', 'Profile', 'views_data_export_8');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = ' ';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Area of research */
  $handler->display->display_options['fields']['field_profile_research']['id'] = 'field_profile_research';
  $handler->display->display_options['fields']['field_profile_research']['table'] = 'field_data_field_profile_research';
  $handler->display->display_options['fields']['field_profile_research']['field'] = 'field_profile_research';
  $handler->display->display_options['fields']['field_profile_research']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_profile_research']['delta_offset'] = '0';
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_profile_attachments']['id'] = 'field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['table'] = 'field_data_field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['field'] = 'field_profile_attachments';
  $handler->display->display_options['fields']['field_profile_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_attachments']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_profile_attachments']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_profile_summary']['id'] = 'field_profile_summary';
  $handler->display->display_options['fields']['field_profile_summary']['table'] = 'field_data_field_profile_summary';
  $handler->display->display_options['fields']['field_profile_summary']['field'] = 'field_profile_summary';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_profile_category']['id'] = 'field_profile_category';
  $handler->display->display_options['fields']['field_profile_category']['table'] = 'field_data_field_profile_category';
  $handler->display->display_options['fields']['field_profile_category']['field'] = 'field_profile_category';
  $handler->display->display_options['fields']['field_profile_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_profile_email']['id'] = 'field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['table'] = 'field_data_field_profile_email';
  $handler->display->display_options['fields']['field_profile_email']['field'] = 'field_profile_email';
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['field_profile_faxnumber']['id'] = 'field_profile_faxnumber';
  $handler->display->display_options['fields']['field_profile_faxnumber']['table'] = 'field_data_field_profile_faxnumber';
  $handler->display->display_options['fields']['field_profile_faxnumber']['field'] = 'field_profile_faxnumber';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
    'url_type' => '3',
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Image caption */
  $handler->display->display_options['fields']['field_profile_caption']['id'] = 'field_profile_caption';
  $handler->display->display_options['fields']['field_profile_caption']['table'] = 'field_data_field_profile_caption';
  $handler->display->display_options['fields']['field_profile_caption']['field'] = 'field_profile_caption';
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Lab */
  $handler->display->display_options['fields']['field_profile_lab']['id'] = 'field_profile_lab';
  $handler->display->display_options['fields']['field_profile_lab']['table'] = 'field_data_field_profile_lab';
  $handler->display->display_options['fields']['field_profile_lab']['field'] = 'field_profile_lab';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_profile_lastname']['id'] = 'field_profile_lastname';
  $handler->display->display_options['fields']['field_profile_lastname']['table'] = 'field_data_field_profile_lastname';
  $handler->display->display_options['fields']['field_profile_lastname']['field'] = 'field_profile_lastname';
  /* Field: Content: Mailing address */
  $handler->display->display_options['fields']['field_profile_address']['id'] = 'field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['table'] = 'field_data_field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['field'] = 'field_profile_address';
  /* Field: Content: Office */
  $handler->display->display_options['fields']['field_profile_office']['id'] = 'field_profile_office';
  $handler->display->display_options['fields']['field_profile_office']['table'] = 'field_data_field_profile_office';
  $handler->display->display_options['fields']['field_profile_office']['field'] = 'field_profile_office';
  /* Field: Content: Phone number */
  $handler->display->display_options['fields']['field_profile_telephonenumber']['id'] = 'field_profile_telephonenumber';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['table'] = 'field_data_field_profile_telephonenumber';
  $handler->display->display_options['fields']['field_profile_telephonenumber']['field'] = 'field_profile_telephonenumber';
  /* Field: Content: Position/title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  /* Field: Content: Preferred name */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  /* Field: Content: Profile fields */
  $handler->display->display_options['fields']['field_profile_custom']['id'] = 'field_profile_custom';
  $handler->display->display_options['fields']['field_profile_custom']['table'] = 'field_data_field_profile_custom';
  $handler->display->display_options['fields']['field_profile_custom']['field'] = 'field_profile_custom';
  $handler->display->display_options['fields']['field_profile_custom']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_profile_custom']['delta_offset'] = '0';
  /* Field: Content: Profile sections */
  $handler->display->display_options['fields']['field_profile_multipart']['id'] = 'field_profile_multipart';
  $handler->display->display_options['fields']['field_profile_multipart']['table'] = 'field_data_field_profile_multipart';
  $handler->display->display_options['fields']['field_profile_multipart']['field'] = 'field_profile_multipart';
  $handler->display->display_options['fields']['field_profile_multipart']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_profile_multipart']['delta_offset'] = '0';
  /* Field: Content: Role */
  $handler->display->display_options['fields']['field_profile_role']['id'] = 'field_profile_role';
  $handler->display->display_options['fields']['field_profile_role']['table'] = 'field_data_field_profile_role';
  $handler->display->display_options['fields']['field_profile_role']['field'] = 'field_profile_role';
  $handler->display->display_options['fields']['field_profile_role']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_profile_role']['delta_offset'] = '0';
  /* Field: Content: Sub-unit */
  $handler->display->display_options['fields']['field_profile_subunit']['id'] = 'field_profile_subunit';
  $handler->display->display_options['fields']['field_profile_subunit']['table'] = 'field_data_field_profile_subunit';
  $handler->display->display_options['fields']['field_profile_subunit']['field'] = 'field_profile_subunit';
  $handler->display->display_options['fields']['field_profile_subunit']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_profile_teaser']['id'] = 'field_profile_teaser';
  $handler->display->display_options['fields']['field_profile_teaser']['table'] = 'field_data_field_profile_teaser';
  $handler->display->display_options['fields']['field_profile_teaser']['field'] = 'field_profile_teaser';
  /* Field: Content: Unit */
  $handler->display->display_options['fields']['field_profile_unit']['id'] = 'field_profile_unit';
  $handler->display->display_options['fields']['field_profile_unit']['table'] = 'field_data_field_profile_unit';
  $handler->display->display_options['fields']['field_profile_unit']['field'] = 'field_profile_unit';
  $handler->display->display_options['fields']['field_profile_unit']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Website links */
  $handler->display->display_options['fields']['field_profile_website']['id'] = 'field_profile_website';
  $handler->display->display_options['fields']['field_profile_website']['table'] = 'field_data_field_profile_website';
  $handler->display->display_options['fields']['field_profile_website']['field'] = 'field_profile_website';
  $handler->display->display_options['fields']['field_profile_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_profile_website']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_profile_website']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'profile' => 'profile',
  );
  $handler->display->display_options['path'] = 'export/profile.csv';

  /* Display: Social */
  $handler = $view->new_display('views_data_export', 'Social', 'views_data_export_9');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_replacement'] = ' ';
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Node UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Account category */
  $handler->display->display_options['fields']['field_social_category']['id'] = 'field_social_category';
  $handler->display->display_options['fields']['field_social_category']['table'] = 'field_data_field_social_category';
  $handler->display->display_options['fields']['field_social_category']['field'] = 'field_social_category';
  $handler->display->display_options['fields']['field_social_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Account URL */
  $handler->display->display_options['fields']['field_social_link']['id'] = 'field_social_link';
  $handler->display->display_options['fields']['field_social_link']['table'] = 'field_data_field_social_link';
  $handler->display->display_options['fields']['field_social_link']['field'] = 'field_social_link';
  $handler->display->display_options['fields']['field_social_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_social_link']['type'] = 'link_plain';
  /* Field: Content: Keywords */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Social media network */
  $handler->display->display_options['fields']['field_social_network']['id'] = 'field_social_network';
  $handler->display->display_options['fields']['field_social_network']['table'] = 'field_data_field_social_network';
  $handler->display->display_options['fields']['field_social_network']['field'] = 'field_social_network';
  $handler->display->display_options['fields']['field_social_network']['type'] = 'list_key';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'social' => 'social',
  );
  $handler->display->display_options['path'] = 'export/social.csv';
  $export['node_export'] = $view;

  return $export;
}
