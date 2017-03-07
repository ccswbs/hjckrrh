<?php
/**
 * @file
 * S4 - Find us on Social Media (Icons and Names)
 *
 * Available variables:
 * - $title: title of news article
 * - $network_key: key of social network this account belongs to
 * - $network_name: name of social network this account belongs to
 * - $link: link to social media page
 * - $icon: icon for social media network
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
 * @ingroup views_templates
 */
?>

<li class="media">
  <div class="pull-left">
    <div class="media-object h3"><?php print $icon; ?></div>
  </div>  
  <div class="media-body media-middle">
    <p class="media-heading">
      <span class="element-invisible"><?php print $network_name; ?> - </span><?php print $title; ?>
    </p>
  </div>
</li>

