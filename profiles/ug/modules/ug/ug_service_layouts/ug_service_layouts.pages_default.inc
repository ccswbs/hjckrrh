<?php
/**
 * @file
 * ug_service_layouts.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ug_service_layouts_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__service';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Service',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'detail-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'service',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'service' => 'service',
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
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '0',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
      'middle' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '3',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '1',
      ),
      'bottom' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'c39ec56c-364b-420b-bb40-7eefc8f8444b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__service';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-072680c6-4786-409d-aa9c-5ac699134b1c';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_service_description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '600',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '072680c6-4786-409d-aa9c-5ac699134b1c';
  $display->content['new-072680c6-4786-409d-aa9c-5ac699134b1c'] = $pane;
  $display->panels['middle'][0] = 'new-072680c6-4786-409d-aa9c-5ac699134b1c';
  $pane = new stdClass();
  $pane->pid = 'new-2f2bbe99-1e69-4c46-b642-7cacfd5f58fd';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_service_price';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '2f2bbe99-1e69-4c46-b642-7cacfd5f58fd';
  $display->content['new-2f2bbe99-1e69-4c46-b642-7cacfd5f58fd'] = $pane;
  $display->panels['middle'][1] = 'new-2f2bbe99-1e69-4c46-b642-7cacfd5f58fd';
  $pane = new stdClass();
  $pane->pid = 'new-95b3fc1e-12df-4d72-be6f-2ceab3d32758';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'sr2-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '95b3fc1e-12df-4d72-be6f-2ceab3d32758';
  $display->content['new-95b3fc1e-12df-4d72-be6f-2ceab3d32758'] = $pane;
  $display->panels['middle'][2] = 'new-95b3fc1e-12df-4d72-be6f-2ceab3d32758';
  $pane = new stdClass();
  $pane->pid = 'new-c21e40a7-cea2-4fe9-bbca-b7c4f7c09d9b';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_service_related';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Related Services',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'c21e40a7-cea2-4fe9-bbca-b7c4f7c09d9b';
  $display->content['new-c21e40a7-cea2-4fe9-bbca-b7c4f7c09d9b'] = $pane;
  $display->panels['middle'][3] = 'new-c21e40a7-cea2-4fe9-bbca-b7c4f7c09d9b';
  $pane = new stdClass();
  $pane->pid = 'new-57a599f7-be4e-452e-b2ee-b7b518f6446e';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_service_private';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view field_service_private',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'field_collection_fields',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'edit' => 'Edit',
      'delete' => 'Delete',
      'add' => 'Add',
      'description' => 1,
      'view_mode' => 'full',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '57a599f7-be4e-452e-b2ee-b7b518f6446e';
  $display->content['new-57a599f7-be4e-452e-b2ee-b7b518f6446e'] = $pane;
  $display->panels['middle'][4] = 'new-57a599f7-be4e-452e-b2ee-b7b518f6446e';
  $pane = new stdClass();
  $pane->pid = 'new-23f4cf45-fd3a-462d-bcf0-15ed76eae732';
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
  $pane->uuid = '23f4cf45-fd3a-462d-bcf0-15ed76eae732';
  $display->content['new-23f4cf45-fd3a-462d-bcf0-15ed76eae732'] = $pane;
  $display->panels['right'][0] = 'new-23f4cf45-fd3a-462d-bcf0-15ed76eae732';
  $pane = new stdClass();
  $pane->pid = 'new-5825d927-013f-441b-b72c-34f20d4b143b';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'service_keywords-panel_pane_1';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5825d927-013f-441b-b72c-34f20d4b143b';
  $display->content['new-5825d927-013f-441b-b72c-34f20d4b143b'] = $pane;
  $display->panels['right'][1] = 'new-5825d927-013f-441b-b72c-34f20d4b143b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__service'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_service_layouts_default_page_manager_pages() {
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
    'title' => 'Services by Category',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Services',
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
  $handler->name = 'page_services__panel_context_15805d9d-902d-4bea-abcd-a2a5f379f9bb';
  $handler->task = 'page';
  $handler->subtask = 'services';
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_services__panel_context_15805d9d-902d-4bea-abcd-a2a5f379f9bb';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-34f48c4a-d691-473d-bd0f-5579e017c2bd';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'sr1-panel_pane_1';
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
  $pane->uuid = '34f48c4a-d691-473d-bd0f-5579e017c2bd';
  $display->content['new-34f48c4a-d691-473d-bd0f-5579e017c2bd'] = $pane;
  $display->panels['middle'][0] = 'new-34f48c4a-d691-473d-bd0f-5579e017c2bd';
  $display->hide_title = PANELS_TITLE_PANE;
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
    'title' => 'Services by Audience',
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_services_audience__panel_context_a0651967-02cb-44dd-ac8f-83a6d0d23cb3';
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
  $pane->uuid = 'f7d9ef6e-5ee6-45c9-9809-181f91082217';
  $display->content['new-f7d9ef6e-5ee6-45c9-9809-181f91082217'] = $pane;
  $display->panels['middle'][0] = 'new-f7d9ef6e-5ee6-45c9-9809-181f91082217';
  $display->hide_title = PANELS_TITLE_PANE;
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_services_az__panel_context_71bfa60b-fe91-4ed6-924c-587588bafd64';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fc1e1050-bbd6-4a09-aa77-8dfefeee9d46';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'sr3-panel_pane_2';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a3e2cfe8-5f83-4092-bc01-04f45fb42bd6';
  $display->content['new-a3e2cfe8-5f83-4092-bc01-04f45fb42bd6'] = $pane;
  $display->panels['middle'][1] = 'new-a3e2cfe8-5f83-4092-bc01-04f45fb42bd6';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-fc1e1050-bbd6-4a09-aa77-8dfefeee9d46';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['services_az'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'services_by_keyword';
  $page->task = 'page';
  $page->admin_title = 'Services by keyword';
  $page->admin_description = '';
  $page->path = 'services/tags/!tid';
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
          11 => '11',
          2 => 0,
          3 => 0,
          7 => 0,
          8 => 0,
          4 => 0,
          5 => 0,
          9 => 0,
          10 => 0,
          12 => 0,
          13 => 0,
          6 => 0,
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
  $handler->name = 'page_services_by_keyword__panel_context_a820d8b2-feec-432e-85d6-2ce5652dbb21';
  $handler->task = 'page';
  $handler->subtask = 'services_by_keyword';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
      'default' => NULL,
      'top' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '0',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
      'middle' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '3',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '1',
      ),
      'bottom' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a0498d57-30f3-4a81-84ef-d482fbc07633';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_services_by_keyword__panel_context_a820d8b2-feec-432e-85d6-2ce5652dbb21';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-23a6efb5-4533-4dea-9e42-04efffac5d03';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'services_keyword-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'fields_override' => array(
      'title' => 1,
      'field_service_description' => 1,
    ),
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
  $pane->uuid = '23a6efb5-4533-4dea-9e42-04efffac5d03';
  $display->content['new-23a6efb5-4533-4dea-9e42-04efffac5d03'] = $pane;
  $display->panels['middle'][0] = 'new-23a6efb5-4533-4dea-9e42-04efffac5d03';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-23a6efb5-4533-4dea-9e42-04efffac5d03';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['services_by_keyword'] = $page;

  return $pages;

}
