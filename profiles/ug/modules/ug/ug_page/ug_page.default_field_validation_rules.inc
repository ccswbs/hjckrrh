<?php
/**
 * @file
 * ug_page.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function ug_page_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'File description not empty';
  $rule->name = 'page_attach_desc_not_empty';
  $rule->field_name = 'field_page_attachments';
  $rule->col = 'description';
  $rule->entity_type = 'node';
  $rule->bundle = 'page';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '\\w',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = '[field-name] description is required.';
  $export['page_attach_desc_not_empty'] = $rule;

  return $export;
}
