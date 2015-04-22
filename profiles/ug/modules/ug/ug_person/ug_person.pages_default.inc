<?php
/**
 * @file
 * ug_person.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_person_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'people';
  $page->task = 'page';
  $page->admin_title = 'People';
  $page->admin_description = '';
  $page->path = 'people';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_people__panel_context_f7517d83-4212-432d-a204-9cdd2d83171f';
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
  $display->uuid = 'e7d36af6-fb6f-420a-947c-b9bf3e20d23b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-83252d1e-0fc5-45cc-9755-6444d677abfe';
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
    $pane->uuid = '83252d1e-0fc5-45cc-9755-6444d677abfe';
    $display->content['new-83252d1e-0fc5-45cc-9755-6444d677abfe'] = $pane;
    $display->panels['left'][0] = 'new-83252d1e-0fc5-45cc-9755-6444d677abfe';
    $pane = new stdClass();
    $pane->pid = 'new-106e1d02-cf8d-4930-a4da-02c479bbeab7';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-p1-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 0,
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
    $pane->uuid = '106e1d02-cf8d-4930-a4da-02c479bbeab7';
    $display->content['new-106e1d02-cf8d-4930-a4da-02c479bbeab7'] = $pane;
    $display->panels['top'][0] = 'new-106e1d02-cf8d-4930-a4da-02c479bbeab7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-83252d1e-0fc5-45cc-9755-6444d677abfe';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['people'] = $page;

  return $pages;

}
