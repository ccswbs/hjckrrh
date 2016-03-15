<?php

/**
 * @file
 *   UG Book Drupal 7 migration.
 *
 *   Book migration happens in 3 steps.
 *
 *   Step 1: Migrate book pages (nodes)
 *   Step 2: Migrate book menu links (e.g. menu_name = book-toc-???)
 *   Step 3: Migrate the book table.
 */

/**
 * Book migration: Step 1: Migrate book pages
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
    $this->destination = new MigrateDestinationNode('book');
    // Remove any previously registered field mappings.
    $this->removeFieldMapping('title');
    $this->removeFieldMapping('body');
    // Map fields.
    $this->addFieldMapping('title', $this->sourceBookTitle);
    $this->addFieldMapping('body', $this->sourceBookBody);
  }
}

/*
 * Book migration: Step 2: Migrate book-toc menu links
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
 * Book migration: Step 3: Migrate the book table
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

