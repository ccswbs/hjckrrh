<?php

/**
 * @file
 * B1 - Image slider (banner) - Block (Autoplay)
 */
?>

<h2 class="sr-only">Slideshow Banners</h2>
<div id="slides">
  <!-- Slide Pause/Play Button -->
  <?php if ($slide_count > 1): ?>
    <div class="row slidesjs-navigation slidesjs-navigation-top">
      <div class="col-sm-2 col-xs-12">
        <button class="btn btn-block slidesjs-psply" aria-live="assertive">
            <span id="slide-state" class="sr-only">slideshow playing</span>

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

  <!-- Slide Images -->
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>

  <div class="row slidesjs-navigation slidesjs-navigation-bottom">
    <!-- Slide Link and Summary -->
    <div class="col-sm-9 slidesjs-summary">
        <a href="#" class="slidesjs-slide-link slidesjs-slide-title"></a>
        <p class="slidesjs-slide-text"></p>
    </div>

    <!-- Slide Previous and Next Buttons -->
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

    var mousePause = false;
    var mouseUpNxtPrv = false;

    function update(number) {
      var active = $('.slidesjs-control').children()[number-1];
      var focusedElement = document.activeElement;

     // IF FOCUS ON slideshow (exclusive)   
      if ($(focusedElement).is($('#slides').find(':focus'))) {
        var plugin = $('#slides').first().data('plugin_slidesjs');

        $('.slidesjs-summary').attr('aria-live','polite');

        /* NEXT/PREVIOUS Buttons - Reinforce assertive aria-live ON FOCUS */
        if (!($.data(plugin, 'playing'))) {
          if(($(focusedElement).is($('.slidesjs-next'))) || ($(focusedElement).is($('.slidesjs-previous')))) {
            $('.slidesjs-summary').attr('aria-live','assertive');
          }
        }

      }else{  
        $('.slidesjs-summary').attr('aria-live','off');
      }

      // UPDATE VALUES
      $('.slidesjs-slide-number').text(number);
      $('.slidesjs-slide-title').html('<span class="sr-only">Slide ' + number + ' headline: </span>' + $(active).data('title'));
      $('.slidesjs-slide-link').attr('href', $(active).data('link'));
      
      // Add slide # context to alternative text (if not blank)
      if($(active).data('alt') != ""){
        $(active).attr('alt','Slide ' + number + ' banner: ' + $(active).data('alt'));
      }

      // Add slide # context to summary text (if not blank)
      if($(active).data('text') != ""){
        $('.slidesjs-slide-text').html('<span class="sr-only">Slide ' + number + ' summary: </span>' + $(active).data('text'));
      }else{
        $('.slidesjs-slide-text').text($(active).data('text'));
      }

      // Hide inactive banners during first cycle of slideshow
      $('.slidesjs-slide').css("display","none");
      $('.slidesjs-slide').css("z-index","0");
      $(active).css("display","block");
      $(active).css("z-index","10");

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

    function pauseSlides() {
      var plugin = $('#slides').first().data('plugin_slidesjs');

      /* Bug Fix for Mouse Up on Next/Previous Pause Glitch

      Clicking next/previous buttons (specifically) with mouse causes 
      the slideshow to pause, but does not flag the $.data(plugin, 'playing') value as TRUE.
      We end up with the Pause button even though the slideshow is paused.

      As an override, we use the mouseUpNxtPrv variable to track if the mouseup event occurred.
      If so, allow the plugin through. At the end, we reset the variable, so keyboard-friendly
      behaviour is not affected.

      */

      if (($.data(plugin, 'playing'))||(mouseUpNxtPrv == true)) {
        plugin.stop();
        $('#slide-state').text('slideshow paused');
        $('.slidesjs-stop').hide();
        $('.slidesjs-play').show();
        mouseUpNxtPrv = false;
      }
    }

    function playSlides() {
      var plugin = $('#slides').first().data('plugin_slidesjs');

      if (!($.data(plugin, 'playing'))) {
        //set to false to wait full interval before advancing to next slide 
        plugin.play(false);
        $('#slide-state').text('slideshow playing');
        $('.slidesjs-play').hide();
        $('.slidesjs-stop').show();
      }
    }

    /**** Slide LINK ****/

      /*-- Focus ON --*/    
      $('.slidesjs-slide-link').focus(function () {
        pauseSlides();
      });

    /**** NEXT/PREVIOUS Buttons ****/

      /*-- Mouse/Key Trackers --*/
      $(".slidesjs-previous, .slidesjs-next").mouseup( function() {
        mouseUpNxtPrv = true;
      });

      $(".slidesjs-previous, .slidesjs-next").keydown( function() {
        mouseUpNxtPrv = false;
      });

      /*-- Focus ON --*/
      $('.slidesjs-next, .slidesjs-previous').focus(function() {
        var plugin = $('#slides').first().data('plugin_slidesjs');

        /* IF PAUSED - switch to aria-live ASSERTIVE Title/Summary */
        if (!($.data(plugin, 'playing'))) {
          $('.slidesjs-summary').attr('aria-live','assertive');
        }
      });

      /*-- FOCUS OFF (Blur) --*/
      $('.slidesjs-next, .slidesjs-previous').blur(function () {
        /* switch to aria-live POLITE Title/Summary */
        $('.slidesjs-summary').attr('aria-live','polite');
      });

      /*-- CLICK --*/
      $('.slidesjs-next, .slidesjs-previous').click(function() {
        pauseSlides();

        /* switch to aria-live ASSERTIVE Title/Summary */
        $('.slidesjs-summary').attr('aria-live','assertive');
      });

    /**** PAUSE/PLAY ****/

      /*-- Mouse/Key Trackers --*/
      $( ".slidesjs-psply" ).mousedown(function(){
        mousePause = true;
      });

      $( ".slidesjs-psply" ).keydown(function(){
        mousePause = false;
      });

      /*-- Focus ON --*/
      $('.slidesjs-psply').focus(function() {
        var plugin = $('#slides').first().data('plugin_slidesjs');

        $('.slidesjs-psply').attr('aria-live','assertive');
        if (($.data(plugin, 'playing') && (mousePause == false))) {
          pauseSlides();
        }
      });

      /*-- CLICK --*/
      $('.slidesjs-psply').click(function() {
        var plugin = $('#slides').first().data('plugin_slidesjs');

        if ($.data(plugin, 'playing')) {
          pauseSlides();
        }else {
          playSlides();
        }
      });

  });
</script>

