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
  $output = '<figure class="float-md-left">' . $output . '</figure>';
  return $output;
}


/*
 * Theme more link as a bootstrap button.
 */
function ug_theme_more_link($variables) {
  return '<p class="more-link">' . l(t('More'), $variables['url'], array('attributes' => array('title' => $variables['title'], 'class' => $variables['class']))) . '</p>';
}

