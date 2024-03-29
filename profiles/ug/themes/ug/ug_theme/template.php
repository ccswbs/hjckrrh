<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_menu_link__menu_block.
 * Use Drupal's default theme_menu_link for menu blocks. The Drupal
 * theme provides its own menu_link theme function, but it renders
 * submenus as drop down menus, and only to 2 levels.
 */
function ug_theme_menu_link__menu_block(array $variables) {
  //return theme_menu_link($variables);
  return ug_theme_theme_menu_link($variables);
}

/**
 * Source: menu.inc
 * [DISABLED] Add aria-describedby current page label to menu blocks
 * Removed aria-describedby label in exchange for sr-only text
 */

function ug_theme_theme_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  //0VERRIDE - add aria-describedby current page label
  if(in_array('active', $element['#attributes']['class'])){
    $element['#title'] .= '<span class="sr-only"> (current page)</span>';
    $element['#localized_options']['html'] = TRUE;
    $element['#localized_options']['attributes']['class'][] = 'active-trail';
    $element['#attributes']['class'][] = 'active-trail';
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}


/**
 * Implements hook_theme().
 */
function ug_theme_theme() {
  return array(
    'icon' => array(
      'variables' => array('icon' => NULL, 'bundle' => 'glyphicon'),
    ),
  );
}

function ug_theme_preprocess_image_style(&$vars) {
  $vars['attributes']['class'][] = 'img-responsive';
  $vars['attributes']['class'][] = 'img-rounded';
}


/**
 * Outputs an icon.
 */
function ug_theme_icon($variables) {
  $icon = $variables['icon'];
  $bundle = $variables['bundle'];
  $prefix = $bundle;

  // Ensure Font Awesome prefixes work if .fab, .fas, etc.
  if(strpos($prefix, 'fa') === 0) {
    $prefix = 'fa';
  }

  $attributes = array('class' => array($bundle, $prefix.'-'.$icon));
  return '<span' . drupal_attributes($attributes) . '></span>';
}

/**
 * Processes the icon bundle
 */

function process_icon_bundle($network_key){

  // Default is Font Awesome brand .fab
  // Add any non-brand icons (e.g. rss) to $fa_icons array
  $fa_icons = array('rss');
  $bundle = 'fab';

  foreach ($fa_icons as $key => $value) {
    if($network_key == $value){
      $bundle = 'fa';
    }
  }

  return $bundle;
}


/**
 * Allow each views template to specify its own preprocess function.
 */
function ug_theme_preprocess_views_view_unformatted(&$vars) {
  if (isset($vars['view']->name)) {
    $function = 'ug_theme_preprocess_views_view_unformatted__'.$vars['view']->name;
    if (function_exists($function)) {
     $function($vars);
    }
  }
}

/**
 * Allow each views template to specify its own view preprocess function.
 */
function ug_theme_preprocess_views_view(&$vars) {
  $view = $vars['view'];
  if (isset($view->name)) {
    $function = 'ug_theme_preprocess_views_view__'.$view->name;
    if (function_exists($function)) {
     $function($vars);
    }
  }

  // Replace the build title with overriden title from the pane in feed links.
  // The feed icon has already been rendered at this point, so it's too late to alter the output.
  $has_feed_icon = isset($vars['feed_icon']);
  $has_pane_conf = isset($view->display_handler->display->display_options['pane_conf']);
  if ($has_feed_icon && $has_pane_conf) {
    $pane_conf = $view->display_handler->display->display_options['pane_conf'];
    $has_override_title = isset($pane_conf['override_title']);
    if ($has_override_title) {
      if ($pane_conf['override_title'] === 1 && isset($view->build_info['title'])) {
        $vars['feed_icon'] = str_replace($view->build_info['title'], $pane_conf['override_title_text'], $vars['feed_icon']);
      }
    }
  }       
}

/**
 * FT3 - Featured item teaser list
 */
function ug_theme_preprocess_views_view__ft3(&$vars) {
  $view = views_get_current_view();
  if(!empty($view->args[0])){
    $category_filter = $view->args[0];
    $view->display_handler->set_option('link_url', 'features/category/' . $category_filter);
  }
  $vars['more'] = $view->display_handler->render_more_link();
} 

/**
 * Allow each views template to specify its own fields preprocess function.
 */
function ug_theme_preprocess_views_view_fields(&$vars) {
  if (isset($vars['view']->name)) {
    $function = 'ug_theme_preprocess_views_view_fields__'.$vars['view']->name;
    if (function_exists($function)) {
     $function($vars);
    }
  }
}

/**
 * V2 - Detail page for single video
 */
function ug_theme_preprocess_views_view_fields__v2(&$vars) {
  $vars['nid']   = $vars['fields']['nid']->content;
  $vars['title'] = $vars['fields']['title']->content;
  $vars['video'] = $vars['fields']['field_video_id']->content;
  $vars['transcript'] = $vars['fields']['field_transcript_file']->content;
  $vars['description'] = $vars['fields']['field_description_file']->content;
}

/**
 * E1 - Listing page for multiple events.
 */
function ug_theme_preprocess_views_view_fields__e1(&$vars) {
  $vars['title']    = $vars['fields']['title']->content;
  $vars['date']     = $vars['fields']['field_event_date']->content;
  $vars['image']    = $vars['fields']['field_event_image']->content;
  $vars['body']     = $vars['fields']['field_event_body']->content;
  $vars['register'] = $vars['fields']['field_event_registration_link']->content;
}

