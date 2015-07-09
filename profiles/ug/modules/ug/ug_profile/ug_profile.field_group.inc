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
  $field_group->identifier = 'group_about|profile2|faculty|form';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'faculty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_body';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '9',
    'children' => array(
      0 => 'field_profile_about',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_about|profile2|faculty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attachments|profile2|faculty|form';
  $field_group->group_name = 'group_attachments';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'faculty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_body';
  $field_group->data = array(
    'label' => 'Attachments',
    'weight' => '15',
    'children' => array(
      0 => 'field_profile_attachments',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-attachments field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_attachments|profile2|faculty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_body|profile2|faculty|form';
  $field_group->group_name = 'group_body';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'faculty';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '0',
    'children' => array(
      0 => 'group_about',
      1 => 'group_education',
      2 => 'group_publications',
      3 => 'group_research',
      4 => 'group_attachments',
      5 => 'group_photo',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-body field-group-tabs',
      ),
    ),
  );
  $export['group_body|profile2|faculty|form'] = $field_group;

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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_education|profile2|faculty|form';
  $field_group->group_name = 'group_education';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'faculty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_body';
  $field_group->data = array(
    'label' => 'Education',
    'weight' => '10',
    'children' => array(
      0 => 'field_profile_education',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-education field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_education|profile2|faculty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_name|profile2|main|form';
  $field_group->group_name = 'group_name';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '1',
    'children' => array(
      0 => 'field_profile_name',
      1 => 'field_profile_lastname',
      2 => 'field_profile_role',
      3 => 'field_profile_unit',
      4 => 'field_profile_subunit',
      5 => 'field_profile_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_name|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_office|profile2|main|form';
  $field_group->group_name = 'group_office';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Office location',
    'weight' => '3',
    'children' => array(
      0 => 'field_profile_building',
      1 => 'field_profile_room',
      2 => 'field_profile_lab',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_office|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo|profile2|faculty|form';
  $field_group->group_name = 'group_photo';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'faculty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_body';
  $field_group->data = array(
    'label' => 'Photo',
    'weight' => '13',
    'children' => array(
      0 => 'field_profile_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-photo field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_photo|profile2|faculty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publications|profile2|faculty|form';
  $field_group->group_name = 'group_publications';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'faculty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_body';
  $field_group->data = array(
    'label' => 'Publications',
    'weight' => '11',
    'children' => array(
      0 => 'field_profile_publications',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publications field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_publications|profile2|faculty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_research|profile2|faculty|form';
  $field_group->group_name = 'group_research';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'faculty';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_body';
  $field_group->data = array(
    'label' => 'Research',
    'weight' => '12',
    'children' => array(
      0 => 'field_profile_research',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-research field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_research|profile2|faculty|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sections|profile2|main|form';
  $field_group->group_name = 'group_sections';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sections',
    'weight' => '0',
    'children' => array(
      0 => 'group_contact',
      1 => 'group_office',
      2 => 'group_name',
      3 => 'group_website',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-sections field-group-tabs',
      ),
    ),
  );
  $export['group_sections|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_website|profile2|main|form';
  $field_group->group_name = 'group_website';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sections';
  $field_group->data = array(
    'label' => 'Website',
    'weight' => '4',
    'children' => array(
      0 => 'field_profile_website',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-website field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_website|profile2|main|form'] = $field_group;

  return $export;
}
