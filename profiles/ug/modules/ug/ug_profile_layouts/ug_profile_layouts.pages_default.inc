<?php
/**
 * @file
 * ug_profile_layouts.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ug_profile_layouts_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__profile';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => 'Profile',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'profile',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'profile' => 'profile',
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
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'top' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '3',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '3',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'default' => NULL,
      'middle' => array(
        'column_type' => 'col-sm',
        'column_size' => '6',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '419a35c4-6a7d-461e-8995-fd9f1abfd040';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__profile';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bb69816b-11ad-4a80-a370-1473c4d11035';
  $pane->panel = 'bottom';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_profile_summary';
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
    'style' => 'naked',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bb69816b-11ad-4a80-a370-1473c4d11035';
  $display->content['new-bb69816b-11ad-4a80-a370-1473c4d11035'] = $pane;
  $display->panels['bottom'][0] = 'new-bb69816b-11ad-4a80-a370-1473c4d11035';
  $pane = new stdClass();
  $pane->pid = 'new-d6f72e51-d772-48ad-9da7-a708e6c91787';
  $pane->panel = 'bottom';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_profile_multipart';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd6f72e51-d772-48ad-9da7-a708e6c91787';
  $display->content['new-d6f72e51-d772-48ad-9da7-a708e6c91787'] = $pane;
  $display->panels['bottom'][1] = 'new-d6f72e51-d772-48ad-9da7-a708e6c91787';
  $pane = new stdClass();
  $pane->pid = 'new-1a94b0c1-4f5c-4dc2-b2c8-85663a0ae403';
  $pane->panel = 'bottom';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_profile_research';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Area of Research',
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
  $pane->uuid = '1a94b0c1-4f5c-4dc2-b2c8-85663a0ae403';
  $display->content['new-1a94b0c1-4f5c-4dc2-b2c8-85663a0ae403'] = $pane;
  $display->panels['bottom'][2] = 'new-1a94b0c1-4f5c-4dc2-b2c8-85663a0ae403';
  $pane = new stdClass();
  $pane->pid = 'new-89d0de72-d1b6-4cee-998a-e07f5e4221b7';
  $pane->panel = 'bottom';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_profile_attachments';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Relevant Files',
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
  $pane->uuid = '89d0de72-d1b6-4cee-998a-e07f5e4221b7';
  $display->content['new-89d0de72-d1b6-4cee-998a-e07f5e4221b7'] = $pane;
  $display->panels['bottom'][3] = 'new-89d0de72-d1b6-4cee-998a-e07f5e4221b7';
  $pane = new stdClass();
  $pane->pid = 'new-f8dad7e8-c9b7-4545-9c90-861fc4c517bd';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_profile_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'large',
      'image_link' => '',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f8dad7e8-c9b7-4545-9c90-861fc4c517bd';
  $display->content['new-f8dad7e8-c9b7-4545-9c90-861fc4c517bd'] = $pane;
  $display->panels['left'][0] = 'new-f8dad7e8-c9b7-4545-9c90-861fc4c517bd';
  $pane = new stdClass();
  $pane->pid = 'new-5aa692d9-516f-45c8-b067-8f338504cdad';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5aa692d9-516f-45c8-b067-8f338504cdad';
  $display->content['new-5aa692d9-516f-45c8-b067-8f338504cdad'] = $pane;
  $display->panels['middle'][0] = 'new-5aa692d9-516f-45c8-b067-8f338504cdad';
  $pane = new stdClass();
  $pane->pid = 'new-f97a2b20-9f6a-40b9-9c5e-b5107f3e9e91';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'pp4-panel_pane_1';
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
  $pane->uuid = 'f97a2b20-9f6a-40b9-9c5e-b5107f3e9e91';
  $display->content['new-f97a2b20-9f6a-40b9-9c5e-b5107f3e9e91'] = $pane;
  $display->panels['right'][0] = 'new-f97a2b20-9f6a-40b9-9c5e-b5107f3e9e91';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-5aa692d9-516f-45c8-b067-8f338504cdad';
  $handler->conf['display'] = $display;
  $export['node_view__profile'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_profile_layouts_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'people';
  $page->task = 'page';
  $page->admin_title = 'People';
  $page->admin_description = '';
  $page->path = 'people';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'People',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_people__panel_context_a657cdcf-2b11-467a-9d67-570a00d33602';
  $handler->task = 'page';
  $handler->subtask = 'people';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
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
    'top' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8db0f571-e639-4b01-aa37-30739bdf06dc';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_people__panel_context_a657cdcf-2b11-467a-9d67-570a00d33602';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a82b921d-c065-4936-9723-924e8c06e63a';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'pp1-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'more_link' => 0,
    'more_text' => '',
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '10',
    'arguments' => array(
      'field_profile_category_tid' => '',
    ),
    'override_title' => 1,
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
  $pane->uuid = 'a82b921d-c065-4936-9723-924e8c06e63a';
  $display->content['new-a82b921d-c065-4936-9723-924e8c06e63a'] = $pane;
  $display->panels['left'][0] = 'new-a82b921d-c065-4936-9723-924e8c06e63a';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-a82b921d-c065-4936-9723-924e8c06e63a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['people'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'people_grid';
  $page->task = 'page';
  $page->admin_title = '';
  $page->admin_description = '';
  $page->path = 'people/faces/!tid';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'tid' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          18 => 0,
          2 => 0,
          7 => 0,
          5 => 0,
          6 => 0,
          4 => 0,
          8 => 0,
          3 => 0,
          9 => 0,
          10 => 0,
          11 => 0,
          12 => 0,
          13 => 0,
          14 => 0,
          16 => 0,
          17 => 0,
          15 => 0,
          19 => 0,
          20 => 0,
          21 => 0,
          22 => 0,
          23 => 0,
          24 => 0,
          25 => 0,
          26 => 0,
          1 => 0,
        ),
        'breadcrumb' => 0,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_people_grid__panel_context_fb039883-9b1b-496a-a578-305c1605c5e7';
  $handler->task = 'page';
  $handler->subtask = 'people_grid';
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
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'top' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'middle' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '504d9d54-78e5-4dce-b70c-d4a386fbef23';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_people_grid__panel_context_fb039883-9b1b-496a-a578-305c1605c5e7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9383541a-4fb0-4c9f-bc5e-83d217484268';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'pp1b-panel_pane_1';
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
  $pane->uuid = '9383541a-4fb0-4c9f-bc5e-83d217484268';
  $display->content['new-9383541a-4fb0-4c9f-bc5e-83d217484268'] = $pane;
  $display->panels['middle'][0] = 'new-9383541a-4fb0-4c9f-bc5e-83d217484268';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9383541a-4fb0-4c9f-bc5e-83d217484268';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['people_grid'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'people_related';
  $page->task = 'page';
  $page->admin_title = 'People Related';
  $page->admin_description = '';
  $page->path = 'people/tag/!tag';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'People',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'tag' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_people_related__panel_context_22baaa16-e69e-48ce-94f3-565df2814082';
  $handler->task = 'page';
  $handler->subtask = 'people_related';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
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
    'top' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8db0f571-e639-4b01-aa37-30739bdf06dc';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_people_related__panel_context_22baaa16-e69e-48ce-94f3-565df2814082';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3b47161d-3403-4b60-8c62-70cbb3ec9416';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'pp5-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'more_link' => 0,
    'more_text' => '',
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '10',
    'arguments' => array(
      'field_profile_category_tid' => '',
    ),
    'override_title' => 1,
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
  $pane->uuid = '3b47161d-3403-4b60-8c62-70cbb3ec9416';
  $display->content['new-3b47161d-3403-4b60-8c62-70cbb3ec9416'] = $pane;
  $display->panels['left'][0] = 'new-3b47161d-3403-4b60-8c62-70cbb3ec9416';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-3b47161d-3403-4b60-8c62-70cbb3ec9416';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['people_related'] = $page;

  return $pages;

}
