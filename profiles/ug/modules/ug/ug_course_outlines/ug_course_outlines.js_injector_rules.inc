<?php
/**
 * @file
 * ug_course_outlines.js_injector_rules.inc
 */

/**
 * Implements hook_js_injector_rule().
 */
function ug_course_outlines_js_injector_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 1;
  $rule->name = 'View Labels Fix';
  $rule->admin_description = 'Fix the accessibility error by removing element-invisible';
  $rule->js = 'jQuery(document).ready(function() {
   jQuery("label[for=\'edit-field-course-year-value-value-year\']").removeClass("element-invisible");
});';
  $rule->position = 'header';
  $rule->preprocess = 0;
  $rule->inline = 1;
  $rule->page_visibility = 1;
  $rule->page_visibility_pages = 'course-outlines';
  $export['View Labels Fix'] = $rule;

  return $export;
}
