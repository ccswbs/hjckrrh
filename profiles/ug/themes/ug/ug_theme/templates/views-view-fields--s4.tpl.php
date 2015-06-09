<?php
/**
 * @file
 * S4 - Follow us - Icons and names
 *
 * Available variables:
 * - $icon: social media account icon
 * - $title: name of social media account
 *
 * Other variables:
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 */
?>
<div class="media h4">
  <div class="media-left pull-left media-top">
    <div class="media-object social-media-icon"><?php print $icon; ?></div>
  </div>
  <div class="media-body">
    <div class="media-heading h4"><?php print $title; ?></div>
  </div>
</div>
