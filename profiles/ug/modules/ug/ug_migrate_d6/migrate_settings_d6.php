<?php

/*****************************
SITE CONFIGURATION VARIABLES
******************************/

/* ---- 
* 
*  UPDATE NODELINKS
*
*  Allows you to replace the source node ID with the destination node ID in body field links.
*  For example, /sitename/node/12 may become /sitename/node/84 to match the new post-migration node ID.
*
*  USAGE: Set update_nodelinks to TRUE in $update_arguments. 
*  Add list of any internal urls (relative and absolute) referencing /node in $update_nodelinks_urls.
*
* 'update_nodelinks' => TRUE,
*
*  $update_nodelinks_urls = array(
*      '/node/'
*      '/sitename/node/',
*      'http://www.uoguelph.ca/sitename/node/',
*      'https://www.uoguelph.ca/sitename/node/',
*  );
*
*/

/* ---- 
* 
*  UPDATE HARD-LINKED URLs in Body Field
*
*  Allows you to replace any absolute urls in the body field with relative urls.
*  For example, https://www.uoguelph.ca/sitename/pagename could become /sitename/pagename
*
*  Can also be used when updating the sitename.
*  For example, /oldsitename can be updated to /newsitename.
*
*  USAGE: Set update_nodelinks to TRUE in $update_arguments. 
*  Set update_hardlinks_destination to new URL in quotes.
*  Add list of any (old) absolute urls that you want to fix in $update_hardlinks_source.
*
* 'update_nodelinks' => TRUE,
* 'update_hardlinks_destination' => '/sitename',
*
*  $update_hardlinks_source = array(
*      'http://www.uoguelph.ca/sitename',
*      'https://www.uoguelph.ca/sitename',
*      'https://www.uoguelph.ca/oldsitename',
*      'http://www.uoguelph.ca/oldsitename',
*      '/oldsitename',
*  );
*
*/

/* ---- 
* 
*  UPDATE PREFIX SOURCE 
*
*  Allows you to update the prefix source for any inline files and images referenced in the body field.
*  For example, /oldsitename/sites/default could become completely/newname/sites/default
*
*  USAGE: Set update_prefix_inline to TRUE in $update_arguments. 
*  Set update_hardlinks_destination to new URL in quotes.
*  Add list of any (old) absolute urls that you want to fix in $update_prefix_source.
*
* 'update_prefix_inline' => TRUE,
* 'update_prefix_destination' => '/completely/newname/sites/default',
*
*  $update_prefix_source = array(
*      '/sitename/sites/default',
*      'http://www.uoguelph.ca/sitename/sites/default',
*      'https://www.uoguelph.ca/sitename/sites/default',
*  );
*
*/

$destination_sitestub = '';

/**************************
*  UPDATE NODE Settings
**************************/

  $update_nodelinks_urls = array(
      //'/sitename/node/',
      //'http://www.uoguelph.ca/site-stub/node/',
      //'https://www.uoguelph.ca/site-stub/node/',
  );

  $update_hardlinks_source = array(
      //'http://www.uoguelph.ca/site-stub',
      //'https://www.uoguelph.ca/site-stub',
  );

  $update_prefix_source = array(
      //'/sitename/sites/default',
      //'http://www.uoguelph.ca/sitename/sites/default',
      //'https://www.uoguelph.ca/sitename/sites/default',
  );

  // Usage: define site_stub in specific site config file & set nodelinks to TRUE
  $update_arguments = array(
    'update_nodelinks'             => FALSE,
    'update_nodelinks_urls'        => $update_nodelinks_urls,
    'update_hardlinks_source'      => $update_hardlinks_source,
    'update_hardlinks_destination' => $destination_sitestub,
    'update_prefix_inline'         => FALSE,
    'update_prefix_source'         => $update_prefix_source,
    'update_prefix_destination'    => '',
  );

/**************************
*  MENU Settings
**************************/

  $menu_names = array('primary-links');

/**************************
*  USER Settings
**************************/

  $role_mappings = array(
    // e.g. 'source-editor' => 'editor',
  );

  $user_arguments = array(
    'role_mappings'       => $role_mappings,
    'picture_source'      => '',
    'picture_destination' => 'public://',
  );

/**************************
*  FILE Settings
**************************/

  $file_arguments = array(
    'source_directory'      => 'public://',
    'destination_directory' => 'public://',
  );

