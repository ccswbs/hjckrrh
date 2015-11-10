<?php

/*
* Implements hook_migrate_api()
*/

function ug_migrate_d6_migrate_api() {

  $migrate_config_backup = 'migrate_settings_d6.php';
  $migrate_config = DRUPAL_ROOT . '/' . conf_path() . '/migrate_settings_d6.php';

  include $migrate_config_backup;

  if (file_exists($migrate_config)){
    //$migrate_config = $migrate_config_backup; 
    include $migrate_config;
  }

  //General variables
  $common_arguments = array(
    'source_connection' => 'legacy_d6',
    'source_version' => 6,
    'group_name' => 'ug_migrate_d6',
  );

  //Node variables
  $node_arguments = $common_arguments + array(
    'user_migration' => 'UGUser6',
    'default_uid' => 1,
  );

  $api = array(
    //set API level to 2 to work with 7.x-2.x Migrate branch
    'api' => 2,

    /**** GROUP ****/
    'groups' => array(
      'ug_migrate_d6' => array(
        'title' => t('UG Drupal 6 to Drupal 7 migration'),
      )
    ),

    'migrations' => array(

      /**** USER migration ****/
      'UGRole6' => $common_arguments + array(
        'description' => t('Migration of user roles from Drupal 6'),
        'class_name' => 'UGRole6Migration',
        'role_mappings' => $role_mappings,
      ),

      'UGPicture6' => $common_arguments + array(
        'description' => t('Migration of user pictures from Drupal 6'),
        'class_name' => 'UGPicture6Migration',
        'default_uid' => 1,
        'source_dir' => $picture_source,
        'destination_dir' => $picture_destination,
      ),

      'UGUser6' => $common_arguments + array(
        'description' => t('Migration of users from Drupal 6'),
        'class_name' => 'UGUser6Migration',
        'role_migration' => 'UGRole6',
        'picture_migration' => 'UGPicture6',
      ),

      /**** TERM migration ****/
      'UGTerm6' => $common_arguments + array(
        'description' => t('Migration of terms from Drupal 6'),
        'class_name' => 'UGTerm6Migration',
        'source_vocabulary' => $term_keyword_source,
        'destination_vocabulary' => 'tags',
      ),

      /**** PAGE migration ****/
      'UGPageCategory6' => $common_arguments + array(
        'description' => t('Migration of page category terms from Drupal 6'),
        'class_name' => 'UGPageCategory6Migration',
        'source_vocabulary' => $term_page_category_source, 
        'destination_vocabulary' => 'page_category',
      ),

      'UGPage6' => $node_arguments + $page_arguments + array(
        'description' => t('Migration of basic pages from Drupal 6'),
        'class_name' => 'UGPage6Migration',
        'source_type' => $node_page_type_source, 
        'destination_type' => 'page',
      ),

      /**** NEWS migration ****/
      'UGNewsCategory6' => $common_arguments + array(
        'description' => t('Migration of news category terms from Drupal 6'),
        'class_name' => 'UGNewsCategory6Migration',
        'source_vocabulary' => $term_news_category_source, 
        'destination_vocabulary' => 'news_category',
      ),

      'UGNewsKeyword6' => $common_arguments + array(
        'description' => t('Migration of news keyword terms from Drupal 6'),
        'class_name' => 'UGNewsKeyword6Migration',
        'source_vocabulary' => $term_news_keyword_source,
        'destination_vocabulary' => 'tags',
      ),

      'UGNews6' => $node_arguments + $news_arguments + array(
        'description' => t('Migration of news articles from Drupal 6'),
        'class_name' => 'UGNews6Migration',
        'source_type' => $node_news_type_source, 
        'destination_type' => 'news',
      ),

      /**** EVENT migration ****/
      'UGEventCategory6' => $common_arguments + array(
        'description' => t('Migration of event category terms from Drupal 6'),
        'class_name' => 'UGEventCategory6Migration',
        'source_vocabulary' => $term_event_category_source, 
        'destination_vocabulary' => 'event_category',
      ),

      'UGEventKeyword6' => $common_arguments + array(
        'description' => t('Migration of event keyword terms from Drupal 6'),
        'class_name' => 'UGEventKeyword6Migration',
        'source_vocabulary' => $term_event_keyword_source,
        'destination_vocabulary' => 'tags',
      ),

      'UGEvent6' => $node_arguments + $event_arguments + array(
        'description' => t('Migration of events from Drupal 6'),
        'class_name' => 'UGEvent6Migration',
        'source_type' => $node_event_type_source, 
        'destination_type' => 'event',
      ),
    ),

  );

  return $api;
}
