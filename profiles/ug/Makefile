
PREFIX ?= /usr/local
DEST ?= $(PREFIX)/drupal-7.x
VERSION ?= 7.x-11.1

site:
	drush -y site-install ug

test: 
	if command -v drush; then drush -y pm-enable simpletest; fi
	cd ../..; sudo -nu apache php scripts/run-tests.sh --url http://localhost/~$(USER) UG

install:
	rsync --recursive --verbose --cvs-exclude ../../ $(DEST)/

release:
	find . -name '*.info' -exec sed -i -e 's/^version = .*/version = $(VERSION)/' {} \;

