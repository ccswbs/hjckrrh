/*-------------------------------------
Bootstrap collapsible aria-expanded fix
------------------------------------**/
jQuery(function($) {
	$(document).ready(function(e) {
		// For each collapsible element
		$(".collapse").each(function(i, elem) {
			// Determine if element is collapsed by default
			var isExpanded = $(elem).hasClass('in');

			// Set aria-expanded on collapsible container
			$(elem).attr("aria-expanded", isExpanded);

			// Select controlling element
			var controller = $('[data-target="#' + $(elem).attr("id") + '"]');

			// Set aria-controls on controlling element
			controller.attr("aria-controls", $(elem).attr("id"));
			controller.attr("data-toggle", "collapse");

			// If controller is a link, also set href to target id
			if(controller.get(0).tagName.toLowerCase() == "a") controller.attr("href", $(elem).attr("id"));
		});
	});
});
