<?php
/**
 * @file
 * ug_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ug_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
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
  $display->title = '%node:title';
  $display->uuid = 'd22f0d0f-7831-47b5-bb27-cf5f94617b3b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b9cea767-eff7-42fe-9845-bce3e3830863';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'pg1-panel_pane_1';
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
    $pane->uuid = 'b9cea767-eff7-42fe-9845-bce3e3830863';
    $display->content['new-b9cea767-eff7-42fe-9845-bce3e3830863'] = $pane;
    $display->panels['left'][0] = 'new-b9cea767-eff7-42fe-9845-bce3e3830863';
    $pane = new stdClass();
    $pane->pid = 'new-94e8fb6f-785f-437c-9cc4-e1050c918f84';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 's1-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '94e8fb6f-785f-437c-9cc4-e1050c918f84';
    $display->content['new-94e8fb6f-785f-437c-9cc4-e1050c918f84'] = $pane;
    $display->panels['right'][0] = 'new-94e8fb6f-785f-437c-9cc4-e1050c918f84';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b9cea767-eff7-42fe-9845-bce3e3830863';
  $handler->conf['display'] = $display;
  $export['node_view__page'] = $handler;

  return $export;
}
