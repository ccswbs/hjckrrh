<?php
/**
 * @file
 * N2 - Template to display one news article
 *
 * Available variables:
 * - $title: title of news article
 * - $created: date posted
 * - $writer: name of author
 * - $image: feature image
 * - $caption: feature image caption
 * - $body: body of news article
 * - $attachments: file attachments
 * - $tags: category (tags)
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

<p><?php print t('Posted on ') . $created; ?></p>
<?php if (!empty($writer)): ?>
  <p><?php print t('Written by ') . $writer; ?></p>
<?php endif; ?>
<?php if (!empty($image)): ?>
  <div class="thumbnail">
    <?php print $image; ?>
    <?php if (!empty($caption)): ?>
      <div class="caption">
        <?php print $caption; ?>
      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>
<?php print $body; ?>
<?php if ($attachments): ?>
  <h2><?php print t('File attachments'); ?></h2>
  <?php print $attachments; ?>
<?php endif; ?>
<?php if ($tags): ?>
  <hr>
  <h2><?php print t('Find related news by category') ?></h2>
  <p><?php print $tags; ?></p>
<?php endif; ?>

