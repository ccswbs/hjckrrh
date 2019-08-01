<?php

/**
 * @file
 * The TabTamer module.
 *
 * Admin functionality for Tab Tamer.
 *
 * @ingroup tabtamer
 */

/**
 * Settings page form.
 */
function tabtamer_admin($form, &$form_state) {
  $form = array();

  $form['tabtamer_control_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Control Administration Tabs'),
    '#default_value' => variable_get('tabtamer_control_admin', 0),
    '#description' => t('Most of the tabs in Drupal are found in the administration pages, an area which the average user will not access. Because of this, and to keep the interface as simple as possible, administration page tabs are not processed by default. You can override the default behavior by enabling this option. When disabling this option, you need to clear the Drupal caches to reflect the change.'),
  );

  return system_settings_form($form);
}

/**
 * Helper function to create a list of menu items and their weights.
 * It will be in the form: $item['parent']['parent/tabs'] = array(weight, original/%with_ugly_stuff/path, title)
 */
function _tabtamer_tabs($reset = FALSE) {
  static $tabs = NULL;
  if ($reset) {
    $tabs = NULL;
    cache_clear_all(TABTAMER_CACHE_ID, TABTAMER_CACHE_TABLE);
  }
  if (!is_null($tabs)) {
    return $tabs;
  }
  $cache = cache_get(TABTAMER_CACHE_ID, TABTAMER_CACHE_TABLE);
  if (!empty($cache)) {
    $tabs = $cache->data;
    return $tabs;
  }

  // Get the original menu router table.
  menu_router_build();
  $items = _tabtamer_backup();

  // Create an array of menu items and their weights.
  $menu = array();
  foreach ($items as $key => $val) {
    if (isset($val['type']) && ($val['type'] == MENU_LOCAL_TASK || $val['type'] == MENU_DEFAULT_LOCAL_TASK)) {
      $sanitized_path = _tabtamer_true_base($key);
      $menu[$sanitized_path] = $val;
      $menu[$sanitized_path]['tabtamer_original_path'] = $key;
      $menu[$sanitized_path]['tabtamer_title'] = isset($val['title']) ? $val['title'] : '';
    }
  }

  // Create a structured array so that sibling tabs can be easily identified.
  $structured_tabs = array();
  foreach ($menu as $key => $val) {
    _tabtamer_create_tab_structure($structured_tabs, $key, $val, $key);
  }

  // Use the structured array to create a final, flat array in the form:
  // $item['parent']['parent/tabs'] = array(weight, original/%with_ugly_stuff/path, title)
  $tabs = array();
  _tabtamer_convert_to_single_array($tabs, $structured_tabs);
  cache_set(TABTAMER_CACHE_ID, $tabs, TABTAMER_CACHE_TABLE, CACHE_TEMPORARY);
  return $tabs;
}

/**
 * Helper function that takes the flat $items array from hook_menu_alter()
 * and returns a structured array representing the tab menu structure.
 */
function _tabtamer_create_tab_structure(&$tabs, $key, $addition, $original) {
  $parts = explode('/', $key);
  $fragment = array_shift($parts);
  if (count($parts) >= 1) {
    _tabtamer_create_tab_structure($tabs[$fragment], implode('/', $parts), $addition, $original);
  }
  else {
    $tabs[$fragment] = $addition;
  }
}

/**
 * Helper function that takes the structured array from
 * _tabtamer_create_tab_structure() and returns an array of paths and the tabs that
 * they contain, grouped by their respective MENU_DEFAULT_LOCAL_TASKs.
 *
 * $tabs - The array that we are going to add information to.
 * $tabs_source - The structured array that we are gleaning info from.
 * $last_default_path - The last time that a MENU_DEFAULT_LOCAL_TASK was found.
 * $current_path - Keeping up with the current path.
 */
function _tabtamer_convert_to_single_array(&$tabs, $tabs_source, $last_default_path = '', $current_path = '') {
  if ($current_path == 'admin' && !variable_get('tabtamer_control_admin', 0)) {
    return;
  }

  // If there is a MENU_DEFAULT_LOCAL_TASK or this is the only item at this level then set $last_default_path.
  foreach ($tabs_source as $key => $val) {
    if (is_array($val)) {
      if (empty($val['type']) || $val['type'] == MENU_DEFAULT_LOCAL_TASK ||
        ($last_default_path == '' && $val['type'] == MENU_LOCAL_TASK)) {
        $last_default_path = $current_path;
        break;
      }
    }
  }

  // Do the recursive processing.
  foreach ($tabs_source as $key => $val) {
    $test_path = $current_path ? "$current_path/$key" : $key;
    if (is_array($val)) {
      if (isset($val['type']) && ($val['type'] == MENU_LOCAL_TASK || $val['type'] == MENU_DEFAULT_LOCAL_TASK)) {
        $tabs[$last_default_path][$test_path] = array(
          'weight' => isset($val['weight']) ? (int) $val['weight'] : 0,
          'tabtamer_original_path' => $val['tabtamer_original_path'],
          'tabtamer_title' => $val['tabtamer_title'],
        );
      }
      _tabtamer_convert_to_single_array($tabs, $val, $last_default_path, $test_path);
    }
  }
}

/**
 * Helper function to turn this: user/%user_category/edit into this: user/%/edit
 * TODO: see if regex is faster and, if so, convert
 */
function _tabtamer_true_base($path) {
  $parts = explode('/', $path);
  foreach ($parts as $key => $val) {
    if (isset($val) && substr($val, 0, 1) == '%') {
      $parts[$key] = '%';
    }
  }
  return implode('/', $parts);
}

