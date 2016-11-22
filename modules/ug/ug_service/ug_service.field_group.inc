<?php
/**
 * @file
 * ug_service.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ug_service_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_audience|node|service|form';
  $field_group->group_name = 'group_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'service';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Who can use this service?',
    'weight' => '5',
    'children' => array(
      0 => 'field_service_audience',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-audience field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_audience|node|service|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Who can use this service?');

  return $field_groups;
}
