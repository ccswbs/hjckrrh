<?php

/**
 * @file jquery_countdown.rules.inc
 * Rules integration for the jQuery Countdown module.
 */
 
/**
 * Implementation of hook_rules_event_info().
 * @ingroup rules
 */
function jquery_countdown_rules_event_info() {
  
  $items = array();
  
  $defaults = array(
    'group' => t('Miscellaneous'),
    'module' => 'jquery_countdown',
    'help' => t('An event when jQuery Countdown is zero!')
  );

  $items['countdown'] = $defaults + array(
    'label' => t('When countdown = 0'),
    'variables' => array(
      'counter' => array('type' => 'integer', 'label' => t('counter value'))
    )
  );

  return $items;
}// end function myrules_event_info;
