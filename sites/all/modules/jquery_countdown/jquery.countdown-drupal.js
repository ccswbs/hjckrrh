/*
 * provides the countdown language by using the drupal js t() function... 
 */
(function($) {
  
	$.countdown.regional['drupal-locale'] = {
		labels: [
		  Drupal.t('Years'),
		  Drupal.t('Months'),
		  Drupal.t('Weeks'),
		  Drupal.t('Days'),
		  Drupal.t('Hours'),
		  Drupal.t('Minutes'),
		  Drupal.t('Seconds')
		],
		
		labels1: [
		  Drupal.t('Year'),
		  Drupal.t('Month'),
		  Drupal.t('Week'),
		  Drupal.t('Day'),
		  Drupal.t('Hour'),
		  Drupal.t('Minute'),
		  Drupal.t('Second')
		],
		
		compactLabels: [
		  Drupal.t('J'),
		  Drupal.t('M'),
		  Drupal.t('W'),
		  Drupal.t('D')
		],
		
		timeSeparator: ':', isRTL: false};
		
	$.countdown.setDefaults($.countdown.regional['drupal-locale']);
})(jQuery);
