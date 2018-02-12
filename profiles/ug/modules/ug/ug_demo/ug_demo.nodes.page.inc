<?php

/**
 * @file
 * Migrations for page nodes.
 */

class UGDemoPageMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migrate UG demo content.');
    $bundle = $arguments['bundle'];
    $machine_name = $this->machineName;
    $source_key = array();
    $source_key['nid'] = array();
    $source_key['nid']['type'] = 'int';
    $source_key['nid']['not null'] = TRUE;
    $source_key['nid']['description'] = 'Node ID';
    $destination_key = MigrateDestinationNode::getKeySchema();
    $this->map = new MigrateSQLMap($machine_name, $source_key, $destination_key);
    $import_path = drupal_get_path('module', 'ug_demo') . '/data/';
    $path = $import_path . 'ug_demo.nodes.page.csv';
    $csvcolumns = array();
    $csvcolumns[0] = array('nid', 'NID');
    $csvcolumns[1] = array('title', 'Title');
    $csvcolumns[2] = array('body', 'Body');
    $csvcolumns[3] = array('category', 'Category');
    $options = array('header_rows' => 1);
    $fields = array();
    $fields['uid'] = 'User ID';
    $this->source = new MigrateSourceCSV($path, $csvcolumns, $options, $fields);
    $this->destination = new MigrateDestinationNode('page');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_page_body', 'body');
    $this->addFieldMapping('field_page_body:format')->defaultValue('filtered_html');
    $this->addFieldMapping('field_page_category', 'category');
  }

  public function prepareRow($row) {
    $row->uid = 0;
  }

  protected function generateMachineName($class_name = NULL) {
    return drupal_strtolower(pathinfo($this->arguments['source_file'], PATHINFO_FILENAME));
  }
}

