<?php

/**
 * @file
 * template.php
 */


/**
 * Implements hook_theme().
 */
function ug_theme_theme() {
  return array(
    'icon' => array(
      'variables' => array('icon' => NULL, 'bundle' => NULL),
    ),
  );
}


/**
 * Outputs a responsive image.
 */
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


/**
 * Outputs an icon.
 */
function ug_theme_icon($variables) {
  $attributes = array('class' => array('fa', 'fa-' . $variables['icon']));
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
 * N1 - Listing page for multiple news articles.
 */
function ug_theme_preprocess_views_view_fields__n1(&$vars) {
  $vars['title']     = $vars['fields']['title']->content;
  $vars['created']   = $vars['fields']['created']->content;
  $vars['body']      = $vars['fields']['field_news_body']->content;
  $vars['image']     = $vars['fields']['field_news_image']->content;
}


/**
 * N3 - Recent news teaser list.
 */
function ug_theme_preprocess_views_view_fields__n3(&$vars) {
  $vars['title']     = $vars['fields']['title']->content;
  $vars['created']   = $vars['fields']['created']->content;
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
 * E3 - Upcoming events teaser list.
 */
function ug_theme_preprocess_views_view_fields__e3(&$vars) {
  $vars['title']    = $vars['fields']['title']->content;
  $vars['date']     = $vars['fields']['field_event_date']->content;
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
  $vars['user_url']  = url('user/'.$vars['uid']);
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
  $vars['icon']     = theme('icon', array('bundle' => 'icomoon', 'icon' => $vars['network']));
}


/**
 * S4 - Find us on Social Media (icons and names)
 */
function ug_theme_preprocess_views_view_fields__s4(&$vars) {
  $vars['title']    = $vars['fields']['title']->content;
  $vars['network']  = $vars['fields']['field_social_network']->content;
  $vars['link']     = $vars['fields']['field_social_link']->content;
  $vars['icon']     = theme('icon', array('bundle' => 'icomoon', 'icon' => $vars['network']));
}


/**
 * S6 - Social media directory
 */
function ug_theme_preprocess_views_view_fields__s6(&$vars) {
  $vars['title']    = $vars['fields']['title']->content;
  $vars['network']  = $vars['fields']['field_social_network']->content;
  $vars['link']     = $vars['fields']['field_social_link']->content;
  $vars['icon']     = theme('icon', array('bundle' => 'icomoon', 'icon' => $vars['network']));
}


