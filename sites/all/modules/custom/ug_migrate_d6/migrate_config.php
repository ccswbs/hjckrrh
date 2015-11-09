<?php

  /*****************************
  SITE CONFIGURATION VARIABLES
  (source => destination)
  ******************************/

  /* USER SETTINGS */
  $role_mappings = array(
    'source-d6-editor' => 'editor',
  );

  /* TAXONOMY Settings */
  $term_keyword_source = '2'; //comuspicloto'
  $term_page_category_source = '3';
  $term_news_keyword_source = '2'; //comuspicloto'
  $term_news_category_source = '1'; //locl

  /* PAGE Settings */
  $node_page_type_source = 'page';

  $page_arguments = array(
  	'source_page_body' => 'body',
    'source_page_format' => 'body:format',
    'source_page_category' => '3',
    'source_page_keyword' => '2',
  );

  /* NEWS Settings */
  $node_news_type_source = 'story';

  $news_arguments = array(
  	'source_news_body' => 'body',
    'source_news_format' => 'body:format',
	'source_news_category' => '1', //locl
	'source_news_keyword' => '2', //comuspicloto'
  );

  /* Picture Settings */
  $picture_source = '/Applications/MAMP/htdocs/tempsite/drupal-6.37/';
  $picture_destination = 'public://';

  /************************************************/

?>