/*************************
Dropdown Menus
*************************/

	/*---------------------
	Expanded State Fix
	---------------------**/
	jQuery(
	  	function($) {
		// On dropdown close
			$(document).on('hidden.bs.dropdown', function(event) {
			 var dropdown = $(event.target);
			 
			 // Set aria-expanded to false 
			 dropdown.find('.dropdown-menu').attr('aria-expanded', false);
			 
			 // Set focus back to dropdown toggle
			 dropdown.find('.dropdown-toggle').focus();
			});
		}
	)