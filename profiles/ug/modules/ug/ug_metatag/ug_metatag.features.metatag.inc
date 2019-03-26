<?php
/**
 * @file
 * ug_metatag.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function ug_metatag_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [current-page:pager][site:name]',
      ),
      'description' => array(
        'value' => '',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'rating' => array(
        'value' => '',
      ),
      'referrer' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => 'Drupal 7 (http://drupal.org)',
      ),
      'rights' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'prev' => array(
        'value' => '',
      ),
      'next' => array(
        'value' => '',
      ),
      'content-language' => array(
        'value' => '',
      ),
      'geo.position' => array(
        'value' => '',
      ),
      'geo.placename' => array(
        'value' => '',
      ),
      'geo.region' => array(
        'value' => '',
      ),
      'icbm' => array(
        'value' => '',
      ),
      'refresh' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
      'pragma' => array(
        'value' => '',
      ),
      'cache-control' => array(
        'value' => '',
      ),
      'expires' => array(
        'value' => '',
      ),
      'twitter:card' => array(
        'value' => 'summary',
      ),
      'twitter:site' => array(
        'value' => '@uofg',
      ),
      'twitter:site:id' => array(
        'value' => '',
      ),
      'twitter:creator' => array(
        'value' => '',
      ),
      'twitter:creator:id' => array(
        'value' => '',
      ),
      'twitter:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'twitter:title' => array(
        'value' => '[current-page:title]',
      ),
      'twitter:description' => array(
        'value' => 'University of Guelph',
      ),
      'twitter:image' => array(
        'value' => '',
      ),
      'twitter:image:width' => array(
        'value' => '',
      ),
      'twitter:image:height' => array(
        'value' => '',
      ),
      'twitter:image:alt' => array(
        'value' => '',
      ),
      'twitter:image0' => array(
        'value' => '',
      ),
      'twitter:image1' => array(
        'value' => '',
      ),
      'twitter:image2' => array(
        'value' => '',
      ),
      'twitter:image3' => array(
        'value' => '',
      ),
      'twitter:player' => array(
        'value' => '',
      ),
      'twitter:player:width' => array(
        'value' => '',
      ),
      'twitter:player:height' => array(
        'value' => '',
      ),
      'twitter:player:stream' => array(
        'value' => '',
      ),
      'twitter:player:stream:content_type' => array(
        'value' => '',
      ),
      'twitter:app:country' => array(
        'value' => '',
      ),
      'twitter:app:name:iphone' => array(
        'value' => '',
      ),
      'twitter:app:id:iphone' => array(
        'value' => '',
      ),
      'twitter:app:url:iphone' => array(
        'value' => '',
      ),
      'twitter:app:name:ipad' => array(
        'value' => '',
      ),
      'twitter:app:id:ipad' => array(
        'value' => '',
      ),
      'twitter:app:url:ipad' => array(
        'value' => '',
      ),
      'twitter:app:name:googleplay' => array(
        'value' => '',
      ),
      'twitter:app:id:googleplay' => array(
        'value' => '',
      ),
      'twitter:app:url:googleplay' => array(
        'value' => '',
      ),
      'twitter:label1' => array(
        'value' => '',
      ),
      'twitter:data1' => array(
        'value' => '',
      ),
      'twitter:label2' => array(
        'value' => '',
      ),
      'twitter:data2' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [current-page:pager][site:name]',
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
    ),
  );

  // Exported Metatag config instance: node:course_outline.
  $config['node:course_outline'] = array(
    'instance' => 'node:course_outline',
    'disabled' => FALSE,
    'config' => array(
      'twitter:description' => array(
        'value' => '[node:field_course_body]',
      ),
    ),
  );

  // Exported Metatag config instance: node:event.
  $config['node:event'] = array(
    'instance' => 'node:event',
    'disabled' => FALSE,
    'config' => array(
      'twitter:description' => array(
        'value' => '[node:field_event_body]',
      ),
      'twitter:image' => array(
        'value' => '[node:field_event_image]',
      ),
    ),
  );

  // Exported Metatag config instance: node:feature.
  $config['node:feature'] = array(
    'instance' => 'node:feature',
    'disabled' => FALSE,
    'config' => array(
      'twitter:description' => array(
        'value' => '[node:field_feature_text]',
      ),
      'twitter:image' => array(
        'value' => '[node:field_feature_image]',
      ),
    ),
  );

  // Exported Metatag config instance: node:news.
  $config['node:news'] = array(
    'instance' => 'node:news',
    'disabled' => FALSE,
    'config' => array(
      'twitter:description' => array(
        'value' => '[node:field_news_body]',
      ),
      'twitter:image' => array(
        'value' => '[node:field_news_image]',
      ),
    ),
  );

  // Exported Metatag config instance: node:page.
  $config['node:page'] = array(
    'instance' => 'node:page',
    'disabled' => FALSE,
    'config' => array(
      'twitter:description' => array(
        'value' => '[node:field_page_body]',
      ),
    ),
  );

  // Exported Metatag config instance: node:profile.
  $config['node:profile'] = array(
    'instance' => 'node:profile',
    'disabled' => FALSE,
    'config' => array(
      'twitter:description' => array(
        'value' => '[node:field_profile_summary]',
      ),
      'twitter:image' => array(
        'value' => '[node:field_profile_image]',
      ),
    ),
  );

  // Exported Metatag config instance: node:service.
  $config['node:service'] = array(
    'instance' => 'node:service',
    'disabled' => FALSE,
    'config' => array(
      'twitter:description' => array(
        'value' => '[node:field_service_description]',
      ),
    ),
  );

  return $config;
}
