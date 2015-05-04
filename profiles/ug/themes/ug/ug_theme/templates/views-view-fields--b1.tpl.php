<?php
/**
 * @file
 * Template to display one banner image.
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
<div class="panel-body">
  <img class="img-responsive"
    src="<?php print $fields['field_banner_image']->content; ?>"/>
</div>
<div class="panel-footer">
  <div class="row">
    <div class="col-md-10">
      <a class="h3" href="<?php print $fields['field_banner_link']->content; ?>"
        ><?php print $fields['title']->content; ?></a>
    </div>
    <div class="col-md-2 text-right">
      <a href="#carousel" class="btn btn-default btn-sm" role="button" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
        <span class="sr-only">Previous</span>
      </a>
      <?php print t('Item @num of @total', array('@num' => $view->row_index+1,
        '@total' => count($view->result))); ?>
      <a href="#carousel" class="btn btn-default btn-sm" role="button" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
        <span class="sr-only">Next</span>
      </a>
    </div>
  </div>
</div>

