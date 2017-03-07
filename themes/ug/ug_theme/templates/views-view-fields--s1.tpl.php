<?php
/**
 * @file
 * S1 - Share this page
 *
 * Displays "share this page" links for a node.
 *
 * Available variables:
 * - $link: URL of the current page.
 * - $title: page title.
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

<!-- Facebook -->
<li>
  <a class="h1" data-toggle="tooltip" data-placement="bottom"
    href="https://www.facebook.com/sharer/sharer.php?u=<?php print $link; ?>"
    title="<?php print t('Share on Facebook'); ?>"
    ><span class="fa fa-facebook-square"></span>
    <span class="element-invisible">
      <?php print t('Share on Facebook'); ?>
    </span>
  </a>
</li>

<!-- Twitter -->
<li>
  <a class="h1" data-toggle="tooltip" data-placement="bottom"
    href="http://twitter.com/home?status=<?php print $link; ?>"
    title="<?php print t('Share on Twitter'); ?>"
    ><span class="fa fa-twitter-square"></span>
    <span class="element-invisible">
      <?php print t('Share on Twitter'); ?>
    </span>
  </a>
</li>

<!-- LinkedIn -->
<li>
  <a class="h1" data-toggle="tooltip" data-placement="bottom"
    href="http://www.linkedin.com/shareArticle?mini=true&amp;url=<?php print $link; ?>&amp;title=&amp;summary="
    title="<?php print t('Share on LinkedIn'); ?>"
    ><span class="fa fa-linkedin-square"></span>
    <span class="element-invisible">
      <?php print t('Share on LinkedIn'); ?>
    </span>
  </a>
</li>

<!-- Print -->
<li>
  <a class="h1" data-toggle="tooltip" data-placement="bottom" href="<?php echo url('print/'.$nid); ?>" title="<?php echo t('Print this page'); ?>">
    <span class="fa fa-print"></span>
    <span class="element-invisible">
      <?php echo t('Print this page'); ?>
    </span>
  </a>
</li>
