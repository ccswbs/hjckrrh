<?php
/**
 * @file
 * ug_profile.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_profile_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'people';
  $page->task = 'page';
  $page->admin_title = 'People';
  $page->admin_description = '';
  $page->path = 'people/!unit';
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
    'unit' => array(
      'id' => 1,
      'identifier' => 'Unit',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          3 => '3',
          5 => 0,
          2 => 0,
          4 => 0,
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
  $handler->name = 'page_people__panel_context_9a810f37-51b2-41b5-a037-fe5df6dcc666';
  $handler->task = 'page';
  $handler->subtask = 'people';
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
  );
  $display = new panels_display();
  $display->layout = 'aside';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Our People';
  $display->uuid = '8db0f571-e639-4b01-aa37-30739bdf06dc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-08bfe71d-5ab9-4091-ad20-3fd998f5f1a7';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'p1-panel_pane_1';
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
    $pane->uuid = '08bfe71d-5ab9-4091-ad20-3fd998f5f1a7';
    $display->content['new-08bfe71d-5ab9-4091-ad20-3fd998f5f1a7'] = $pane;
    $display->panels['left'][0] = 'new-08bfe71d-5ab9-4091-ad20-3fd998f5f1a7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['people'] = $page;

  return $pages;

}
