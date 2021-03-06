<?php
/**
 * @file
 * Base class for migrating menu links into Drupal.
 */

/*
 * Class for menu link migrations: from {menu_links} into {menu_links}.
 */
abstract class DrupalMenuLinksMigration extends DrupalMigration {

  protected $menu_migration = '';
  protected $node_migrations = array();
  protected $term_migrations = array();
  protected $path_migration = '';

  /**
   * @param array $arguments
   *     $arguments['menu_migration'] should be defined -- menu links are normally
   *        dependent on menus.
   *     $arguments['node_migrations'] is an optional array of node migrations,
   *        required in order to update nids in link_path
   *     $arguments['term_migrations'] is an optional array of term migrations,
   *        required in order to update tids in link_path
   *     $arguments['path_migration'] is an optional string defining the path migration,
   *        required in order to update URL aliases in link_path
   */
  public function __construct(array $arguments) {
    if (!empty($arguments['menu_migration'])) {
      $this->menu_migration = $arguments['menu_migration'];
      $this->dependencies[] = $this->menu_migration;
    }
    if (!empty($arguments['node_migrations'])) {
      $this->node_migrations = $arguments['node_migrations'];
      foreach ($this->node_migrations as $node_migration) {
        $this->dependencies[] = $node_migration;
      }
    }
    if (!empty($arguments['term_migrations'])) {
      $this->term_migrations = $arguments['term_migrations'];
      foreach ($this->term_migrations as $term_migration) {
        $this->dependencies[] = $term_migration;
      }
    }
    if (!empty($arguments['path_migration'])) {
      $this->path_migration = $arguments['path_migration'];
      $this->dependencies[] = $this->path_migration;
    }

    parent::__construct($arguments);

    // Create our three main objects - source, destination, and map
    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->destination = new MigrateDestinationMenuLinks();

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'mlid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'ID of destination link',
        ),
      ),
      MigrateDestinationMenuLinks::getKeySchema()
    );
  }

  /**
   * Creates a stub menu link, for when a child is imported before its parent
   *
   * @param $migration
   *  The source migration
   * @return
   *  int $mlid on success
   *  FALSE on failure
   */
  protected function createStub($migration) {
    // if plid is 0, that means it has no parent, so don't create a stub
    if (!$migration->sourceValues->plid) {
      return FALSE;
    }
    $menu_link = array(
      'menu_name' => $migration->sourceValues->menu_name,
      'link_path' => 'stub-path',
      'router_path' => 'stub-path',
      'link_title' => t('Stub title'),
    );
    $mlid = menu_link_save($menu_link);
    if ($mlid) {
      return array($mlid);
    }
    else {
      return FALSE;
    }
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param $row
   */
  function prepareRow($row) {

    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    /*
     * Fun with link_path!
     *
     * check for nids
     *   if pattern 'node/nid', replace nid with handleSourceMigration($node_migrations, $nid)
     * check for tids
     *   if pattern 'term/tid', replace tid with handleSourceMigration($term_migrations, $tid)
     * check for potential alias (after basepath, I believe)
     *   if (handleSourceMigration($path_migration, $potentialalias), replace potentialalias with result
     */

    // Grabs numbers preceded by 'node/', followed by end of string or '/'
    // eg: 'node/63' -> '63', 'node/17/edit' -> '17', 'node/53ea' -> NULL
    $regexes = array(
      'node_migrations' => "/(?<=node\/)[\d]+(?=$|\/)/",
      'term_migrations' => "/(?<=taxonomy\/term\/)[\d]+(?=$|\/)/",
    );
    // @todo: extend the lookbehind so it returns NULL for inputs like 'awetnode/34'

    foreach ($regexes as $property => $regex) {

      $matches = array();
      $value = '';

      if (!empty($this->{$property})) {

        if (preg_match($regex, $row->link_path, $matches)) {
          if ($value = $this->handleSourceMigration($this->{$property}, $matches[0])) {
            $new_path = preg_replace('/' . $matches[0] . '/', $value, $row->link_path);
            if ($new_path) {
              $row->link_path = $new_path;
            }
          }
        }
      }
    }

    // @todo: handle url_alias
  }
}
