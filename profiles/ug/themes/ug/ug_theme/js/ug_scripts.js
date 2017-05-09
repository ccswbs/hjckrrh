/*-------------------------------------
Bootstrap collapsible aria-expanded fix
------------------------------------**/
jQuery(function($) {
	$(document).ready(function(e) {
		$(".collapse").each(function(i, elem) {
			var isExpanded = $(elem).hasClass('in');
			$(elem).attr("aria-expanded", isExpanded);
			$('[data-target="#' + $(elem).attr("id") + '"]').attr("aria-expanded", isExpanded);
		});
	});
});