/**
 * E2a - Event Image
 */
function ug_theme_preprocess_views_view_fields__event_image(&$vars) {
  $vars['image']    = $vars['fields']['field_event_image']->content;
  $vars['caption']    = $vars['fields']['field_event_image_caption']->content;
}


/**
 * Event month list
 */
function ug_theme_preprocess_views_view_fields__event_month_list(&$vars) {
  $vars['title']    = $vars['fields']['title']->content;
  $vars['date']     = $vars['fields']['field_event_date']->content;
  $vars['image']    = $vars['fields']['field_event_image']->content;
  $vars['body']     = $vars['fields']['field_event_body']->content;
}


/**
 * Event week list
 */
function ug_theme_preprocess_views_view_fields__event_week_list(&$vars) {
  $vars['title']    = $vars['fields']['title']->content;
  $vars['date']     = $vars['fields']['field_event_date']->content;
  $vars['image']    = $vars['fields']['field_event_image']->content;
  $vars['body']     = $vars['fields']['field_event_body']->content;
}

/**
 * Event section headers
 */
function ug_theme_field__field_event_heading($vars) {
  return '<h3>'.drupal_render($vars['items'][0]).'</h3>';
}

/**
 * Event Registration Link field
 */
function ug_theme_preprocess_field(&$vars) {
  $field_name = $vars['element']['#field_name'];
  if ($field_name == 'field_event_registration_link') {
    $vars['items'][0]['#element']['title'] = 'Register';
    $vars['items'][0]['#element']['attributes'] = array (
      'class' => 'btn btn-success btn-lg btn-block',
    );
  }
}


/**
 * PG1 - Listing page for one page.
 */
function ug_theme_preprocess_views_view_fields__pg1(&$vars) {
  $vars['title']        = $vars['fields']['title']->content;
  // removed since we don't have these fields yet
  //$vars['image']        = $vars['fields']['field_page_image']->content;
  //$vars['caption']      = $vars['fields']['field_page_caption']->content;
  $vars['body']         = $vars['fields']['field_page_body']->content;
  $vars['attachments']  = $vars['fields']['field_page_attachments']->content;
}

/**
 * PG2 - Listing page for multiple basic pages.
 */
function ug_theme_preprocess_views_view_fields__pg2(&$vars) {
  $vars['title']     = $vars['fields']['title']->content;
  $vars['created']   = $vars['fields']['created']->content;
  $vars['body']      = $vars['fields']['field_page_body']->content;
}

/**
 * PG3 - Page item teaser list
 */
function ug_theme_preprocess_views_view__pg3_page_item_teaser_list(&$vars) {

  $view = views_get_current_view();

  if(!empty($view->args[0])){
    $category_filter = $view->args[0];
    $view->display_handler->set_option('link_url', 'pages/category/' . $category_filter);
  } else {

    $view->display_handler->set_option('link_url', 'pages');

  }

  $vars['more'] = $view->display_handler->render_more_link();
}

/**
 * P1 - Listing page for multiple people profiles.
 */
function ug_theme_preprocess_views_view_fields__p1(&$vars) {
  $vars['image']     = $vars['fields']['field_profile_image']->content;
  $vars['name']      = $vars['fields']['field_profile_name']->content;
  $vars['lastname']  = $vars['fields']['field_profile_lastname']->content;
  $vars['uid']       = $vars['fields']['uid']->content;
  $vars['phone']     = $vars['fields']['field_profile_telephonenumber']->content;
  $vars['email']     = $vars['fields']['field_profile_email']->content;
  $vars['user_url']  = 'user/'.$vars['uid'];
  $vars['fullname']  = l($vars['name'].' '.$vars['lastname'], 'user/'.$vars['uid']);
  $vars['office']    = $vars['fields']['field_profile_office']->content;
}


/**
 * P2 - Detail page for single person profile
 */
function ug_theme_preprocess_views_view_fields__p2(&$vars) {
  $vars['firstname']    = $vars['fields']['field_profile_name']->content;
  $vars['lastname']     = $vars['fields']['field_profile_lastname']->content;
  $vars['fullname']     = $vars['firstname'] . ' ' . $vars['lastname'];
  $vars['image']        = $vars['fields']['field_profile_image']->content;
  $vars['title']        = $vars['fields']['field_profile_title']->content;
  $vars['unit']         = $vars['fields']['field_profile_unit']->content;
  $vars['subunit']      = $vars['fields']['field_profile_subunit']->content;
  $vars['email']        = $vars['fields']['field_profile_email']->content;
  $vars['fax']          = $vars['fields']['field_profile_faxnumber']->content;
  $vars['lab']          = $vars['fields']['field_profile_lab']->content;
  $vars['phone']        = $vars['fields']['field_profile_telephonenumber']->content;
  $vars['room']         = $vars['fields']['field_profile_room']->content;
  $vars['website']      = $vars['fields']['field_profile_website']->content;
  drupal_set_title($vars['fullname']);
}

/**
 * PP6 - Listing page for multiple customizable people profiles.
 */