/**************************
*  TAXONOMY Settings
**************************/

  $term_arguments = array(
    'source_term_keyword' => 'tags',
  );


/* ----
*
*  MAPPING TAXONOMIES
*
*  For D6 to D7 migrations, map the taxonomy ID to BOTH the field and vocabulary/term source for the taxonomy.
*
*  Examples:
*
*  'source_page_category'      => '8',
*  'source_page_term_category' => '8',
*
*  'source_profile_category'            => '7',
*  'source_profile_category_vocabulary' => '7',
* 
*/


/* ----
*
*  USING DEFAULT VALUES
*
*  Use with caution. Setting default value will override the value for all migrated rows.
*  To set multiple default values in one taxonomy, use an array.
*
*  Single value example: 'source_page_category_default_value' => 47,
*  Multi value example:  'source_page_keyword_default_value' => array(1,2,3),
* 
*/


/* ----
*
*  MAPPING CUSTOM TEXT FIELDS into Body field
*  
*  Allows you to add text field content directly into content type body field with a custom heading.
*
*  1. For each field, create an array containing the following key values:
*     - db_table: database table to retrieve text field
*     - db_field_value: database column to retrieve text field value
*     - db_field_entity_id: database column to retrieve entity_id value (ie. nid for node associated with field)
*     - content_before: Include any HTML content that needs to occur before the text field (eg. HTML heading)
*     - content_after: (optional) Include any HTML content that needs to occur after the text field (eg. separator, heading)
*     
        $field_page_custom_info2 = array(
          'db_table' => 'field_data_field_source_table_name',
          'db_field_value' => array('field_value_column2'),
          'db_field_entity_id' => 'field_entityid_column',
          'content_before' => '<h3>Custom Field Heading 2</h2>',
          'content_after' => '',
        );
*
*  2. Add each field from the previous step into a field grouping array, using the machine name as the key (see $page_intro_fields as example).
*     Place fields in the order you would like them to display.
*     
        $page_intro_fields = array(
          'field_machine_name1' => $field_page_custom_info1,
        );
*
*  3. For each field group, create an array containing the following key values:
*     - fields: Array containing a list of all fields in this group, using machine_name as key (see $page_intro as example)
*     - content_before: Include any HTML content that needs to occur before the field group (eg. HTML heading)
*     - content_after: (optional) Include any HTML content that needs to occur after the field group (eg. separator, heading)
*     - placement: Each field group can be set to "top" (above target) or "bottom" (below target). Default is bottom.
*
        $page_intro = array(
          'fields' => $page_intro_fields,
          'content_before' => '<h2>Introduction</h2>',
          'content_after' => '',
          'placement' => 'top',
        );
*
*  4. Add each field group from the previous step into an array containing all field groups.
*
        $page_field_groups = array(
          $page_intro,
        );
*
*  5. For each content type insert, set the <content-type>_insert_fields array to the following key values:
*     - target: Specify the target field machine_name to insert fields (Variable unused at this time)
*     - before_target: Include any HTML content that needs to occur before the target field (eg. HTML heading)
*     - after_target: (optional) Include any HTML content that needs to occur after the target field
*     - field_groups: Array containing a list of all field groups
*  
        $page_insert_fields = array(
          'target' => 'body',
          'before_target' => '<h2>Description</h2>',
          'after_target' => '',
          'field_groups' => $page_field_groups,
        );
*
*/

$image_src_prefix = $destination_sitestub;

/**************************
*  PAGE Settings
**************************/

  $page_insert_fields = NULL;
  $page_arguments = array(
    'source_page_node_type'              => 'page',
    'source_page_term_category'          => '',
    'source_page_term_keyword'           => '',
    'source_page_body'                   => 'body',
    'source_page_summary'                => 'body:summary',
    'source_page_format'                 => 'body:format',
    'source_page_category'               => '',
    'source_page_category_default_value' => '',
    'source_page_keyword'                => 'field_tags',
    'source_page_keyword_default_value'  => '',
    'source_page_attachments'            => 'upload',
    'source_page_image_src_prefix'       => $image_src_prefix,
    'source_page_insert_fields'          => $page_insert_fields,
  );
  
