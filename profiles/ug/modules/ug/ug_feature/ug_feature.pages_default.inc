<?php
/**
 * @file
 * ug_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'features';
  $page->task = 'page';
  $page->admin_title = 'Features';
  $page->admin_description = '';
  $page->path = 'features';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_features__panel_context_9a6dccff-22ef-4d28-8ca0-3b99949d5b6a';
  $handler->task = 'page';
  $handler->subtask = 'features';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'middle' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
      'default' => NULL,
      'top' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '0',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '3',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '1',
      ),
      'bottom' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
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
  );
  $display->cache = array();
  $display->title = 'Features';
  $display->uuid = 'b52a242a-20c6-4e57-9050-1019815d41e9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-539ac6b4-fe23-4651-9fc2-4bdb5c5b3f41';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ft2-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '10',
      'arguments' => array(
        'field_feature_category_tid' => '',
      ),
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
    $pane->uuid = '539ac6b4-fe23-4651-9fc2-4bdb5c5b3f41';
    $display->content['new-539ac6b4-fe23-4651-9fc2-4bdb5c5b3f41'] = $pane;
    $display->panels['middle'][0] = 'new-539ac6b4-fe23-4651-9fc2-4bdb5c5b3f41';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-539ac6b4-fe23-4651-9fc2-4bdb5c5b3f41';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['features'] = $page;

  return $pages;

}
