<?php

/**
 * @file
 *  Migrations for news.
 */

class UGDemoNewsMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import nodes.');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uuid' => array(
          'type' => 'char',
          'length' => 36,
          'not null' => FALSE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $import_path = drupal_get_path('module', 'ug_demo') . '/data/';
    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV($import_path . 'ug_demo.nodes.news.csv', $this->csvcolumns(), array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode('news');
    // Title
    $this->addFieldMapping('title', 'title');
    // Body
    $this->addFieldMapping('field_news_body', 'body');
    $this->addFieldMapping('field_news_body:format')->defaultValue('filtered_html');
    // Category
    $this->addFieldMapping('field_news_tags', 'category');
    // External link
    $this->addFieldMapping('field_news_link', 'link');
    // Image
    $this->addFieldMapping('field_news_image', 'image');
    $this->addFieldMapping('field_news_image:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_news_image:source_dir')->defaultValue($import_path . 'images');
    $this->addFieldMapping('field_news_image:destination_file', 'filename');
    // Caption
    $this->addFieldMapping('field_news_caption', 'caption');
    // Keywords
    $this->addFieldMapping('field_tags', 'keywords');
    // Created
    $this->addFieldMapping('created', 'created')->defaultValue(strtotime("now"));
  }

  function csvcolumns() {
    $columns[] = array('uuid', 'Node UUID');
    $columns[] = array('title', 'Title');
    $columns[] = array('attachment', 'Attachment');
    $columns[] = array('body', 'Body');
    $columns[] = array('category', 'Category');
    $columns[] = array('link', 'External link');
    $columns[] = array('image', 'Feature image');
    $columns[] = array('caption', 'Feature image caption');
    $columns[] = array('keywords', 'Keywords');
    $columns[] = array('byline', 'Written by');
    return $columns;
  }

  public function prepareRow($row) {
  }

}

