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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'events_archive';
  $page->task = 'page';
  $page->admin_title = 'Events Archive';
  $page->admin_description = '';
  $page->path = 'events/archive/!date';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Past Events',
    'name' => 'navigation',
    'weight' => '3',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'date' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
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
  $handler->name = 'page_events_archive__panel_context_e61344ac-294a-4e95-b5ff-0e1b171d706c';
  $handler->task = 'page';
  $handler->subtask = 'events_archive';
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
  $display->uuid = 'cd94cdf8-3c30-4b67-8a1c-311d50ba1b72';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5ac41dd9-f955-4898-bb56-13d9e8e4ae6c';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'e1-panel_pane_2';
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
    $pane->uuid = '5ac41dd9-f955-4898-bb56-13d9e8e4ae6c';
    $display->content['new-5ac41dd9-f955-4898-bb56-13d9e8e4ae6c'] = $pane;
    $display->panels['left'][0] = 'new-5ac41dd9-f955-4898-bb56-13d9e8e4ae6c';
    $pane = new stdClass();
    $pane->pid = 'new-3a0506a1-e2f1-439c-b858-e2381023bebf';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'e5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
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
    $pane->uuid = '3a0506a1-e2f1-439c-b858-e2381023bebf';
    $display->content['new-3a0506a1-e2f1-439c-b858-e2381023bebf'] = $pane;
    $display->panels['right'][0] = 'new-3a0506a1-e2f1-439c-b858-e2381023bebf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5ac41dd9-f955-4898-bb56-13d9e8e4ae6c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['events_archive'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'events_month';
  $page->task = 'page';
  $page->admin_title = 'Events Month';
  $page->admin_description = '';
  $page->path = 'events/month';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Monthly Calendar',
    'name' => 'navigation',
    'weight' => '2',
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
  $handler->name = 'page_events_month__panel_context_3b8ec598-e6ad-4c23-b26c-4d8add234593';
  $handler->task = 'page';
  $handler->subtask = 'events_month';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '37d444c2-b46b-4924-a45f-04ad351215f1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3024235a-5da0-46b9-987a-25837e55ec19';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'e9';
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
      'display' => 'page_1',
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
    $pane->uuid = '3024235a-5da0-46b9-987a-25837e55ec19';
    $display->content['new-3024235a-5da0-46b9-987a-25837e55ec19'] = $pane;
    $display->panels['middle'][0] = 'new-3024235a-5da0-46b9-987a-25837e55ec19';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['events_month'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'events_past';
  $page->task = 'page';
  $page->admin_title = 'Past events';
  $page->admin_description = '';
  $page->path = 'events/archive/!date';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Past Events',
    'name' => 'navigation',
    'weight' => '3',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'date' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_events_past__panel_context_2bd7fb47-ffb1-41e1-9002-d5ab82bfc853';
  $handler->task = 'page';
  $handler->subtask = 'events_past';
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
  $display->uuid = 'e4f1a925-8485-451f-aba2-4aa737554802';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d9fa10b8-6894-4703-8466-e5f6fdae57e6';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'e1-panel_pane_3';
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
    $pane->uuid = 'd9fa10b8-6894-4703-8466-e5f6fdae57e6';
    $display->content['new-d9fa10b8-6894-4703-8466-e5f6fdae57e6'] = $pane;
    $display->panels['left'][0] = 'new-d9fa10b8-6894-4703-8466-e5f6fdae57e6';
    $pane = new stdClass();
    $pane->pid = 'new-253671cf-b796-4a35-9275-3cfca860bb7c';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'e5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
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
      'override_title' => 1,
      'override_title_text' => 'Event Archives',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '253671cf-b796-4a35-9275-3cfca860bb7c';
    $display->content['new-253671cf-b796-4a35-9275-3cfca860bb7c'] = $pane;
    $display->panels['right'][0] = 'new-253671cf-b796-4a35-9275-3cfca860bb7c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d9fa10b8-6894-4703-8466-e5f6fdae57e6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['events_past'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'events_week';
  $page->task = 'page';
  $page->admin_title = 'Events Week';
  $page->admin_description = '';
  $page->path = 'events/week';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'This Week',
    'name' => 'navigation',
    'weight' => '1',
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
  $handler->name = 'page_events_week__panel_context_dd6ebb91-808b-4692-9fe7-81fc0dc7152c';
  $handler->task = 'page';
  $handler->subtask = 'events_week';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7bf0db93-5d02-4600-98e3-f63d1958f771';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-57d15c4f-5ce8-4eac-bab9-3753dc7f4031';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'e9';
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
      'display' => 'page_2',
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
    $pane->uuid = '57d15c4f-5ce8-4eac-bab9-3753dc7f4031';
    $display->content['new-57d15c4f-5ce8-4eac-bab9-3753dc7f4031'] = $pane;
    $display->panels['middle'][0] = 'new-57d15c4f-5ce8-4eac-bab9-3753dc7f4031';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-57d15c4f-5ce8-4eac-bab9-3753dc7f4031';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['events_week'] = $page;

  return $pages;

}