function ug_theme_preprocess_views_view_fields__pp6(&$vars) {
  $vars['nid']            = (isset($vars['fields']['nid'])                           ? $vars['fields']['nid']->content : '');
  $vars['firstname']      = (isset($vars['fields']['field_profile_name'])            ? $vars['fields']['field_profile_name']->content : '');
  $vars['lastname']       = (isset($vars['fields']['field_profile_lastname'])        ? $vars['fields']['field_profile_lastname']->content : '');
  $vars['teaser']         = (isset($vars['fields']['field_profile_teaser'])          ? $vars['fields']['field_profile_teaser']->content : '');
  $vars['summary']        = (isset($vars['fields']['field_profile_summary'])         ? $vars['fields']['field_profile_summary']->content : '');
  $vars['phone']          = (isset($vars['fields']['field_profile_telephonenumber']) ? $vars['fields']['field_profile_telephonenumber']->content : '');
  $vars['email']          = (isset($vars['fields']['field_profile_email'])           ? $vars['fields']['field_profile_email']->content : '');
  $vars['office']         = (isset($vars['fields']['field_profile_office'])          ? $vars['fields']['field_profile_office']->content : '');
  $vars['title']          = (isset($vars['fields']['field_profile_title'])           ? $vars['fields']['field_profile_title']->content : '');
  $vars['unit']           = (isset($vars['fields']['field_profile_unit'])            ? $vars['fields']['field_profile_unit']->content : '');
  $vars['website']        = (isset($vars['fields']['field_profile_website'])         ? $vars['fields']['field_profile_website']->content : '');
  $vars['tags']        = (isset($vars['fields']['field_tags'])                    ? $vars['fields']['field_tags']->content : '');
  $vars['align']          = (isset($vars['fields']['field_profile_align_names'])     ? TRUE : FALSE);
  $vars['custom_fields']  = (isset($vars['fields']['field_profile_custom'])          ? $vars['fields']['field_profile_custom']->content : '');
  
  if ($vars['nid'] != '') {
     $vars['fullname']    = t('<a href="@url">'.$vars['firstname'].' '.$vars['lastname'].'</a>', array('@url' => url('node/'.$vars['nid'])));
  } else {
     $vars['fullname']    = t($vars['firstname'].' '.$vars['lastname']);
  }
  $vars['content_width']  = 'col-md-12';
  $vars['content_offset'] = '';
  // Small image
  if(isset($vars['fields']['field_profile_image'])) {
    $vars['content_width'] = 'col-md-10';
    $vars['small_image'] = $vars['fields']['field_profile_image']->content;
    if($vars['align']==TRUE) {
      if(!isset($vars['small_image'])) $vars['content_offset'] = 'col-md-offset-2';
    } else {
      if(!isset($vars['small_image'])) $vars['content_width'] = 'col-md-12';
    }
  }
  // Large image
  if(isset($vars['fields']['field_profile_image_1'])) {
    $vars['content_width'] = 'col-md-8';
    $vars['large_image']  = $vars['fields']['field_profile_image_1']->content;
    if($vars['align']==TRUE) {
      if($vars['large_image'] == '') $vars['content_offset'] = 'col-md-offset-4';
    } else {
      if($vars['large_image'] == '') $vars['content_width'] = 'col-md-12';
    }
  }
}

 /**
  * PP7 - People Profile teaser list
  */
 function ug_theme_preprocess_views_view_fields__pp7(&$vars) {
   $vars['title']  = $vars['fields']['title']->content;
   $vars['teaser'] = $vars['fields']['field_profile_teaser']->content;
   if(isset($vars['fields']['field_profile_image']->content)) {
    $vars['image']  = $vars['fields']['field_profile_image']->content;
   }
 }

/**
 * Output profile heading as a heading level 2.
 */
function ug_theme_field__field_profile_heading($variables) {
  $output = '';
  $tabs = module_exists('field_collection_bootstrap');

  // Render the items.
  foreach ($variables['items'] as $delta => $item) {
    if ($tabs)
      $output .= drupal_render($item);
    else 
      $output .= '<h2>' . drupal_render($item) . '</h2>';
  }

  return $output;
}

/**
 * Add proper classes to custom fields
 */
function ug_theme_field__field_profile_custom_label($variables) {
  return '<div class="field-label-inline"><div class="field-label">'.drupal_render($variables['items'][0]).':&nbsp;</div></div>';
}

function ug_theme_field__field_profile_custom_content($variables) {
  return '<div class="field-items"><div class="field-item">'.$variables['items'][0]['#markup'].'</div></div>';
}

/**
 * B1 - Image slider
 */
function ug_theme_preprocess_views_view_unformatted__b1(&$vars) {
  $vars['slide_number'] = "1";
  $vars['slide_count'] = count($vars['view']->result);
}
function ug_theme_preprocess_views_view_fields__b1(&$vars) {
  // $vars['title']    = $vars['fields']['title']->content;
  $vars['title']    = $vars['fields']['field_banner_headline']->content;
  $vars['image']    = $vars['fields']['field_banner_image']->content;
  $vars['link']     = $vars['fields']['field_banner_link']->content;
  $vars['text']     = $vars['fields']['field_banner_text']->content;
  $vars['alt']      = $vars['fields']['field_banner_alttext']->content;
}

/**
 * S1 - Share this page
 */
function ug_theme_preprocess_views_view_fields__s1(&$vars) {
  global $base_url;
  $vars['title']  = $vars['fields']['title']->content;
  $vars['link']   = $vars['fields']['path']->content;
  $vars['nid']    = $vars['fields']['nid']->content;
}


/**
 * S3 - Find us on Social Media icons
 */
