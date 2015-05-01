<?php

/**
 * @file
 * template.php
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

  return '<img' . drupal_attributes($attributes) . ' />';
}


function ug_theme_field($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}


function ug_theme_field__field_image__news($variables) {
  $output = ug_theme_field($variables);
  $output = '<figure>' . $output . '</figure>';
  return $output;
}


/**
 * Allow each views template to specify its own preprocess function.
 */
function ug_theme_preprocess_views_view(&$vars) {
  if (isset($vars['view']->name)) {
    $function = 'ug_theme_preprocess_views_view__'.$vars['view']->name; 
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


function ug_theme_preprocess_views_view_fields__n1(&$vars) {
  $vars['title']     = $vars['fields']['title']->content;
  $vars['created']   = $vars['fields']['created']->content;
  $vars['body']      = $vars['fields']['field_news_body']->content;
  $vars['image']     = $vars['fields']['field_news_image']->content;
}



/**
 * Preprocess function for person profile detail view.
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

