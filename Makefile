
PREFIX ?= /usr/local
DEST ?= $(PREFIX)/drupal-7.x
VERSION ?= 7.x-12.0

site:
	drush -y site-install ug

test: 
	if command -v drush; then drush -y pm-enable simpletest; fi
	cd ../..; sudo -nu apache php scripts/run-tests.sh --url http://localhost/~$(USER) UG

install:
	rsync --recursive --verbose --cvs-exclude ../../ $(DEST)/

build:
	cd ../..; drush -y make profiles/ug/build-ug.make || true

release: build
	cd ../..; rm [A-Z]*.txt
	find . -name '*.info' -exec sed -i -e 's/^version = .*/version = $(VERSION)/' {} \;