function ug_theme_preprocess_views_view_fields__s3(&$vars) {
  $vars['title']        = $vars['fields']['title']->content;
  $vars['network_key']  = $vars['fields']['field_social_network']->content;
  $vars['network_name'] = $vars['fields']['field_social_network_1']->content;
  $vars['link']         = $vars['fields']['field_social_link']->content;
  $vars['icon'] = theme('icon', array('bundle' => process_icon_bundle($vars['network_key']), 'icon' => $vars['network_key']));
}


/**
 * S4 - Find us on Social Media (Icons and Names)
 */
function ug_theme_preprocess_views_view_fields__s4(&$vars) {
  $title = $vars['fields']['title']->content;
  $link  = $vars['fields']['field_social_link']->content;
  $vars['title'] = l($title, $link, array('html' => TRUE));
  $vars['network_key'] = $vars['fields']['field_social_network']->content;
  $vars['network_name'] = $vars['fields']['field_social_network_1']->content;
  $vars['link'] = $vars['fields']['field_social_link']->content;  
  $vars['icon'] = theme('icon', array('bundle' => process_icon_bundle($vars['network_key']), 'icon' => $vars['network_key']));
}

/**
 * S5 - Feed aggregator block
 */
function ug_theme_preprocess_views_view_fields__s5_attachment(&$vars) {

  $vars['title']  = $vars['fields']['title_1']->content;
  $vars['date']   = $vars['fields']['timestamp']->content;

}

/**
 * S5b - Feed aggregator category block
 */
function ug_theme_preprocess_views_view_fields__s5b_attachment(&$vars) {
 ug_theme_preprocess_views_view_fields__s5_attachment($vars);
}

/**
 * S6 - Social media directory
 */
function ug_theme_preprocess_views_view_fields__s6(&$vars) {
  $vars['title']    = $vars['fields']['title']->content;
  $vars['network_key']  = $vars['fields']['field_social_network']->content;
  $vars['link']     = $vars['fields']['field_social_link']->content;
  $vars['icon']     = theme('icon', array('bundle' => process_icon_bundle($vars['network_key']), 'icon' => $vars['network_key']));
}


/**
 * N1 - Listing page for multiple news articles.
 */
function ug_theme_preprocess_views_view_fields__n1(&$vars) {
  $nid = $vars['fields']['nid']->content;
  $link = $vars['fields']['field_news_link']->content;
  if (!empty($link)) {
    $vars['link'] = $link;
  } else {
    $path = 'node/' . $nid;
    $vars['link'] = url($path);
  }
  $vars['image']     = $vars['fields']['field_news_image']->content;
  $vars['title']     = $vars['fields']['title']->content;
  $vars['created']   = $vars['fields']['created']->content;
  $vars['body']      = $vars['fields']['field_news_body']->content;
}


/**
 * N2 - Detail page for single news article
 */
function ug_theme_preprocess_views_view_fields__n2(&$vars) {
  $vars['title']        = $vars['fields']['title']->content;
  $vars['created']      = $vars['fields']['created']->content;
  $vars['writer']       = $vars['fields']['field_news_writer']->content;
  $vars['image']        = $vars['fields']['field_news_image']->content;
  $vars['caption']      = $vars['fields']['field_news_caption']->content;
  $vars['body']         = $vars['fields']['field_news_body']->content;
  $vars['attachments']  = $vars['fields']['field_news_attachment']->content;
  $vars['tags']         = $vars['fields']['field_news_tags']->content;
}

/**
 * N2ab - Post Date / Written by
 */
function ug_theme_preprocess_views_view_fields__n2ab(&$vars) {
  $vars['created']      = $vars['fields']['created']->content;
  $vars['writer']       = $vars['fields']['field_news_writer']->content;
}

/**
 * N2c - News Image
 */
function ug_theme_preprocess_views_view_fields__news_image(&$vars) {
  $vars['caption']  = $vars['fields']['field_news_caption']->content;
  $vars['image']    = $vars['fields']['field_news_image']->content;
}


/**
 * N3 - Recent news teaser list
 */
function ug_theme_preprocess_views_view_fields__n3(&$vars) {
  $nid = $vars['fields']['nid']->content;
  $link = $vars['fields']['field_news_link']->content;

  if (!empty($link)) {
    $vars['link'] = $link;
  } else {
    $path = 'node/' . $nid;
    $vars['link'] = url($path);
  }

  $vars['title']     = $vars['fields']['title']->content;
  $vars['created']   = $vars['fields']['created']->content;
}

/**
 * N3 - Recent news teaser list - with summary
 */
function ug_theme_preprocess_views_view_fields__n3_summary(&$vars) {
  $nid = $vars['fields']['nid']->content;
  $link = $vars['fields']['field_news_link']->content;

  if (!empty($link)) {
    $vars['link'] = $link;
  } else {
    $path = 'node/' . $nid;
    $vars['link'] = url($path);
  }

  $vars['title']     = $vars['fields']['title']->content;
  $vars['created']   = $vars['fields']['created']->content;
}

/**
 * F1 - FAQ listing
 */
function ug_theme_preprocess_views_view_fields__f1(&$vars) {
  $vars['question'] = $vars['fields']['title']->content;
}


/**
 * F2 - FAQ detail
 */
