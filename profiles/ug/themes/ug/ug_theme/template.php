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
  return theme_menu_link($variables);
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
  $attributes = array('class' => array($bundle, $bundle.'-'.$icon));
  return '<span' . drupal_attributes($attributes) . '></span>';
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
 * E1 - Listing page for multiple events. 
 */ 
function ug_theme_preprocess_views_view_fields__e1(&$vars) { 
  $vars['title']    = $vars['fields']['title']->content; 
  $vars['date']     = $vars['fields']['field_event_date']->content; 
  $vars['image']    = $vars['fields']['field_event_image']->content; 
  $vars['body']     = $vars['fields']['field_event_body']->content; 
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
 * P1 - Listing page for multiple people profiles.
 */
function ug_theme_preprocess_views_view_fields__p1(&$vars) {
  $vars['image']     = $vars['fields']['field_profile_image']->content;
  $vars['name']      = $vars['fields']['field_profile_name']->content;
  $vars['lastname']  = $vars['fields']['field_profile_lastname']->content;
  $vars['uid']       = $vars['fields']['uid']->content;
  $vars['title']     = $vars['fields']['field_profile_title']->content;
  $vars['unit']      = $vars['fields']['field_profile_unit']->content;
  $vars['phone']     = $vars['fields']['field_profile_telephonenumber']->content;
  $vars['email']     = $vars['fields']['field_profile_email']->content;
  $vars['user_url']  = 'user/'.$vars['uid'];
  $vars['fullname']  = l($vars['name'].' '.$vars['lastname'], 'user/'.$vars['uid']);
}


/**
 * PG1 - Listing page for one page.
 */
function ug_theme_preprocess_views_view_fields__pg1(&$vars) {
  $vars['title']        = $vars['fields']['title']->content;
  $vars['image']        = $vars['fields']['field_page_image']->content;
  $vars['caption']      = $vars['fields']['field_page_caption']->content;
  $vars['body']         = $vars['fields']['field_page_body']->content;
  $vars['attachments']  = $vars['fields']['field_page_attachments']->content;
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
}


/**
 * S3 - Find us on Social Media icons
 */
function ug_theme_preprocess_views_view_fields__s3(&$vars) {
  $vars['title']        = $vars['fields']['title']->content;
  $vars['network_key']  = $vars['fields']['field_social_network']->content;
  $vars['network_name'] = $vars['fields']['field_social_network_1']->content;
  $vars['link']         = $vars['fields']['field_social_link']->content;
  $vars['icon']         = theme('icon', array('bundle' => 'fa', 'icon' => $vars['network_key']));
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
  $vars['icon'] = theme('icon', array('bundle' => 'fa', 'icon' => $vars['network_key']));
}


/**
 * S6 - Social media directory
 */
function ug_theme_preprocess_views_view_fields__s6(&$vars) {
  $vars['title']    = $vars['fields']['title']->content;
  $vars['network']  = $vars['fields']['field_social_network']->content;
  $vars['link']     = $vars['fields']['field_social_link']->content;
  $vars['icon']     = theme('icon', array('bundle' => 'fa', 'icon' => $vars['network']));
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
 * N3 - Recent news teaser list
 */
function ug_theme_preprocess_views_view_fields__n3(&$vars) {
  $nid = $vars['fields']['nid']->content;
  $link = $vars['fields']['field_news_link']->content;
  // $href = empty($link)? 'node/'.$nid: $link;
  if (!empty($link)) {
    $vars['link'] = $link;
  } else {
    $path = 'node/' . $nid;
    $vars['link'] = url($path);
  }
  // $vars['title']     = l($vars['fields']['title']->content, $href);
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
 * Implements hook_preprocess_node.
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
      $sub_menu = '<ul class="dropdown-menu" role="menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      // $element['#title'] .= ' <span class="caret"></span>';
      $element['#title'] .= ' <span class="toggle-indicator sr-only">show menu </span><span class="caret"></span>';
      // $element['#title'] = '<span class="toggle-indicator sr-only">Show </span>' . $element['#title'] . ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      // $element['#localized_options']['attributes']['aria-haspopup'] = 'true';
      $element['#localized_options']['attributes']['aria-expanded'] = 'false';
      $element['#localized_options']['attributes']['role'] = 'button';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

