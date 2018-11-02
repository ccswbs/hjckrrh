<?php
/**
 * @file
 * ug_video.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ug_video_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'v1';
  $view->description = 'List of videos, list of videos with embed code, Embed code content pane, and Video teaser list';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'V1 - Listing page for multiple videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Videos for embedding';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_video_url']['id'] = 'field_video_url';
  $handler->display->display_options['fields']['field_video_url']['table'] = 'field_data_field_video_url';
  $handler->display->display_options['fields']['field_video_url']['field'] = 'field_video_url';
  $handler->display->display_options['fields']['field_video_url']['label'] = '';
  $handler->display->display_options['fields']['field_video_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Video Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Video ID */
  $handler->display->display_options['fields']['field_video_id']['id'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['table'] = 'field_data_field_video_id';
  $handler->display->display_options['fields']['field_video_id']['field'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['label'] = '';
  $handler->display->display_options['fields']['field_video_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_id']['type'] = 'text_plain';
  /* Field: Content: Transcript file */
  $handler->display->display_options['fields']['field_transcript_file']['id'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['table'] = 'field_data_field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['field'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['label'] = '';
  $handler->display->display_options['fields']['field_transcript_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transcript_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_transcript_file']['type'] = 'file_url_plain';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
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
    'accessible_video' => 'accessible_video',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'row media';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'media-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'teaser-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: unlinked title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['ui_name'] = 'Content: unlinked title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Video ID */
  $handler->display->display_options['fields']['field_video_id']['id'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['table'] = 'field_data_field_video_id';
  $handler->display->display_options['fields']['field_video_id']['field'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['label'] = '';
  $handler->display->display_options['fields']['field_video_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_id']['type'] = 'text_plain';
  /* Field: Content: video thumbnail */
  $handler->display->display_options['fields']['field_video_id_1']['id'] = 'field_video_id_1';
  $handler->display->display_options['fields']['field_video_id_1']['table'] = 'field_data_field_video_id';
  $handler->display->display_options['fields']['field_video_id_1']['field'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id_1']['ui_name'] = 'Content: video thumbnail';
  $handler->display->display_options['fields']['field_video_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_video_id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_video_id_1']['alter']['text'] = '<div class=media-thumbnail">
<figure>
<a href="https://www.youtube.com/watch?v=[field_video_id]">
<img class="img-responsive img-rounded" src="https://img.youtube.com/vi/[field_video_id]/0.jpg" alt="View [title_1] on YouTube" /></a>
<figcaption>View on YouTube</figcaption>
</figure>
</div>';
  $handler->display->display_options['fields']['field_video_id_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_video_id_1']['element_class'] = 'col-md-4';
  $handler->display->display_options['fields']['field_video_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_id_1']['element_default_classes'] = FALSE;
  /* Field: Content: transcript div */
  $handler->display->display_options['fields']['field_transcript_file']['id'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['table'] = 'field_data_field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['field'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['ui_name'] = 'Content: transcript div';
  $handler->display->display_options['fields']['field_transcript_file']['label'] = '';
  $handler->display->display_options['fields']['field_transcript_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file']['alter']['text'] = 'data-transcript-div="transcript-container[nid]"';
  $handler->display->display_options['fields']['field_transcript_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transcript_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_transcript_file']['type'] = 'file_url_plain';
  /* Field: Content: transcript path */
  $handler->display->display_options['fields']['field_transcript_file_1']['id'] = 'field_transcript_file_1';
  $handler->display->display_options['fields']['field_transcript_file_1']['table'] = 'field_data_field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file_1']['field'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file_1']['ui_name'] = 'Content: transcript path';
  $handler->display->display_options['fields']['field_transcript_file_1']['label'] = '';
  $handler->display->display_options['fields']['field_transcript_file_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file_1']['alter']['text'] = '&lt;track kind="captions" src="[field_transcript_file_1]" /&gt;';
  $handler->display->display_options['fields']['field_transcript_file_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transcript_file_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_transcript_file_1']['type'] = 'file_url_plain';
  /* Field: Content: description path */
  $handler->display->display_options['fields']['field_description_file']['id'] = 'field_description_file';
  $handler->display->display_options['fields']['field_description_file']['table'] = 'field_data_field_description_file';
  $handler->display->display_options['fields']['field_description_file']['field'] = 'field_description_file';
  $handler->display->display_options['fields']['field_description_file']['ui_name'] = 'Content: description path';
  $handler->display->display_options['fields']['field_description_file']['label'] = '';
  $handler->display->display_options['fields']['field_description_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description_file']['alter']['text'] = '&lt;track kind="descriptions" src="[field_description_file]" />';
  $handler->display->display_options['fields']['field_description_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_description_file']['type'] = 'file_url_plain';
  /* Field: Content: transcript display area */
  $handler->display->display_options['fields']['field_transcript_file_2']['id'] = 'field_transcript_file_2';
  $handler->display->display_options['fields']['field_transcript_file_2']['table'] = 'field_data_field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file_2']['field'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file_2']['ui_name'] = 'Content: transcript display area';
  $handler->display->display_options['fields']['field_transcript_file_2']['label'] = '';
  $handler->display->display_options['fields']['field_transcript_file_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file_2']['alter']['text'] = '&lt;div id="transcript-container[nid]"&gt;&lt;/div&gt;';
  $handler->display->display_options['fields']['field_transcript_file_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transcript_file_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_transcript_file_2']['type'] = 'file_url_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2 class="media-heading">[title]</h2>
<h3>Embed code:</h3>
<pre>
&lt;video data-able-player playsinline [field_transcript_file] data-youtube-id="[field_video_id]" id="video[nid]" preload="auto"&gt;
    [field_transcript_file_1]
    [field_description_file]
&lt;/video&gt;
[field_transcript_file_2]
</pre>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'col-md-8';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
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
    'accessible_video' => 'accessible_video',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Video category (field_video_category) */
  $handler->display->display_options['filters']['field_video_category_tid']['id'] = 'field_video_category_tid';
  $handler->display->display_options['filters']['field_video_category_tid']['table'] = 'field_data_field_video_category';
  $handler->display->display_options['filters']['field_video_category_tid']['field'] = 'field_video_category_tid';
  $handler->display->display_options['filters']['field_video_category_tid']['value'] = '';
  $handler->display->display_options['filters']['field_video_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_video_category_tid']['expose']['operator_id'] = 'field_video_category_tid_op';
  $handler->display->display_options['filters']['field_video_category_tid']['expose']['label'] = 'Search by category';
  $handler->display->display_options['filters']['field_video_category_tid']['expose']['operator'] = 'field_video_category_tid_op';
  $handler->display->display_options['filters']['field_video_category_tid']['expose']['identifier'] = 'field_video_category_tid';
  $handler->display->display_options['filters']['field_video_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_video_category_tid']['vocabulary'] = 'video_category';
  /* Filter criterion: Content: Keywords (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Search by keyword';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['path'] = 'videos-embed';

  /* Display: Code content pane */
  $handler = $view->new_display('panel_pane', 'Code content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_video_url' => 'field_video_url',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Video ID */
  $handler->display->display_options['fields']['field_video_id']['id'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['table'] = 'field_data_field_video_id';
  $handler->display->display_options['fields']['field_video_id']['field'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['label'] = '';
  $handler->display->display_options['fields']['field_video_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_id']['type'] = 'text_plain';
  /* Field: Content: transcript div ID */
  $handler->display->display_options['fields']['field_transcript_file']['id'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['table'] = 'field_data_field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['field'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['ui_name'] = 'Content: transcript div ID';
  $handler->display->display_options['fields']['field_transcript_file']['label'] = '';
  $handler->display->display_options['fields']['field_transcript_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file']['alter']['text'] = 'data-transcript-div="transcript-container[nid]"';
  $handler->display->display_options['fields']['field_transcript_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transcript_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_transcript_file']['type'] = 'file_url_plain';
  /* Field: Content: transcript path */
  $handler->display->display_options['fields']['field_transcript_file_1']['id'] = 'field_transcript_file_1';
  $handler->display->display_options['fields']['field_transcript_file_1']['table'] = 'field_data_field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file_1']['field'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file_1']['ui_name'] = 'Content: transcript path';
  $handler->display->display_options['fields']['field_transcript_file_1']['label'] = '';
  $handler->display->display_options['fields']['field_transcript_file_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file_1']['alter']['text'] = '&lt;track kind="captions" src="[field_transcript_file_1]" srclang="en" /&gt;';
  $handler->display->display_options['fields']['field_transcript_file_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transcript_file_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_transcript_file_1']['type'] = 'file_url_plain';
  /* Field: Content: description path */
  $handler->display->display_options['fields']['field_description_file_1']['id'] = 'field_description_file_1';
  $handler->display->display_options['fields']['field_description_file_1']['table'] = 'field_data_field_description_file';
  $handler->display->display_options['fields']['field_description_file_1']['field'] = 'field_description_file';
  $handler->display->display_options['fields']['field_description_file_1']['ui_name'] = 'Content: description path';
  $handler->display->display_options['fields']['field_description_file_1']['label'] = '';
  $handler->display->display_options['fields']['field_description_file_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description_file_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description_file_1']['alter']['text'] = '&lt;track kind="descriptions" src="[field_description_file_1]" srclang="en" /&gt;';
  $handler->display->display_options['fields']['field_description_file_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description_file_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_description_file_1']['type'] = 'file_url_plain';
  /* Field: Content: transcript display area */
  $handler->display->display_options['fields']['field_transcript_file_3']['id'] = 'field_transcript_file_3';
  $handler->display->display_options['fields']['field_transcript_file_3']['table'] = 'field_data_field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file_3']['field'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file_3']['ui_name'] = 'Content: transcript display area';
  $handler->display->display_options['fields']['field_transcript_file_3']['label'] = '';
  $handler->display->display_options['fields']['field_transcript_file_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_transcript_file_3']['alter']['text'] = '&lt;div id="transcript-container[nid]"&gt;&lt;/div&gt;';
  $handler->display->display_options['fields']['field_transcript_file_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transcript_file_3']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_transcript_file_3']['type'] = 'file_url_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Embed Code';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<pre>
&lt;video data-able-player playsinline [field_transcript_file] data-youtube-id="[field_video_id]" id="video[nid]" preload="auto"&gt;
    [field_transcript_file_1]
    [field_description_file_1]
&lt;/video&gt;
[field_transcript_file_3]
</pre>';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = 'h2';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'accessible_video' => 'accessible_video',
  );
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:field_collection_item.archived',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Video teaser list */
  $handler = $view->new_display('panel_pane', 'Video teaser list', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured Videos';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More videos';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'row media';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'media-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'teaser-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: video thumbnail */
  $handler->display->display_options['fields']['field_video_id']['id'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['table'] = 'field_data_field_video_id';
  $handler->display->display_options['fields']['field_video_id']['field'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['ui_name'] = 'Content: video thumbnail';
  $handler->display->display_options['fields']['field_video_id']['label'] = '';
  $handler->display->display_options['fields']['field_video_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_video_id']['alter']['text'] = '<div class="media-thumbnail">
    <img class="img-responsive img-rounded" alt="" src="https://img.youtube.com/vi/[field_video_id]/0.jpg" />
</div>';
  $handler->display->display_options['fields']['field_video_id']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_video_id']['element_class'] = 'col-md-6';
  $handler->display->display_options['fields']['field_video_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_id']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['field_video_body']['id'] = 'body';
  $handler->display->display_options['fields']['field_video_body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['field_video_body']['field'] = 'body';
  $handler->display->display_options['fields']['field_video_body']['label'] = '';
  $handler->display->display_options['fields']['field_video_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_body']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_video_body']['element_class'] = 'media-summary';
  $handler->display->display_options['fields']['field_video_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_video_body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_video_body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_video_body']['settings'] = array(
    'trim_length' => '150',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="media-header">
    <h3 class="media-heading ug-media-heading">[title]</h3>
</div>
[body]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'col-md-6 xs-gutter';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Video category (field_video_category) */
  $handler->display->display_options['arguments']['field_video_category_tid']['id'] = 'field_video_category_tid';
  $handler->display->display_options['arguments']['field_video_category_tid']['table'] = 'field_data_field_video_category';
  $handler->display->display_options['arguments']['field_video_category_tid']['field'] = 'field_video_category_tid';
  $handler->display->display_options['arguments']['field_video_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_video_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_category_tid']['summary_options']['items_per_page'] = '25';
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
    'field_video_category_tid' => array(
      'type' => 'user',
      'context' => 'entity:field_collection_item.archived',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Category',
    ),
  );

  /* Display: All videos */
  $handler = $view->new_display('panel_pane', 'All videos', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured Videos';
  $handler->display->display_options['display_description'] = 'Content pane with a paged list of all videos';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More videos';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'row media';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: video thumbnail */
  $handler->display->display_options['fields']['field_video_id']['id'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['table'] = 'field_data_field_video_id';
  $handler->display->display_options['fields']['field_video_id']['field'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['ui_name'] = 'Content: video thumbnail';
  $handler->display->display_options['fields']['field_video_id']['label'] = '';
  $handler->display->display_options['fields']['field_video_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_video_id']['alter']['text'] = '<div class="media-thumbnail">
    <img class="img-responsive img-rounded" alt="" src="https://img.youtube.com/vi/[field_video_id]/0.jpg" />
</div>';
  $handler->display->display_options['fields']['field_video_id']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_video_id']['element_class'] = 'col-md-4';
  $handler->display->display_options['fields']['field_video_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_id']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'media-summary';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '150',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="media-header">
    <h2 class="media-heading">[title]</h2>
</div>
[body]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'col-md-8';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Video category (field_video_category) */
  $handler->display->display_options['arguments']['field_video_category_tid']['id'] = 'field_video_category_tid';
  $handler->display->display_options['arguments']['field_video_category_tid']['table'] = 'field_data_field_video_category';
  $handler->display->display_options['arguments']['field_video_category_tid']['field'] = 'field_video_category_tid';
  $handler->display->display_options['arguments']['field_video_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_video_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_category_tid']['summary_options']['items_per_page'] = '25';
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
    'field_video_category_tid' => array(
      'type' => 'panel',
      'context' => 'entity:field_collection_item.archived',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Category',
    ),
  );
  $export['v1'] = $view;

  $view = new view();
  $view->name = 'v2';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'V2 - Detail view for single video';
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
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Video ID */
  $handler->display->display_options['fields']['field_video_id']['id'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['table'] = 'field_data_field_video_id';
  $handler->display->display_options['fields']['field_video_id']['field'] = 'field_video_id';
  $handler->display->display_options['fields']['field_video_id']['label'] = '';
  $handler->display->display_options['fields']['field_video_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_video_id']['alter']['text'] = '[field_video_id-value]';
  $handler->display->display_options['fields']['field_video_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_id']['type'] = 'text_plain';
  /* Field: Content: Transcript file */
  $handler->display->display_options['fields']['field_transcript_file']['id'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['table'] = 'field_data_field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['field'] = 'field_transcript_file';
  $handler->display->display_options['fields']['field_transcript_file']['label'] = '';
  $handler->display->display_options['fields']['field_transcript_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transcript_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_transcript_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_transcript_file']['type'] = 'file_url_plain';
  /* Field: Content: Description file */
  $handler->display->display_options['fields']['field_description_file']['id'] = 'field_description_file';
  $handler->display->display_options['fields']['field_description_file']['table'] = 'field_data_field_description_file';
  $handler->display->display_options['fields']['field_description_file']['field'] = 'field_description_file';
  $handler->display->display_options['fields']['field_description_file']['label'] = '';
  $handler->display->display_options['fields']['field_description_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_description_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_description_file']['type'] = 'file_url_plain';
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
    'accessible_video' => 'accessible_video',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:field_collection_item.archived',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['v2'] = $view;

  return $export;
}
