<?php
/**
 * @file
 * Template file for the example display.
 *
 * Variables available:
 * 
 * $plugin: The pager plugin object. This contains the view.
 *
 * $plugin->view
 *   The view object for this navigation.
 *
 * $nav_title
 *   The formatted title for this view. In the case of block
 *   views, it will be a link to the full view, otherwise it will
 *   be the formatted name of the year, month, day, or week.
 *
 * $prev_url
 * $next_url
 *   Urls for the previous and next calendar pages. The links are
 *   composed in the template to make it easier to change the text,
 *   add images, etc.
 *
 * $prev_options
 * $next_options
 *   Query strings and other options for the links that need to
 *   be used in the l() function, including rel=nofollow.
 */
?>
<?php if (!empty($pager_prefix)) print $pager_prefix; ?>
<div class="container-fluid date-nav-wrapper clearfix<?php if (!empty($extra_classes)) print $extra_classes; ?>">
  <div class="date-nav item-list row">

    <div class="date-heading col-sm-8">
      <h2><?php print $nav_title ?></h2>
    </div>

    <div class="pager-wrapper col-sm-3 col-sm-offset-1">
      <div class="row">
        <ul class="pager">
  <!--    <div class="row"> -->
        <?php if (!empty($prev_url)) : ?>
          <li class="date-prev col-xs-2">
            <?php print l('&laquo;' . ($mini ? '' : ' ' . t('prev', array(), array('context' => 'date_nav'))), $prev_url, $prev_options); ?>
          </li>
        <?php endif; ?>
        <?php if (!empty($next_url)) : ?>
          <li class="date-next col-xs-2">
            <?php print l(($mini ? '' : t('next', array(), array('context' => 'date_nav')) . ' ') . '&raquo;', $next_url, $next_options); ?>
          </li>
        <?php endif; ?>
        <!-- </div> -->
        </ul>
      </div>
    </div>
  </div>
</div>