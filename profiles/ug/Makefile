
PREFIX ?= /usr/local
DEST ?= $(PREFIX)/drupal-7.x

site:
	drush -y site-install ug

test: 
	if command -v drush; then drush -y pm-enable simpletest; fi
	cd ../..; sudo -nu apache php scripts/run-tests.sh --url http://localhost/~$(USER) UG

install:
	rsync --recursive --verbose --cvs-exclude ../../ $(DEST)/

build:
	cd ../..; drush -y make profiles/ug/build-ug.make || true

release:
	scripts/drupal-org-package.sh

