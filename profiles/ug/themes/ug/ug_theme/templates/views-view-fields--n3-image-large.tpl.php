<?php if (!empty($fields['field_news_image'])): ?>
  <div class="col-md-6">
    <div class="media-thumbnail">
      <?php print $fields['field_news_image']->content; ?>
    </div>
  </div>
<?php endif; ?>
<div class="col-md-6 xs-gutter">
  <div class="media-header">
	<time datetime="<?php echo date("Y-m-d\TH:i:s", strtotime($created)); ?>"><?php print $created; ?></time>
	<p class="media-heading"><a href="<?php print $link; ?>"><?php print $title; ?></a></p>
  </div>
</div>
