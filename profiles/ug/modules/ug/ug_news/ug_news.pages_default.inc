<?php
/**
 * @file
 * ug_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news';
  $page->task = 'page';
  $page->admin_title = 'News';
  $page->admin_description = '';
  $page->path = 'news/!tags';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'News',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'tags' => array(
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
  $handler->name = 'page_news__news';
  $handler->task = 'page';
  $handler->subtask = 'news';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'News',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'news',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
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
  $display->uuid = 'b823df8a-0169-451b-b489-67c86a42562b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8e2840cf-be7c-4347-88b0-afda8331e80c';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'n1';
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
    $pane->uuid = '8e2840cf-be7c-4347-88b0-afda8331e80c';
    $display->content['new-8e2840cf-be7c-4347-88b0-afda8331e80c'] = $pane;
    $display->panels['left'][0] = 'new-8e2840cf-be7c-4347-88b0-afda8331e80c';
    $pane = new stdClass();
    $pane->pid = 'new-a51af7f6-9dcd-4dca-ae62-544d1fc6d66f';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'news_filter_date-panel_pane_1';
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
    $pane->uuid = 'a51af7f6-9dcd-4dca-ae62-544d1fc6d66f';
    $display->content['new-a51af7f6-9dcd-4dca-ae62-544d1fc6d66f'] = $pane;
    $display->panels['right'][0] = 'new-a51af7f6-9dcd-4dca-ae62-544d1fc6d66f';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-8e2840cf-be7c-4347-88b0-afda8331e80c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_archive';
  $page->task = 'page';
  $page->admin_title = 'News archive';
  $page->admin_description = '';
  $page->path = 'news/archive/%date';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'date' => array(
      'id' => 1,
      'identifier' => 'Date',
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
  $handler->name = 'page_news_archive__panel_context_d2956ac9-06ee-48fa-8844-dc52d7db005a';
  $handler->task = 'page';
  $handler->subtask = 'news_archive';
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
  $display->title = '';
  $display->uuid = '44c1c8d1-d8fe-40f0-89f0-ffbd4e9a68a2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c47d59a7-8dfa-4969-91b0-5e48b33f43b1';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'n1-panel_pane_3';
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
    $pane->uuid = 'c47d59a7-8dfa-4969-91b0-5e48b33f43b1';
    $display->content['new-c47d59a7-8dfa-4969-91b0-5e48b33f43b1'] = $pane;
    $display->panels['left'][0] = 'new-c47d59a7-8dfa-4969-91b0-5e48b33f43b1';
    $pane = new stdClass();
    $pane->pid = 'new-d10a4d26-a5f1-4fe6-9fa7-33fb05c50a39';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'news_filter_date-panel_pane_1';
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
    $pane->uuid = 'd10a4d26-a5f1-4fe6-9fa7-33fb05c50a39';
    $display->content['new-d10a4d26-a5f1-4fe6-9fa7-33fb05c50a39'] = $pane;
    $display->panels['right'][0] = 'new-d10a4d26-a5f1-4fe6-9fa7-33fb05c50a39';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-c47d59a7-8dfa-4969-91b0-5e48b33f43b1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_archive'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_category';
  $page->task = 'page';
  $page->admin_title = 'News category';
  $page->admin_description = '';
  $page->path = 'news/category/%category';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'category' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          3 => '3',
          2 => 0,
          6 => 0,
          4 => 0,
          5 => 0,
          1 => 0,
        ),
        'breadcrumb' => 1,
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
  $handler->name = 'page_news_category__panel_context_44478c82-da24-49e9-a7ad-77dcf951b91c';
  $handler->task = 'page';
  $handler->subtask = 'news_category';
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
        'column_type' => 'col-sm',
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
  $display->title = '';
  $display->uuid = '44c1c8d1-d8fe-40f0-89f0-ffbd4e9a68a2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e521219a-590e-4275-98f3-96d126f5fffa';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'n1-panel_pane_2';
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
    $pane->uuid = 'e521219a-590e-4275-98f3-96d126f5fffa';
    $display->content['new-e521219a-590e-4275-98f3-96d126f5fffa'] = $pane;
    $display->panels['left'][0] = 'new-e521219a-590e-4275-98f3-96d126f5fffa';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-e521219a-590e-4275-98f3-96d126f5fffa';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_category'] = $page;

  return $pages;

}
