<?php
/**
 * @file
 * ug_faq.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_faq_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'faq';
  $page->task = 'page';
  $page->admin_title = 'FAQ';
  $page->admin_description = '';
  $page->path = 'faq';
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
  $handler->name = 'page_faq__panel_context_0713fb5d-c16e-4e21-95ed-7ca4c8093473';
  $handler->task = 'page';
  $handler->subtask = 'faq';
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
      'default' => NULL,
      'top' => NULL,
      'left' => array(
        'column_type' => 'col-lg',
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
  );
  $display->cache = array();
  $display->title = 'Frequently Asked Questions';
  $display->uuid = 'da7c3324-cb38-431c-a92d-699e7fe619e6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d0294c34-5bf1-4089-b3d3-5119b803afb1';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'f1-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'List of Frequently Asked Questions',
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
    $pane->uuid = 'd0294c34-5bf1-4089-b3d3-5119b803afb1';
    $display->content['new-d0294c34-5bf1-4089-b3d3-5119b803afb1'] = $pane;
    $display->panels['left'][0] = 'new-d0294c34-5bf1-4089-b3d3-5119b803afb1';
    $pane = new stdClass();
    $pane->pid = 'new-49c6ceb5-97dc-42e3-8f9b-3a21b7b9ec06';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'f2-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Answers to Frequently Asked Questions',
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
    $pane->uuid = '49c6ceb5-97dc-42e3-8f9b-3a21b7b9ec06';
    $display->content['new-49c6ceb5-97dc-42e3-8f9b-3a21b7b9ec06'] = $pane;
    $display->panels['left'][1] = 'new-49c6ceb5-97dc-42e3-8f9b-3a21b7b9ec06';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d0294c34-5bf1-4089-b3d3-5119b803afb1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faq'] = $page;

  return $pages;

}
