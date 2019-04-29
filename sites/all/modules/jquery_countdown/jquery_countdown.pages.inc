<?php
// $Id$

/**
 * @file
 * Page callbacks.
 */

/**
 * AJAX Menu Callback, to trigger event when countdown is zero.
 *
 */
function jquery_countdown_invoke_rule() {
  
  if (module_exists('rules'))
    rules_invoke_event('countdown', 0);
  
  print drupal_json_output(array('response' => TRUE));
  exit();
}// end function jquery_countdown_invoke_rule;
