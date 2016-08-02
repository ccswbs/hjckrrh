
PREFIX ?= /usr/local
DEST ?= $(PREFIX)/drupal-7.x
VERSION ?= 7.x-7.0

site:
	drush -y site-install ug

test: 
	drush -y pm-enable simpletest
	cd ../..; sudo -u apache php scripts/run-tests.sh --url http://localhost/~$(USER) UG

install:
	rsync --recursive --verbose --cvs-exclude ../../ $(DEST)/

release:
	find . -name '*.info' -exec sed -i -e 's/^version = .*/version = $(VERSION)/' {} \;

