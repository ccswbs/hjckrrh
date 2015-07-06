<?php
/**
 * @file
 * ug_profile.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ug_profile_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'profile2_view__panel_context_4fa1adaf-9455-4041-9b27-cb32816f68e6';
  $handler->task = 'profile2_view';
  $handler->subtask = '';
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
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'right' => array(
        'column_type' => 'col-sm',
        'column_size' => '9',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'left' => array(
        'column_type' => 'col-sm',
        'column_size' => '3',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'default' => NULL,
      'top' => NULL,
      'bottom' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'bottom' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%profile2:field_profile_name %profile2:field_profile_lastname';
  $display->uuid = '5f6d6bca-bae2-4014-93aa-974a06adf90c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5d038dbe-2a30-4236-84a5-ec009441e663';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'profile_multipart-panel_pane_1';
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
    $pane->uuid = '5d038dbe-2a30-4236-84a5-ec009441e663';
    $display->content['new-5d038dbe-2a30-4236-84a5-ec009441e663'] = $pane;
    $display->panels['bottom'][0] = 'new-5d038dbe-2a30-4236-84a5-ec009441e663';
    $pane = new stdClass();
    $pane->pid = 'new-97816423-d05e-41f5-a90f-7b8b17abe903';
    $pane->panel = 'bottom';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_profile_attachments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_table',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:profile2_1',
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
    $pane->uuid = '97816423-d05e-41f5-a90f-7b8b17abe903';
    $display->content['new-97816423-d05e-41f5-a90f-7b8b17abe903'] = $pane;
    $display->panels['bottom'][1] = 'new-97816423-d05e-41f5-a90f-7b8b17abe903';
    $pane = new stdClass();
    $pane->pid = 'new-f3649e49-22d7-4848-afd5-0f5a58da1ffe';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_profile_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'large',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:profile2_1',
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
    $pane->uuid = 'f3649e49-22d7-4848-afd5-0f5a58da1ffe';
    $display->content['new-f3649e49-22d7-4848-afd5-0f5a58da1ffe'] = $pane;
    $display->panels['left'][0] = 'new-f3649e49-22d7-4848-afd5-0f5a58da1ffe';
    $pane = new stdClass();
    $pane->pid = 'new-181d4771-64be-4bca-a4fc-2cbf226b3038';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Header',
      'title' => '',
      'body' => '<h3>%profile2:field_profile_title, %profile2:field_profile_unit</h3>

<p>%profile2:field_profile_subunit</p>
',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '181d4771-64be-4bca-a4fc-2cbf226b3038';
    $display->content['new-181d4771-64be-4bca-a4fc-2cbf226b3038'] = $pane;
    $display->panels['right'][0] = 'new-181d4771-64be-4bca-a4fc-2cbf226b3038';
    $pane = new stdClass();
    $pane->pid = 'new-e4dfd9e7-6534-4d63-ab65-fe54ea4720ca';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_profile_email';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:profile2_1',
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
    $pane->uuid = 'e4dfd9e7-6534-4d63-ab65-fe54ea4720ca';
    $display->content['new-e4dfd9e7-6534-4d63-ab65-fe54ea4720ca'] = $pane;
    $display->panels['right'][1] = 'new-e4dfd9e7-6534-4d63-ab65-fe54ea4720ca';
    $pane = new stdClass();
    $pane->pid = 'new-0e380bcf-ea1e-437c-968a-34f45018b312';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_profile_telephonenumber';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:profile2_1',
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
    $pane->uuid = '0e380bcf-ea1e-437c-968a-34f45018b312';
    $display->content['new-0e380bcf-ea1e-437c-968a-34f45018b312'] = $pane;
    $display->panels['right'][2] = 'new-0e380bcf-ea1e-437c-968a-34f45018b312';
    $pane = new stdClass();
    $pane->pid = 'new-46cf2b3a-6c49-4f75-9965-4b573a3c7bb3';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_profile_faxnumber';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:profile2_1',
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
    $pane->uuid = '46cf2b3a-6c49-4f75-9965-4b573a3c7bb3';
    $display->content['new-46cf2b3a-6c49-4f75-9965-4b573a3c7bb3'] = $pane;
    $display->panels['right'][3] = 'new-46cf2b3a-6c49-4f75-9965-4b573a3c7bb3';
    $pane = new stdClass();
    $pane->pid = 'new-a3e04d82-9b7d-42a5-b274-5bd6bad2b845';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_profile_office';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:profile2_1',
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
    $pane->uuid = 'a3e04d82-9b7d-42a5-b274-5bd6bad2b845';
    $display->content['new-a3e04d82-9b7d-42a5-b274-5bd6bad2b845'] = $pane;
    $display->panels['right'][4] = 'new-a3e04d82-9b7d-42a5-b274-5bd6bad2b845';
    $pane = new stdClass();
    $pane->pid = 'new-725e6cb0-e726-499e-b580-260055b842c4';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_profile_lab';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:profile2_1',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '725e6cb0-e726-499e-b580-260055b842c4';
    $display->content['new-725e6cb0-e726-499e-b580-260055b842c4'] = $pane;
    $display->panels['right'][5] = 'new-725e6cb0-e726-499e-b580-260055b842c4';
    $pane = new stdClass();
    $pane->pid = 'new-7d6864b7-0d6c-4bed-af43-c81c85f5e514';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'profile2:field_profile_website';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:profile2_1',
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '7d6864b7-0d6c-4bed-af43-c81c85f5e514';
    $display->content['new-7d6864b7-0d6c-4bed-af43-c81c85f5e514'] = $pane;
    $display->panels['right'][6] = 'new-7d6864b7-0d6c-4bed-af43-c81c85f5e514';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['profile2_view__panel_context_4fa1adaf-9455-4041-9b27-cb32816f68e6'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ug_profile_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'people';
  $page->task = 'page';
  $page->admin_title = 'People';
  $page->admin_description = '';
  $page->path = 'people/!unit';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'People',
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
    'unit' => array(
      'id' => 1,
      'identifier' => 'Unit',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          3 => '3',
          5 => 0,
          2 => 0,
          4 => 0,
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
  $handler->name = 'page_people__panel_context_9a810f37-51b2-41b5-a037-fe5df6dcc666';
  $handler->task = 'page';
  $handler->subtask = 'people';
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
  $display->title = 'Our People';
  $display->uuid = '8db0f571-e639-4b01-aa37-30739bdf06dc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-08bfe71d-5ab9-4091-ad20-3fd998f5f1a7';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'p1-panel_pane_1';
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
    $pane->uuid = '08bfe71d-5ab9-4091-ad20-3fd998f5f1a7';
    $display->content['new-08bfe71d-5ab9-4091-ad20-3fd998f5f1a7'] = $pane;
    $display->panels['left'][0] = 'new-08bfe71d-5ab9-4091-ad20-3fd998f5f1a7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['people'] = $page;

  return $pages;

}
