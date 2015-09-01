<?php

/**
 * @file
 * B1 - Image slider (banner) - Block (Autoplay)
 */
?>
<div id="slides">
  <?php if ($slide_count > 1): ?>
    <div class="row slidesjs-navigation slidesjs-navigation-top">
      <div class="col-sm-2 col-xs-12">
        <button class="btn btn-block slidesjs-psply">
            <span class="slidesjs-stop">
              <span class="glyphicon glyphicon-pause" aria-hidden="true"></span>
              <?php print t('Pause<span class="visible-xs-inline"> slideshow</span>'); ?>
            </span>
            <span class="slidesjs-play" style="display:none;">
              <span class="glyphicon glyphicon-play" aria-hidden="true"></span>
              <?php print t('Play<span class="visible-xs-inline"> slideshow</span>'); ?>
            </span>
        </button>
      </div>
    </div>
  <?php endif; ?>
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
  <div class="row slidesjs-navigation slidesjs-navigation-bottom">

    <div class="col-sm-9 slidesjs-summary">
        <a href="#" class="slidesjs-slide-link slidesjs-slide-title"></a>
        <p class="slidesjs-slide-text"></p>
    </div>

    <?php if ($slide_count > 1): ?>
      <div class="col-sm-1 col-xs-3">
        <button class="btn btn-block slidesjs-previous" role="button">
          <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
          <span class="sr-only"><?php print t('Previous item'); ?></span>
        </button>
      </div>
      <div class="col-sm-1 col-xs-6 slidesjs-pagination">
        <div class="btn btn-block disabled">
          <?php print t('Slide <span class="slidesjs-slide-number">@number</span> of @count',
                      array('@number' => $slide_number, '@count' => $slide_count)); ?>
        </div>
      </div>
      <div class="col-sm-1 col-xs-3">
        <button class="btn btn-block slidesjs-next" role="button">
          <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
          <span class="sr-only"><?php print t('Next item'); ?></span>
        </button>
      </div>
    <?php endif; ?>

  </div>
</div>
<script src="//www.uoguelph.ca/js/jquery.slides.min.js"></script>
<script>
  jQuery(function($) {

    function update(number) {
      var active = $('.slidesjs-control').children()[number-1];
      $('.slidesjs-slide-number').text(number);
      $('.slidesjs-slide-title').text($(active).data('title'));
      $('.slidesjs-slide-link').attr('href', $(active).data('link'));
      $('.slidesjs-slide-text').text($(active).data('text'));

      <?php 
        if ($slide_count == 1) {
          // Force banner to display when there's only 1 slide
          print '$(".slidesjs-slide").css("left","0px");';
        }
      ?>
    }

    $('#slides').slidesjs({
      width: 1140,
      height: 292,
      play: {
        auto: <?php print $slide_count > 1 ? 'true' : 'false'; ?>,
        interval: 6000,
        swap: false,
        effect: 'fade',
      },
      navigation: {
        active: false,
        effect: 'fade',
      },
      pagination: {
        active: false,
      },
      callback: {
        loaded: update,
        complete: update,
      },
    });

    $('.slidesjs-slide-link').focus(function() {
      var plugin = $('#slides').first().data('plugin_slidesjs');
      plugin.stop();
      $('.slidesjs-stop').hide();
      $('.slidesjs-play').show();
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

