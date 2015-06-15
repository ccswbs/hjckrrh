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
}

/**
 * Outputs a responsive image.
function ug_theme_image($variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);
  $attributes['class'] = array('img-responsive');

  foreach (array('width', 'height', 'alt', 'title') as $key) {
    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . '/>';
}
 */


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
 * E2 - Detail page for single event.
 */
function ug_theme_preprocess_views_view_fields__e2(&$vars) {
  $vars['title']       = $vars['fields']['title']->content;
  $vars['body']        = $vars['fields']['field_event_body']->content;
  $vars['email']       = $vars['fields']['field_event_email']->content;
  $vars['contact']     = $vars['fields']['field_event_contact']->content;
  $vars['cost']        = $vars['fields']['field_event_cost']->content;
  $vars['date']        = $vars['fields']['field_event_date']->content;
  $vars['image']       = $vars['fields']['field_event_image']->content;
  $vars['caption']     = $vars['fields']['field_event_image_caption']->content;
  $vars['attachments'] = $vars['fields']['field_event_attachments']->content;
  $vars['location']    = $vars['fields']['field_event_location']->content; 
  $vars['link']        = $vars['fields']['field_event_link']->content; 
  $vars['address']     = $vars['fields']['field_event_address']->content;
  $vars['city']        = $vars['fields']['field_event_city']->content;
  $vars['category']    = $vars['fields']['field_event_category']->content;
}


/**
 * FT1 - Featured item
 */
function ug_theme_preprocess_views_view_fields__ft1(&$vars) {
  $vars['title']  = $vars['fields']['title']->content;
  $vars['image']  = $vars['fields']['field_feature_image']->content;
  $vars['link']   = $vars['fields']['field_feature_link']->content;
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
  $vars['building']     = $vars['fields']['field_profile_building']->content;
  $vars['email']        = $vars['fields']['field_profile_email']->content;
  $vars['fax']          = $vars['fields']['field_profile_faxnumber']->content;
  $vars['lab']          = $vars['fields']['field_profile_lab']->content;
  $vars['phone']        = $vars['fields']['field_profile_telephonenumber']->content;
  $vars['room']         = $vars['fields']['field_profile_room']->content;
  $vars['website']      = $vars['fields']['field_profile_website']->content;
  $vars['about']        = $vars['fields']['field_profile_about']->content;
  $vars['education']    = $vars['fields']['field_profile_education']->content;
  $vars['research']     = $vars['fields']['field_profile_research']->content;
  $vars['publications'] = $vars['fields']['field_profile_publications']->content;
  $vars['attachments']  = $vars['fields']['field_profile_attachments']->content;
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
  $vars['title'] = $vars['fields']['title']->content;
  $vars['image'] = $vars['fields']['field_banner_image']->content;
  $vars['link']  = $vars['fields']['field_banner_link']->content;
  $vars['text']  = $vars['fields']['field_banner_text']->content;
}


/**
 * S1 - Share this page
 */
function ug_theme_preprocess_views_view_fields__s1(&$vars) {
  global $base_url;
  $vars['title']  = $vars['fields']['title']->content;
  $vars['path']   = $vars['fields']['path']->content;
  $vars['link']   = $base_url . $vars['path'];
}


/**
 * S3 - Find us on Social Media icons
 */
function ug_theme_preprocess_views_view_fields__s3(&$vars) {
  $vars['title']    = $vars['fields']['title']->content;
  $vars['network']  = $vars['fields']['field_social_network']->content;
  $vars['link']     = $vars['fields']['field_social_link']->content;
  $vars['icon']     = theme('icon', array('bundle' => 'fa', 'icon' => $vars['network']));
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
 * F1 - FAQ listing
 */
function ug_theme_preprocess_views_view_fields__f1(&$vars) {
  $nid = $vars['fields']['nid']->content;
  $question = $vars['fields']['title']->content;
  $vars['question'] = format_string("<a href='#faq@nid'>@q</a>", array('@q' => $question, '@nid' => $nid));
}


/**
 * F2 - FAQ detail
 */
function ug_theme_preprocess_views_view_fields__f2(&$vars) {
  $vars['nid']      = $vars['fields']['nid']->content;
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