/**
 * Theme function for the tabtamer_tabs_form() form.
 */
function theme_tabtamer_tabs_form($variables) {
  $form = $variables['form'];
  $output = '';
  $tabs = _tabtamer_tabs();
  $header = array(t('Title'), t('Path'), t('Options'), t('Weight'));

  // Create the tables and their rows.
  foreach ($tabs as $base => $paths) {
    $rows = array();

    foreach ($form[$base] as $path => $val) {
      if (is_array($val) && (!empty($val['weight']) || !empty($val['action']))) {
        unset($form[$base][$path]['#type']);
        $row = array(
          render($form[$base][$path]['tabtamer_title']),
          check_plain($path),
          render($form[$base][$path]['action']),
          render($form[$base][$path]['weight']),
        );
        $rows[] = array(
          'data' => $row,
          'class' => array('draggable'),
        );
      }
    }

    $id = 'tabtamer-' . str_replace(array('/', '%'), array('-', '-'), $base);
    $table = array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array(
        'id' => $id,
      ),
    );
    $form[$base]['#description'] .= theme('table', $table);
    drupal_add_tabledrag($id, 'order', 'sibling', 'tabtamer-weight');
  }

  $output .= drupal_render_children($form);
  return $output;

}

/**
 * Form creation function
 */
function tabtamer_tabs_form($form, &$form_state) {
  $form = array();

  $form['#tree'] = TRUE;
  $settings = variable_get('tabtamer_tab_settings', array());
  $tabs = _tabtamer_tabs();


  $form['help']['#value'] = '<p>' . t('Tabs are grouped by their parent path. Many paths use a wilcard ("%") as a placeholder to allow for dynamic paths, such a "user/1/edit" or "node/3/revisions", which are represented here as "user/%/edit" and "node/%/revisions".') . '</p><p>' . t('From this screen, you can change the order that the tabs will be displayed, hide them or disable them.  Hiding a tab allows for the URL to still function, whereas disabling a tab will remove the URL from the menu system altogether.') . '</p>';

  foreach ($tabs as $base => $paths) {
    $form[$base] = array(
      '#type' => 'fieldset',
      '#title' => $base,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => '',
    );
    foreach ($paths as $path => $val) {
      $tabtamer_title = !empty($settings[$path]['tabtamer_title']) ? $settings[$path]['tabtamer_title'] : $val['tabtamer_title'];
      $weight = isset($settings[$path]['weight']) ? $settings[$path]['weight'] : (isset($tabs[$base][$path]['weight']) ? $tabs[$base][$path]['weight'] : '0');
      $action = isset($settings[$path]['action']) ? $settings[$path]['action'] : 'enabled';
      $form[$base][$path] = array(
        '#type' => 'fieldset',
        '#title' => check_plain($val['tabtamer_title'] . ' - ' . $path),
        '#weight' => $weight,
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#description' => '',
      );
      $form[$base][$path]['tabtamer_title'] = array(
        '#type' => 'textfield',
        '#default_value' => $tabtamer_title,
        '#description' => 'Original Title: ' . check_plain($val['tabtamer_title']),
        '#size' => 30,
      );
      $form[$base][$path]['weight'] = array(
        '#type' => 'weight',
        '#default_value' => $weight,
        '#delta' => 100,
        '#attributes' => array(
          'class' => array('tabtamer-weight'),
        ),
      );
      $form[$base][$path]['action'] = array(
        '#type' => 'radios',
        '#default_value' => $action,
        '#options' => array(
          'enabled' => t('Enabled'),
          'hidden' => t('Hidden'),
          'disabled' => t('Disabled'),
        ),
      );
    }
  }

  // Put the tabs in the order that the menu system uses.
  foreach (array_keys($tabs) as $base) {
    uasort($form[$base], '_tabtamer_sort');
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to Defaults'),
  );

  return $form;
}

/**
 * Helper function used to determine the order that tabs appear in Drupal.
 */
function _tabtamer_sort($a, $b) {
  $return = '';
  if (isset($a['weight']) && isset($b['weight'])) {
    if ($a['weight'] == $b['weight']) {
      $return = strcmp($a['#title'], $b['#title']);
    }
    else {
      $return = $a['weight'] < $b['weight'] ? -1 : 1;
    }
  }
  return $return;
}

/**
 * Submission function for tabtamer_tabs_form()
 */
function tabtamer_tabs_form_submit($form_id, $form_values) {
  if ($form_values['clicked_button']['#value'] == t('Reset to Defaults')) {
    variable_set('tabtamer_tab_settings', array());
    drupal_set_message(t('All tabs have been reset.'));
  }
  else {
    $tabs = _tabtamer_tabs();
    $settings = array();
    foreach ($tabs as $base => $paths) {
      foreach (array_keys($paths) as $tab) {
        $settings[$tab] = array(
          'weight' => $form_values['values'][$base][$tab]['weight'],
          'action' => $form_values['values'][$base][$tab]['action'],
          'tabtamer_original_path' => $paths[$tab]['tabtamer_original_path'],
          'tabtamer_title' => $paths[$tab]['tabtamer_title'] == $form_values['values'][$base][$tab]['tabtamer_title'] ? '' : $form_values['values'][$base][$tab]['tabtamer_title'],
        );
      }
    }
    variable_set('tabtamer_tab_settings', $settings);
    drupal_set_message(t('Your changes have been saved.'));
  }
  _tabtamer_tabs(true);
  drupal_set_message(t('You may need to clear your cache in order for these changes to take effect.'));
}
