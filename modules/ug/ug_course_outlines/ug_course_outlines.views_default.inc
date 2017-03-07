<?php
/**
 * @file
 * ug_course_outlines.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ug_course_outlines_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'co1';
  $view->description = 'Provides a pages listing of published course outlines.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CO1 - Listing page for Multiple Course Outlines';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course Outlines';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_course_term',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_course_term' => 'field_course_term',
    'field_course_code' => 'field_course_code',
    'field_course_name' => 'field_course_name',
    'field_course_section' => 'field_course_section',
    'field_course_instructor' => 'field_course_instructor',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_section' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_course_instructor' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Course term (field_course_term) */
  $handler->display->display_options['relationships']['field_course_term_tid']['id'] = 'field_course_term_tid';
  $handler->display->display_options['relationships']['field_course_term_tid']['table'] = 'field_data_field_course_term';
  $handler->display->display_options['relationships']['field_course_term_tid']['field'] = 'field_course_term_tid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Course term */
  $handler->display->display_options['fields']['field_course_term']['id'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['table'] = 'field_data_field_course_term';
  $handler->display->display_options['fields']['field_course_term']['field'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['label'] = 'Term';
  $handler->display->display_options['fields']['field_course_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Course code */
  $handler->display->display_options['fields']['field_course_code']['id'] = 'field_course_code';
  $handler->display->display_options['fields']['field_course_code']['table'] = 'field_data_field_course_code';
  $handler->display->display_options['fields']['field_course_code']['field'] = 'field_course_code';
  /* Field: Content: Course name */
  $handler->display->display_options['fields']['field_course_name']['id'] = 'field_course_name';
  $handler->display->display_options['fields']['field_course_name']['table'] = 'field_data_field_course_name';
  $handler->display->display_options['fields']['field_course_name']['field'] = 'field_course_name';
  $handler->display->display_options['fields']['field_course_name']['label'] = 'Title';
  $handler->display->display_options['fields']['field_course_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_course_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_course_name']['element_label_colon'] = FALSE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  /* Field: Content: Course instructor */
  $handler->display->display_options['fields']['field_course_instructor']['id'] = 'field_course_instructor';
  $handler->display->display_options['fields']['field_course_instructor']['table'] = 'field_data_field_course_instructor';
  $handler->display->display_options['fields']['field_course_instructor']['field'] = 'field_course_instructor';
  $handler->display->display_options['fields']['field_course_instructor']['label'] = 'Instructor';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_course_term_tid';
  /* Sort criterion: Content: Course code (field_course_code) */
  $handler->display->display_options['sorts']['field_course_code_value']['id'] = 'field_course_code_value';
  $handler->display->display_options['sorts']['field_course_code_value']['table'] = 'field_data_field_course_code';
  $handler->display->display_options['sorts']['field_course_code_value']['field'] = 'field_course_code_value';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['arguments']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid_1']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid_1']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid_1']['title'] = '%1 Course Outlines';
  $handler->display->display_options['arguments']['tid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid_1']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['tid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid_1']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid_1']['validate_options']['vocabularies'] = array(
    'course_outline_category' => 'course_outline_category',
    'tags' => 'tags',
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Course level (field_course_level) */
  $handler->display->display_options['filters']['field_course_level_tid']['id'] = 'field_course_level_tid';
  $handler->display->display_options['filters']['field_course_level_tid']['table'] = 'field_data_field_course_level';
  $handler->display->display_options['filters']['field_course_level_tid']['field'] = 'field_course_level_tid';
  $handler->display->display_options['filters']['field_course_level_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_course_level_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_level_tid']['expose']['operator_id'] = 'field_course_level_tid_op';
  $handler->display->display_options['filters']['field_course_level_tid']['expose']['label'] = 'Course level';
  $handler->display->display_options['filters']['field_course_level_tid']['expose']['operator'] = 'field_course_level_tid_op';
  $handler->display->display_options['filters']['field_course_level_tid']['expose']['identifier'] = 'field_course_level_tid';
  $handler->display->display_options['filters']['field_course_level_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_course_level_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_level_tid']['vocabulary'] = 'course_outline_level';
  /* Filter criterion: Content: Course name (field_course_name) */
  $handler->display->display_options['filters']['field_course_name_value']['id'] = 'field_course_name_value';
  $handler->display->display_options['filters']['field_course_name_value']['table'] = 'field_data_field_course_name';
  $handler->display->display_options['filters']['field_course_name_value']['field'] = 'field_course_name_value';
  $handler->display->display_options['filters']['field_course_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_course_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_course_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_name_value']['expose']['operator_id'] = 'field_course_name_value_op';
  $handler->display->display_options['filters']['field_course_name_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['field_course_name_value']['expose']['operator'] = 'field_course_name_value_op';
  $handler->display->display_options['filters']['field_course_name_value']['expose']['identifier'] = 'field_course_name_value';
  $handler->display->display_options['filters']['field_course_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['filters']['field_course_subject_tid']['id'] = 'field_course_subject_tid';
  $handler->display->display_options['filters']['field_course_subject_tid']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['filters']['field_course_subject_tid']['field'] = 'field_course_subject_tid';
  $handler->display->display_options['filters']['field_course_subject_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_subject_tid']['expose']['operator_id'] = 'field_course_subject_tid_op';
  $handler->display->display_options['filters']['field_course_subject_tid']['expose']['label'] = 'Subject';
  $handler->display->display_options['filters']['field_course_subject_tid']['expose']['operator'] = 'field_course_subject_tid_op';
  $handler->display->display_options['filters']['field_course_subject_tid']['expose']['identifier'] = 'field_course_subject_tid';
  $handler->display->display_options['filters']['field_course_subject_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_course_subject_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_subject_tid']['vocabulary'] = 'course_outline_subject';
  /* Filter criterion: Content: Course term (field_course_term) */
  $handler->display->display_options['filters']['field_course_term_tid']['id'] = 'field_course_term_tid';
  $handler->display->display_options['filters']['field_course_term_tid']['table'] = 'field_data_field_course_term';
  $handler->display->display_options['filters']['field_course_term_tid']['field'] = 'field_course_term_tid';
  $handler->display->display_options['filters']['field_course_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['operator_id'] = 'field_course_term_tid_op';
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['operator'] = 'field_course_term_tid_op';
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['identifier'] = 'field_course_term_tid';
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_course_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_term_tid']['vocabulary'] = 'course_outline_term';
  $handler->display->display_options['filters']['field_course_term_tid']['error_message'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['more_text'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'tid_1' => array(
      'type' => 'panel',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Category',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['co1'] = $view;

  $view = new view();
  $view->name = 'co2_info_for_single_course';
  $view->description = 'Provides all details for a single course.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CO2 - Detail Page for Course Outline';
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
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Course code */
  $handler->display->display_options['fields']['field_course_code']['id'] = 'field_course_code';
  $handler->display->display_options['fields']['field_course_code']['table'] = 'field_data_field_course_code';
  $handler->display->display_options['fields']['field_course_code']['field'] = 'field_course_code';
  $handler->display->display_options['fields']['field_course_code']['label'] = '';
  $handler->display->display_options['fields']['field_course_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_code']['element_label_colon'] = FALSE;
  /* Field: Content: Course term */
  $handler->display->display_options['fields']['field_course_term']['id'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['table'] = 'field_data_field_course_term';
  $handler->display->display_options['fields']['field_course_term']['field'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['label'] = '';
  $handler->display->display_options['fields']['field_course_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['label'] = '';
  $handler->display->display_options['fields']['field_course_section']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_section']['element_label_colon'] = FALSE;
  /* Field: Content: Course instructor */
  $handler->display->display_options['fields']['field_course_instructor']['id'] = 'field_course_instructor';
  $handler->display->display_options['fields']['field_course_instructor']['table'] = 'field_data_field_course_instructor';
  $handler->display->display_options['fields']['field_course_instructor']['field'] = 'field_course_instructor';
  $handler->display->display_options['fields']['field_course_instructor']['label'] = '';
  $handler->display->display_options['fields']['field_course_instructor']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_instructor']['element_label_colon'] = FALSE;
  /* Field: Content: Course instructor url */
  $handler->display->display_options['fields']['field_course_instructor_url']['id'] = 'field_course_instructor_url';
  $handler->display->display_options['fields']['field_course_instructor_url']['table'] = 'field_data_field_course_instructor_url';
  $handler->display->display_options['fields']['field_course_instructor_url']['field'] = 'field_course_instructor_url';
  $handler->display->display_options['fields']['field_course_instructor_url']['label'] = '';
  $handler->display->display_options['fields']['field_course_instructor_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_instructor_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_instructor_url']['alter']['text'] = '<a href="[field_course_instructor_url-url]">[field_course_instructor]</a>';
  $handler->display->display_options['fields']['field_course_instructor_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_instructor_url']['empty'] = '[field_course_instructor]';
  $handler->display->display_options['fields']['field_course_instructor_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_course_instructor_url']['type'] = 'link_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<p class="media-condensed"><strong>Code and section:</strong> [field_course_code]*[field_course_section]</p>
<p class="media-condensed"><strong>Term:</strong> [field_course_term]</p>
<p><strong>Instructor:</strong> [field_course_instructor_url]</p>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Details */
  $handler->display->display_options['fields']['field_course_body']['id'] = 'field_course_body';
  $handler->display->display_options['fields']['field_course_body']['table'] = 'field_data_field_course_body';
  $handler->display->display_options['fields']['field_course_body']['field'] = 'field_course_body';
  $handler->display->display_options['fields']['field_course_body']['label'] = '';
  $handler->display->display_options['fields']['field_course_body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_body']['alter']['text'] = '<h2><span class="glyphicon glyphicon-info-sign"></span> Details</h2>
[field_course_body]';
  $handler->display->display_options['fields']['field_course_body']['element_label_colon'] = FALSE;
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_course_attachments']['id'] = 'field_course_attachments';
  $handler->display->display_options['fields']['field_course_attachments']['table'] = 'field_data_field_course_attachments';
  $handler->display->display_options['fields']['field_course_attachments']['field'] = 'field_course_attachments';
  $handler->display->display_options['fields']['field_course_attachments']['label'] = '';
  $handler->display->display_options['fields']['field_course_attachments']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_attachments']['alter']['text'] = '<h2><span class="glyphicon glyphicon-paperclip"></span> Syllabus</h2>
<p>[field_course_attachments]</p>';
  $handler->display->display_options['fields']['field_course_attachments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_attachments']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_course_attachments']['type'] = 'file_table';
  $handler->display->display_options['fields']['field_course_attachments']['delta_offset'] = '0';
  /* Field: Content: Course Website */
  $handler->display->display_options['fields']['field_course_website']['id'] = 'field_course_website';
  $handler->display->display_options['fields']['field_course_website']['table'] = 'field_data_field_course_website';
  $handler->display->display_options['fields']['field_course_website']['field'] = 'field_course_website';
  $handler->display->display_options['fields']['field_course_website']['label'] = '';
  $handler->display->display_options['fields']['field_course_website']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_website']['alter']['text'] = '<h2><span class="glyphicon glyphicon-globe"></span> Website</h2>
<p>[field_course_website]</p>';
  $handler->display->display_options['fields']['field_course_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_course_website']['type'] = 'link_url';
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
    'course_outline' => 'course_outline',
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
      'context' => 'entity:field_collection_item.archived',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['co2_info_for_single_course'] = $view;

  return $export;
}
