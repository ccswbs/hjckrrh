

site:
	drush -y site-install ug

test: site
	drush pm-enable -y ug_devel
	drush generate-content --types=news,event,banner 50
	drush generate-terms social_media_category 4
	drush generate-content --types=social 20

