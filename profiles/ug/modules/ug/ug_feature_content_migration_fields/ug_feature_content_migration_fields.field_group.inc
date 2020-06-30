<?php

/**
 * @file
 * ug_feature_content_migration_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ug_feature_content_migration_fields_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_migration|node|feature|form';
  $field_group->group_name = 'group_migration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'feature';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Migration',
    'weight' => '0',
    'children' => array(
      0 => 'field_subject_expert_team',
      1 => 'field_audience',
      2 => 'field_migrate_content',
      3 => 'field_migrated_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-migration field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_migration|node|feature|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Migration');

  return $field_groups;
}
