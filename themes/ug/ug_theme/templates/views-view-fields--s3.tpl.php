<?php
/**
 * @file
 * S3 - Find us on Social Media (icons only)
 *
 * Available variables:
 * - $title: title of news article
 * - $network_key: key for social network this account belongs to
 * - $network_name: name of social network this account belongs to
 * - $link: link to social media page
 * - $icon: social network icon
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
<li>
  <a class="h1" data-toggle="tooltip" data-placement="bottom"
     href="<?php print $link; ?>"
     title="<?php print $title; ?>">
    <?php print $icon; ?>
    <span class="element-invisible">
      <?php print $network_name; ?> - <?php print $title; ?>
    </span>
  </a>
</li>

