/**
 * @file
 * Contains the Siteimprove Plugin methods.
 */

(function ($) {

    var siteimprove = {
        input: function () {
            this.url = Drupal.settings.siteimprove.input.url;
            this.method = 'input';
            this.common();
        },
        domain: function () {
            this.url = Drupal.settings.siteimprove.domain.url;
            this.method = 'domain';
            this.common();
        },
        recheck: function () {
            this.url = Drupal.settings.siteimprove.recheck.url;
            this.method = 'recheck';
            this.common();
        },
        recrawl: function () {
            this.url = Drupal.settings.siteimprove.recrawl.url;
            this.method = 'recrawl';
            this.common();
        },
        common: function () {
            var _si = window._si || [];
            _si.push([this.method, this.url, Drupal.settings.siteimprove.token]);
        },
        events: {
            recheck: function () {
                $('.recheck-button').click(function() {
                    siteimprove.recheck();
                    $(this).attr('disabled', true);
                    $(this).addClass('form-button-disabled');
                    return false;
                });
            }
        }
    };

    Drupal.behaviors.siteimprove = {
        attach: function (context, settings) {

            // If exist recheck, call recheck Siteimprove method.
            if (typeof settings.siteimprove.recheck !== 'undefined') {
                if (settings.siteimprove.recheck.auto) {
                    siteimprove.recheck();
                }
                siteimprove.events.recheck();
            }

            // If exist input, call input Siteimprove method.
            if (typeof settings.siteimprove.input !== 'undefined') {
                if (settings.siteimprove.input.auto) {
                    siteimprove.input();
                }
            }

            // If exist input, call domain Siteimprove method.
            if (typeof settings.siteimprove.domain !== 'undefined') {
                if (settings.siteimprove.domain.auto) {
                    siteimprove.domain();
                }
            }

            // If exist recrawl, call input Siteimprove method.
            if (typeof settings.siteimprove.recrawl !== 'undefined') {
                if (settings.siteimprove.recrawl.auto) {
                    siteimprove.recrawl();
                }
            }

        }
    };

})(jQuery);
