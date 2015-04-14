<?php
/**
 * @file
 * ug_event.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_event_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'events';
  $page->task = 'page';
  $page->admin_title = 'Upcoming Events';
  $page->admin_description = '';
  $page->path = 'events/upcoming';
  $page->access = array();
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Upcoming Events',
    'name' => 'navigation',
    'weight' => '-1',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Events Calendar',
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
  $handler->name = 'page_events__panel_context_e04e5a91-fd0c-4a59-a29c-622261beafc5';
  $handler->task = 'page';
  $handler->subtask = 'events';
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
  $display->title = 'Events Calendar';
  $display->uuid = 'b3915726-f6fc-4665-96df-a222ba62410e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bf20e585-a1a2-4550-b30a-c76e16eada78';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'e1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 1,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
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
    $pane->uuid = 'bf20e585-a1a2-4550-b30a-c76e16eada78';
    $display->content['new-bf20e585-a1a2-4550-b30a-c76e16eada78'] = $pane;
    $display->panels['left'][0] = 'new-bf20e585-a1a2-4550-b30a-c76e16eada78';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bf20e585-a1a2-4550-b30a-c76e16eada78';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['events'] = $page;

  return $pages;

}
