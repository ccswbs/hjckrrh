<?php
/**
 * @file
 * ug_front.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_front_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front';
  $page->task = 'page';
  $page->admin_title = 'Front';
  $page->admin_description = '';
  $page->path = 'front';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'weight' => '0',
    'name' => 'navigation',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
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
  $handler->name = 'page_front__front';
  $handler->task = 'page';
  $handler->subtask = 'front';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Front',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'front',
  );
  $display = new panels_display();
  $display->layout = 'ug_1_1_1';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0f9fa8ae-f049-4c30-9250-10f3a41fc487';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1027894c-128f-4486-91a4-842f5ca7d3be';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'n3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1027894c-128f-4486-91a4-842f5ca7d3be';
    $display->content['new-1027894c-128f-4486-91a4-842f5ca7d3be'] = $pane;
    $display->panels['left'][0] = 'new-1027894c-128f-4486-91a4-842f5ca7d3be';
    $pane = new stdClass();
    $pane->pid = 'new-f0112557-96cd-4dc5-9f33-fc9e400f6a03';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'events';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
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
    $pane->uuid = 'f0112557-96cd-4dc5-9f33-fc9e400f6a03';
    $display->content['new-f0112557-96cd-4dc5-9f33-fc9e400f6a03'] = $pane;
    $display->panels['middle'][0] = 'new-f0112557-96cd-4dc5-9f33-fc9e400f6a03';
    $pane = new stdClass();
    $pane->pid = 'new-14548eac-b77f-4749-84cd-eac4e05d7602';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'podcast';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '14548eac-b77f-4749-84cd-eac4e05d7602';
    $display->content['new-14548eac-b77f-4749-84cd-eac4e05d7602'] = $pane;
    $display->panels['right'][0] = 'new-14548eac-b77f-4749-84cd-eac4e05d7602';
    $pane = new stdClass();
    $pane->pid = 'new-7acb0db1-bbbd-4db3-9a6a-980ca994685e';
    $pane->panel = 'top';
    $pane->type = 'views';
    $pane->subtype = 'feature';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '4',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
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
    $pane->uuid = '7acb0db1-bbbd-4db3-9a6a-980ca994685e';
    $display->content['new-7acb0db1-bbbd-4db3-9a6a-980ca994685e'] = $pane;
    $display->panels['top'][0] = 'new-7acb0db1-bbbd-4db3-9a6a-980ca994685e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-7acb0db1-bbbd-4db3-9a6a-980ca994685e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  return $pages;

}
