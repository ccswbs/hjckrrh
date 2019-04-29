<?php
// $Id: jquery_countdown.jq.inc,v 1.1.2.4 2009/11/28 19:46:21 robloach Exp $

/**
 * @file
 * Provides integration with the jQ module:
 * http://drupal.org/project/jq
 */

/**
 * Implementation of hook_jq().
 */
function jquery_countdown_jq($op, $plugin = NULL) {
  switch ($op) {
    case 'info':
      return array(
        'jquery_countdown' => array(
          'name' => t('jQuery Countdown'),
          'description' => t('This is a simple countdown plugin which displays a countdown effect.'),
          'version' => '1.5.5',
          'url' => 'http://keith-wood.name/countdown.html',
        ),
      );
    break;
    case 'add':
      switch ($plugin) {
        case 'jquery_countdown':
          // When adding the plugin, allow additional arguments so that
          // we can automatically add the jQuery $selector and $options
          // function.
          $args = func_get_args();
          unset($args[0]); // $op
          unset($args[1]); // $plugin
          call_user_func_array('jquery_countdown_add', $args);
        break;
      }
    break;
  }
}
