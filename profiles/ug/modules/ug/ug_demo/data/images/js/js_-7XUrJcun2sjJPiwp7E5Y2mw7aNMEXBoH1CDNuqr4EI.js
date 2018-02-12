(function ($) {

/**
 * Attaches sticky table headers.
 */
Drupal.behaviors.tableHeader = {
  attach: function (context, settings) {
    if (!$.support.positionFixed) {
      return;
    }

    $('table.sticky-enabled', context).once('tableheader', function () {
      $(this).data("drupal-tableheader", new Drupal.tableHeader(this));
    });
  }
};

/**
 * Constructor for the tableHeader object. Provides sticky table headers.
 *
 * @param table
 *   DOM object for the table to add a sticky header to.
 */
Drupal.tableHeader = function (table) {
  var self = this;

  this.originalTable = $(table);
  this.originalHeader = $(table).children('thead');
  this.originalHeaderCells = this.originalHeader.find('> tr > th');
  this.displayWeight = null;

  // React to columns change to avoid making checks in the scroll callback.
  this.originalTable.bind('columnschange', function (e, display) {
    // This will force header size to be calculated on scroll.
    self.widthCalculated = (self.displayWeight !== null && self.displayWeight === display);
    self.displayWeight = display;
  });

  // Clone the table header so it inherits original jQuery properties. Hide
  // the table to avoid a flash of the header clone upon page load.
  this.stickyTable = $('<table class="sticky-header"/>')
    .insertBefore(this.originalTable)
    .css({ position: 'fixed', top: '0px' });
  this.stickyHeader = this.originalHeader.clone(true)
    .hide()
    .appendTo(this.stickyTable);
  this.stickyHeaderCells = this.stickyHeader.find('> tr > th');

  this.originalTable.addClass('sticky-table');
  $(window)
    .bind('scroll.drupal-tableheader', $.proxy(this, 'eventhandlerRecalculateStickyHeader'))
    .bind('resize.drupal-tableheader', { calculateWidth: true }, $.proxy(this, 'eventhandlerRecalculateStickyHeader'))
    // Make sure the anchor being scrolled into view is not hidden beneath the
    // sticky table header. Adjust the scrollTop if it does.
    .bind('drupalDisplaceAnchor.drupal-tableheader', function () {
      window.scrollBy(0, -self.stickyTable.outerHeight());
    })
    // Make sure the element being focused is not hidden beneath the sticky
    // table header. Adjust the scrollTop if it does.
    .bind('drupalDisplaceFocus.drupal-tableheader', function (event) {
      if (self.stickyVisible && event.clientY < (self.stickyOffsetTop + self.stickyTable.outerHeight()) && event.$target.closest('sticky-header').length === 0) {
        window.scrollBy(0, -self.stickyTable.outerHeight());
      }
    })
    .triggerHandler('resize.drupal-tableheader');

  // We hid the header to avoid it showing up erroneously on page load;
  // we need to unhide it now so that it will show up when expected.
  this.stickyHeader.show();
};

/**
 * Event handler: recalculates position of the sticky table header.
 *
 * @param event
 *   Event being triggered.
 */
Drupal.tableHeader.prototype.eventhandlerRecalculateStickyHeader = function (event) {
  var self = this;
  var calculateWidth = event.data && event.data.calculateWidth;

  // Reset top position of sticky table headers to the current top offset.
  this.stickyOffsetTop = Drupal.settings.tableHeaderOffset ? eval(Drupal.settings.tableHeaderOffset + '()') : 0;
  this.stickyTable.css('top', this.stickyOffsetTop + 'px');

  // Save positioning data.
  var viewHeight = document.documentElement.scrollHeight || document.body.scrollHeight;
  if (calculateWidth || this.viewHeight !== viewHeight) {
    this.viewHeight = viewHeight;
    this.vPosition = this.originalTable.offset().top - 4 - this.stickyOffsetTop;
    this.hPosition = this.originalTable.offset().left;
    this.vLength = this.originalTable[0].clientHeight - 100;
    calculateWidth = true;
  }

  // Track horizontal positioning relative to the viewport and set visibility.
  var hScroll = document.documentElement.scrollLeft || document.body.scrollLeft;
  var vOffset = (document.documentElement.scrollTop || document.body.scrollTop) - this.vPosition;
  this.stickyVisible = vOffset > 0 && vOffset < this.vLength;
  this.stickyTable.css({ left: (-hScroll + this.hPosition) + 'px', visibility: this.stickyVisible ? 'visible' : 'hidden' });

  // Only perform expensive calculations if the sticky header is actually
  // visible or when forced.
  if (this.stickyVisible && (calculateWidth || !this.widthCalculated)) {
    this.widthCalculated = true;
    var $that = null;
    var $stickyCell = null;
    var display = null;
    var cellWidth = null;
    // Resize header and its cell widths.
    // Only apply width to visible table cells. This prevents the header from
    // displaying incorrectly when the sticky header is no longer visible.
    for (var i = 0, il = this.originalHeaderCells.length; i < il; i += 1) {
      $that = $(this.originalHeaderCells[i]);
      $stickyCell = this.stickyHeaderCells.eq($that.index());
      display = $that.css('display');
      if (display !== 'none') {
        cellWidth = $that.css('width');
        // Exception for IE7.
        if (cellWidth === 'auto') {
          cellWidth = $that[0].clientWidth + 'px';
        }
        $stickyCell.css({'width': cellWidth, 'display': display});
      }
      else {
        $stickyCell.css('display', 'none');
      }
    }
    this.stickyTable.css('width', this.originalTable.outerWidth());
  }
};

})(jQuery);
;
/**
 * @file
 * A JavaScript file for the theme.
 * This file should be used as a template for your other js files.
 * It defines a drupal behavior the "Drupal way".
 *
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth

(function ($, Drupal, window, document, undefined) {
  'use strict';

  // To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.hideSubmitBlockit = {
    attach: function(context) {
      var timeoutId = null;
      $('form', context).once('hideSubmitButton', function () {
        var $form = $(this);

        // Bind to input elements.
        if (Drupal.settings.hide_submit.hide_submit_method === 'indicator') {
          // Replace input elements with buttons.
          $('input.form-submit', $form).each(function(index, el) {
            var attrs = {};

            $.each($(this)[0].attributes, function(idx, attr) {
                attrs[attr.nodeName] = attr.nodeValue;
            });

            $(this).replaceWith(function() {
                return $("<button/>", attrs).append($(this).attr('value'));
            });
          });
          // Add needed attributes to the submit buttons.
          $('button.form-submit', $form).each(function(index, el) {
            $(this).addClass('ladda-button button').attr({
              'data-style': Drupal.settings.hide_submit.hide_submit_indicator_style,
              'data-spinner-color': Drupal.settings.hide_submit.hide_submit_spinner_color,
              'data-spinner-lines': Drupal.settings.hide_submit.hide_submit_spinner_lines
            });
          });
          Ladda.bind('.ladda-button', $form, {
            timeout: Drupal.settings.hide_submit.hide_submit_reset_time
          });
        }
        else {
          $('input.form-submit, button.form-submit', $form).click(function (e) {
            var el = $(this);
            el.after('<input type="hidden" name="' + el.attr('name') + '" value="' + el.attr('value') + '" />');
            return true;
          });
        }

        // Bind to form submit.
        $('form', context).submit(function (e) {
          var $inp;
          if (!e.isPropagationStopped()) {
            if (Drupal.settings.hide_submit.hide_submit_method === 'disable') {
              $('input.form-submit, button.form-submit', $form).attr('disabled', 'disabled').each(function (i) {
                var $button = $(this);
                if (Drupal.settings.hide_submit.hide_submit_css) {
                  $button.addClass(Drupal.settings.hide_submit.hide_submit_css);
                }
                if (Drupal.settings.hide_submit.hide_submit_abtext) {
                  $button.val($button.val() + ' ' + Drupal.settings.hide_submit.hide_submit_abtext);
                }
                $inp = $button;
              });

              if ($inp && Drupal.settings.hide_submit.hide_submit_atext) {
                $inp.after('<span class="hide-submit-text">' + Drupal.checkPlain(Drupal.settings.hide_submit.hide_submit_atext) + '</span>');
              }
            }
            else if (Drupal.settings.hide_submit.hide_submit_method !== 'indicator'){
              var pdiv = '<div class="hide-submit-text' + (Drupal.settings.hide_submit.hide_submit_hide_css ? ' ' + Drupal.checkPlain(Drupal.settings.hide_submit.hide_submit_hide_css) + '"' : '') + '>' + Drupal.checkPlain(Drupal.settings.hide_submit.hide_submit_hide_text) + '</div>';
              if (Drupal.settings.hide_submit.hide_submit_hide_fx) {
                $('input.form-submit, button.form-submit', $form).addClass(Drupal.settings.hide_submit.hide_submit_css).fadeOut(100).eq(0).after(pdiv);
                $('input.form-submit, button.form-submit', $form).next().fadeIn(100);
              }
              else {
                $('input.form-submit, button.form-submit', $form).addClass(Drupal.settings.hide_submit.hide_submit_css).hide().eq(0).after(pdiv);
              }
            }
            // Add a timeout to reset the buttons (if needed).
            if (Drupal.settings.hide_submit.hide_submit_reset_time) {
              timeoutId = window.setTimeout(function() {
                hideSubmitResetButtons(null, $form);
              }, Drupal.settings.hide_submit.hide_submit_reset_time);
            }
          }
          return true;
        });
      });

      // Bind to clientsideValidationFormHasErrors to support clientside validation.
      // $(document).bind('clientsideValidationFormHasErrors', function(event, form) {
        //hideSubmitResetButtons(event, form.form);
      // });

      // Reset all buttons.
      function hideSubmitResetButtons(event, form) {
        // Clear timer.
        window.clearTimeout(timeoutId);
        timeoutId = null;
        switch (Drupal.settings.hide_submit.hide_submit_method) {
          case 'disable':
            $('input.' + Drupal.checkPlain(Drupal.settings.hide_submit.hide_submit_css) + ', button.' + Drupal.checkPlain(Drupal.settings.hide_submit.hide_submit_css), form)
              .each(function (i, el) {
                $(el).removeClass(Drupal.checkPlain(Drupal.settings.hide_submit.hide_submit_hide_css))
                  .removeAttr('disabled');
              });
            $('.hide-submit-text', form).remove();
            break;

          case 'indicator':
            Ladda.stopAll();
            break;

          default:
            $('input.' + Drupal.checkPlain(Drupal.settings.hide_submit.hide_submit_css) + ', button.' + Drupal.checkPlain(Drupal.settings.hide_submit.hide_submit_css), form)
              .each(function (i, el) {
                $(el).stop()
                  .removeClass(Drupal.checkPlain(Drupal.settings.hide_submit.hide_submit_hide_css))
                  .show();
              });
            $('.hide-submit-text', form).remove();
        }
      }
    }
  };

})(jQuery, Drupal, window, this.document);
;
