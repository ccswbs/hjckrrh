<?php
/**
 * @file
 * ug_wysiwyg.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function ug_wysiwyg_ckeditor_profile_defaults() {
  $data = array(
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'ckeditor_path' => '//cdn.ckeditor.com/4.4.3/full-all',
      ),
      'input_formats' => array(),
    ),
  );
  return $data;
}
