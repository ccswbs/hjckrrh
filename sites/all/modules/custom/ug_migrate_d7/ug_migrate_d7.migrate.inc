<?php

/*
* Implements hook_migrate_api()
*/

function ug_migrate_d7_migrate_api() {

  $migrate_settings = 'migrate_settings_d7.php';
  $migrate_settings_override = DRUPAL_ROOT . '/' . conf_path() . '/migrate_settings_d7.php';

  include $migrate_settings;

  if (file_exists($migrate_settings_override)){
    include $migrate_settings_override;
  }


  //General variables
  $common_arguments = array(
    'source_connection' => 'legacy_d7',
    'source_version' => 7,
    'group_name' => 'ug_migrate_d7',
  );

  //Node variables
  $node_arguments = $common_arguments + array(
    'user_migration' => 'UGUser7',
    'default_uid' => 1,
  );

  $api = array(
    //set API level to 2 to work with 7.x-2.x Migrate branch
    'api' => 2,

    /**** GROUP ****/
    'groups' => array(
      'ug_migrate_d7' => array(
        'title' => t('UG Drupal 7 to Drupal 7 migration'),
      )
    ),

    'migrations' => array(



      /**** USER migrations ****/
      'UGRole7' => $common_arguments + array(
        'description' => t('Migration of user roles from Drupal 7'),
        'class_name' => 'UGRole7Migration',
        'role_mappings' => $role_mappings,
      ),

      'UGUser7' => $common_arguments + array(
        'description' => t('Migration of users from Drupal 7'),
        'class_name' => 'UGUser7Migration',
        'role_migration' => 'UGRole7',
      ),

      /**** TERM migration ****/
      'UGTerm7' => $common_arguments + array(
        'description' => t('Migration of terms from Drupal 7'),
        'class_name' => 'UGTerm7Migration',
        'source_vocabulary' => $term_keyword_source, 
        'destination_vocabulary' => 'tags',
      ),

      /**** PAGE migration ****/
      'UGPageCategory7' => $common_arguments + array(
        'description' => t('Migration of page category terms from Drupal 7'),
        'class_name' => 'UGPageCategory7Migration',
        'source_vocabulary' => $term_page_category_source, 
        'destination_vocabulary' => 'page_category',
      ),

      'UGPage7' => $node_arguments + $page_arguments + array(
        'description' => t('Migration of basic pages from Drupal 7'),
        'class_name' => 'UGPage7Migration',
        'source_type' => $node_page_type_source, 
        'destination_type' => 'page',
      ),

      /**** NEWS migration ****/
      'UGNewsCategory7' => $common_arguments + array(
        'description' => t('Migration of news category terms from Drupal 7'),
        'class_name' => 'UGNewsCategory7Migration',
        'source_vocabulary' => $term_news_category_source, 
        'destination_vocabulary' => 'news_category',
      ),

      'UGNewsKeyword7' => $common_arguments + array(
        'description' => t('Migration of news keyword terms from Drupal 7'),
        'class_name' => 'UGNewsKeyword7Migration',
        'source_vocabulary' => $term_news_keyword_source,
        'destination_vocabulary' => 'tags',
      ),

      'UGNews7' => $node_arguments + $news_arguments + array(
        'description' => t('Migration of news articles from Drupal 7'),
        'class_name' => 'UGNews7Migration',
        'source_type' => $node_news_type_source, 
        'destination_type' => 'news',
      ),

      /**** EVENTS migration ****/
      'UGEventsCategory7' => $common_arguments + array(
        'description' => t('Migration of event category terms from Drupal 7'),
        'class_name' => 'UGEventsCategory7Migration',
        'source_vocabulary' => $term_events_category_source, 
        'destination_vocabulary' => 'event_category',
      ),

      'UGEventsKeyword7' => $common_arguments + array(
        'description' => t('Migration of events keyword terms from Drupal 7'),
        'class_name' => 'UGEventsKeyword7Migration',
        'source_vocabulary' => $term_events_keyword_source,
        'destination_vocabulary' => 'tags',
      ),

      'UGEvents7' => $node_arguments + $events_arguments + array(
        'description' => t('Migration of events from Drupal 7'),
        'class_name' => 'UGEvents7Migration',
        'source_type' => $node_events_type_source, 
        'destination_type' => 'event',
      ),

    ),
  );

  return $api;
}
