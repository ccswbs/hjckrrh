<?php
/**
 * @file
 * Template to display multiple basic pages
 *
 * Available variables:
 * - $title: the article title.
 * - $created: the post date.
 * - $body: the article body
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
<?php if (!empty($image)): ?>
  <div class="col-md-4">
    <div class="media-thumbnail">
      <?php print $image; ?>
    </div>
  </div>
<?php endif; ?>

<div class="col-md-<?php print empty($image)?12:8; ?>">
  <header class="media-header">
    <h2 class="media-heading"><?php print $title; ?></h2>
    <div class="media-meta"><time datetime="<?php echo date("Y-m-d\TH:i:s", strtotime($created)); ?>"><?php print $created; ?></time></div>
  </header>
  <div class="media-summary"><?php print $body; ?></div>
</div>