function ug_theme_preprocess_views_view_fields__f2(&$vars) {
  $vars['question'] = $vars['fields']['title']->content;
  $vars['answer']   = $vars['fields']['field_faq_answer']->content;
}


/**
 * SR1 - List of all services by category
 */
function ug_theme_preprocess_views_view_fields__sr1(&$vars) {
  $vars['icon'] = theme('icon', array('icon' => $vars['fields']['field_service_icon']->content));
  $vars['name'] = $vars['fields']['name']->content;
  $vars['description'] = $vars['fields']['description']->content;
}

/**
 * SR8 - Service Category teaser list
 */
function ug_theme_preprocess_views_view_fields__sr8(&$vars) {
  $vars['icon'] = theme('icon', array('icon' => $vars['fields']['field_service_icon']->content));
  $vars['name'] = $vars['fields']['name']->content;
  $vars['description'] = $vars['fields']['description']->content;
}

/**
 * Output Service detail headers as a heading level 3.
 */
function ug_theme_field__field_service_public_heading($variables) {
  $output = '';
  $tabs = module_exists('field_collection_bootstrap');
  // Render the items.
  foreach ($variables['items'] as $delta => $item) {
    if ($tabs)
      $output .= drupal_render($item);
    else 
      $output .= '<h3>' . drupal_render($item) . '</h3>';
  }
  return $output;
}

/**
 * Internal notes
 */
function ug_theme_field__field_service_private_heading($variables) {
  return '<h3>'.drupal_render($variables['items'][0]).'</h3>';
}

/**
 * Returns HTML for a date element formatted as a single date.
 */
function ug_theme_date_display_single($variables) {
  $date = $variables['date'];
  $timezone = $variables['timezone'];
  $attributes = $variables['attributes'];

  // Wrap the result with the attributes.
  $output = '<time class="date-display-single"' . drupal_attributes($attributes) . ' datetime="' . date("Y-m-d\TH:i:s", strtotime($date)) . '">' . $date . $timezone . '</time>
';

  if (!empty($variables['add_microdata'])) {
    $output .= '<meta' . drupal_attributes($variables['microdata']['value']['#attributes']) . '/>';
  }

  return $output;
}

/**
 * Returns HTML for a date element formatted as a range.
 */
function ug_theme_date_display_range($variables) {
  $date1 = $variables['date1'];
  $date2 = $variables['date2'];
  $timezone = $variables['timezone'];
  $attributes_start = $variables['attributes_start'];
  $attributes_end = $variables['attributes_end'];

  $start_date = '<time class="date-display-start"' . drupal_attributes($attributes_start) . ' datetime="' . date("Y-m-d\TH:i:s", strtotime($date1)) . '">' . $date1 . '</time>';
  $end_date = '<time class="date-display-end"' . drupal_attributes($attributes_end) . ' datetime="' . date("Y-m-d\TH:i:s", strtotime($date2)) . '">' . $date2 . $timezone . '</time>';

  // If microdata attributes for the start date property have been passed in,
  // add the microdata in meta tags.
  if (!empty($variables['add_microdata'])) {
    $start_date .= '<meta' . drupal_attributes($variables['microdata']['value']['#attributes']) . '/>';
    $end_date .= '<meta' . drupal_attributes($variables['microdata']['value2']['#attributes']) . '/>';
  }

  // Wrap the result with the attributes.
  return t('!start-date to !end-date', array(
    '!start-date' => $start_date,
    '!end-date' => $end_date,
  ));
}


/**
 * Implements node_view_alter.
 */
function ug_theme_node_view_alter(&$build) {
  $node = $build['#node'];
  // Set custom breadcrumb.
  if($build['#view_mode'] == "full" && node_is_page($node)) {
    $breadcrumb = drupal_get_breadcrumb();
    switch ($node->type) {
      case "faq":
        $breadcrumb[] = l(t('FAQ'), 'faq');
        break;
      case "event":
        $breadcrumb[] = l(t('Events'), 'events');
        break;
      case "news":
        $breadcrumb[] = l(t('News'), 'news');
        break;
    }
    drupal_set_breadcrumb($breadcrumb);
  }
}


/**
 * Implements hook_preprocess_node.
 */
function ug_theme_preprocess_node (&$variables) {
  // Hide read more link.
  unset($variables['content']['links']['node']['#links']['node-readmore']);

  // if taxonomy page, use taxonomy node template
  $path_args = explode('/', current_path());
  if($path_args[0] == 'taxonomy') {
    array_push($variables['theme_hook_suggestions'], 'node__taxonomy');
  }
}



/**
 * Add aria-expanded to Drupal menus.
 * [DISABLED] Add aria-describedby label to current menu item.
 * Removed aria-describedby label in exchange for sr-only text
 */
function ug_theme_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      //OVERRIDE - add aria-expanded attribute
      $element['#localized_options']['attributes']['aria-expanded'] = 'false';
      $element['#localized_options']['attributes']['role'] = 'button';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
    //OVERRIDE - add aria-describedby attribute
    //$element['#title'] .= '<span id="current_localnav" class="hidden"> (current page)</span>';
    //$element['#localized_options']['attributes']['aria-describedby'] = 'current_localnav';
    $element['#title'] .= '<span class="sr-only"> (current page)</span>';
    $element['#localized_options']['html'] = TRUE;
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Theme the calendar title
 */
