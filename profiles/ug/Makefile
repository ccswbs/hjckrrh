

site:
	drush -y site-install ug

test: site
	drush pm-enable -y ug_devel ug_feature ug_faq ug_service
	drush generate-terms tags 100
	drush generate-terms news_category 10
	drush generate-content --types=news 50
	drush generate-terms feature_category 4
	drush generate-content --types=feature 50
	drush generate-terms social_media_category 4
	drush generate-content --types=social 50
	drush generate-terms event_heading 10
	drush generate-terms event_category 10
	drush generate-content --types=event 50
	drush generate-terms faq_category 10
	drush generate-content --types=faq 50
	drush generate-terms service_category 10
	drush generate-terms service_private_heading 10
	drush generate-terms service_public_heading 10
	drush generate-terms service_audience 10
	drush generate-content --types=service 50
	drush pm-enable -y ug_profile
	drush generate-terms profile_research 10
	drush generate-terms profile_field_headings 10
	drush generate-terms profile_role 10
	drush generate-terms profile_subunit 10
	drush generate-terms profile_unit 10
	drush generate-content --types=profile 50

