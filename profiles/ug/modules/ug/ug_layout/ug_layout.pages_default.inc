<?php
/**
 * @file
 * ug_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ug_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__news';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'News',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'news',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'news' => 'news',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'default' => NULL,
      'top' => NULL,
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '0f98c601-13f0-4d54-8f36-87b06be6b7c3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5e3d6294-e02b-4968-82a6-f4fe67c88f09';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'posted_on-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5e3d6294-e02b-4968-82a6-f4fe67c88f09';
    $display->content['new-5e3d6294-e02b-4968-82a6-f4fe67c88f09'] = $pane;
    $display->panels['left'][0] = 'new-5e3d6294-e02b-4968-82a6-f4fe67c88f09';
    $pane = new stdClass();
    $pane->pid = 'new-f2c1e5e7-c3df-40f5-a234-b921c139ffc6';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'written_by-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f2c1e5e7-c3df-40f5-a234-b921c139ffc6';
    $display->content['new-f2c1e5e7-c3df-40f5-a234-b921c139ffc6'] = $pane;
    $display->panels['left'][1] = 'new-f2c1e5e7-c3df-40f5-a234-b921c139ffc6';
    $pane = new stdClass();
    $pane->pid = 'new-f8c35af1-c486-4fc9-ad1f-050e19f863df';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'news_image-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f8c35af1-c486-4fc9-ad1f-050e19f863df';
    $display->content['new-f8c35af1-c486-4fc9-ad1f-050e19f863df'] = $pane;
    $display->panels['left'][2] = 'new-f8c35af1-c486-4fc9-ad1f-050e19f863df';
    $pane = new stdClass();
    $pane->pid = 'new-44a2c678-3480-4fb2-a66d-913f4f82c626';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_news_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '44a2c678-3480-4fb2-a66d-913f4f82c626';
    $display->content['new-44a2c678-3480-4fb2-a66d-913f4f82c626'] = $pane;
    $display->panels['left'][3] = 'new-44a2c678-3480-4fb2-a66d-913f4f82c626';
    $pane = new stdClass();
    $pane->pid = 'new-ca11576b-5ec6-4ef0-880b-c19f08cf846a';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_news_attachment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_table',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'File Attachments',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'ca11576b-5ec6-4ef0-880b-c19f08cf846a';
    $display->content['new-ca11576b-5ec6-4ef0-880b-c19f08cf846a'] = $pane;
    $display->panels['left'][4] = 'new-ca11576b-5ec6-4ef0-880b-c19f08cf846a';
    $pane = new stdClass();
    $pane->pid = 'new-d40c27a3-4e25-4684-90b9-00fc3f700ee4';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'n7-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Find related news by keyword',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'd40c27a3-4e25-4684-90b9-00fc3f700ee4';
    $display->content['new-d40c27a3-4e25-4684-90b9-00fc3f700ee4'] = $pane;
    $display->panels['left'][5] = 'new-d40c27a3-4e25-4684-90b9-00fc3f700ee4';
    $pane = new stdClass();
    $pane->pid = 'new-7a7badc9-4f28-4430-b81a-66538d9be30b';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 's1-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7a7badc9-4f28-4430-b81a-66538d9be30b';
    $display->content['new-7a7badc9-4f28-4430-b81a-66538d9be30b'] = $pane;
    $display->panels['right'][0] = 'new-7a7badc9-4f28-4430-b81a-66538d9be30b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__news'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'default' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'd22f0d0f-7831-47b5-bb27-cf5f94617b3b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-51497ab9-4ab6-40ae-9e08-005f2d3fca1b';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_page_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '51497ab9-4ab6-40ae-9e08-005f2d3fca1b';
    $display->content['new-51497ab9-4ab6-40ae-9e08-005f2d3fca1b'] = $pane;
    $display->panels['left'][0] = 'new-51497ab9-4ab6-40ae-9e08-005f2d3fca1b';
    $pane = new stdClass();
    $pane->pid = 'new-7751ae44-ca1d-4259-ae2b-ec3acf986b9a';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_page_attachments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_table',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7751ae44-ca1d-4259-ae2b-ec3acf986b9a';
    $display->content['new-7751ae44-ca1d-4259-ae2b-ec3acf986b9a'] = $pane;
    $display->panels['left'][1] = 'new-7751ae44-ca1d-4259-ae2b-ec3acf986b9a';
    $pane = new stdClass();
    $pane->pid = 'new-94e8fb6f-785f-437c-9cc4-e1050c918f84';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 's1-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '94e8fb6f-785f-437c-9cc4-e1050c918f84';
    $display->content['new-94e8fb6f-785f-437c-9cc4-e1050c918f84'] = $pane;
    $display->panels['right'][0] = 'new-94e8fb6f-785f-437c-9cc4-e1050c918f84';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_626675f3-46af-46d8-9b83-9f8b00d92e69';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Event',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'event' => 'event',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => NULL,
      'bottom' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '4f0a3459-5e24-491d-9abe-ba357d368e61';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-35dde403-f767-442a-933e-4828c6c430e5';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'long',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<span class="glyphicon glyphicon-time"></span> Date and Time',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '35dde403-f767-442a-933e-4828c6c430e5';
    $display->content['new-35dde403-f767-442a-933e-4828c6c430e5'] = $pane;
    $display->panels['left'][0] = 'new-35dde403-f767-442a-933e-4828c6c430e5';
    $pane = new stdClass();
    $pane->pid = 'new-ed1e27ec-43c1-4d50-a812-aaf48023434b';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_location';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<span class="glyphicon glyphicon-map-marker"></span> Location',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ed1e27ec-43c1-4d50-a812-aaf48023434b';
    $display->content['new-ed1e27ec-43c1-4d50-a812-aaf48023434b'] = $pane;
    $display->panels['left'][1] = 'new-ed1e27ec-43c1-4d50-a812-aaf48023434b';
    $pane = new stdClass();
    $pane->pid = 'new-4c31f9a9-f427-4c3d-9ad4-2da41c2c4ca8';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_summary';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4c31f9a9-f427-4c3d-9ad4-2da41c2c4ca8';
    $display->content['new-4c31f9a9-f427-4c3d-9ad4-2da41c2c4ca8'] = $pane;
    $display->panels['left'][2] = 'new-4c31f9a9-f427-4c3d-9ad4-2da41c2c4ca8';
    $pane = new stdClass();
    $pane->pid = 'new-72c98414-8990-4740-a95b-666eb8a11c2d';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'event_multipart-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '72c98414-8990-4740-a95b-666eb8a11c2d';
    $display->content['new-72c98414-8990-4740-a95b-666eb8a11c2d'] = $pane;
    $display->panels['left'][3] = 'new-72c98414-8990-4740-a95b-666eb8a11c2d';
    $pane = new stdClass();
    $pane->pid = 'new-d6783094-a150-4251-b73d-1dd7755f3867';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<span class="glyphicon glyphicon-link"></span> Event Website',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'd6783094-a150-4251-b73d-1dd7755f3867';
    $display->content['new-d6783094-a150-4251-b73d-1dd7755f3867'] = $pane;
    $display->panels['left'][4] = 'new-d6783094-a150-4251-b73d-1dd7755f3867';
    $pane = new stdClass();
    $pane->pid = 'new-e06d31d6-082f-4847-94c0-6bb82a5eb4da';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_attachments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_table',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<span class="glyphicon glyphicon-paperclip"></span> File Attachments',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'e06d31d6-082f-4847-94c0-6bb82a5eb4da';
    $display->content['new-e06d31d6-082f-4847-94c0-6bb82a5eb4da'] = $pane;
    $display->panels['left'][5] = 'new-e06d31d6-082f-4847-94c0-6bb82a5eb4da';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_626675f3-46af-46d8-9b83-9f8b00d92e69'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__service';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Service',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'service',
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'middle' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'c39ec56c-364b-420b-bb40-7eefc8f8444b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-072680c6-4786-409d-aa9c-5ac699134b1c';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_service_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => '600',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '072680c6-4786-409d-aa9c-5ac699134b1c';
    $display->content['new-072680c6-4786-409d-aa9c-5ac699134b1c'] = $pane;
    $display->panels['middle'][0] = 'new-072680c6-4786-409d-aa9c-5ac699134b1c';
    $pane = new stdClass();
    $pane->pid = 'new-6f16f351-789e-4434-900d-c6d02ce070be';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_service_audience';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6f16f351-789e-4434-900d-c6d02ce070be';
    $display->content['new-6f16f351-789e-4434-900d-c6d02ce070be'] = $pane;
    $display->panels['middle'][1] = 'new-6f16f351-789e-4434-900d-c6d02ce070be';
    $pane = new stdClass();
    $pane->pid = 'new-95b3fc1e-12df-4d72-be6f-2ceab3d32758';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'sr2-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '95b3fc1e-12df-4d72-be6f-2ceab3d32758';
    $display->content['new-95b3fc1e-12df-4d72-be6f-2ceab3d32758'] = $pane;
    $display->panels['middle'][2] = 'new-95b3fc1e-12df-4d72-be6f-2ceab3d32758';
    $pane = new stdClass();
    $pane->pid = 'new-c21e40a7-cea2-4fe9-bbca-b7c4f7c09d9b';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_service_related';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Related Services',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c21e40a7-cea2-4fe9-bbca-b7c4f7c09d9b';
    $display->content['new-c21e40a7-cea2-4fe9-bbca-b7c4f7c09d9b'] = $pane;
    $display->panels['middle'][3] = 'new-c21e40a7-cea2-4fe9-bbca-b7c4f7c09d9b';
    $pane = new stdClass();
    $pane->pid = 'new-57a599f7-be4e-452e-b2ee-b7b518f6446e';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_service_private';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => 'Edit',
        'delete' => 'Delete',
        'add' => 'Add',
        'description' => 1,
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '57a599f7-be4e-452e-b2ee-b7b518f6446e';
    $display->content['new-57a599f7-be4e-452e-b2ee-b7b518f6446e'] = $pane;
    $display->panels['middle'][4] = 'new-57a599f7-be4e-452e-b2ee-b7b518f6446e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__service'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__panel_context_4b915309-9fda-4c42-900d-72fc35fe6822';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(),
    ),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => NULL,
      'bottom' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c922e0ed-6e14-4fcd-8b5a-7814f72aeb05';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1273f670-f0dc-4d59-a578-59422770c43e';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'p2-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1273f670-f0dc-4d59-a578-59422770c43e';
    $display->content['new-1273f670-f0dc-4d59-a578-59422770c43e'] = $pane;
    $display->panels['left'][0] = 'new-1273f670-f0dc-4d59-a578-59422770c43e';
    $pane = new stdClass();
    $pane->pid = 'new-0acfee1c-98e9-4030-9aa8-374777f5d62e';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'profile_multipart-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0acfee1c-98e9-4030-9aa8-374777f5d62e';
    $display->content['new-0acfee1c-98e9-4030-9aa8-374777f5d62e'] = $pane;
    $display->panels['left'][1] = 'new-0acfee1c-98e9-4030-9aa8-374777f5d62e';
    $pane = new stdClass();
    $pane->pid = 'new-b28b4828-b719-4545-b0fb-3c8c6bc937b7';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'profile_attachments-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b28b4828-b719-4545-b0fb-3c8c6bc937b7';
    $display->content['new-b28b4828-b719-4545-b0fb-3c8c6bc937b7'] = $pane;
    $display->panels['left'][2] = 'new-b28b4828-b719-4545-b0fb-3c8c6bc937b7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1273f670-f0dc-4d59-a578-59422770c43e';
  $handler->conf['display'] = $display;
  $export['user_view__panel_context_4b915309-9fda-4c42-900d-72fc35fe6822'] = $handler;

  return $export;
}