function ug_theme_date_nav_title($params) {
  $granularity = $params['granularity'];
  $view = $params['view'];
  $date_info = $view->date_info;
  $link = !empty($params['link']) ? $params['link'] : FALSE;
  $format = !empty($params['format']) ? $params['format'] : NULL;

  // OVERRIDE - added underscore before format_with_year and format_without_year (allows month format to show with August 2015)
  $format_with_year = variable_get('date_views_' . $granularity . '_format_with_year', 'l, F j, Y');
  $format_without_year = variable_get('date_views_' . $granularity . '_format_without_year', 'l, F j');
  switch ($granularity) {
    case 'year':
      $title = $date_info->year;
      $date_arg = $date_info->year;
      break;
    case 'month':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month);
      break;
    case 'day':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month) . '-' . date_pad($date_info->day);
      break;
    case 'week':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = t('Week of @date', array('@date' => date_format_date($date_info->min_date, 'custom', $format)));
      $date_arg = $date_info->year . '-W' . date_pad($date_info->week);
      break;
  }
  if (!empty($date_info->mini) || $link) {
    // Month navigation titles are used as links in the mini view.
    $attributes = array('title' => t('View full page month'));
    $url = date_pager_url($view, $granularity, $date_arg, TRUE);
    return l($title, $url, array('attributes' => $attributes));
  }
  else {
    return $title;
  }
}

/**
 * Add additional labelling info to pagination links
 * Source: includes/pager.inc
 */

function ug_theme_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }

    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($_GET['q'], array('query' => $query));

  // OVERRIDE - update return link to inclue "page" prior to page number
  $pager_label = ' <span class="sr-only">page</span>';
  if(is_numeric($text)) {
    $return_link = '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
  }else {
    $return_link = '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . $pager_label .'</a>';
  }

  return $return_link;
}


/**
 * Override Bootstrap pager
 * Source: sites/all/theme/bootstrap/system/pager.func.php
 */

function ug_theme_pager($variables) {
  $output = "";
  $items = array();
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];

  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // Last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }

  // End of generation loop preparation.

  // OVERRIDE - add back in FIRST link preparation
  // @todo add theme setting for this.
  // --- Uncommented section
  $li_first = theme('pager_first', array(
    //OVERRIDE - trim «‹<>›» characters from FIRST link
    'text' => (isset($tags[0]) ? trim($tags[0],'«‹<>›»') : t('first')),
    'element' => $element,
    'parameters' => $parameters,
  ));
  // --- End of Uncommented section

  $li_previous = theme('pager_previous', array(
    //OVERRIDE - trim «‹<>›» characters from PREVIOUS link
    'text' => (isset($tags[1]) ? trim($tags[1],'«‹<>›»') : t('previous')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));
  $li_next = theme('pager_next', array(
    //OVERRIDE - trim «‹<>›» characters from NEXT link
    'text' => (isset($tags[3]) ? trim($tags[3],'«‹<>›»') : t('next')),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));

  // OVERRIDE - add back in LAST link preparation
  // @todo add theme setting for this.
  // --- Uncommented section
    $li_last = theme('pager_last', array(
      //OVERRIDE - trim «‹<>›» characters from LAST link
      'text' => (isset($tags[4]) ? trim($tags[4],'«‹<>›»') : t('last')),
      'element' => $element,
      'parameters' => $parameters,
    ));
  // --- End of Uncommented section

  if ($pager_total[$element] > 1) {


    // OVERRIDE - add back in FIRST link
    // @todo add theme setting for this.
    // --- Uncommented section
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    // --- End of Uncommented section

    if ($li_previous) {
      $items[] = array(
        'class' => array('prev'),
        'data' => $li_previous,
      );
    }
    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {

      // OVERRIDE - remove pager ellipsis
      // --- Commented out section
      /*if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis', 'disabled'),
          'data' => '<span>…</span>',
        );
      }*/
      // --- End of Commented out section


      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {

        // OVERRIDE - remove PAGER ITEMS BEFORE current page
        // --- Commented out section
        /*if ($i < $pager_current) {
          $items[] = array(
            // 'class' => array('pager-item'),
            'data' => theme('pager_previous', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($pager_current - $i),
              'parameters' => $parameters,
            )),
          );
        }*/
        // --- End of Commented out section

        if ($i == $pager_current) {
          $items[] = array(

            //ORIGINAL CODE
            // --- Commented out section
            // Add the active class.
            /*'class' => array('active'),
             'data' => l($i, '#', array('fragment' => '', 'external' => TRUE)),
             */
             // --- End of Commented out section

            //OVERRIDE #1 - Provide sr-only current page notification
            //'data' => t('<a href="@url"><span class="sr-only">Current page</span>' . $i .'</a>', array('@url' => '#'), array('fragment' => '', 'external' => TRUE)),

            //OVERRIDE #2 - Change to Page $i of Total # format
            'class' => array('disabled'),
            'data' =>'<span>Page ' . $i . ' of ' . $pager_max . '</span>',
          );
        }

        // OVERRIDE - remove PAGER ITEMS AFTER current page
        // --- Commented out section
        /*if ($i > $pager_current) {
          $items[] = array(
            'data' => theme('pager_next', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($i - $pager_current),
              'parameters' => $parameters,
            )),
          );
        }*/
        // --- End of Commented out section
      }

      // OVERRIDE - remove PAGER MAX
      // --- Commented out section
      /*if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis', 'disabled'),
          'data' => '<span>…</span>',
        );
      }*/
      // --- End of Commented out section
    }


    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('next'),
        'data' => $li_next,
      );
    }

    // OVERRIDE - add back in LAST link
    // @todo add theme setting for this.
    // --- Uncommented section
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    // --- End of Uncommented section

    /* OVERRIDE - Add heading, nav region, navigation role, and aria-labelledby */
    return '<div class="text-center"><nav role="navigation" aria-labelledby="pagination-heading"><h2 id="pagination-heading" class="sr-only">Pagination</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pagination')),
    )) . '</nav></div>';
  }
  return $output;
}

