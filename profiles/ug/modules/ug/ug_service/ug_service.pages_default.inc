<?php
/**
 * @file
 * ug_service.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_service_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'services';
  $page->task = 'page';
  $page->admin_title = 'Services';
  $page->admin_description = '';
  $page->path = 'services/categories';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Service Categories',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Services',
      'name' => 'main-menu',
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
  $handler->name = 'page_services__panel_context_15805d9d-902d-4bea-abcd-a2a5f379f9bb';
  $handler->task = 'page';
  $handler->subtask = 'services';
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
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'middle' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => NULL,
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = 'Services';
  $display->uuid = '02e5baf3-b1f9-4177-bca0-f01fcb5c1524';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-34f48c4a-d691-473d-bd0f-5579e017c2bd';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'sr1-panel_pane_1';
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
    $pane->uuid = '34f48c4a-d691-473d-bd0f-5579e017c2bd';
    $display->content['new-34f48c4a-d691-473d-bd0f-5579e017c2bd'] = $pane;
    $display->panels['middle'][0] = 'new-34f48c4a-d691-473d-bd0f-5579e017c2bd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-34f48c4a-d691-473d-bd0f-5579e017c2bd';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['services'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'services_audience';
  $page->task = 'page';
  $page->admin_title = 'Services by audience';
  $page->admin_description = '';
  $page->path = 'services/audience';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Services by audience',
    'name' => 'navigation',
    'weight' => '20',
    'parent' => array(
      'type' => 'none',
      'title' => '',
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
  $handler->name = 'page_services_audience__panel_context_a0651967-02cb-44dd-ac8f-83a6d0d23cb3';
  $handler->task = 'page';
  $handler->subtask = 'services_audience';
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
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'middle' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => NULL,
      'bottom' => NULL,
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = 'Services';
  $display->uuid = '73381138-0fa8-4e07-bd4c-cf9b4e753558';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f7d9ef6e-5ee6-45c9-9809-181f91082217';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'sr4-panel_pane_1';
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
    $pane->uuid = 'f7d9ef6e-5ee6-45c9-9809-181f91082217';
    $display->content['new-f7d9ef6e-5ee6-45c9-9809-181f91082217'] = $pane;
    $display->panels['middle'][0] = 'new-f7d9ef6e-5ee6-45c9-9809-181f91082217';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f7d9ef6e-5ee6-45c9-9809-181f91082217';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['services_audience'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'services_az';
  $page->task = 'page';
  $page->admin_title = 'Services alphabetical';
  $page->admin_description = '';
  $page->path = 'services/alphabetical/!a';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'All Services (A-Z)',
    'name' => 'navigation',
    'weight' => '10',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Services',
      'name' => 'main-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'a' => array(
      'settings' => array(),
      'identifier' => 'No context',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_services_az__panel_context_71bfa60b-fe91-4ed6-924c-587588bafd64';
  $handler->task = 'page';
  $handler->subtask = 'services_az';
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
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'middle' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => NULL,
      'bottom' => NULL,
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = 'Services';
  $display->uuid = '855ddf73-df27-405b-93fd-a747a73a09f7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fc1e1050-bbd6-4a09-aa77-8dfefeee9d46';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'sr3-panel_pane_2';
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
    $pane->uuid = 'fc1e1050-bbd6-4a09-aa77-8dfefeee9d46';
    $display->content['new-fc1e1050-bbd6-4a09-aa77-8dfefeee9d46'] = $pane;
    $display->panels['middle'][0] = 'new-fc1e1050-bbd6-4a09-aa77-8dfefeee9d46';
    $pane = new stdClass();
    $pane->pid = 'new-a3e2cfe8-5f83-4092-bc01-04f45fb42bd6';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'sr3-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a3e2cfe8-5f83-4092-bc01-04f45fb42bd6';
    $display->content['new-a3e2cfe8-5f83-4092-bc01-04f45fb42bd6'] = $pane;
    $display->panels['middle'][1] = 'new-a3e2cfe8-5f83-4092-bc01-04f45fb42bd6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a3e2cfe8-5f83-4092-bc01-04f45fb42bd6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['services_az'] = $page;

  return $pages;

}