<?php

/**
 * @file
 * template.php
 */

function ug_theme_image($variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);
  $attributes['class'] = 'img-responsive';

  foreach (array('width', 'height', 'alt', 'title') as $key) {
    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}


function ug_theme_field($variables) {
  $output = '';

  // Render the items.
  foreach ($variables['items'] as $item) {
    $output .= drupal_render($item);
  }

  return $output;
}


function ug_theme_field__field_image__news($variables) {
  $output = ug_theme_field($variables);
  $output = '<figure class="float-md-left">' . $output . '</figure>';
  return $output;
}

