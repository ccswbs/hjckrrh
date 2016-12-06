<?php
/**
 * @file
 * Implementation of DrupalMenuMigration for Drupal 7 sources.
 */

/*
 * Class for menu migrations: from {menu_custom} into {menu_custom}.
 */
class DrupalMenu7Migration extends DrupalMenuMigration {

  /**
   * @param array $arguments
   * $arguments['menu_names'] is an optional array of menu names to migrate.
   *   If ommitted, all UI-generated menus will be migrated.
   */
  public function __construct(array $arguments) {

    // Do this before the parent constructor, so that the query will be right.
    if (!empty($arguments['menu_names'])) {
      $this->menu_names = $arguments['menu_names'];
    }

    parent::__construct($arguments);
  }

  protected $menu_names = array();

  /**
   * Query for the basic menu data.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('menu_custom', 'm')
             ->fields('m');

    if (!empty($this->menu_names)) {
      $query->condition('m.menu_name', $this->menu_names, 'IN');
    }

    return $query;
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // D7 prefixes menus added through the UI with 'menu-'. If 'menu_names'
    // was not specified in $arguments, then limit to these UI-added menus.
    if (empty($this->menu_names)) {
      return (substr($row->menu_name, 0, 5) === 'menu-');
    }
  }
}
