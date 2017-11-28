<?php
/**
 * @file
 * ug_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ug_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|profile2|main|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact information',
    'weight' => '13',
    'children' => array(
      0 => 'field_profile_address',
      1 => 'field_profile_email',
      2 => 'field_profile_faxnumber',
      3 => 'field_profile_lab',
      4 => 'field_profile_office',
      5 => 'field_profile_telephonenumber',
      6 => 'field_profile_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_contact|profile2|main|form'] = $field_group;

  return $export;
}
