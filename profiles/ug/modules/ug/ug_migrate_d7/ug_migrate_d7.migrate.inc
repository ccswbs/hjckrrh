
<?php

/*
* Implements hook_migrate_api()
*/

function ug_migrate_d7_migrate_api() {

  /* COMMON VARIABLES */
  $common_arguments = array(
    'source_connection' => 'legacy_d7',
    'source_version' => 7,
    'group_name' => 'ug_migrate_d7',
  );

  /* NODE VARIABLES */
  $node_arguments = $common_arguments + array(
    'user_migration' => 'UGUser7',
    'default_uid' => 1,
  );

  $page_arguments = array(
    'source_page_node_type' => 'page',
    'source_page_term_category' => '',
    'source_page_term_keyword' => '',
  );
  
  $book_arguments = array(
    'source_book_node_type' => 'book',
    'source_book_term_category' => '',
    'source_book_term_keyword' => '',
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

  $featureditem_arguments = array(
    'source_featureditem_node_type' => '',
    'source_featureditem_term_category' => '',
    'source_featureditem_term_keyword' => '',
  );

  $event_multipart_arguments = array();

  $faq_arguments = array(
    'source_faq_node_type' => '',
    'source_faq_term_category' => '',
    'source_faq_term_keyword' => '',
  );

  /* FILE VARIABLES */
  $file_arguments = array(
    'source_directory' => 'public://',
    'destination_directory' => 'public://',
  );

  /* USER VARIABLES */
  $user_arguments = array(
    'role_mappings' => array(),
  );

  /* TAXONOMY VARIABLES */
  $term_arguments = array(
    'source_term_keyword' => 'tags',
  );

  /* MENU VARIABLES */
  $menu_names = array('main-menu');

  $menu_link_arguments = array(
    'menu_migration' => 'UGMenu7',
    'node_migrations' => array('UGPage7', 'UGNews7', 'UGEvent7', 'UGFAQ7','UGFeaturedItem7'),
    'term_migrations' => array('UGTerm7', 'UGPageCategory7', 'UGNewsCategory7', 'UGNewsKeyword7', 'UGEventCategory7', 'UGEventKeyword7','UGFAQCategory7', 'UGFAQKeyword7','UGFeaturedItemCategory7'),
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
  $migrate_settings = 'migrate_settings_d7.php'; //generic config filegi (part of module)
  $migrate_settings_override = DRUPAL_ROOT . '/' . conf_path() . '/migrate_settings_d7.php'; //site config file

  include $migrate_settings;

  if (file_exists($migrate_settings_override)){
    include $migrate_settings_override;
  }

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
        'role_mappings' => $user_arguments['role_mappings'],
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
        'source_vocabulary' => $term_arguments['source_term_keyword'], 
        'destination_vocabulary' => 'tags',
      ),

      /**** FILE migration ****/
      'UGFile7' => $node_arguments + array(
        'description' => t('Migration of files from Drupal 7'),
        'class_name' => 'UGFile7Migration',
        'source_dir' => $file_arguments['source_directory'],
        'destination_dir' => $file_arguments['destination_directory'],
      ),

      /**** PAGE migration ****/
      'UGPageCategory7' => $common_arguments + array(
        'description' => t('Migration of page category terms from Drupal 7'),
        'class_name' => 'UGPageCategory7Migration',
        'source_vocabulary' => $page_arguments['source_page_term_category'], 
        'destination_vocabulary' => 'page_category',
      ),

      'UGPage7' => $node_arguments + $page_arguments + array(
        'description' => t('Migration of basic pages from Drupal 7'),
        'class_name' => 'UGPage7Migration',
        'source_type' => $page_arguments['source_page_node_type'], 
        'destination_type' => 'page',
        'dependencies' => array('UGFile7'),
      ),

      /**** BOOK migration ****/
      'UGBook7' => $node_arguments + $book_arguments + array(
        'description' => t('Migration of books from Drupal 7'),
        'class_name' => 'UGBook7Migration',
        'source_type' => $book_arguments['source_book_node_type'], 
        'destination_type' => 'book',
        'dependencies' => array('UGFile7'),
      ),

      'UGBookMenuLinks7' => $common_arguments + array(
        'description' => t('Migration of book menu links from Drupal 7'),
	'class_name' => 'UGBookMenuLinks7Migration',
	'node_migrations' => array('UGBook7'),
	'dependencies' => array('UGBook7'),
      ),

      'UGBookTable7' => $common_arguments + array(
        'description' => t('Migration of book table from Drupal 7'),
	'class_name' => 'UGBookTable7Migration',
	'node_migrations' => array('UGBook7'),
	'menu_link_migrations' => array('UGBookMenuLinks7'),
	'dependencies' => array('UGBook7', 'UGBookMenuLinks7'),
      ),
	      
      /**** NEWS migration ****/
      'UGNewsCategory7' => $common_arguments + array(
        'description' => t('Migration of news category terms from Drupal 7'),
        'class_name' => 'UGNewsCategory7Migration',
        'source_vocabulary' => $news_arguments['source_news_term_category'],
        'destination_vocabulary' => 'news_category',
      ),

      'UGNewsKeyword7' => $common_arguments + array(
        'description' => t('Migration of news keyword terms from Drupal 7'),
        'class_name' => 'UGNewsKeyword7Migration',
        'source_vocabulary' => $news_arguments['source_news_term_keyword'],
        'destination_vocabulary' => 'tags',
      ),

      'UGNews7' => $node_arguments + $news_arguments + array(
        'description' => t('Migration of news articles from Drupal 7'),
        'class_name' => 'UGNews7Migration',
        'source_type' => $news_arguments['source_news_node_type'], 
        'destination_type' => 'news',
        'dependencies' => array('UGFile7'),
      ),

      /**** EVENT migration ****/
      'UGEventCategory7' => $common_arguments + array(
        'description' => t('Migration of event category terms from Drupal 7'),
        'class_name' => 'UGEventCategory7Migration',
        'source_vocabulary' => $event_arguments['source_event_term_category'],
        'destination_vocabulary' => 'event_category',
      ),

      'UGEventKeyword7' => $common_arguments + array(
        'description' => t('Migration of events keyword terms from Drupal 7'),
        'class_name' => 'UGEventKeyword7Migration',
        'source_vocabulary' => $event_arguments['source_event_term_keyword'],
        'destination_vocabulary' => 'tags',
      ),

      'UGEventHeading7' => $common_arguments + array(
        'description' => t('Migration of events multipart field heading from Drupal 7'),
        'class_name' => 'UGEventHeading7Migration',
        'source_vocabulary' => $event_arguments['source_event_term_heading'],
        'destination_vocabulary' => 'event_heading',
      ),

      'UGEventMultifield7' => $common_arguments + $event_multipart_arguments + array(
        'description' => t('Migration of events multipart field from Drupal 7'),
        'class_name' => 'UGEventMultifield7Migration',
        'dependencies' => array('UGEvent7','UGEventHeading7'),
      ),

      'UGEvent7' => $node_arguments + $event_arguments + array(
        'description' => t('Migration of events from Drupal 7'),
        'class_name' => 'UGEvent7Migration',
        'source_type' => $event_arguments['source_event_node_type'], 
        'destination_type' => 'event',
        'dependencies' => array('UGFile7'),
      ),

      /**** FAQ migrations ****/
      'UGFAQKeyword7' => $common_arguments + array(
        'description' => t('Migration of FAQ keyword terms from Drupal 7'),
        'class_name' => 'UGFAQKeyword7Migration',
        'source_vocabulary' => $faq_arguments['source_faq_term_keyword'],
        'destination_vocabulary' => 'tags',
      ),

      'UGFAQCategory7' => $common_arguments + array(
        'description' => t('Migration of FAQ category terms from Drupal 7'),
        'class_name' => 'UGFAQCategory7Migration',
        'source_vocabulary' => $faq_arguments['source_faq_term_category'],
        'destination_vocabulary' => 'faq_category',
      ),

      'UGFAQ7' => $node_arguments + $faq_arguments + array(
        'description' => t('Migration of FAQ from Drupal 7'),
        'class_name' => 'UGFAQ7Migration',
        'source_type' => $faq_arguments['source_faq_node_type'], 
        'destination_type' => 'faq',
      ),

      /**** FEATURED ITEM migration ****/
      'UGFeaturedItemCategory7' => $common_arguments + array(
        'description' => t('Migration of featured item category terms from Drupal 7'),
        'class_name' => 'UGFeaturedItemCategory7Migration',
        'source_vocabulary' => $featureditem_arguments['source_featureditem_term_category'],
        'destination_vocabulary' => 'feature_category',
      ),

      'UGFeaturedItem7' => $node_arguments + $featureditem_arguments + array(
        'description' => t('Migration of featured items from Drupal 7'),
        'class_name' => 'UGFeaturedItem7Migration',
        'source_type' => $featureditem_arguments['source_featureditem_node_type'], 
        'destination_type' => 'feature',
        'dependencies' => array('UGFile7'),
      ),

      /**** MENU migration ****/
      'UGMenu7' => $menu_arguments + array(
        'description' => t('Migration of menus from Drupal 7'),
        'class_name' => 'UGMenu7Migration',
        'menu_names' => $menu_names,
      ),

      'UGMenuLinks7' => $menu_arguments + $menu_link_arguments + array(
        'description' => t('Migration of menu links from Drupal 7'),
        'class_name' => 'UGMenuLinks7Migration',
        'menu_names' => $menu_names,
      ),

    ) ,
  );

  return $api;
}

?>
