<?php
/**
 * @file
 * ug_news_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_news_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_summary';
  $page->task = 'page';
  $page->admin_title = 'News';
  $page->admin_description = '';
  $page->path = 'news';
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
  $handler->name = 'page_news_summary__panel_context_73908e49-5618-4cdc-93b2-012c905d1006';
  $handler->task = 'page';
  $handler->subtask = 'news_summary';
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
  $display->title = 'News';
  $display->uuid = '5cf14e68-600a-407e-8f07-1ef10a2ac77b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-64adacfa-728a-41fe-b1af-e9b9484ce9ef';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'news_summary';
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
    $pane->uuid = '64adacfa-728a-41fe-b1af-e9b9484ce9ef';
    $display->content['new-64adacfa-728a-41fe-b1af-e9b9484ce9ef'] = $pane;
    $display->panels['left'][0] = 'new-64adacfa-728a-41fe-b1af-e9b9484ce9ef';
    $pane = new stdClass();
    $pane->pid = 'new-8553f423-e622-4afa-bff9-ed4bcc8e7e7e';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'news_date_filter';
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
    $pane->uuid = '8553f423-e622-4afa-bff9-ed4bcc8e7e7e';
    $display->content['new-8553f423-e622-4afa-bff9-ed4bcc8e7e7e'] = $pane;
    $display->panels['right'][0] = 'new-8553f423-e622-4afa-bff9-ed4bcc8e7e7e';
    $pane = new stdClass();
    $pane->pid = 'new-11395a7e-fd54-45df-b10a-dcbd6aebf13e';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'news_tags_filter';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '11395a7e-fd54-45df-b10a-dcbd6aebf13e';
    $display->content['new-11395a7e-fd54-45df-b10a-dcbd6aebf13e'] = $pane;
    $display->panels['right'][1] = 'new-11395a7e-fd54-45df-b10a-dcbd6aebf13e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-64adacfa-728a-41fe-b1af-e9b9484ce9ef';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_summary'] = $page;

  return $pages;

}
