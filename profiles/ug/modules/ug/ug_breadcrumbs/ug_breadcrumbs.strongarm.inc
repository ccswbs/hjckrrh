<?php
/**
 * @file
 * ug_breadcrumbs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ug_breadcrumbs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-capitalizator_ignored_words';
  $strongarm->value = array(
    'of' => 'of',
    'and' => 'and',
    'or' => 'or',
    'de' => 'de',
    'del' => 'del',
    'y' => 'y',
    'o' => 'o',
  );
  $export['easy_breadcrumb-capitalizator_ignored_words'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-capitalizator_mode';
  $strongarm->value = 'ucwords';
  $export['easy_breadcrumb-capitalizator_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-disable_drupal_breadcrumb';
  $strongarm->value = 1;
  $export['easy_breadcrumb-disable_drupal_breadcrumb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-excluded_paths';
  $strongarm->value = array(
    'search' => 'search',
    'search/node' => 'search/node',
    'news/category' => 'news/category',
    'news/archive' => 'news/archive',
  );
  $export['easy_breadcrumb-excluded_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-home_segment_title';
  $strongarm->value = 'Home';
  $export['easy_breadcrumb-home_segment_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-include_home_segment';
  $strongarm->value = 1;
  $export['easy_breadcrumb-include_home_segment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-include_invalid_paths';
  $strongarm->value = 1;
  $export['easy_breadcrumb-include_invalid_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-include_title_segment';
  $strongarm->value = 1;
  $export['easy_breadcrumb-include_title_segment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-segments_separator';
  $strongarm->value = '/';
  $export['easy_breadcrumb-segments_separator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-title_from_page_when_available';
  $strongarm->value = 1;
  $export['easy_breadcrumb-title_from_page_when_available'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'easy_breadcrumb-title_segment_as_link';
  $strongarm->value = 0;
  $export['easy_breadcrumb-title_segment_as_link'] = $strongarm;

  return $export;
}
