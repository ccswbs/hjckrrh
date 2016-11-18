<?php

/**
 * @file
 *   UG Book Drupal 7 migration.
 *
 *   Book migration happens in 3 steps.
 *
 *   Step 1: Migrate book category vocabulary & terms (taxonomy)
 *   Step 2: Migrate book keyword terms into tags vocabulary (taxonomy)
 *   Step 3: Migrate book pages (nodes)
 *   Step 4: Migrate book menu links (e.g. menu_name = book-toc-???)
 *   Step 5: Migrate the book table.
 */

/**
 * Book migration: Step 3: Migrate book pages
 */
class UGBook7Migration extends DrupalNode7Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import books from a D7 site.');
    if (isset($this->arguments['source_book_title'])) {
      $this->sourceBookTitle = $this->arguments['source_book_title'];
    }
    else {
      $this->sourceBookTitle = 'title';
    }
    if (isset($this->arguments['source_book_body'])) {
      $this->sourceBookBody = $this->arguments['source_book_body'];
    }
    else {
      $this->sourceBookBody = 'body';
    }

    /* DEFAULT arguments */
    $book_arguments = array(
      'source_book_body'                     => 'body',
      'source_book_body_summary'             => 'body:summary',
      'source_book_body_format'              => 'body:format',
      'source_book_attachments'               => 'field_book_attachments',
      'source_book_category'                 => 'field_book_category',
      'source_book_category_source_type'     => 'tid',
      'source_book_category_ignore_case'     => TRUE,
      'source_book_category_create_term'     => TRUE,
      'source_book_category_vocabulary'      => 'book_category',
      'source_book_category_default_value'   => '',
      'source_book_keyword'                  => 'field_tags',
      'source_book_keyword_source_type'      => 'tid',
      'source_book_keyword_ignore_case'      => TRUE,
      'source_book_keyword_create_term'      => TRUE,
      'source_book_keyword_vocabulary'       => 'tags',
      'source_book_keyword_default_value'    => '',
      'source_book_insert_fields'            => $book_insert_fields,
    );

    //Override default values with arguments if they exist
    foreach ($book_arguments as $key => $value) {
        if(isset($this->arguments[$key])){
          if($this->arguments[$key] != ''){
            $book_arguments[$key] = $this->arguments[$key];
          }
        }
    }

    $this->destination = new MigrateDestinationNode('book');

    // INSERT fields into Body variables
    $this->arguments['update_source_body'] = $book_arguments['source_book_body'];
    $this->arguments['update_insert_fields'] = $book_arguments['source_book_insert_fields'];

    // Remove any previously registered field mappings.
    $this->removeFieldMapping('title');
    $this->removeFieldMapping('body');
    $this->removeFieldMapping('body:summary');
    $this->removeFieldMapping('body:format');

    // Map Title and Body fields.
    $this->addFieldMapping('title', $this->sourceBookTitle);
    $this->addFieldMapping('body', $this->sourceBookBody);
    $this->addFieldMapping('body:summary', $book_arguments['source_book_summary']);

    // Map Body Format
    if($book_arguments['source_book_body'] == 'body'){
        $this->addFieldMapping('body:format', $book_arguments['source_book_format'])
          ->defaultValue('full_html');
    }else{
        $this->addFieldMapping('body:format', $book_arguments['source_book_format'])
          ->callbacks(array($this, 'mapFormat'))
          ->defaultValue('full_html');
    }

    // Map Book Category
    if($book_arguments['source_book_category_default_value']!=''){
      $this->addFieldMapping('field_book_category')
           ->defaultValue($book_arguments['source_book_category_default_value']);
    }else{
      $this->addFieldMapping('field_book_category', $book_arguments['source_book_category'])
           ->sourceMigration('UGBookCategory7');
    }
    $this->addFieldMapping('field_book_category:source_type')
         ->defaultValue($book_arguments['source_book_category_source_type']);
    $this->addFieldMapping('field_book_category:ignore_case')
         ->defaultValue($book_arguments['source_book_category_ignore_case']);
    $this->addFieldMapping('field_book_category:create_term')
         ->defaultValue($book_arguments['source_book_category_create_term']);

    // Map Book Keywords
    if($book_arguments['source_book_keyword_default_value']!=''){
      $this->addFieldMapping('field_tags')
           ->defaultValue($book_arguments['source_book_keyword_default_value']);
    }else{
      $this->addFieldMapping('field_tags', $book_arguments['source_book_keyword'])
           ->sourceMigration(array('UGTerm7','UGBookKeyword7'));
    }
    $this->addFieldMapping('field_tags:source_type')
         ->defaultValue($book_arguments['source_book_keyword_source_type']);
    $this->addFieldMapping('field_tags:ignore_case')
         ->defaultValue($book_arguments['source_book_keyword_ignore_case']);
    $this->addFieldMapping('field_tags:create_term')
         ->defaultValue($book_arguments['source_book_keyword_create_term']);

    // Map Book Attachments
    $this->addFieldMapping('field_book_attachments', $book_arguments['source_book_attachments'])
      ->sourceMigration('UGFile7');
      $this->addFieldMapping('field_book_attachments:file_class')
          ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_book_attachments:preserve_files')
          ->defaultValue('TRUE');
      $this->addFieldMapping('field_book_attachments:description', $book_arguments['source_book_attachments'] . ':description')
          ->defaultValue('');
      $this->addFieldMapping('field_book_attachments:language')
          ->defaultValue(LANGUAGE_NONE);

  }
}