/**************************
*  NEWS Settings
**************************/

  $news_insert_fields = NULL;
  $news_arguments = array(
    'source_news_node_type'              => 'story',
    'source_news_term_category'          => '',
    'source_news_term_keyword'           => '',
    'source_news_body'                   => 'body',
    'source_news_summary'                => 'body:summary',
    'source_news_format'                 => 'body:format',
    'source_news_category'               => '',
    'source_news_category_default_value' => '',
    'source_news_keyword'                => '',
    'source_news_keyword_default_value'  => '',
    'source_news_writer'                 => '',
    'source_news_link'                   => '',
    'source_news_image'                  => '',
    'source_news_caption'                => '',
    'source_news_attachment'             => 'upload',
    'source_news_image_src_prefix'       => $image_src_prefix,
    'source_news_insert_fields'          => $news_insert_fields,
  );

/**************************
*  FAQ Settings
**************************/

  $faq_insert_fields = NULL;
  $faq_arguments = array(
    'source_faq_node_type'              => '',
    'source_faq_term_category'          => '',
    'source_faq_term_keyword'           => '',
    'source_faq_answer'                 => 'body',
    'source_faq_format'                 => 'body:format',
    'source_faq_category'               => '',
    'source_faq_category_default_value' => '',
    'source_faq_keyword'                => '',
    'source_faq_keyword_default_value'  => '',
    'source_faq_image_src_prefix'       => $image_src_prefix,
    'source_faq_insert_fields'          => $faq_insert_fields,
  );

/**************************
*  FEATURED ITEM Settings
**************************/

  $featureditem_insert_fields = NULL;
  $featureditem_arguments = array(
    'source_featureditem_node_type'              => '',
    'source_featureditem_term_category'          => '',
    'source_featureditem_term_keyword'           => '',
    'source_featureditem_body'                   => 'body',
    'source_featureditem_summary'                => 'body:summary',
    'source_featureditem_format'                 => 'body:format',
    'source_featureditem_link'                   => '',
    'source_featureditem_image'                  => '',
    'source_featureditem_category'               => '',
    'source_featureditem_category_default_value' => '',
    'source_featureditem_keyword'                => '',
    'source_featureditem_keyword_default_value'  => '',
    'source_featureditem_image_src_prefix'       => $image_src_prefix,
    'source_featureditem_insert_fields'          => $featureditem_insert_fields,
  );

/**************************
*  EVENT Settings
**************************/

  $event_insert_fields = NULL;
  $event_arguments = array(
    'source_event_node_type'              => '',
    'source_event_term_category'          => '',
    'source_event_term_keyword'           => '',
    'source_event_term_heading'           => '',
    'source_event_body'                   => 'body',
    'source_event_summary'                => 'body:summary',
    'source_event_format'                 => 'body:format',
    'source_event_category'               => '',
    'source_event_category_default_value' => '',
    'source_event_keyword'                => '',
    'source_event_keyword_default_value'  => '',
    'source_event_date'                   => '',
    'source_event_location'               => '',
    'source_event_multipart'              => '',
    'source_event_multipart_heading'      => '',
    'source_event_multipart_content'      => '',
    'source_event_image'                  => '',
    'source_event_caption'                => '',
    'source_event_attachments'            => 'upload',
    'source_event_link'                   => '',
    'source_event_image_src_prefix'       => $image_src_prefix,
    'source_event_insert_fields'          => $event_insert_fields,
  );


