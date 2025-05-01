<?php

/**
 * @file
 * Administrative page callbacks for the Facebook Pixel module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function facebook_pixel_admin_settings_form($form_state) {
  $form = array();

  $form['facebook_pixel_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Pixel ID'),
    '#required' => TRUE,
    '#default_value' => variable_get('facebook_pixel_id'),
  );

  $form['facebook_pixel_exclude_admin_paths'] = array(
    '#type' => 'checkbox',
    '#title' => t('Exclude from admin pages'),
    '#description' => t('The pixel tracking code will not be added to admin pages.'),
    '#default_value' => variable_get('facebook_pixel_exclude_admin_paths', 1),
  );

  // Role specific visibility configurations.
  $roles = user_roles();
  $role_options = array();
  foreach ($roles as $rid => $name) {
    $role_options[$rid] = $name;
  }
  $form['facebook_pixel_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Remove Facebook Pixel for specific roles'),
    '#default_value' => variable_get('facebook_pixel_roles', array()),
    '#options' => $role_options,
    '#description' => t('Remove script only for the selected role(s). If none of the roles are selected, all roles will have the Facebook Pixel. Otherwise, any roles selected here will NOT have the script.'),
  );

  return system_settings_form($form);
}
