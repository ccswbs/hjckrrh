<?php

/**
 * @file
 * Administrative functions and forms for mpac.module.
 */

function mpac_settings_form() {
  $form = array();

  $form['mpac_max_items'] = array(
    '#type' => 'select',
    '#title' => t('Maximum number of items'),
    '#description' => t('Select the maximum number of items in an autocomplete popup provided by mpac.'),
    '#default_value' => variable_get('mpac_max_items', 20),
    '#options' => drupal_map_assoc(array(10, 20, 50, 100)),
  );

  return system_settings_form($form);
}
