<?php

/**
 * @file
 * B1 - Image slider (banner)
 */
?>
<div class="panel panel-default"><div class="panel-body">
<div id="slides">
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
  <div class="row slidesjs-navigation">
    <div class="col-sm-6">
      <a href="#" class="btn btn-link slidesjs-slide-link slidesjs-slide-title"></a>
    </div>
    <div class="col-sm-6">
      <div class="btn-toolbar pull-right" role="toolbar">
        <div class="btn-group" role="group">
          <a href="#slides" class="btn btn-default slidesjs-previous" role="button">
            <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
            <span class="sr-only"><?php print t('Previous'); ?></span>
          </a>
          <div class="btn btn-default" disabled>
            <?php print t('Slide <span class="slidesjs-slide-number">@number</span> of @count',
                        array('@number' => $slide_number, '@count' => $slide_count)); ?>
          </div>
          <a href="#slides" class="btn btn-default slidesjs-next" role="button">
            <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
            <span class="sr-only"><?php print t('Next'); ?></span>
          </a>
        </div>
        <div class="btn-group" role="group">
          <a href="#slides" class="btn btn-default slidesjs-stop" role="button">
            <span class="glyphicon glyphicon-pause" aria-hidden="true"></span>
            <span class="sr-only"><?php print t('Pause'); ?></span>
          </a>
          <a href="#slides" class="btn btn-default slidesjs-play" role="button" disabled>
            <span class="glyphicon glyphicon-play" aria-hidden="true"></span>
            <span class="sr-only"><?php print t('Play'); ?></span>
          </a>
        </div>
      </div>
    </div>
  </div>
</div>
</div></div>
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
    $('.slidesjs-stop').click(function () {
      $('#slides').first().data('plugin_slidesjs').stop();
      $('.slidesjs-stop').attr('disabled', 'disabled');
      $('.slidesjs-play').removeAttr('disabled');
    });
    $('.slidesjs-play').click(function () {
      $('#slides').first().data('plugin_slidesjs').play(true);
      $('.slidesjs-play').attr('disabled', 'disabled');
      $('.slidesjs-stop').removeAttr('disabled');
    });
  });
</script>