/**
 * Override search module to add label
 * Source: https://www.drupal.org/node/2540856
 */
function ug_theme_bootstrap_search_form_wrapper($variables) {
  $output = '<label for="'.$variables['element']['#id'].'" >Search ' .variable_get('site_name'). '</label>';
  $output .= '<div class="input-group">';

//added
    //$output .= '<label for="'.$variables['element']['#id'].'" class="element-invisible">Search this site</label>';

  $output .= $variables['element']['#children'];
  $output .= '<span class="input-group-btn">';
  $output .= '<button type="submit" class="btn btn-default">';
  // We can be sure that the font icons exist in CDN.
  if (theme_get_setting('bootstrap_cdn')) {
    $output .= _bootstrap_icon('search');
    $output .= '<span class="element-invisible">';
    $output .= t('Search');
    $output .= '</span>';
  } else {
    $output .= t('Search');
  }
  $output .= '</button>';
  $output .= '</span>';
  $output .= '</div>';
  return $output;
}

/**
 * N3 - News teaser list
 */
function ug_theme_preprocess_views_view__n3(&$vars) {

  $view = views_get_current_view();

  if(!empty($view->args[0])){
    $category_filter = $view->args[0];
    $view->display_handler->set_option('link_url', 'news/category/' . $category_filter);
  }

  $vars['more'] = $view->display_handler->render_more_link();
}

/**
 * N4 - News teaser row
 */
function ug_theme_preprocess_views_view__n4(&$vars) {

  $view = views_get_current_view();

  if(!empty($view->args[0])){
    $category_filter = $view->args[0];
    $view->display_handler->set_option('link_url', 'news/category/' . $category_filter);
  }

  $vars['more'] = $view->display_handler->render_more_link();
}

/**
 * PP7 - People profiles teaser list
 */
function ug_theme_preprocess_views_view__pp7(&$vars) {

  $view = views_get_current_view();

  if(!empty($view->args[0])){
    $keyword_filter = $view->args[0];
    $view->display_handler->set_option('link_url', 'people/' . $keyword_filter);
  }

  $vars['more'] = $view->display_handler->render_more_link();
}

function ug_theme_form_required_marker($variables) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();
  $attributes = array(
    'class' => 'form-required',
    'title' => $t('This field is required.'),
  );
  return '<span' . drupal_attributes($attributes) . '>(' . $t('required') . ')</span>';
}


/**
 * Overrides theme_button().
 */
function ug_theme_button($variables) {
  $element = $variables['element'];
  $label = $element['#value'];
  element_set_attributes($element, array('id', 'name', 'value', 'type'));

  // If a button type class isn't present then add in default.
  $button_classes = array(
    'btn-default',
    'btn-primary',
    'btn-success',
    'btn-info',
    'btn-warning',
    'btn-danger',
    'btn-link',
  );
  $class_intersection = array_intersect($button_classes, $element['#attributes']['class']);
  if (empty($class_intersection)) {
    $element['#attributes']['class'][] = 'btn-default';
  }

  // Add in the button type class.
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];

  // Remove name attribute if empty, for W3C compliance.
  if (isset($element['#attributes']['name']) && $element['#attributes']['name'] === '') {
    unset($element['#attributes']['name']);
  }

  // This line break adds inherent margin between multiple buttons.
  return '<button' . drupal_attributes($element['#attributes']) . '>' . $label . "</button>\n";
}

/**
 * Add spacing between webform fields
 * https://www.drupal.org/node/2712217 - used the ideas from this patch.
 * May need to remove this override at some point.
 */
function ug_theme_webform_element(&$variables) {
  bootstrap_include('bootstrap', 'templates/system/form-element.func.php');
  $element = &$variables['element'];
  $element['#attributes']['class'][] = 'form-group';
  return bootstrap_form_element($variables);
}

/**
 * Pre-processes variables for the "book_navigation" theme hook.
 *
 * See template for list of available variables.
 *
 * @see book-navigation.tpl.php
 *
 * @ingroup theme_preprocess
 */
function ug_theme_preprocess_book_navigation(&$variables) {
  /* https://www.drupal.org/node/1697570#comment-10357129 */
  drupal_static_reset('_menu_build_tree');
  /* Call default function from book.module. */
  template_preprocess_book_navigation ($variables);
}

/**
 * Returns HTML for a feed icon.
 *
 * @param $variables
 *   An associative array containing:
 *   - url: An internal system path or a fully qualified external URL of the
 *     feed.
 *   - title: A descriptive title of the feed.
 */

function ug_theme_feed_icon($variables) {
  $text = t('Subscribe to !feed-title', array('!feed-title' => $variables['title']));
  #2436: Subscribe RSS Feed buttons do not read descriptive link text in Screen-reader Browse mode*/             
  $image = '<span class="fa fa-rss"></span><span class="element-invisible">'.$text.'</span>'; 
  return l($image, $variables['url'], array('html' => TRUE, 'attributes' => array('class' => array('feed-icon', 'btn', 'btn-default'))));
}

