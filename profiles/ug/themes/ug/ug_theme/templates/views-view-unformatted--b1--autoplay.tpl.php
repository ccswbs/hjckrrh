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
    <div class="col-sm-6">
      <div class="btn-group" role="group">
        <button class="btn btn-default slidesjs-psply">
          <span class="slidesjs-stop">
            <span class="glyphicon glyphicon-pause" aria-hidden="true"></span>
            <span class="sr-only"><?php print t('Pause slideshow'); ?></span>
          </span>
          <span class="slidesjs-play" style="display:none;">
            <span class="glyphicon glyphicon-play" aria-hidden="true"></span>
            <span class="sr-only"><?php print t('Play slideshow'); ?></span>
          </span>
        </button>
      </div>
      <a href="#" class="btn btn-link slidesjs-slide-link slidesjs-slide-title"></a>
    </div>
    <div class="col-sm-6">
      <div class="btn-toolbar pull-right" role="toolbar">
        <div class="btn-group" role="group">
          <button class="btn btn-default slidesjs-previous" role="button">
            <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
            <span class="sr-only"><?php print t('Previous slide'); ?></span>
          </button>
          <div class="btn btn-default" disabled>
            <?php print t('Slide <span class="slidesjs-slide-number">@number</span> of @count',
                        array('@number' => $slide_number, '@count' => $slide_count)); ?>
          </div>
          <button class="btn btn-default slidesjs-next" role="button">
            <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
            <span class="sr-only"><?php print t('Next slide'); ?></span>
          </button>
        </div>
      </div>
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
      width: 1140,
      height: 334,
      play: {
        auto: true,
        interval: 6000,
        swap: false,
      },
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
    $('.slidesjs-next, .slidesjs-previous').click(function () {
      $('.slidesjs-stop').hide();
      $('.slidesjs-play').show();
    });
    $('.slidesjs-psply').click(function () {
      var plugin = $('#slides').first().data('plugin_slidesjs');
      if ($.data(plugin, 'playing')) {
        plugin.stop();
        $('.slidesjs-stop').hide();
        $('.slidesjs-play').show();
      } else {
        plugin.play(true);
        $('.slidesjs-play').hide();
        $('.slidesjs-stop').show();
      }
    });
  });
</script>
