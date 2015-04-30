<?php
/**
 * @file
 * Template to display one row of the news listing.
 *
 * Available variables:
 * - $title: title of news article
 * - $created: post date
 * - $body: body of article
 * - $image: image attached to article
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

<div class="row">
  <div class="col-md-4">
    <img class="img-responsive" src="<?php print $image; ?>"/>
  </div>
  <div class="col-md-8">
    <?php print $title; ?><br>
    <?php print $created; ?><br>
    <?php print $body; ?>
  </div>
</div> 
<hr/>

