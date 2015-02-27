<?php
/**
 * @file
 * ug_event.features.inc
 */

/**
 * Implements hook_node_info().
 */
function ug_event_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Use <em>events</em> for calendar appointments.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
