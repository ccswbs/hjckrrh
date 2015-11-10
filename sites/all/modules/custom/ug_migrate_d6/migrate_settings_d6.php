<?php

  /*****************************
  SITE CONFIGURATION VARIABLES
  (source => destination)
  ******************************/

  /* USER SETTINGS */
  $role_mappings = array(
    //'source-d6-editor' => 'editor',
  );

  /* Picture Settings */
  $picture_source = '';
  $picture_destination = 'public://';

  /* TAXONOMY Settings */
  //Note: for D6, use term id

  $term_keyword_source = ''; 
  $term_news_keyword_source = '';
  $term_event_keyword_source = '';

  $term_page_category_source = ''; 
  $term_news_category_source = '';
  $term_event_category_source = '';

  /* PAGE Settings */
  $node_page_type_source = 'page';

  $page_arguments = array(
  	'source_page_body' => 'body',
    'source_page_format' => 'body:format',
    'source_page_category' => '',
    'source_page_keyword' => '',
  );

  /* NEWS Settings */
  $node_news_type_source = 'story';

  $news_arguments = array(
  	'source_news_body' => 'body',
    'source_news_format' => 'body:format',
  	'source_news_category' => '',
  	'source_news_keyword' => '',
  );

  /* EVENT Settings */
  $node_event_type_source = '';

  $event_arguments = array(
    'source_event_body' => 'body',
    'source_event_format' => 'body:format',
    'source_event_category' => '',
    'source_event_keyword' => '',
  );

  /************************************************/

?>