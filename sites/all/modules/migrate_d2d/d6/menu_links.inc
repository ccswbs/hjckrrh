<?php
/**
 * @file
 * Implementation of DrupalMenuLinksMigration for Drupal 6 sources.
 */

/*
 * Class for menu link migrations: from {menu_links} into {menu_links}.
 */
class DrupalMenuLinks6Migration extends DrupalMenuLinksMigration {

  protected $menu_names = array();

  /**
   * @param array $arguments
   *     $arguments['menu_migration'] should be defined -- menu links are normally
   *        dependent on menus.
   *     $arguments['menu_names'] is an optional array of menu names to migrate
   *        menu links from. If ommitted, all links from UI-generated menus will
   *        be migrated.
   */
  public function __construct(array $arguments) {

    // Do this before the parent constructor, so that the query will be right.
    if (!empty($arguments['menu_names'])) {
      $this->menu_names = $arguments['menu_names'];
    }

    parent::__construct($arguments);

    // Most mappings are straightforward
    $this->addSimpleMappings(array('router_path', 'link_title',
        'module', 'hidden', 'external', 'has_children',
        'expanded', 'weight', 'depth', 'customized', 'p1', 'p2', 'p3', 'p4',
        'p5', 'p6', 'p7', 'p8', 'p9', 'updated', 'menu_name'));

    // plid is taken from this migration. If the parent hasn't yet been migrated,
    // we need to create a stub.
    $this->addFieldMapping('plid', 'plid')
         ->sourceMigration($this->getMachineName());

    // @todo: What do we do if pathing changes? Can/Should we make this dependent on
    //   an implementation of MigratePathEntityHandler, if it exists?
    // Most likely this will involve a callback.
    $this->addFieldMapping('link_path', 'link_path');

    // Ran into trouble with options, so I'm leaving it out for now
    $this->addUnmigratedSources(array('options'));
    $this->addUnmigratedDestinations(array('options'));
  }

  /**
   * Query for the basic menu_links data.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('menu_links', 'm')
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
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // D6 prefixes menus added through the UI with 'menu-'. If 'menu_names'
    // was not specified in $arguments, then limit to these UI-added menus,
    // as well as primary-links and secondary-links.
    if (empty($this->menu_names)) {
      if (!($row->menu_name == 'primary-links' ||
        $row->menu_name == 'secondary-links' ||
        substr($row->menu_name, 0, 5) == 'menu-')
      ) {
        return FALSE;
      }
    }

    if ($row->menu_name == 'primary-links') {
      $row->menu_name = 'main-menu';
    }
  }

  /**
   * Migrate menu link language, if set.
   */
  public function prepare($menu_link, $row) {
    $options = unserialize($row->options);
    if (isset($options['langcode']) && module_exists('i18n_menu')) {
      $menu_link->language = $options['langcode'];
    }
  }
}