/**
* Overrides bootstrap_form_alter()
*
*  Fixes Issue 606 - By default, Bootstrap hides a 2nd Drupal-generated Search button.
*  This fix ensures assistive tech users can also ignore this invisible button.
*
*  Updates placeholder text for search forms
*/

function ug_theme_form_alter(array &$form, array &$form_state = array(), $form_id = NULL) {

  switch ($form_id){

    // Affects Drupal search results page
    case 'search_form':
      $class_array = &$form['basic']['submit']['#attributes']['class'];
      $form['basic']['keys']['#attributes']['placeholder'] = t('');
      break;

    // Affects Drupal block form
    case 'search_block_form':
      $class_array = &$form['actions']['submit']['#attributes']['class'];
      $form['search_block_form']['#attributes']['placeholder'] = t('');
      break;
  }

  if(isset($class_array)){
    //Use Bootstrap hidden class instead of element-invisible
    foreach ($class_array as $key => $value) {
      if($value === 'element-invisible'){
        $class_array[$key] = 'hidden';
      }
    }
  }
}

/**                                                                                                                 
 * Returns HTML for status and/or error messages, grouped by type.                                                  
 *                                                                                                                  
 * An invisible heading identifies the messages for assistive technology.                                           
 * Sighted users see a colored box. See http://www.w3.org/TR/WCAG-TECHS/H69.html                                    
 * for info.                                                                                                        
 *                                                                                                                  
 * @param array $variables                                                                                          
 *   An associative array containing:                                                                               
 *   - display: (optional) Set to 'status' or 'error' to display only messages                                      
 *     of that type.                                                                                                
 *                                                                                                                  
 * @return string                                                                                                   
 *   The constructed HTML.                                                                                          
 *                                                                                                                  
 * @see theme_status_messages()                                                                                     
 *                                                                                                                  
 * @ingroup theme_functions                                                                                         
 */

function ug_theme_status_messages($variables) {                                                                    
  $display = $variables['display'];                                                                                 
  $output = '';                                                                                                     
                                                                                                                    
  $status_heading = array(                                                                                          
    'status' => t('Status message'),                                                                                
    'error' => t('Error message'),                                                                                  
    'warning' => t('Warning message'),                                                                              
    'info' => t('Informative message'),                                                                             
  );                                                                                                                
                                                                                                                    
  // Map Drupal message types to their corresponding Bootstrap classes.                                             
  // @see http://twitter.github.com/bootstrap/components.html#alerts                                                
  $status_class = array(                                                                                            
    'status' => 'success',                                                                                          
    'error' => 'danger',                                                                                            
    'warning' => 'warning',                                                                                         
    // Not supported, but in theory a module could send any type of message.                                        
    // @see drupal_set_message()                                                                                    
    // @see theme_status_messages()                                                                                 
    'info' => 'info',                                                                                               
  );                                             
  // Retrieve messages.                                                                                             
  $message_list = drupal_get_messages($display);                                                                    
                                                                                                                    
  // Allow the disabled_messages module to filter the messages, if enabled.                                         
  if (module_exists('disable_messages') && variable_get('disable_messages_enable', '1')) {                          
    $message_list = disable_messages_apply_filters($message_list);                                                  
  }                                                                                                                 
                                                                                                                    
  foreach ($message_list as $type => $messages) {                                                                   
    $class = (isset($status_class[$type])) ? ' alert-' . $status_class[$type] : '';                                  
    $output .= '<div class="alert alert-block '.$class.' messages '.$type.'">';                                          
//    $output .= "  <a class=\"close\" data-dismiss=\"alert\" href=\"#\">&times;</a>\n";
    $output .= '  <a class="close" data-dismiss="alert" href="#"><span aria-label="' . t('Close this message box') .'"></span><span aria-hidden="true">&times;</span></a>';                                                    
                                                                                                                    
    if (!empty($status_heading[$type])) {                                                                           
      $output .= '<h2 class="element-invisible">' . _bootstrap_filter_xss($status_heading[$type]) . "</h2>\n";      
    }                                                                                                               
                                                                                                                    
    if (count($messages) > 1) {                                                                                     
      $output .= " <ul>\n";                                                                                         
      foreach ($messages as $message) {                                                                             
        $output .= '  <li>' . _bootstrap_filter_xss($message) . "</li>\n";                                          
      }                                                                                                             
      $output .= " </ul>\n";                                                                                        
    }                                                                                                               
    else {                                                                                                          
      $output .= $messages[0];   
       }                                                                                                               
    $output .= "</div>\n";                                                                                          
  }                                                                                                                 
  return $output;                                                                                                   
}                                               

/**
 * Override: field_collection_bootstrap_tab_title()
 *
 * Include aria-expanded on page load
 */
function ug_theme_field_collection_bootstrap_tab_title($variables) {
  $tab_id = $variables['tab_id'];
  $title = $variables['title'];
  $active = $variables['active'];
   return '<li role="presentation"' . (($active) ? ' class="active"' : '') . '><a href="#' . $tab_id . '" aria-controls="' . $tab_id . '" role="tab" data-toggle="tab" aria-expanded=' . (($active) ? '"true"' : '"false"')  . '>' . $title . '</a></li>';
}
