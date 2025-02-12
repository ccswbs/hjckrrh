<?php

/**
 * @file
 * Provides info-type hook implementations that are infrequently called.
 *
 * @author Jim Berry ("solotandem", http://drupal.org/user/240748)
 */

/**
 * Implements hook_help().
 */
function _google_tag_help($path, $arg) {
  switch ($path) {
    case 'admin/help#google_tag':
    case 'admin/config/system/google_tag':
      $args = array('@path' => 'https://tagmanager.google.com/');
      return t('<a href="@path">Google Tag Manager</a> is a free service (registration required) to manage the insertion of tags for capturing website analytics.', $args);
  }
}

/**
 * Implements hook_menu().
 */
function _google_tag_menu() {
  $items['admin/config/system/google_tag/settings'] = array(
    'title' => 'Settings',
    'description' => 'Configure the website integration with GTM and the resultant capturing of website analytics.',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('google_tag_settings_form'),
    'access arguments' => array('administer google tag manager'),
    'type' => MENU_LOCAL_TASK,
    'file' => 'includes/form/settings.inc',
  );

  return $items;
}

/**
 * Implements hook_permission().
 */
function _google_tag_permission() {
  return array(
    'administer google tag manager' => array(
      'title' => t('Administer Google Tag Manager'),
      'description' => t('Configure the website integration with Google Tag Manager.'),
      'restrict access' => TRUE,
    ),
  );
}