/**************************
*  PROFILE Settings
**************************/

  $profile_insert_fields = NULL;
  $profile_arguments = array(
    'source_profile_node_type'              => '',
    'source_profile_name'                   => '',
    'source_profile_lastname'               => '',
    'source_profile_role'                   => '',
    'source_profile_role_source_type'       => 'tid',
    'source_profile_role_ignore_case'       => TRUE,
    'source_profile_role_create_term'       => TRUE,
    'source_profile_role_vocabulary'        => '',
    'source_profile_role_default_value'     => '',
    'source_profile_unit'                   => '',
    'source_profile_unit_source_type'       => 'tid',
    'source_profile_unit_ignore_case'       => TRUE,
    'source_profile_unit_create_term'       => TRUE,
    'source_profile_unit_vocabulary'        => '',
    'source_profile_unit_default_value'     => '',
    'source_profile_summary'                => 'body',
    'source_profile_format'                 => 'body:format',
    'source_profile_category'               => '',
    'source_profile_category_source_type'   => 'tid',
    'source_profile_category_ignore_case'   => TRUE,
    'source_profile_category_create_term'   => TRUE,
    'source_profile_category_vocabulary'    => '',
    'source_profile_category_default_value' => '',
    'source_profile_title'                  => '',
    'source_profile_subunit'                => '',
    'source_profile_subunit_source_type'    => 'tid',
    'source_profile_subunit_ignore_case'    => TRUE,
    'source_profile_subunit_create_term'    => TRUE,
    'source_profile_subunit_vocabulary'     => '',
    'source_profile_subunit_default_value'  => '',
    'source_profile_research'               => '',
    'source_profile_research_source_type'   => 'tid',
    'source_profile_research_ignore_case'   => TRUE,
    'source_profile_research_create_term'   => TRUE,
    'source_profile_research_vocabulary'    => '',
    'source_profile_research_default_value' => '',
    'source_profile_attachments'            => 'upload',
    'source_profile_image'                  => '',
    'source_profile_caption'                => '',
    'source_profile_address'                => '',
    'source_profile_email'                  => '',
    'source_profile_telephonenumber'        => '',
    'source_profile_faxnumber'              => '',
    'source_profile_office'                 => '',
    'source_profile_lab'                    => '',
    'source_profile_website'                => '',
    'source_tags'                           => '',
    'source_tags_source_type'               => 'tid',
    'source_tags_ignore_case'               => TRUE,
    'source_tags_create_term'               => TRUE,
    'source_tags_vocabulary'                => '',
    'source_tags_default_value'             => '',
    'source_profile_image_src_prefix'       => $image_src_prefix,
    'source_profile_insert_fields'          => $profile_insert_fields,
  );

/**************************
*  BANNER Settings
**************************/

  $banner_insert_fields = NULL;

  $banner_arguments = array(
    'source_banner_node_type'                => 'banner',
    'source_banner_headline'                 => 'field_banner_headline',
    'source_banner_headline_format'          => 'field_banner_headline:format',
    'source_banner_text'                     => 'field_banner_text',
    'source_banner_text_format'              => 'field_banner_text:format',
    'source_banner_category'                 => 'field_banner_category',
    'source_banner_category_source_type'     => 'tid',
    'source_banner_category_ignore_case'     => TRUE,
    'source_banner_category_create_term'     => TRUE,
    'source_banner_category_vocabulary'      => 'banner_category',
    'source_banner_category_default_value'   => '',
    'source_banner_link'                     => 'field_banner_link',
    'source_banner_image'                    => 'field_banner_image',
    'source_banner_alttext'                  => 'field_banner_alttext',
    'source_banner_keyword'                  => 'field_tags',
    'source_banner_keyword_source_type'      => 'tid',
    'source_banner_keyword_ignore_case'      => TRUE,
    'source_banner_keyword_create_term'      => TRUE,
    'source_banner_keyword_vocabulary'       => 'tags',
    'source_banner_keyword_default_value'    => '',
    'source_banner_weight'                   => 'field_banner_weight',
    'source_banner_image_src_prefix'         => $image_src_prefix,
    'source_banner_insert_fields'            => $banner_insert_fields,
  );

