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
    'event' => 'events',
    'faq' => 'faq',
    'feature' => 'features',
    'news' => 'news',
    'page' => '',
    'service' => 'services',
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
    'event_category' => 'events',
    'event_heading' => '',
    'banner_category' => '',
    'news_category' => 'news',
    'page_category' => '',
    'social_media_category' => '',
    'faq_category' => 'faq',
    'feature_category' => 'features',
    'service_audience' => 'services',
    'service_category' => 'services',
    'service_keywords' => 'services',
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
    'taxonomy.termReference.field_event_category.node.event' => 6,
    'crumbs.entityParent.node.event' => 7,
    'crumbs.entityParent.taxonomy_term.event_category' => 8,
    'taxonomy.termParent.event_category' => 9,
    'taxonomy.termReference.field_faq_category.node.faq' => 10,
    'crumbs.entityParent.node.faq' => 11,
    'taxonomy.termParent.faq_category' => 12,
    'crumbs.entityParent.taxonomy_term.faq_category' => 13,
    'taxonomy.termReference.field_feature_category.node.feature' => 14,
    'crumbs.entityParent.node.feature' => 15,
    'taxonomy.termParent.feature_category' => 16,
    'crumbs.entityParent.taxonomy_term.feature_category' => 17,
    'taxonomy.termReference.field_service_category.node.service' => 18,
    'crumbs.entityParent.node.service' => 19,
    'taxonomy.termParent.service_category' => 20,
    'crumbs.entityParent.taxonomy_term.service_category' => 21,
    'menu.link_title.main-menu' => 22,
    'menu.hierarchy.main-menu' => 23,
    'menu.hierarchy.*' => 24,
    '*' => 25,
    'menu.*' => FALSE,
    'menu.hierarchy.navigation' => FALSE,
    'menu.link_title.*' => FALSE,
    'menu.link_title.navigation' => FALSE,
    'path' => FALSE,
    'views.*' => FALSE,
    'taxonomy.termReference.*' => FALSE,
    'taxonomy.termReference.field_tags.node.event' => FALSE,
    'taxonomy.termReference.field_tags.node.faq' => FALSE,
    'taxonomy.termReference.field_news_tags.node.*' => FALSE,
    'taxonomy.termReference.field_service_category.node.*' => FALSE,
    'crumbs.entityParent.taxonomy_term.service_audience' => FALSE,
    'crumbs.entityParent.taxonomy_term.service_keywords' => FALSE,
  );
  $export['crumbs_weights'] = $strongarm;

  return $export;
}
