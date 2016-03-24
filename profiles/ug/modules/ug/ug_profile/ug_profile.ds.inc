<?php
/**
 * @file
 * ug_profile.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ug_profile_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|profile|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'profile';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'media-heading',
      ),
    ),
  );
  $export['node|profile|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ug_profile_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|profile|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'profile';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_4_8';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_profile_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_profile_unit',
        3 => 'field_profile_telephonenumber',
        4 => 'field_profile_email',
      ),
    ),
    'fields' => array(
      'field_profile_image' => 'left',
      'title' => 'right',
      'field_profile_unit' => 'right',
      'field_profile_telephonenumber' => 'right',
      'field_profile_email' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => 'class="media"',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|profile|teaser'] = $ds_layout;

  return $export;
}
