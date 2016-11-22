<?php
/**
 * @file
 * ug_faq_layouts.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ug_faq_layouts_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__faq';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'FAQ',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'detail-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'faq' => 'faq',
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
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '7a7f593d-fbb3-41b4-b8fe-ce8aec4e060c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ff2caa01-7597-456d-8481-f98d528de82a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_faq_answer';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ff2caa01-7597-456d-8481-f98d528de82a';
    $display->content['new-ff2caa01-7597-456d-8481-f98d528de82a'] = $pane;
    $display->panels['middle'][0] = 'new-ff2caa01-7597-456d-8481-f98d528de82a';
    $pane = new stdClass();
    $pane->pid = 'new-e5f51bf0-4c3f-4631-9a5b-6d09afa42ef6';
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
    $pane->uuid = 'e5f51bf0-4c3f-4631-9a5b-6d09afa42ef6';
    $display->content['new-e5f51bf0-4c3f-4631-9a5b-6d09afa42ef6'] = $pane;
    $display->panels['right'][0] = 'new-e5f51bf0-4c3f-4631-9a5b-6d09afa42ef6';
    $pane = new stdClass();
    $pane->pid = 'new-d413c67a-3f67-4c0b-b4c5-1f4d669c18a9';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'faq_filter_keyword-panel_pane_1';
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
    $pane->uuid = 'd413c67a-3f67-4c0b-b4c5-1f4d669c18a9';
    $display->content['new-d413c67a-3f67-4c0b-b4c5-1f4d669c18a9'] = $pane;
    $display->panels['right'][1] = 'new-d413c67a-3f67-4c0b-b4c5-1f4d669c18a9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__faq'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_faq_layouts_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'faq';
  $page->task = 'page';
  $page->admin_title = 'FAQ';
  $page->admin_description = '';
  $page->path = 'faq/!term';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'FAQ',
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
    'term' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'term',
        'vids' => array(
          8 => '8',
          2 => 0,
          3 => 0,
          7 => 0,
          4 => 0,
          5 => 0,
          6 => 0,
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
  $handler->name = 'page_faq__panel_context_cf043979-c421-4a07-9258-40e91ea651da';
  $handler->task = 'page';
  $handler->subtask = 'faq';
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
  $display->uuid = 'da7c3324-cb38-431c-a92d-699e7fe619e6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d0294c34-5bf1-4089-b3d3-5119b803afb1';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'f1-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'arguments' => array(
        'field_faq_category_tid' => '',
      ),
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
    $display->panels['middle'][0] = 'new-d0294c34-5bf1-4089-b3d3-5119b803afb1';
    $pane = new stdClass();
    $pane->pid = 'new-49c6ceb5-97dc-42e3-8f9b-3a21b7b9ec06';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'f2-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'arguments' => array(
        'field_faq_category_tid' => '',
      ),
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
    $display->panels['middle'][1] = 'new-49c6ceb5-97dc-42e3-8f9b-3a21b7b9ec06';
    $pane = new stdClass();
    $pane->pid = 'new-4c4655c5-8b45-421e-b392-792418d92d95';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'f3-panel_pane_1';
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
    $pane->uuid = '4c4655c5-8b45-421e-b392-792418d92d95';
    $display->content['new-4c4655c5-8b45-421e-b392-792418d92d95'] = $pane;
    $display->panels['right'][0] = 'new-4c4655c5-8b45-421e-b392-792418d92d95';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-d0294c34-5bf1-4089-b3d3-5119b803afb1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faq'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'faq_category';
  $page->task = 'page';
  $page->admin_title = 'FAQ category';
  $page->admin_description = '';
  $page->path = 'faq/category/%category';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'category' => array(
      'id' => 2,
      'identifier' => 'Taxonomy term: ID 2',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          15 => 0,
          2 => 0,
          3 => 0,
          7 => 0,
          8 => 0,
          4 => 0,
          5 => 0,
          14 => 0,
          16 => 0,
          9 => 0,
          10 => 0,
          11 => 0,
          12 => 0,
          13 => 0,
          6 => 0,
          17 => 0,
          1 => 0,
          18 => 0,
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
  $handler->name = 'page_faq_category__panel_context_6cdacd7b-2695-4291-92d8-da7ad5a53ffe';
  $handler->task = 'page';
  $handler->subtask = 'faq_category';
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
  $display->title = '%category:name';
  $display->uuid = 'da7c3324-cb38-431c-a92d-699e7fe619e6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1f56d272-85e8-4c84-bea2-861a57033b22';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'f1-panel_pane_2';
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
    $pane->uuid = '1f56d272-85e8-4c84-bea2-861a57033b22';
    $display->content['new-1f56d272-85e8-4c84-bea2-861a57033b22'] = $pane;
    $display->panels['middle'][0] = 'new-1f56d272-85e8-4c84-bea2-861a57033b22';
    $pane = new stdClass();
    $pane->pid = 'new-93902679-525c-429a-bc28-876a81d75e4f';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'f2-panel_pane_2';
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
    $pane->uuid = '93902679-525c-429a-bc28-876a81d75e4f';
    $display->content['new-93902679-525c-429a-bc28-876a81d75e4f'] = $pane;
    $display->panels['middle'][1] = 'new-93902679-525c-429a-bc28-876a81d75e4f';
    $pane = new stdClass();
    $pane->pid = 'new-66f0888c-8815-4e17-b572-40a6d572773f';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'f3-panel_pane_1';
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
    $pane->uuid = '66f0888c-8815-4e17-b572-40a6d572773f';
    $display->content['new-66f0888c-8815-4e17-b572-40a6d572773f'] = $pane;
    $display->panels['right'][0] = 'new-66f0888c-8815-4e17-b572-40a6d572773f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faq_category'] = $page;

  return $pages;

}
