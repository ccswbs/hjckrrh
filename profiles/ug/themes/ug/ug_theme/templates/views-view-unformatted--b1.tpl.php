<?php

/**
 * @file
 * B1 - Image slider (banner)
 */
?>
<div id="slides">
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
  <div class="row slidesjs-navigation">
    <div class="col-xs-6 col-sm-8">
      <a href="#" class="btn btn-link slidesjs-slide-link slidesjs-slide-title"></a>
    </div>
    <div class="col-xs-2 col-sm-1">
      <a href="#" class="btn btn-default btn-block slidesjs-previous" role="button">
        <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
        <span class="sr-only"><?php print t('Previous'); ?></span>
      </a>
    </div>
    <div class="col-xs-2 col-sm-2 btn disabled">
      <?php print t('Slide <span class="slidesjs-slide-number">@number</span> of @count',
                    array('@number' => $slide_number, '@count' => $slide_count)); ?>
    </div>
    <div class="col-xs-2 col-sm-1">
      <a href="#" class="btn btn-default btn-block slidesjs-next" role="button">
        <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
        <span class="sr-only"><?php print t('Next'); ?></span>
      </a>
    </div>
  </div>
</div>
<script src="//www.uoguelph.ca/js/jquery.slides.min.js"></script>
<script>
  jQuery(function($) {
    function update(number) {
      var active = $('.slidesjs-control').children()[number-1];
      $('.slidesjs-slide-number').text(number);
      $('.slidesjs-slide-title').text($(active).attr('alt'));
      $('.slidesjs-slide-link').attr('href', $(active).data('link'));
    }
    $('#slides').slidesjs({
      width: 860,
      height: 228,
      navigation: {
        active: false,
        effect: 'slide',
      },
      pagination: {
        active: false,
      },
      callback: {
        loaded: update,
        complete: update,
      },
    });
  });
</script>
