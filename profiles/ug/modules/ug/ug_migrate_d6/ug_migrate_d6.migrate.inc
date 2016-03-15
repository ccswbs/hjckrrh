<?php

/*
* Implements hook_migrate_api()
*/

function ug_migrate_d6_migrate_api() {

  /* COMMON VARIABLES */
  $common_arguments = array(
    'source_connection' => 'legacy_d6',
    'source_version' => 6,
    'group_name' => 'ug_migrate_d6',
  );

  /* NODE VARIABLES */
  $node_arguments = $common_arguments + array(
    'user_migration' => 'UGUser6',
    'default_uid' => 1,
  );

  $page_arguments = array(
    'source_page_node_type' => 'page',
    'source_page_term_category' => '',
    'source_page_term_keyword' => '',
  );

  $news_arguments = array(
    'source_news_node_type' => 'article',
    'source_news_term_category' => '',
    'source_news_term_keyword' => '',
  );

  $event_arguments = array(
    'source_event_node_type' => '',
    'source_event_term_category' => '',
    'source_event_term_keyword' => '',
    'source_event_term_heading' => '',
  );

  $event_multipart_arguments = array();

  $faq_arguments = array(
    'source_faq_node_type' => '',
    'source_faq_term_category' => '',
    'source_faq_term_keyword' => '',
  );

  /* USER VARIABLES */
  $user_arguments = array(
    'role_mappings' => array(),
    'picture_source' => '',
    'picture_destination' => 'public://',
  );

  /* FILE VARIABLES */
  $file_arguments = array(
    'source_directory' => 'public://',
    'destination_directory' => 'public://',
  );


  /* TAXONOMY VARIABLES */
  $term_arguments = array(
    'source_term_keyword' => 'tags',
  );

  /* MENU VARIABLES */
  $menu_names = array('primary-links');
  $menu_link_arguments = array(
    'menu_migration' => 'UGMenu6',
    'node_migrations' => array('UGPage6', 'UGNews6', 'UGEvent6', 'UGFAQ6'),
    'term_migrations' => array('UGTerm6', 'UGPageCategory6', 'UGNewsCategory6', 'UGNewsKeyword6', 'UGEventCategory6', 'UGEventKeyword6','UGFAQCategory6', 'UGFAQKeyword6'),
  );

  $menu_arguments = $common_arguments + array(
    'protected_system_menus' => array(
      'navigation', 
      'user-menu', 
      'devel', 
      'management',
    ),
  );

  /* OVERRIDE variables with site configuration files */
  $migrate_settings = 'migrate_settings_d6.php';
  $migrate_settings_override = DRUPAL_ROOT . '/' . conf_path() . '/migrate_settings_d6.php';

  include $migrate_settings;

  if (file_exists($migrate_settings_override)){
    include $migrate_settings_override;
  }

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
        'role_mappings' => $user_arguments['role_mappings'],
      ),

      'UGPicture6' => $common_arguments + array(
        'description' => t('Migration of user pictures from Drupal 6'),
        'class_name' => 'UGPicture6Migration',
        'default_uid' => 1,
        'source_dir' => $user_arguments['picture_source'],
        'destination_dir' => $user_arguments['picture_destination'],
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
        'source_vocabulary' => $term_arguments['source_term_keyword'],
        'destination_vocabulary' => 'tags',
      ),

      /**** FILE migration ****/
      'UGFile6' => $node_arguments + array(
        'description' => t('Migration of files from Drupal 6'),
        'class_name' => 'UGFile6Migration',
        'source_dir' => $file_arguments['source_directory'],
        'destination_dir' => $file_arguments['destination_directory'],
      ),

      /**** PAGE migration ****/
      'UGPageCategory6' => $common_arguments + array(
        'description' => t('Migration of page category terms from Drupal 6'),
        'class_name' => 'UGPageCategory6Migration',
        'source_vocabulary' => $page_arguments['source_page_term_category'], 
        'destination_vocabulary' => 'page_category',
      ),

      'UGPage6' => $node_arguments + $page_arguments + array(
        'description' => t('Migration of basic pages from Drupal 6'),
        'class_name' => 'UGPage6Migration',
        'source_type' => $page_arguments['source_page_node_type'], 
        'destination_type' => 'page',
        'dependencies' => array('UGFile6'),
      ),

      /**** NEWS migration ****/
      'UGNewsCategory6' => $common_arguments + array(
        'description' => t('Migration of news category terms from Drupal 6'),
        'class_name' => 'UGNewsCategory6Migration',
        'source_vocabulary' => $news_arguments['source_news_term_category'], 
        'destination_vocabulary' => 'news_category',
      ),

      'UGNewsKeyword6' => $common_arguments + array(
        'description' => t('Migration of news keyword terms from Drupal 6'),
        'class_name' => 'UGNewsKeyword6Migration',
        'source_vocabulary' => $news_arguments['source_news_term_keyword'],
        'destination_vocabulary' => 'tags',
      ),

      'UGNews6' => $node_arguments + $news_arguments + array(
        'description' => t('Migration of news articles from Drupal 6'),
        'class_name' => 'UGNews6Migration',
        'source_type' => $news_arguments['source_news_node_type'], 
        'destination_type' => 'news',
        'dependencies' => array('UGFile6'),
      ),

      /**** EVENT migration ****/
      'UGEventCategory6' => $common_arguments + array(
        'description' => t('Migration of event category terms from Drupal 6'),
        'class_name' => 'UGEventCategory6Migration',
        'source_vocabulary' => $event_arguments['source_event_term_category'], 
        'destination_vocabulary' => 'event_category',
      ),

      'UGEventKeyword6' => $common_arguments + array(
        'description' => t('Migration of event keyword terms from Drupal 6'),
        'class_name' => 'UGEventKeyword6Migration',
        'source_vocabulary' => $event_arguments['source_event_term_keyword'],
        'destination_vocabulary' => 'tags',
      ),

      'UGEventHeading6' => $common_arguments + array(
        'description' => t('Migration of events multipart field heading from Drupal 6'),
        'class_name' => 'UGEventHeading6Migration',
        'source_vocabulary' => $event_arguments['source_event_term_heading'],
        'destination_vocabulary' => 'event_heading',
      ),

      'UGEventMultifield6' => $common_arguments + $event_multipart_arguments + array(
        'description' => t('Migration of events multipart field from Drupal 6'),
        'class_name' => 'UGEventMultifield6Migration',
        'dependencies' => array('UGEvent6','UGEventHeading6'),
      ),

      'UGEvent6' => $node_arguments + $event_arguments + array(
        'description' => t('Migration of events from Drupal 6'),
        'class_name' => 'UGEvent6Migration',
        'source_type' => $event_arguments['source_event_node_type'], 
        'destination_type' => 'event',
        'dependencies' => array('UGFile6'),
      ),

      /**** FAQ migration ****/
      'UGFAQKeyword6' => $common_arguments + array(
        'description' => t('Migration of FAQ keyword terms from Drupal 6'),
        'class_name' => 'UGFAQKeyword6Migration',
        'source_vocabulary' => $faq_arguments['source_faq_term_keyword'],
        'destination_vocabulary' => 'tags',
      ),

      'UGFAQCategory6' => $common_arguments + array(
        'description' => t('Migration of FAQ category terms from Drupal 6'),
        'class_name' => 'UGFAQCategory6Migration',
        'source_vocabulary' => $faq_arguments['source_faq_term_category'],
        'destination_vocabulary' => 'faq_category',
      ),

      'UGFAQ6' => $node_arguments + $faq_arguments + array(
        'description' => t('Migration of FAQ from Drupal 6'),
        'class_name' => 'UGFAQ6Migration',
        'source_type' => $faq_arguments['source_faq_node_type'], 
        'destination_type' => 'faq',
      ),

      /**** MENU migration ****/
      'UGMenu6' => $menu_arguments + array(
        'description' => t('Migration of menus from Drupal 6'),
        'class_name' => 'UGMenu6Migration',
        'menu_names' => $menu_names,
      ),

      'UGMenuLinks6' => $menu_arguments + $menu_link_arguments + array(
        'description' => t('Migration of menu links from Drupal 6'),
        'class_name' => 'UGMenuLinks6Migration',
        'menu_names' => $menu_names,
      ),

    ),

  );

  return $api;
}
