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
  $strongarm->name = 'crumbs_node_parent_patterns';
  $strongarm->value = array(
    'banner' => '',
    'event' => '',
    'faq' => '',
    'feature' => '',
    'news' => 'News',
    'page' => '',
    'service' => 'Services',
    'social' => '',
  );
  $export['crumbs_node_parent_patterns'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_original_theme_breadcrumb';
  $strongarm->value = array(
    'seven' => 'theme_breadcrumb',
    'ug_cornerstone' => 'bootstrap_breadcrumb',
  );
  $export['crumbs_original_theme_breadcrumb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_taxonomy_term_parent_patterns';
  $strongarm->value = array(
    'tags' => '',
    'event_category' => '',
    'event_heading' => '',
    'banner_category' => '',
    'news_category' => 'News',
    'page_category' => '',
    'social_media_category' => '',
    'faq_category' => '',
    'feature_category' => '',
    'service_audience' => 'Services',
    'service_category' => 'Services',
    'service_keywords' => 'Services',
    'service_private_heading' => '',
    'service_public_heading' => '',
  );
  $export['crumbs_taxonomy_term_parent_patterns'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'crumbs_weights';
  $strongarm->value = array(
    'crumbs.home_title' => 1,
    'taxonomy.termReference.field_news_tags.node.news' => 2,
    'crumbs.entityParent.node.news' => 3,
    'taxonomy.termParent.news_category' => 4,
    'crumbs.entityParent.taxonomy_term.news_category' => 5,
    'taxonomy.termReference.field_service_category.node.service' => 6,
    'crumbs.entityParent.node.service' => 7,
    'taxonomy.termParent.service_category' => 8,
    'crumbs.entityParent.taxonomy_term.service_category' => 9,
    'menu.hierarchy.*' => 10,
    '*' => 11,
    'menu.link_title.*' => FALSE,
    'menu.link_title.main-menu' => FALSE,
    'taxonomy.termReference.*' => FALSE,
    'taxonomy.termReference.field_news_tags.node.*' => FALSE,
    'taxonomy.termReference.field_service_category.node.*' => FALSE,
  );
  $export['crumbs_weights'] = $strongarm;

  return $export;
}
