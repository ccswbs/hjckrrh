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

    // var testcounter = 0;
    var mousePause = false;
    var mouseUpNxtPrv = false;

    function update(number) {
      var active = $('.slidesjs-control').children()[number-1];
      var focusedElement = document.activeElement;

      //$('.slidesjs-slide-number').text(number);
      $('.slidesjs-pagination .btn').html('Slide <span class="slidesjs-slide-number">' + number + '</span> of ' + <?php print $slide_count ?>);
      $('.slidesjs-slide-title').html('<span class="sr-only">slide ' + number + ' headline - </span>' + $(active).data('title'));
      $('.slidesjs-slide-link').attr('href', $(active).data('link'));
      $('.slidesjs-slide-text').text($(active).data('text'));

      if($(active).data('alt') != ""){
        $(active).attr('alt','slide ' + number + ' banner - ' + $(active).data('alt'));
      }

      // Hide inactive banners during first cycle of slideshow
      $('.slidesjs-slide').css("display","none");
      $('.slidesjs-slide').css("z-index","0");
      $(active).css("display","block");
      $(active).css("z-index","10");

      // IF FOCUS ON slideshow (exclusive)   
      if ($(focusedElement).is($('#slides').find(':focus'))) {
        var plugin = $('#slides').first().data('plugin_slidesjs');
        $('.slidesjs-summary').attr('aria-live','polite');

        /**** NEXT/PREVIOUS Buttons - Reinforce assertive aria-live ON FOCUS ****/
        if (!($.data(plugin, 'playing'))) {
          if(($(focusedElement).is($('.slidesjs-next'))) || ($(focusedElement).is($('.slidesjs-previous')))) {
            $('.slidesjs-summary').attr('aria-live','assertive');
          }
        }
      }else{  
        $('.slidesjs-summary').attr('aria-live','off');
      }

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
      // if (testcounter <= 3){
        // alert("pause 1b - pauseSlides()");
        // alert($.data(plugin, 'playing'));
      // }


      /* Bug Fix for Mouse Up on Next/Previous Pause Glitch

      Clicking next/previous buttons (specifically) with mouse causes 
      the slideshow to pause, but does not flag the $.data(plugin, 'playing') value as TRUE.
      We end up with the Pause button even though the slideshow is paused.

      As an override, we use the mouseUpNxtPrv variable to track if the mouseup event occurred.
      If so, allow the plugin through. At the end, we reset the variable, so keyboard-friendly
      behaviour is not affected.

      */

      if (($.data(plugin, 'playing'))||(mouseUpNxtPrv == true)) {
        // alert("pause 2b - stop slides");
        plugin.stop();
        // alert("pause 3b - switch to play btn");
        $('#slide-state').text('slideshow paused');
        $('.slidesjs-stop').hide();
        $('.slidesjs-play').show();
        // alert("pause 4b - end of pauseSlides()");
        mouseUpNxtPrv = false;
      }//else{

      
      // testcounter++;
      // }
    }

    function playSlides() {
      var plugin = $('#slides').first().data('plugin_slidesjs');

      // alert("play 1 - playSlides()");
      if (!($.data(plugin, 'playing'))) {

        // alert("play 2 - play slides");
        //set to false to wait full interval before advancing to next slide 
        plugin.play(false);
        // alert("play 3 - switch to pause btn");
        $('#slide-state').text('slideshow playing');
        $('.slidesjs-play').hide();
        $('.slidesjs-stop').show();
        // alert("play 4 - end of playSlides()");
      }
    }

    /**** Slide LINK - ON FOCUS ****/
    $('.slidesjs-slide-link').focus(function () {
      pauseSlides();
    });


    /**** NEXT/PREVIOUS Buttons - Mouse/Key Trackers ****/
    $(".slidesjs-previous, .slidesjs-next").mouseup( function() {
      mouseUpNxtPrv = true;
    });

    $(".slidesjs-previous, .slidesjs-next").keydown( function() {
      mouseUpNxtPrv = false;
    });

    /**** NEXT/PREVIOUS Buttons - ON FOCUS ****/
    $('.slidesjs-next, .slidesjs-previous').focus(function() {
      var plugin = $('#slides').first().data('plugin_slidesjs');

      /* IF PAUSED - switch to aria-live ASSERTIVE Title/Summary */
      if (!($.data(plugin, 'playing'))) {
        $('.slidesjs-summary').attr('aria-live','assertive');
      }
    });

    /**** NEXT/PREVIOUS - FOCUS OFF (Blur) ****/
    $('.slidesjs-next, .slidesjs-previous').blur(function () {
      /* switch to aria-live POLITE Title/Summary */
      $('.slidesjs-summary').attr('aria-live','polite');
    });

    /**** NEXT/PREVIOUS - CLICK ****/
    $('.slidesjs-next, .slidesjs-previous').click(function() {
      // alert("next/prev - CLICK");

      // if (($.data(plugin, 'playing') && (mouseUser == false))) {
        // pauseSlides();
      // }

      // testcounter = 0;
      pauseSlides();

      /* switch to aria-live ASSERTIVE Title/Summary */
      $('.slidesjs-summary').attr('aria-live','assertive');
    });

    /**** PAUSE/PLAY - Mouse/Key Trackers ****/
    $( ".slidesjs-psply" ).mousedown(function(){
      mousePause = true;
    });

    $( ".slidesjs-psply" ).keydown(function(){
      mousePause = false;
    });

    /**** PAUSE/PLAY - ON FOCUS ****/
    $('.slidesjs-psply').focus(function() {
      var plugin = $('#slides').first().data('plugin_slidesjs');

      // if (testcounter <= 3){
      //   alert("FOCUS on psply");
      // }

      $('.slidesjs-psply').attr('aria-live','assertive');
      if (($.data(plugin, 'playing') && (mousePause == false))) {
        pauseSlides();
      }

      // testcounter++;
    });

    /**** PAUSE/PLAY - CLICK ****/
    $('.slidesjs-psply').click(function() {
      var plugin = $('#slides').first().data('plugin_slidesjs');

      testcounter = 0;
      // alert("CLICK on psply");

      if ($.data(plugin, 'playing')) {
        // alert("pause");
        pauseSlides();
      }else {
        // alert("play");
        playSlides();
      }

      // alert ('end of click');
    });

  });
</script>

