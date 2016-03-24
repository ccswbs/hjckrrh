<?php
/**
 * @file
 * ug_book_layouts.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ug_book_layouts_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__book';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -22;
  $handler->conf = array(
    'title' => 'Book',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'book',
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'book' => 'book',
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
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0e2992e5-b445-4ed7-a737-336913f6f061';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-55b65063-7ff5-4cfd-82ed-d6a6652d885d';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
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
    $pane->uuid = '55b65063-7ff5-4cfd-82ed-d6a6652d885d';
    $display->content['new-55b65063-7ff5-4cfd-82ed-d6a6652d885d'] = $pane;
    $display->panels['left'][0] = 'new-55b65063-7ff5-4cfd-82ed-d6a6652d885d';
    $pane = new stdClass();
    $pane->pid = 'new-1b00cc15-6276-4c8d-b9f3-b5f5528fbfeb';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_book_attachments';
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
    $pane->uuid = '1b00cc15-6276-4c8d-b9f3-b5f5528fbfeb';
    $display->content['new-1b00cc15-6276-4c8d-b9f3-b5f5528fbfeb'] = $pane;
    $display->panels['left'][1] = 'new-1b00cc15-6276-4c8d-b9f3-b5f5528fbfeb';
    $pane = new stdClass();
    $pane->pid = 'new-0935e6fd-70e6-453f-9245-c6a823f09241';
    $pane->panel = 'left';
    $pane->type = 'node_book_nav';
    $pane->subtype = 'node_book_nav';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0935e6fd-70e6-453f-9245-c6a823f09241';
    $display->content['new-0935e6fd-70e6-453f-9245-c6a823f09241'] = $pane;
    $display->panels['left'][2] = 'new-0935e6fd-70e6-453f-9245-c6a823f09241';
    $pane = new stdClass();
    $pane->pid = 'new-cc24395a-98ee-44fc-8be6-6a3648f51c19';
    $pane->panel = 'right';
    $pane->type = 'menu_tree';
    $pane->subtype = '_active';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'parent' => '_active:0',
      'title_link' => 0,
      'admin_title' => '',
      'level' => '1',
      'follow' => 0,
      'depth' => '0',
      'depth_relative' => 0,
      'expanded' => 0,
      'sort' => 0,
      'menu_name' => '_active',
      'parent_mlid' => '0',
      'override_title' => 1,
      'override_title_text' => '<none>',
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
    $pane->uuid = 'cc24395a-98ee-44fc-8be6-6a3648f51c19';
    $display->content['new-cc24395a-98ee-44fc-8be6-6a3648f51c19'] = $pane;
    $display->panels['right'][0] = 'new-cc24395a-98ee-44fc-8be6-6a3648f51c19';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__book'] = $handler;

  return $export;
}
