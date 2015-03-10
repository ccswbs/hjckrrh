<?php

/**
 * @file
 * View template to all the news summary fields as a row.
 *
 * - $view: The view in use.
 * - $fields['title']: The node title.
 * - $fields['created']: The post date.
 * - $fields['field_image']: URL of the image attached to the node.
 * - $fields['body']: Summary or trimmed version of the body.
 * - $fields[id]->content: The output of the field.
 * - $fields[id]->raw: The raw data for the field, if it exists. This is NOT output safe.
 * - $fields[id]->class: The safe class id to use.
 * - $fields[id]->handler: The Views field handler object controlling this field. Do not use
 *   var_export to dump this object, as it can't handle the recursion.
 * - $fields[id]->inline: Whether or not the field should be inline.
 * - $fields[id]->inline_html: either div or span based on the above flag.
 * - $fields[id]->wrapper_prefix: A complete wrapper containing the inline_html to use.
 * - $fields[id]->wrapper_suffix: The closing tag for the wrapper.
 * - $fields[id]->separator: an optional separator that may appear before a field.
 * - $fields[id]->label: The wrap label text to use.
 * - $fields[id]->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<div class='col-md-4'>
  <img src="<?php print $fields['field_image']->content; ?>" class="img-responsive"></img>
</div>
<div class='col-md-8'>
  <h3><?php print $fields['title']->content; ?></h3>
  <p><?php print $fields['created']->content; ?></p>
  <?php print $fields['body']->content; ?>
</div>
