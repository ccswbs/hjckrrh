(function ($) {
Drupal.behaviors.editablefields_submit = {
  attach: function (context) {
    $('.editablefield-item', context).once('editablefield', function() {
      var $this = $(this);

      // There is only one editable field in that form, we can hide the submit
      // button.
      var $singleEditableFields = $this.find('input[type=text],input[type=checkbox],textarea,select');
      // Filter out select's from table drag.
      $singleEditableFields = $singleEditableFields.not('[name*="[_weight]"]');
      if ($singleEditableFields.length === 1 || $this.find('input[type=radio]').length > 1) {
        $this.find('.form-submit').hide();
        $this.find('input[type=text],input[type=checkbox],input[type=radio],textarea,select').change(function () {
          $this.find('.form-submit').triggerHandler('click');
        });
      }

      var submitName = '.form-submit.editablefield-edit-hover';
      var linkName = '.editablefield-hover-link';

      var $submit = $this.find(submitName);
      $submit.hide().after('<a href="#" class="editablefield-hover-link">' + $submit.attr('value') + '</a>');

      $this.find(linkName).hide().click(function () {
        $this.find(submitName).click();
        return false;
      });

      $this.hover(function () {
        $this.find(linkName).fadeToggle('fast');
      });
    });
  }
};

/**
 * Overridden from Drupal core autocomplete.js
 * Hides the autocomplete suggestions.
 */
Drupal.jsAC.prototype.hidePopup = function (keycode) {
  // Select item if the right key or mousebutton was pressed.
  if (this.selected && ((keycode && keycode !== 46 && keycode !== 8 && keycode !== 27) || !keycode)) {
    this.input.value = $(this.selected).data('autocompleteValue');
    $(this.input).trigger('change');
  }
  // Hide popup.
  var popup = this.popup;
  if (popup) {
    this.popup = null;
    $(popup).fadeOut('fast', function () { $(popup).remove(); });
  }
  this.selected = false;
  $(this.ariaLive).empty();
};

})(jQuery);
