<?php

/**
 * @file
 * Administrative page callbacks for the siteimprove module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function siteimprove_admin_settings_form($form_state) {

  $form['container'] = array(
    '#title' => t('Token'),
    '#type' => 'fieldset',
  );

  $form['container']['siteimprove_token'] = array(
    '#default_value' => variable_get('siteimprove_token'),
    '#description' => t('Configure Siteimprove Plugin token.'),
    '#maxlength' => 50,
    '#prefix' => '<div id="token-wrapper">',
    '#required' => TRUE,
    '#size' => 50,
    '#suffix' => '</div>',
    '#title' => t('Token'),
    '#type' => 'textfield',
  );

  $form['container']['siteimprove_request_new_token'] = array(
    '#ajax' => array(
      'callback' => 'siteimprove_admin_settings_form_ajax_request_token',
      'wrapper' => 'token-wrapper',
    ),
    '#limit_validation_errors' => array(),
    '#type' => 'button',
    '#value' => t('Request new token'),
  );

  return system_settings_form($form);
}

/**
 * Callback for submit_driven example.
 *
 * Select the 'box' element, change the markup in it, and return it as a
 * renderable array.
 *
 * @return array
 *   Renderable array (the box element)
 */
function siteimprove_admin_settings_form_ajax_request_token($form, $form_state) {

  // Request new token.
  if ($token = SiteimproveUtils::requestToken()) {
    $form['container']['siteimprove_token']['#value'] = $token;
  }
  else {
    form_set_error('siteimprove_token', t('There was an error requesting a new token. Please try again in a few minutes.'));
  }

  return $form['container']['siteimprove_token'];
}
