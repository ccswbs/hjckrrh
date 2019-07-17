<?php

/**
 * @file
 * Administrative / settings functionality.
 */

/**
 * The main settings form.
 */
function scanner_admin_form($form, &$form_state) {
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default options'),
  );
  $form['settings']['scanner_mode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Default: Case Sensitive Search Mode'),
    '#default_value' => variable_get('scanner_mode', 0),
  );
  $form['settings']['scanner_wholeword'] = array(
    '#type' => 'checkbox',
    '#title' => t('Default: Match Whole Word'),
    '#default_value' => variable_get('scanner_wholeword', 0),
  );
  $form['settings']['scanner_regex'] = array(
    '#type' => 'checkbox',
    '#title' => t('Default: Regular Expression Search'),
    '#default_value' => variable_get('scanner_regex', 0),
  );
  $form['settings']['scanner_published'] = array(
    '#type' => 'checkbox',
    '#title' => t('Default: Search Published Nodes Only'),
    '#default_value' => variable_get('scanner_published', 1),
  );
  $form['settings']['scanner_pathauto'] = array(
    '#type' => 'checkbox',
    '#title' => t('Default: Maintain Custom Aliases'),
    '#default_value' => variable_get('scanner_pathauto', 1),
  );

  if (module_exists('taxonomy')) {
    $vocabularies = taxonomy_get_vocabularies();

    if (count($vocabularies)) {
      $options = array();
      foreach ($vocabularies as $vocabulary) {
        $options[$vocabulary->vid] = $vocabulary->name;
      }

      $form['taxonomy'] = array(
        '#type' => 'fieldset',
        '#title' => t('Allow restrictions by terms in a vocabulary'),
        '#description' => t('Adds search option to only match nodes tagged with specified terms from these vocabularies.'),
      );
      $form['taxonomy']['scanner_vocabulary'] = array(
        '#type' => 'checkboxes',
        '#options' => $options,
        '#default_value' => variable_get('scanner_vocabulary', array()),
      );
    }
  }

  $form['tables'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fields that will be searched'),
    '#description' => t('Fields are listed in [nodetype: fieldname] order:'),
  );

  $table_map = _scanner_get_all_tables_map();
  usort($table_map, '_scanner_compare_fields_by_name');
  foreach ($table_map as $item) {
    $key = 'scanner_' . $item['field'] . '_' . $item['table'] . '_' . $item['type'];
    $form['tables'][$key] = array(
      '#type' => 'checkbox',
      '#title' => filter_xss('<strong>' . $item['type'] . ':</strong> ' . $item['field'], $allowed_values = array('strong', 'p')),
      '#default_value' => variable_get($key, TRUE),
    );
  }

  return system_settings_form($form);
}
