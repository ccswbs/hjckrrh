<?php
// $Id$

/**
 * @file
 * Content administration and module settings UI.
 */

/**
 * Menu callback, to display admin settings for jQuery Countdown module.
 *
 */
function jquery_countdown_admin() {

  $form = array();
  //drupal_set_message(variable_get('jquery_countdown_target'));
  //[month] => 3 [day] => 9 [year] => 1993
  
  $form['jquery_countdown_event_name'] = array(
    '#title' => t('Event name'),
    '#description' => t(''),
    '#type' => 'textfield',
    '#default_value' => variable_get('jquery_countdown_event_name', ''),
    '#max_length' => 250,
    '#size' => 25,
    '#required' => TRUE
  );
  
  $form['jquery_countdown_target'] = array(
    '#title' => t('Start countdown from'),
    '#description' => t(''),
    '#type' => 'date_popup',
    '#default_value' => variable_get('jquery_countdown_target', '')
  );
  
  $form['jquery_countdown_description'] = array(
    '#title' => t('Countdown description'),
    '#description' => t('Enter the description to go below the countdown. You may use <strong>@event_name</strong> as a special token in this field that will be replaced with the dynamic value of the event name. The default is "Until <strong>@event_name</strong>". If you do not wish to have a description, simply leave this field blank.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('jquery_countdown_description', 'Until @event_name'),
    '#max_length' => 250,
    '#size' => 80,
    '#required' => FALSE
  );
  
  $form['jquery_countdown_exp_txt'] = array(
    '#title' => t('Expiry Text'),
    '#description' => t('Enter the message that will be shown when the countdown reaches zero.'),
    '#type' => 'textarea',
    '#default_value' => variable_get('jquery_countdown_exp_txt', ''),
  );
  
  $form['jquery_countdown_msg_format'] = array(
    '#title' => t('Message format'),
    '#description' => t('Enter time components seperated by spaces, each component will be included in the countdown block. For example: <strong>%years %months %weeks %days %hours %minutes %seconds</strong> will display <strong>Years Months Weeks Days Hours Minutes Seconds</strong> in countdown, <strong>%days %hours</strong> will display <strong>Days Hours</strong> in countdown. The order of component will not affect the countdown output i.e. <strong>%months %years</strong> will display <strong>Years Months</strong>.'),
    '#type' => 'textarea',
    '#default_value' => variable_get('jquery_countdown_msg_format', ''),
  );
  
  return system_settings_form($form);
}// end function jquery_countdown_admin;
