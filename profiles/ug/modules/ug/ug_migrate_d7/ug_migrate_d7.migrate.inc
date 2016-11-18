
<?php

/*
* Implements hook_migrate_api()
*/

function ug_migrate_d7_migrate_api() {

  $node_migrations = array(
    'UGPage7', 
    'UGNews7', 
    'UGEvent7', 
    'UGFAQ7',
    'UGFeaturedItem7',
    'UGProfile7',
    'UGCourseOutline7',
    'UGBanner7',
    'UGBook7',
  );

  $update_migrations = array(
    'UGUpdatePage7', 
    'UGUpdateNews7', 
    'UGUpdateEvent7', 
    'UGUpdateFAQ7',
    'UGUpdateFeaturedItem7',
    'UGUpdateProfile7',
    'UGUpdateCourseOutline7',
    'UGUpdateBanner7',
    'UGUpdateBook7',
  );

  $term_migrations = array(
    'UGTerm7', 
    'UGPageCategory7', 
    'UGPageKeyword7', 
    'UGNewsCategory7', 
    'UGNewsKeyword7', 
    'UGEventCategory7', 
    'UGEventKeyword7',
    'UGFAQCategory7', 
    'UGFAQKeyword7',
    'UGFeaturedItemCategory7',
    'UGFeaturedItemKeyword7',
    'UGProfileCategory7',
    'UGProfileKeyword7',
    'UGCourseOutlineCategory7',
    'UGCourseOutlineKeyword7',
    'UGCourseOutlineSemester7',
    'UGCourseOutlineLevel7',
    'UGCourseOutlineAcademicLevel7',
    'UGCourseOutlineSubject7',
    'UGCourseOutlineDepartment7',
    'UGBannerCategory7',
    'UGBannerKeyword7',
    'UGBookCategory7',
    'UGBookKeyword7',
  );


  /* UPDATE VARIABLES */
  $update_arguments = array(
    'update_nodelinks' => FALSE,
    'update_source_body' => 'body',
  );

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

  $profile_arguments = array(
    'source_profile_node_type' => 'profile',
    'source_profile_category_vocabulary' => '',
    'source_tags_vocabulary' => '',
  );

  $course_arguments = array(
    'source_course_node_type' => '',
    'source_course_category_vocabulary' => '',
    'source_course_keyword_vocabulary' => '',
    'source_course_academic_level_vocabulary' => '',
    'source_course_level_vocabulary' => '',
    'source_course_subject_vocabulary' => '',
    'source_course_semester_vocabulary' => '',
    'source_course_department_vocabulary' => '',
  );

  $banner_arguments = array(
    'source_banner_node_type' => 'banner',
    'source_banner_category_vocabulary' => '',
    'source_banner_keyword_vocabulary' => '',
  );

 
  $book_arguments = array(
    'source_book_node_type' => 'book',
    'source_book_category_vocabulary' => '',
    'source_book_keyword_vocabulary' => '',
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
    'node_migrations' => $node_migrations,
    'term_migrations' => $term_migrations,
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
      'UGPageKeyword7' => $common_arguments + array(
        'description' => t('Migration of page keyword terms from Drupal 7'),
        'class_name' => 'UGPageKeyword7Migration',
        'source_vocabulary' => $page_arguments['source_page_term_keyword'], 
        'destination_vocabulary' => 'tags',
      ),

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

      'UGFeaturedItemKeyword7' => $common_arguments + array(
        'description' => t('Migration of featured item keyword terms from Drupal 7'),
        'class_name' => 'UGFeaturedItemKeyword7Migration',
        'source_vocabulary' => $featureditem_arguments['source_featureditem_term_keyword'],
        'destination_vocabulary' => 'tags',
      ),

      'UGFeaturedItem7' => $node_arguments + $featureditem_arguments + array(
        'description' => t('Migration of featured items from Drupal 7'),
        'class_name' => 'UGFeaturedItem7Migration',
        'source_type' => $featureditem_arguments['source_featureditem_node_type'], 
        'destination_type' => 'feature',
        'dependencies' => array('UGFile7'),
      ),

      /**** PROFILE migration ****/
      'UGProfile7' => $node_arguments + $profile_arguments + array(
        'description' => t('Migration of profiles from Drupal 7'),
        'class_name' => 'UGProfile7Migration',
        'source_type' => $profile_arguments['source_profile_node_type'],
        'destination_type' => 'profile',
      ),
      
      'UGProfileRole7' => $common_arguments + array(
        'description' => t('Migration of profile role terms from Drupal 7'),
        'class_name' => 'UGProfileRole7Migration',
        'source_vocabulary' => $profile_arguments['source_profile_role_vocabulary'],
        'destination_vocabulary' => 'profile_role',
      ),

      'UGProfileUnit7' => $common_arguments + array(
        'description' => t('Migration of profile unit terms from Drupal 7'),
        'class_name' => 'UGProfileUnit7Migration',
        'source_vocabulary' => $profile_arguments['source_profile_unit_vocabulary'],
        'destination_vocabulary' => 'profile_unit',
      ),

      'UGProfileCategory7' => $common_arguments + array(
        'description' => t('Migration of profile category terms from Drupal 7'),
        'class_name' => 'UGProfileCategory7Migration',
        'source_vocabulary' => $profile_arguments['source_profile_category_vocabulary'],
        'destination_vocabulary' => 'profile_category',
      ),

      'UGProfileKeyword7' => $common_arguments + array(
        'description' => t('Migration of profile keyword terms from Drupal 7'),
        'class_name' => 'UGProfileKeyword7Migration',
        'source_vocabulary' => $profile_arguments['source_tags_vocabulary'],
        'destination_vocabulary' => 'tags',
      ),

      'UGProfileSubunit7' => $common_arguments + array(
        'description' => t('Migration of profile subunit terms from Drupal 7'),
        'class_name' => 'UGProfileSubunit7Migration',
        'source_vocabulary' => $profile_arguments['source_profile_subunit_vocabulary'],
        'destination_vocabulary' => 'profile_subunit',
      ),

      'UGProfileResearch7' => $common_arguments + array(
        'description' => t('Migration of profile research terms from Drupal 7'),
        'class_name' => 'UGProfileResearch7Migration',
        'source_vocabulary' => $profile_arguments['source_profile_research_vocabulary'],
        'destination_vocabulary' => 'profile_research',
      ),

      /**** COURSE OUTLINE migration ****/
      'UGCourseOutlineCategory7' => $common_arguments + array(
        'description' => t('Migration of course outline category terms from Drupal 7'),
        'class_name' => 'UGCourseOutlineCategory7Migration',
        'source_vocabulary' => $course_arguments['source_course_category_vocabulary'],
        'destination_vocabulary' => 'course_outline_category',
      ),

      'UGCourseOutlineKeyword7' => $common_arguments + array(
        'description' => t('Migration of course outline keyword terms from Drupal 7'),
        'class_name' => 'UGCourseOutlineKeyword7Migration',
        'source_vocabulary' => $course_arguments['source_course_keyword_vocabulary'],
        'destination_vocabulary' => 'tags',
      ),

      'UGCourseOutlineSemester7' => $common_arguments + array(
        'description' => t('Migration of course outline term (semester) terms from Drupal 7'),
        'class_name' => 'UGCourseOutlineSemester7Migration',
        'source_vocabulary' => $course_arguments['source_course_semester_vocabulary'],
        'destination_vocabulary' => 'course_outline_term',
      ),

      'UGCourseOutlineLevel7' => $common_arguments + array(
        'description' => t('Migration of course outline level terms from Drupal 7'),
        'class_name' => 'UGCourseOutlineLevel7Migration',
        'source_vocabulary' => $course_arguments['source_course_level_vocabulary'],
        'destination_vocabulary' => 'course_outline_level',
      ),

      'UGCourseOutlineAcademicLevel7' => $common_arguments + array(
        'description' => t('Migration of course outline academic level terms from Drupal 7'),
        'class_name' => 'UGCourseOutlineAcademicLevel7Migration',
        'source_vocabulary' => $course_arguments['source_course_academic_level_vocabulary'],
        'destination_vocabulary' => 'course_outline_academic_level',
      ),

      'UGCourseOutlineSubject7' => $common_arguments + array(
        'description' => t('Migration of course outline subject terms from Drupal 7'),
        'class_name' => 'UGCourseOutlineSubject7Migration',
        'source_vocabulary' => $course_arguments['source_course_subject_vocabulary'],
        'destination_vocabulary' => 'course_outline_subject',
      ),

      'UGCourseOutlineDepartment7' => $common_arguments + array(
        'description' => t('Migration of course outline department terms from Drupal 7'),
        'class_name' => 'UGCourseOutlineDepartment7Migration',
        'source_vocabulary' => $course_arguments['source_course_department_vocabulary'],
        'destination_vocabulary' => 'course_outline_department',
      ),

      'UGCourseOutline7' => $node_arguments + $course_arguments + array(
        'description' => t('Migration of course outlines from Drupal 7'),
        'class_name' => 'UGCourseOutline7Migration',
        'source_type' => $course_arguments['source_course_node_type'],
        'destination_type' => 'course_outline',
        'dependencies' => array('UGFile7'),
      ),

      /**** BANNER migration ****/
      'UGBannerKeyword7' => $common_arguments + array(
        'description' => t('Migration of Banner keyword terms from Drupal 7'),
        'class_name' => 'UGBannerKeyword7Migration',
        'source_vocabulary' => $banner_arguments['source_banner_keyword_vocabulary'],
        'destination_vocabulary' => 'tags',
      ),

      'UGBannerCategory7' => $common_arguments + array(
        'description' => t('Migration of Banner category terms from Drupal 7'),
        'class_name' => 'UGBannerCategory7Migration',
        'source_vocabulary' => $banner_arguments['source_banner_category_vocabulary'],
        'destination_vocabulary' => 'banner_category',
      ),

      'UGBanner7' => $node_arguments + $banner_arguments + array(
        'description' => t('Migration of Banner from Drupal 7'),
        'class_name' => 'UGBanner7Migration',
        'source_type' => $banner_arguments['source_banner_node_type'], 
        'destination_type' => 'banner',
        'dependencies' => array('UGFile7'),
      ),

      /**** MENU migration ****/
      'UGMenu7' => $menu_arguments + array(
        'description' => t('Migration of menus from Drupal 7'),
        'class_name' => 'UGMenu7Migration',
        'menu_names' => $menu_names,
        'dependencies' => $update_migrations,
      ),

      'UGMenuLinks7' => $menu_arguments + $menu_link_arguments + array(
        'description' => t('Migration of menu links from Drupal 7'),
        'class_name' => 'UGMenuLinks7Migration',
        'menu_names' => $menu_names,
        'dependencies' => $update_migrations,
      ),

      /**** UPDATE migration ****/
      'UGUpdatePage7' => $node_arguments + $update_arguments + $page_arguments + array(
        'description' => t('Update migrated page nodes after initial Drupal 7 to Drupal 7 migration'),
        'class_name' => 'UGUpdatePage7Migration',
        'source_type' => $page_arguments['source_page_node_type'], 
        'destination_type' => 'page',
        'dependencies' => $node_migrations,
      ),

      'UGUpdateNews7' => $node_arguments + $update_arguments + $news_arguments + array(
        'description' => t('Update migrated news nodes after initial Drupal 7 to Drupal 7 migration'),
        'class_name' => 'UGUpdateNews7Migration',
        'source_type' => $news_arguments['source_news_node_type'], 
        'destination_type' => 'news',
        'dependencies' => $node_migrations,
      ),

      'UGUpdateEvent7' => $node_arguments + $update_arguments + $event_arguments + array(
        'description' => t('Update migrated event nodes after initial Drupal 7 to Drupal 7 migration'),
        'class_name' => 'UGUpdateEvent7Migration',
        'source_type' => $event_arguments['source_event_node_type'], 
        'destination_type' => 'event',
        'dependencies' => $node_migrations,
      ),

      'UGUpdateFAQ7' => $node_arguments + $update_arguments + $faq_arguments + array(
        'description' => t('Update migrated faq nodes after initial Drupal 7 to Drupal 7 migration'),
        'class_name' => 'UGUpdateFAQ7Migration',
        'source_type' => $faq_arguments['source_faq_node_type'], 
        'destination_type' => 'faq',
        'dependencies' => $node_migrations,
      ),

      'UGUpdateFeaturedItem7' => $node_arguments + $update_arguments + $featureditem_arguments + array(
        'description' => t('Update migrated featured item nodes after initial Drupal 7 to Drupal 7 migration'),
        'class_name' => 'UGUpdateFeaturedItem7Migration',
        'source_type' => $featureditem_arguments['source_featureditem_node_type'], 
        'destination_type' => 'feature',
        'dependencies' => $node_migrations,
      ),

      'UGUpdateProfile7' => $node_arguments + $update_arguments + $profile_arguments + array(
        'description' => t('Update migrated profile nodes after initial Drupal 7 to Drupal 7 migration'),
        'class_name' => 'UGUpdateProfile7Migration',
        'source_type' => $profile_arguments['source_profile_node_type'], 
        'destination_type' => 'profile',
        'dependencies' => $node_migrations,
      ),

      'UGUpdateCourseOutline7' => $node_arguments + $update_arguments + $course_arguments + array(
        'description' => t('Update migrated course nodes after initial Drupal 7 to Drupal 7 migration'),
        'class_name' => 'UGUpdateCourseOutline7Migration',
        'source_type' => $course_arguments['source_course_node_type'], 
        'destination_type' => 'course_outline',
        'dependencies' => $node_migrations,
      ),

     'UGUpdateBanner7' => $node_arguments + $update_arguments + $banner_arguments + array(
        'description' => t('Update migrated banner nodes after initial Drupal 7 to Drupal 7 migration'),
        'class_name' => 'UGUpdateBanner7Migration',
        'source_type' => $banner_arguments['source_banner_node_type'], 
        'destination_type' => 'banner',
        'dependencies' => $node_migrations,
      ),

    ),

  );

  /* Book migration */
  if (db_table_exists('book')) {
    $api['migrations']['UGBook7'] = $node_arguments + $book_arguments + array(
      'description' => t('Migration of books from Drupal 7'),
      'class_name' => 'UGBook7Migration',
      'source_type' => $book_arguments['source_book_node_type'], 
      'destination_type' => 'book',
      'dependencies' => array('UGFile7'),
    );
    $api['migrations']['UGBookMenuLinks7'] = $common_arguments + array(
      'description' => t('Migration of book menu links from Drupal 7'),
      'class_name' => 'UGBookMenuLinks7Migration',
      'node_migrations' => array('UGBook7'),
      'dependencies' => array('UGBook7'),
    );
    $api['migrations']['UGBookTable7'] = $common_arguments + array(
      'description' => t('Migration of book table from Drupal 7'),
      'class_name' => 'UGBookTable7Migration',
      'node_migrations' => array('UGBook7'),
      'menu_link_migrations' => array('UGBookMenuLinks7'),
      'dependencies' => array('UGBook7', 'UGBookMenuLinks7'),
    );
    $api['migrations']['UGBookCategory7'] = $common_arguments + array(
      'description' => t('Migration of book category vocabulary + terms from Drupal 7'),
      'class_name' => 'UGBookCategory7Migration',
      'source_vocabulary' => $book_arguments['source_book_category_vocabulary'],
      'destination_vocabulary' => 'book_category',
    );
    $api['migrations']['UGBookKeyword7'] = $common_arguments + array(
      'description' => t('Migration of book keyword terms from Drupal 7'),
      'class_name' => 'UGBookKeyword7Migration',
      'source_vocabulary' => $book_arguments['source_book_keyword_vocabulary'],
      'destination_vocabulary' => 'tags',
    );
    $api['migrations']['UGUpdateBook7'] = $node_arguments + $update_arguments + $book_arguments + array(
      'description' => t('Update migrated book nodes after initial Drupal 7 to Drupal 7 migration'),
      'class_name' => 'UGUpdateBook7Migration',
      'source_type' => $book_arguments['source_book_node_type'], 
      'destination_vocabulary' => 'book',
      'dependencies' => $node_migrations,
    );
  }

  return $api;
}

?>