/**************************
*  COURSE OUTLINE Settings
**************************/

  $course_insert_fields = NULL;

  $course_arguments = array(
    'source_course_node_type'                    => 'course_outline',
    'source_course_title'                        => 'field_course_title',
    'source_course_name'                         => 'field_course_name',
    'source_course_code'                         => 'field_course_code',
    'source_course_section'                      => 'field_course_section',
    'source_course_category'                     => 'field_course_category',
    'source_course_category_vocabulary'          => 'course_outline_category',
    'source_course_category_default_value'       => '',
    'source_course_category_source_type'         => 'tid',
    'source_course_category_ignore_case'         => TRUE,
    'source_course_category_create_term'         => TRUE,
    'source_course_semester'                     => 'field_course_term',
    'source_course_semester_vocabulary'          => 'course_outline_term',
    'source_course_semester_default_value'       => '',
    'source_course_semester_source_type'         => 'tid',
    'source_course_semester_ignore_case'         => TRUE,
    'source_course_semester_create_term'         => TRUE,
    'source_course_level'                        => 'field_course_level',
    'source_course_level_vocabulary'             => 'course_outline_level',
    'source_course_level_default_value'          => '',
    'source_course_level_source_type'            => 'tid',
    'source_course_level_ignore_case'            => TRUE,
    'source_course_level_create_term'            => TRUE,
    'source_course_academic_level'               => 'field_course_acad_level', 
    'source_course_academic_level_vocabulary'    => 'course_outline_academic_level',
    'source_course_academic_level_default_value' => '',
    'source_course_academic_level_source_type'   => 'tid',
    'source_course_academic_level_ignore_case'   => TRUE,
    'source_course_academic_level_create_term'   => TRUE,
    'source_course_subject'                      => 'field_course_subject',
    'source_course_subject_vocabulary'           => 'course_outline_subject',
    'source_course_subject_default_value'        => '',
    'source_course_subject_source_type'          => 'tid',
    'source_course_subject_ignore_case'          => TRUE,
    'source_course_subject_create_term'          => TRUE,
    'source_course_department'                   => 'field_course_department',
    'source_course_department_vocabulary'        => 'course_outline_department',
    'source_course_department_default_value'     => '',
    'source_course_department_source_type'       => 'tid',
    'source_course_department_ignore_case'       => TRUE,
    'source_course_department_create_term'       => TRUE,
    'source_course_instructor'                   => 'field_course_instructor', 
    'source_course_instructor_url'               => 'field_course_instructor_url',
    'source_course_body'                         => 'field_course_body',
    'source_course_summary'                      => 'field_course_body:summary',
    'source_course_format'                       => 'field_course_body:format',
    'source_course_website'                      => 'field_course_website',
    'source_course_attachments'                  => 'field_course_attachments',
    'source_course_keyword'                      => 'field_tags',
    'source_course_keyword_vocabulary'           => '',
    'source_course_keyword_default_value'        => '',
    'source_course_keyword_source_type'          => 'tid',
    'source_course_keyword_ignore_case'          => TRUE,
    'source_course_keyword_create_term'          => TRUE,
    'source_course_image_src_prefix'             => $image_src_prefix,
    'source_course_insert_fields'                => $course_insert_fields,
  );




/**************************
*  EVENT MULTIPART (Field Collection) Settings
**************************/

/******
*
*   VARIABLES
*
*   $event_multipart_query: Contains SOURCE database query for collecting event field collection heading + content
*   $event_multipart_sourcefields: Contains array of source fields (heading + content) used in event field collection
*   $event_multipart_mapping: Contains mapping for field collection ID
*
******/

/******
*
*   SAMPLE CODE:
*
*   $event_multipart_query = Database::getConnection('default','legacy_d7')
*     -> select('tableA', 'tableA_alias');
*
*   $event_multipart_query->join('tableB','tableB_alias','tableA_alias.fieldCollectionID = tableB_alias.id');
*   $event_multipart_query->join('tableC','tableC_alias','tableA_alias.fieldCollectionID = tableC_alias.id');
*
*   $event_multipart_query->fields('tableA',array('eventID', 'fieldCollectionID'));
*   $event_multipart_query->fields('tableB',array('id','heading'));
*   $event_multipart_query->fields('tablec',array('id','content'));
*
*   $event_multipart_sourcefields = array(
*       'heading' => 'Field Collection Heading Term ID',
*       'content' => 'Field Collection Content',
*   );
*
*
*  $event_multipart_mapping = array(
*    'fieldCollectionID' => array(
*      'type' => 'int',
*      'not signed' => true,
*      'not null' => true,
*      'description' => t('Field Collection ID'),
*      'alias' => 'f',
*    ),
*  );
*
*/

  $event_multipart_query = NULL; //database query for field collection heading + content
  $event_multipart_sourcefields = array();
  $event_multipart_mapping = NULL;

  /* Field collection ID, heading termID, and content fields should match fields retrieved by query */
  $event_multipart_arguments = array(
    'source_event_multipart_query' => $event_multipart_query,
    'source_event_multipart_sourcefields' => $event_multipart_sourcefields,
    'source_event_multipart_mapping' => $event_multipart_mapping,
    'source_event_multipart_field_collection_ID'=>'',
    'source_event_multipart_field_collection_heading_termID'=>'',
    'source_event_multipart_field_collection_content'=>'',
  );

?>