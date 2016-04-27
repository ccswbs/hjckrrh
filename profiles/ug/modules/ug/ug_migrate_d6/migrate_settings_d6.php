<?php

  /*****************************
  SITE CONFIGURATION VARIABLES
  ******************************/

  $update_nodelinks_urls = array(
      //'/sitename/node/',
      //'http://www.uoguelph.ca/site-stub/node/',
      //'https://www.uoguelph.ca/site-stub/node/',
  );

  $update_hardlinks_source = array(
      //'http://www.uoguelph.ca/site-stub',
      //'https://www.uoguelph.ca/site-stub',
  );

  // Usage: define site_stub in specific site config file & set nodelinks to TRUE
  $update_arguments = array(
    'update_nodelinks' => FALSE,
    'update_nodelinks_urls' => $update_nodelinks_urls,
    'update_hardlinks_source' => $update_hardlinks_source,
    'update_hardlinks_destination' => '',
  );

  /* MENU Settings */
  $menu_names = array('primary-links');

  /* USER SETTINGS */
  $role_mappings = array(
    // e.g. 'source-editor' => 'editor',
  );

  $user_arguments = array(
    'role_mappings' => $role_mappings,
    'picture_source' => '',
    'picture_destination' => 'public://',
  );

  /* FILE SETTINGS */
  $file_arguments = array(
    'source_directory' => 'public://',
    'destination_directory' => 'public://',
  );

  /* TAXONOMY Settings */
  $term_arguments = array(
    'source_term_keyword' => 'tags',
  );

  /* PAGE Settings */
  $page_arguments = array(
    'source_page_node_type' => 'page',
    'source_page_term_category' => '',
    'source_page_term_keyword' => '',
    'source_page_body' => 'body',
    'source_page_summary' => 'body:summary',
    'source_page_format' => 'body:format',
    'source_page_category' => '',
    'source_page_keyword' => 'field_tags',
    'source_page_attachments' => 'upload',
    'source_page_image_src_prefix' => '',
  );
  
  /* NEWS Settings */
  $news_arguments = array(
    'source_news_node_type' => 'story',
    'source_news_term_category' => '',
    'source_news_term_keyword' => '',
    'source_news_body' => 'body',
    'source_news_summary' => 'body:summary',
    'source_news_format' => 'body:format',
    'source_news_category' => '',
    'source_news_keyword' => '',
    'source_news_writer' => '',
    'source_news_link' => '',
    'source_news_image' => '',
    'source_news_caption' => '',
    'source_news_attachment' => 'upload',
    'source_news_image_src_prefix' => '',
  );

  /* FAQ Settings */
  $faq_arguments = array(
    'source_faq_node_type' => '',
    'source_faq_term_category' => '',
    'source_faq_term_keyword' => '',
    'source_faq_answer' => 'body',
    'source_faq_format' => 'body:format',
    'source_faq_category' => '',
    'source_faq_keyword' => '',
  );

  /* EVENT Settings */
  $event_arguments = array(
    'source_event_node_type' => '',
    'source_event_term_category' => '',
    'source_event_term_keyword' => '',
    'source_event_term_heading' => '',
    'source_event_body' => 'body',
    'source_event_summary' => 'body:summary',
    'source_event_format' => 'body:format',
    'source_event_category' => '',
    'source_event_keyword' => '',
    'source_event_date' => '',
    'source_event_location' => '',
    'source_event_multipart' => '',
    'source_event_multipart_heading' => '',
    'source_event_multipart_content' => '',
    'source_event_image' => '',
    'source_event_caption' => '',
    'source_event_attachments' => 'upload',
    'source_event_link' => '',
    'source_event_image_src_prefix' => '',
  );

 /* EVENT Multipart (Field Collection) Settings */

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