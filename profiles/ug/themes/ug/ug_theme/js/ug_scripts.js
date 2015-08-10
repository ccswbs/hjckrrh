/*************************
Dropdown Menus
*************************/

	/*---------------------
	Expanded/Collapsed State Fix
	---------------------**/
	jQuery(
	  	function($) {

		// On dropdown open
		$(document).on('shown.bs.dropdown', function(event) {
		  var dropdown = $(event.target);
		 
		  // Set aria-expanded to true
		  dropdown.find('.dropdown-menu').attr('aria-expanded', true);
		  dropdown.find('.dropdown-toggle .toggle-indicator').html('hide menu ');
		 
		  // Set focus on the first link in the dropdown
		  setTimeout(function() {
		    dropdown.find('.dropdown-menu li:first-child a').focus();
		  }, 10);
		});
	  		
		// On dropdown close
		$(document).on('hidden.bs.dropdown', function(event) {
			 var dropdown = $(event.target);
			 
			 // Set aria-expanded to false 
			 dropdown.find('.dropdown-menu').attr('aria-expanded', false);
			 dropdown.find('.dropdown-toggle .toggle-indicator').html('show menu ');
			 
			 // Set focus back to dropdown toggle
			 dropdown.find('.dropdown-toggle').focus();
			});
		}
	)