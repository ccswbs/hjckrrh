<?php
/**
 * @file
 * ug_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ug_news_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__news';
  $handler->task = 'node_view';
  $handler->subtask = '';
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
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
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
  $display->layout = 'detail';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => NULL,
      'middle' => array(
        'column_type' => 'col-lg',
        'column_size' => '6',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '3',
      ),
      'left' => NULL,
      'right' => NULL,
      'centre' => NULL,
    ),
    'left' => array(
      'style' => 'default',
    ),
    'right' => array(
      'style' => 'default',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '89435642-902d-4a60-b1c3-52039ebd859a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-eec080aa-7320-4a5e-886a-1148feb06499';
    $pane->panel = 'centre';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'eec080aa-7320-4a5e-886a-1148feb06499';
    $display->content['new-eec080aa-7320-4a5e-886a-1148feb06499'] = $pane;
    $display->panels['centre'][0] = 'new-eec080aa-7320-4a5e-886a-1148feb06499';
    $pane = new stdClass();
    $pane->pid = 'new-1ec361b5-d803-4cb5-bf1a-cc24e6423678';
    $pane->panel = 'centre';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p class="text-muted">Posted on %node:created</p>
<p class="text-muted">Written by %node:author</p>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1ec361b5-d803-4cb5-bf1a-cc24e6423678';
    $display->content['new-1ec361b5-d803-4cb5-bf1a-cc24e6423678'] = $pane;
    $display->panels['centre'][1] = 'new-1ec361b5-d803-4cb5-bf1a-cc24e6423678';
    $pane = new stdClass();
    $pane->pid = 'new-4a4ffb6f-f58b-4971-bf01-e42488e3997e';
    $pane->panel = 'centre';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
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
    $pane->uuid = '4a4ffb6f-f58b-4971-bf01-e42488e3997e';
    $display->content['new-4a4ffb6f-f58b-4971-bf01-e42488e3997e'] = $pane;
    $display->panels['centre'][2] = 'new-4a4ffb6f-f58b-4971-bf01-e42488e3997e';
    $pane = new stdClass();
    $pane->pid = 'new-bdfbf10d-40d6-461d-a031-4e7feeed8413';
    $pane->panel = 'centre';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_attachment';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'file_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '%title',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'bdfbf10d-40d6-461d-a031-4e7feeed8413';
    $display->content['new-bdfbf10d-40d6-461d-a031-4e7feeed8413'] = $pane;
    $display->panels['centre'][3] = 'new-bdfbf10d-40d6-461d-a031-4e7feeed8413';
    $pane = new stdClass();
    $pane->pid = 'new-945dbaa2-323b-4fd6-a30b-ff40958093de';
    $pane->panel = 'centre';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'taxonomy_term_reference_link',
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '945dbaa2-323b-4fd6-a30b-ff40958093de';
    $display->content['new-945dbaa2-323b-4fd6-a30b-ff40958093de'] = $pane;
    $display->panels['centre'][4] = 'new-945dbaa2-323b-4fd6-a30b-ff40958093de';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__news'] = $handler;

  return $export;
}

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
  $page->path = 'news/!tags/!date';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'tags' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
    'date' => array(
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
    $pane->uuid = '8e2840cf-be7c-4347-88b0-afda8331e80c';
    $display->content['new-8e2840cf-be7c-4347-88b0-afda8331e80c'] = $pane;
    $display->panels['left'][0] = 'new-8e2840cf-be7c-4347-88b0-afda8331e80c';
    $pane = new stdClass();
    $pane->pid = 'new-6cafc83b-3253-41c4-a3d9-9bf070c4f01d';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'n6';
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
      'settings' => array(
        'hide_classes' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'additional_classes' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
        ),
      ),
      'style' => 'bootstrap_styles:well',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6cafc83b-3253-41c4-a3d9-9bf070c4f01d';
    $display->content['new-6cafc83b-3253-41c4-a3d9-9bf070c4f01d'] = $pane;
    $display->panels['right'][0] = 'new-6cafc83b-3253-41c4-a3d9-9bf070c4f01d';
    $pane = new stdClass();
    $pane->pid = 'new-5d2b0ef8-8d15-40a8-8a26-85655a8cc7a1';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'n5';
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
    $pane->uuid = '5d2b0ef8-8d15-40a8-8a26-85655a8cc7a1';
    $display->content['new-5d2b0ef8-8d15-40a8-8a26-85655a8cc7a1'] = $pane;
    $display->panels['right'][1] = 'new-5d2b0ef8-8d15-40a8-8a26-85655a8cc7a1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news'] = $page;

  return $pages;

}
