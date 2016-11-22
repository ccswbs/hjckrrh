<?php
/**
 * @file
 * ug_social.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_social_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'social_directory';
  $page->task = 'page';
  $page->admin_title = 'Social directory';
  $page->admin_description = '';
  $page->path = 'connect';
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
  $handler->name = 'page_social_directory__panel_context_62ee7986-bc72-48c4-ab43-742aa34868d8';
  $handler->task = 'page';
  $handler->subtask = 'social_directory';
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
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'left' => NULL,
    ),
    'left' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = 'Social Media Directory';
  $display->uuid = '8dae6c2f-2c8c-47a6-82e5-42266a434b8f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_social_directory__panel_context_62ee7986-bc72-48c4-ab43-742aa34868d8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1af4557b-e9a6-4181-b14e-0c4af3d63bff';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 's6-panel_pane_1';
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
  $pane->uuid = '1af4557b-e9a6-4181-b14e-0c4af3d63bff';
  $display->content['new-1af4557b-e9a6-4181-b14e-0c4af3d63bff'] = $pane;
  $display->panels['left'][0] = 'new-1af4557b-e9a6-4181-b14e-0c4af3d63bff';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1af4557b-e9a6-4181-b14e-0c4af3d63bff';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['social_directory'] = $page;

  return $pages;

}
