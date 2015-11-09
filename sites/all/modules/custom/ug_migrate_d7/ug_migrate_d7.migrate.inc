<?php

/*
* Implements hook_migrate_api()
*/

function ug_migrate_d7_migrate_api() {

  include 'migrate_config.php';

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

      /**** ROLE migration ****/
      'UGRole7' => $common_arguments + array(
        'description' => t('Migration of user roles from Drupal 7'),
        'class_name' => 'UGRole7Migration',
        'role_mappings' => $role_mappings,
      ),

      /**** USER migration ****/
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

      /**** PAGE CATEGORY migration ****/
      'UGPageCategory7' => $common_arguments + array(
        'description' => t('Migration of page category terms from Drupal 7'),
        'class_name' => 'UGPageCategory7Migration',
        'source_vocabulary' => $term_page_category_source, 
        'destination_vocabulary' => 'page_category',
      ),

      /**** PAGE migration ****/
      'UGPage7' => $node_arguments + $page_arguments + array(
        'description' => t('Migration of basic pages from Drupal 7'),
        'class_name' => 'UGPage7Migration',
        'source_type' => $node_page_type_source, 
        'destination_type' => 'page',
      ),

      /**** NEWS CATEGORY migration ****/
      'UGNewsCategory7' => $common_arguments + array(
        'description' => t('Migration of news category terms from Drupal 7'),
        'class_name' => 'UGNewsCategory7Migration',
        'source_vocabulary' => $term_news_category_source, 
        'destination_vocabulary' => 'news_category',
      ),

      /**** NEWS migration ****/
      'UGNews7' => $node_arguments + $news_arguments + array(
        'description' => t('Migration of news articles from Drupal 7'),
        'class_name' => 'UGNews7Migration',
        'source_type' => $node_news_type_source, 
        'destination_type' => 'news',
      ),

    ),
  );

  return $api;
}
