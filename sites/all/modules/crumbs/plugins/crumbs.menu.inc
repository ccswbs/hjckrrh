<?php


/**
 * Implementation of hook_crumbs_plugins()
 *
 * @param crumbs_InjectedAPI_hookCrumbsPlugins $api
 */
function menu_crumbs_plugins($api) {
  $api->multiPlugin('hierarchy');
  $api->multiPlugin('link_title');
  $api->disabledByDefault('hierarchy.*');
  $api->disabledByDefault('link_title.*');
}


class menu_CrumbsMultiPlugin_hierarchy implements crumbs_MultiPlugin_FindParentInterface {

  /**
   * {@inheritdoc}
   */
  function describe($api) {
    foreach (menu_get_menus() as $key => $title) {
      $api->ruleWithLabel($key, $title, t('Menu'));
    }
    $api->descWithLabel(t('The parent item\'s path'), t('Parent'));
  }

  /**
   * {@inheritdoc}
   */
  function findParent($path, $item) {
    // Support for special_menu_items module.
    /* @see crumbs_menu() */
    /* @see menu_link_load() */
    if ('crumbs/special-menu-item/%' === $item['route']) {
      return $this->specialMenuItemFindParent($item);
    }

    $q = db_select('menu_links', 'child');
    // Join the parent item, but allow for toplevel items without a parent.
    $q->leftJoin('menu_links', 'parent', 'parent.mlid = child.plid');
    $q->addExpression('parent.link_path', 'parent_path');
    $q->addExpression('child.menu_name', 'menu_name');
    $q->addExpression('child.plid', 'plid');
    $q->condition('child.link_path', $path);

    if (module_exists('i18n_menu')) {
      // Filter and sort by language.
      // The 'language' column only exists if i18n_menu is installed.
      // (See i18n_menu_install())
      $language = LANGUAGE_NONE;
      if (isset($GLOBALS['language'])) {
        $language = array($language, $GLOBALS['language']->language);
      }
      $q->condition('child.language', $language);
    }

    // Top-level links have higher priority.
    $q->orderBy('child.depth', 'ASC');

    // Collect candidates for the parent path, keyed by menu name.
    $candidates = array();
    foreach ($q->execute() as $row) {
      if (!array_key_exists($row->menu_name, $candidates)) {
        if ('<separator>' === $row->parent_path) {
          // Ignore separator menu items added by special_menu_items.
          continue;
        }
        if ('<nolink>' === $row->parent_path) {
          $candidates[$row->menu_name] = 'crumbs/special-menu-item/' . $row->plid;
        }
        else {
          // This may add NULL values for toplevel items.
          $candidates[$row->menu_name] = $row->parent_path;
        }
      }
    }

    // Filter out NULL values for toplevel items.
    return array_filter($candidates);
  }

  /**
   * Finds the parent path for an artificial router item representing a special
   * menu item with '<nolink>' path.
   *
   * @param array $item
   *
   * @return string[]
   *   Parent path candidates (can't be more than one).
   */
  protected function specialMenuItemFindParent(array $item) {

    if (empty($item['map'][2]['menu_name']) || empty($item['map'][2]['plid'])) {
      return array();
    }
    $menu_name = $item['map'][2]['menu_name'];
    $parent_link = menu_link_load($item['map'][2]['plid']);

    if (empty($parent_link['link_path'])) {
      return array();
    }
    $parent_path = $parent_link['link_path'];

    if ('<separator>' === $parent_path) {
      return array();
    }

    if ('<nolink>' === $parent_path) {
      $parent_path = 'crumbs/special-menu-item/' . $parent_link['mlid'];
    }

    return array($menu_name => $parent_path);
  }

}


class menu_CrumbsMultiPlugin_link_title implements crumbs_MultiPlugin_FindTitleInterface {

  /**
   * {@inheritdoc}
   */
  function describe($api) {
    foreach (menu_get_menus() as $key => $title) {
      $api->ruleWithLabel($key, $title, t('Menu'));
    }
    $api->descWithLabel(t('Menu link title'), t('Title'));
  }

  /**
   * Find all menu links with $path as the link path.
   * For each menu, find the one with the lowest depth.
   *
   * {@inheritdoc}
   */
  function findTitle($path, $item) {

    // We need to load the original title from menu_router,
    // because _menu_item_localize() does a decision based on that, that we want
    // to reproduce.
    $q = db_select('menu_router', 'mr');
    $q->condition('path', $item['path']);
    $q->fields('mr', array('title'));
    $router_title = $q->execute()->fetchField();

    // Reproduce menu_link_load() with _menu_link_translate() and
    // _menu_item_localize(). However, a lot of information is already provided
    // in the $item argument, so we can skip these steps.
    $q = db_select('menu_links', 'ml');
    $q->fields('ml');
    $q->condition('link_path', $path);
    $q->condition('router_path', $item['path']);

    // Top-level links have higher priority.
    $q->orderBy('ml.depth', 'ASC');

    if (module_exists('i18n_menu')) {
      // Filter and sort by language.
      // The 'language' column only exists if i18n_menu is installed.
      // (See i18n_menu_install())
      $language = LANGUAGE_NONE;
      if (isset($GLOBALS['language'])) {
        $language = array($language, $GLOBALS['language']->language);
        $q->addExpression('case ml.language when :language then 1 else 0 end', 'has_language', array(':language' => LANGUAGE_NONE));
        $q->orderBy('has_language');
      }
      $q->condition('language', $language);
    }

    $result = $q->execute();

    $titles = array();
    while ($row = $result->fetchAssoc()) {
      if (!isset($titles[$row['menu_name']])) {
        $link = $row + $item;
        if ($row['link_title'] == $router_title) {
          // Use the localized title from menu_router.
          // Fortunately, this is already computed by menu_get_item().
          $link['title'] = $item['title'];
        }
        else {
          // Use the untranslated title from menu_links.
          $link['title'] = $row['link_title'];
        }
        if (!is_array($link['options'])) {
          // hook_translated_menu_link_alter() expects options to be an array.
          $link['options'] = unserialize($link['options']);
        }
        if (1
          // Check if i18n_menu < 7.x-1.8 is installed.
          // We need to support older versions, because 7.x-1.8 is a bit buggy.
          // See http://drupal.org/node/1781112#comment-7163324
          && module_exists('i18n_menu')
          && !function_exists('_i18n_menu_link_process')
        ) {
          if (1
            && isset($link['language'])
            && $link['language'] === LANGUAGE_NONE
          ) {
            // i18n_menu_translated_menu_link_alter() in older versions of
            // i18n_menu expects $link['language'] to be empty for language
            // neutral.
            unset($link['language']);
          }
          // Give other modules (e.g. i18n_menu) a chance to alter the title.
          drupal_alter('translated_menu_link', $link, $item['map']);
          // i18n_menu < 7.x-1.8 sets the 'link_title' instead of 'title'.
          $titles[$row['menu_name']] = $link['link_title'];
        }
        else {
          // Give other modules (e.g. i18n_menu) a chance to alter the title.
          drupal_alter('translated_menu_link', $link, $item['map']);
          $titles[$row['menu_name']] = $link['title'];
        }
      }
    }
    return $titles;
  }
}