/*
 * Book migration: Step 4: Migrate book-toc menu links
 */
class UGBookMenuLinks7Migration extends DrupalMenuLinks7Migration {

  /**
   * @param array $arguments
   *     $arguments['menu_migration'] should be defined -- menu links are normally
   *        dependent on menus.
   *     $arguments['menu_names'] is an optional array of menu names to migrate
   *        menu links from. If ommitted, all links from UI-generated menus will
   *        be migrated.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    // Migrate all book toc menus.
    unset($this->menu_names);
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param $row
   */
  public function prepareRow($row) {
    // D7 book menu name all start with 'book-toc-'.
    if (!(substr($row->menu_name, 0, 9) == 'book-toc-')) {
      return FALSE;
    }
    // Map node ID, path, etc.
    parent::prepareRow($row);
    // Extract source book ID from menu name.
    $matches = array();
    $regex = "/(?<=book-toc-)[\d]+(?=$)/";
    if (preg_match($regex, $row->menu_name, $matches)) {
      $source_bid = $matches[0];
    }
    else {
      return FALSE;
    }
    // Map source BID (source NID of top-level page) to destination BID.
    $dest_bid = $this->handleSourceMigration($this->{'node_migrations'}, $source_bid);
    // Map menu_name book-toc-{sourceid} to book-toc-{destid}.
    $row->menu_name = 'book-toc-' . $dest_bid;
  }
}

/**
 * Book migration: Step 5: Migrate the book table
 */
class UGBookTable7Migration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    if (!empty($arguments['source_connection'])) {
      $this->sourceConnection = $arguments['source_connection'];
    }
    if (!empty($arguments['node_migrations'])) {
      $this->nodeMigrations = (array) $arguments['node_migrations'];
    }
    if (!empty($arguments['menu_link_migrations'])) {
      $this->menuLinkMigrations = (array) $this->arguments['menu_link_migrations'];
    }
    $table_name = 'book';
    $this->description = "Migrate book table";
    $this->map = new MigrateSQLMap($this->machineName,
      array('mlid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => t('Source menu link ID'),
      )),
      MigrateDestinationTable::getKeySchema($table_name)
    );
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('book', 'b')->fields('b', array('mlid', 'nid', 'bid'));
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTable($table_name);
    $this->addSimpleMappings(array('mlid', 'nid', 'bid'));
  }
  public function prepareRow($row) {
    $row->nid = $this->handleSourceMigration($this->nodeMigrations, $row->nid);
    $row->bid = $this->handleSourceMigration($this->nodeMigrations, $row->bid);
    $row->mlid = $this->handleSourceMigration($this->menuLinkMigrations, $row->mlid);
  }
}


/**
 * Book migration: Step 1: Migrate book category vocabulary
 */
class UGBookCategory7Migration extends DrupalTerm7Migration {
  public function __construct($arguments) {
      parent::__construct($arguments);

  } 
}

/**
 * Book migration: Step 2: Migrate book keyword terms into tags vocabulary
 */
class UGBookKeyword7Migration extends DrupalTerm7Migration {
  public function __construct($arguments) {
      parent::__construct($arguments);

  } 
}


class UGUpdateBook7Migration extends UGUpdate7Migration {
  public function __construct($arguments) {
      parent::__construct($arguments);

    $this->destination = new MigrateDestinationNode('book');

      /* DEFAULT arguments */
    $update_arguments = array(
      'update_nodelinks' => FALSE,
      'update_nodelinks_urls' => '/node/',
      'update_hardlinks_source' => '',
      'update_hardlinks_destination' => '',
    );

      /* DEFAULT arguments */
      $book_arguments = array(
        'source_book_body'                     => 'body',
        'source_book_body_summary'             => 'body:summary',
        'source_book_body_format'              => 'body:format',
        'source_book_insert_fields'            => NULL,
      );

    //Override default values with arguments if they exist
    foreach ($book_arguments as $key => $value) {
        if(isset($this->arguments[$key])){
          if($this->arguments[$key] != ''){
            $book_arguments[$key] = $this->arguments[$key];
          }
        }
    }

    //Override default values with arguments if they exist
    foreach ($update_arguments as $key => $value) {
        if(isset($this->arguments[$key])){
          if($this->arguments[$key]!=''){
            $update_arguments[$key] = $this->arguments[$key];
          }
        }
    }

      $this->addFieldMapping('nid', 'nid')
      ->sourceMigration('UGBook7');
    $this->arguments['update_map_table'] = 'migrate_map_ugbook7';

      // Update body field
      $this->arguments['update_insert_fields'] = $book_arguments['source_course_insert_fields'];
    $this->arguments['update_source_body'] = $book_arguments['source_book_body'];


      $this->addFieldMapping('body', $book_arguments['source_book_body']);
      $this->addFieldMapping('body:summary', $book_arguments['source_book_summary']);

      // Map Body Format
      if($book_arguments['source_book_body'] == 'body'){
          $this->addFieldMapping('body:format', $book_arguments['source_book_format'])
            ->defaultValue('full_html');
      }else{
          $this->addFieldMapping('body:format', $book_arguments['source_book_format'])
            ->callbacks(array($this, 'mapFormat'))
            ->defaultValue('full_html');
      }
  }
}
