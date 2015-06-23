

site:
	drush -y site-install ug

test: site
	drush pm-enable -y ug_devel ug_feature
	drush generate-terms feature_category 4
	drush generate-content --types=feature,news,event,banner,page 50
	drush generate-terms social_media_category 4
	drush generate-content --types=social 20

