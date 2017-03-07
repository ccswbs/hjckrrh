<?php
/**
 * @file
 * ug_tags.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_tags_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'keyword_search';
  $page->task = 'page';
  $page->admin_title = 'Keyword search';
  $page->admin_description = '';
  $page->path = 'tags/!tid';
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
          1 => '1',
          2 => 0,
          3 => 0,
          7 => 0,
          8 => 0,
          4 => 0,
          5 => 0,
          9 => 0,
          10 => 0,
          11 => 0,
          12 => 0,
          13 => 0,
          6 => 0,
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
  $handler->name = 'page_keyword_search__panel_context_9c0e7db9-4cbe-4f30-97dc-94f886398b7d';
  $handler->task = 'page';
  $handler->subtask = 'keyword_search';
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
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'middle' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2d0e7c3a-3ee2-4a92-8abc-aed5e7c870c2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c8abc21d-e528-4f81-bf53-e82ce60c02ef';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'keyword_search_results-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'c8abc21d-e528-4f81-bf53-e82ce60c02ef';
    $display->content['new-c8abc21d-e528-4f81-bf53-e82ce60c02ef'] = $pane;
    $display->panels['middle'][0] = 'new-c8abc21d-e528-4f81-bf53-e82ce60c02ef';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-c8abc21d-e528-4f81-bf53-e82ce60c02ef';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['keyword_search'] = $page;

  return $pages;

}
