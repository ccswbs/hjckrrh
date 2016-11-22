<?php
/**
 * @file
 * ug_news_layouts.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ug_news_layouts_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__news';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'News',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'detail-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'news',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'news' => 'news',
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
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '0f98c601-13f0-4d54-8f36-87b06be6b7c3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-54849362-b8d6-4306-b99a-c11a0e4d0e80';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'n2ab-panel_pane_1';
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
    $pane->uuid = '54849362-b8d6-4306-b99a-c11a0e4d0e80';
    $display->content['new-54849362-b8d6-4306-b99a-c11a0e4d0e80'] = $pane;
    $display->panels['middle'][0] = 'new-54849362-b8d6-4306-b99a-c11a0e4d0e80';
    $pane = new stdClass();
    $pane->pid = 'new-f8c35af1-c486-4fc9-ad1f-050e19f863df';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'news_image-panel_pane_1';
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
    $pane->uuid = 'f8c35af1-c486-4fc9-ad1f-050e19f863df';
    $display->content['new-f8c35af1-c486-4fc9-ad1f-050e19f863df'] = $pane;
    $display->panels['middle'][1] = 'new-f8c35af1-c486-4fc9-ad1f-050e19f863df';
    $pane = new stdClass();
    $pane->pid = 'new-44a2c678-3480-4fb2-a66d-913f4f82c626';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_news_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '44a2c678-3480-4fb2-a66d-913f4f82c626';
    $display->content['new-44a2c678-3480-4fb2-a66d-913f4f82c626'] = $pane;
    $display->panels['middle'][2] = 'new-44a2c678-3480-4fb2-a66d-913f4f82c626';
    $pane = new stdClass();
    $pane->pid = 'new-ca11576b-5ec6-4ef0-880b-c19f08cf846a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_news_attachment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_table',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'File Attachments',
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
    $pane->uuid = 'ca11576b-5ec6-4ef0-880b-c19f08cf846a';
    $display->content['new-ca11576b-5ec6-4ef0-880b-c19f08cf846a'] = $pane;
    $display->panels['middle'][3] = 'new-ca11576b-5ec6-4ef0-880b-c19f08cf846a';
    $pane = new stdClass();
    $pane->pid = 'new-7a7badc9-4f28-4430-b81a-66538d9be30b';
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
    $pane->uuid = '7a7badc9-4f28-4430-b81a-66538d9be30b';
    $display->content['new-7a7badc9-4f28-4430-b81a-66538d9be30b'] = $pane;
    $display->panels['right'][0] = 'new-7a7badc9-4f28-4430-b81a-66538d9be30b';
    $pane = new stdClass();
    $pane->pid = 'new-d40c27a3-4e25-4684-90b9-00fc3f700ee4';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'n7-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Find related news by keyword',
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
    $pane->uuid = 'd40c27a3-4e25-4684-90b9-00fc3f700ee4';
    $display->content['new-d40c27a3-4e25-4684-90b9-00fc3f700ee4'] = $pane;
    $display->panels['right'][1] = 'new-d40c27a3-4e25-4684-90b9-00fc3f700ee4';
    $pane = new stdClass();
    $pane->pid = 'new-acc5000e-a7bf-4b66-a95f-b7eb867ab449';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'acc5000e-a7bf-4b66-a95f-b7eb867ab449';
    $display->content['new-acc5000e-a7bf-4b66-a95f-b7eb867ab449'] = $pane;
    $display->panels['right'][2] = 'new-acc5000e-a7bf-4b66-a95f-b7eb867ab449';
    $pane = new stdClass();
    $pane->pid = 'new-69530c85-8f11-4d68-a82e-33dc3537de3c';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'n6_cat-panel_pane_1';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '69530c85-8f11-4d68-a82e-33dc3537de3c';
    $display->content['new-69530c85-8f11-4d68-a82e-33dc3537de3c'] = $pane;
    $display->panels['right'][3] = 'new-69530c85-8f11-4d68-a82e-33dc3537de3c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__news'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_news_layouts_default_page_manager_pages() {
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
  $handler->weight = 1;
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
      'middle' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = 'News';
  $display->uuid = 'b823df8a-0169-451b-b489-67c86a42562b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-50d3147c-e941-4c82-8f90-2e6710a3f20a';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'n1-panel_pane_1';
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
    $pane->uuid = '50d3147c-e941-4c82-8f90-2e6710a3f20a';
    $display->content['new-50d3147c-e941-4c82-8f90-2e6710a3f20a'] = $pane;
    $display->panels['middle'][0] = 'new-50d3147c-e941-4c82-8f90-2e6710a3f20a';
    $pane = new stdClass();
    $pane->pid = 'new-43d491ad-a040-49fc-b41d-d253d0cc8443';
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
    $pane->uuid = '43d491ad-a040-49fc-b41d-d253d0cc8443';
    $display->content['new-43d491ad-a040-49fc-b41d-d253d0cc8443'] = $pane;
    $display->panels['right'][0] = 'new-43d491ad-a040-49fc-b41d-d253d0cc8443';
    $pane = new stdClass();
    $pane->pid = 'new-b290ee67-641f-426d-9c2e-31c467d18148';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'n6_cat-panel_pane_1';
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
    $pane->uuid = 'b290ee67-641f-426d-9c2e-31c467d18148';
    $display->content['new-b290ee67-641f-426d-9c2e-31c467d18148'] = $pane;
    $display->panels['right'][1] = 'new-b290ee67-641f-426d-9c2e-31c467d18148';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-50d3147c-e941-4c82-8f90-2e6710a3f20a';
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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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
  $handler->name = 'page_news_archive__panel_context_2d9714e4-347b-4ded-b4f3-7dc98b40f27e';
  $handler->task = 'page';
  $handler->subtask = 'news_archive';
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
      'middle' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
    'middle' => array(
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
    $pane->panel = 'middle';
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
    $display->panels['middle'][0] = 'new-c47d59a7-8dfa-4969-91b0-5e48b33f43b1';
    $pane = new stdClass();
    $pane->pid = 'new-9ead9b06-2e57-4c8d-818b-408c876b540f';
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
    $pane->uuid = '9ead9b06-2e57-4c8d-818b-408c876b540f';
    $display->content['new-9ead9b06-2e57-4c8d-818b-408c876b540f'] = $pane;
    $display->panels['right'][0] = 'new-9ead9b06-2e57-4c8d-818b-408c876b540f';
    $pane = new stdClass();
    $pane->pid = 'new-a02e831c-b40c-41f1-accd-e1e8eb4f4334';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'n6_cat-panel_pane_1';
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
    $pane->uuid = 'a02e831c-b40c-41f1-accd-e1e8eb4f4334';
    $display->content['new-a02e831c-b40c-41f1-accd-e1e8eb4f4334'] = $pane;
    $display->panels['right'][1] = 'new-a02e831c-b40c-41f1-accd-e1e8eb4f4334';
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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'category' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          4 => 0,
          2 => 0,
          3 => 0,
          8 => 0,
          9 => 0,
          5 => 0,
          6 => 0,
          10 => 0,
          11 => 0,
          12 => 0,
          13 => 0,
          14 => 0,
          7 => 0,
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
  $handler->name = 'page_news_category__panel_context_6d7b55e2-d899-4ce1-9cb6-7835efbdd4e1';
  $handler->task = 'page';
  $handler->subtask = 'news_category';
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
      'middle' => array(
        'column_type' => 'col-sm',
        'column_size' => '8',
        'offset_type' => 'col-sm-offset',
        'offset_size' => '0',
      ),
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = 'News';
  $display->uuid = '44c1c8d1-d8fe-40f0-89f0-ffbd4e9a68a2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e521219a-590e-4275-98f3-96d126f5fffa';
    $pane->panel = 'middle';
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
    $display->panels['middle'][0] = 'new-e521219a-590e-4275-98f3-96d126f5fffa';
    $pane = new stdClass();
    $pane->pid = 'new-68a43b6c-8b3c-40ad-a9fd-c2180d1b2121';
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
    $pane->uuid = '68a43b6c-8b3c-40ad-a9fd-c2180d1b2121';
    $display->content['new-68a43b6c-8b3c-40ad-a9fd-c2180d1b2121'] = $pane;
    $display->panels['right'][0] = 'new-68a43b6c-8b3c-40ad-a9fd-c2180d1b2121';
    $pane = new stdClass();
    $pane->pid = 'new-b397e46f-65f4-4a11-81c8-6a4f08c9c0a4';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'n6_cat-panel_pane_1';
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
    $pane->uuid = 'b397e46f-65f4-4a11-81c8-6a4f08c9c0a4';
    $display->content['new-b397e46f-65f4-4a11-81c8-6a4f08c9c0a4'] = $pane;
    $display->panels['right'][1] = 'new-b397e46f-65f4-4a11-81c8-6a4f08c9c0a4';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-e521219a-590e-4275-98f3-96d126f5fffa';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_category'] = $page;

  return $pages;

}
