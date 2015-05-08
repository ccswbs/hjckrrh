

site:
	drush -y site-install ug
	drush -y pm-enable ug_user
	drush -y features-revert ug_user

test: site
	drush pm-enable -y ug_devel
	drush generate-content --kill --types=news,event,banner 50

