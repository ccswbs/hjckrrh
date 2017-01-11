#!/bin/sh
set -xeuo pipefail
TMP=/tmp
CORE=7.x
RELEASE=$(git describe --tags)
NAME=ug
VERSION=$CORE-$RELEASE
PKG=$TMP/package-$NAME
CWD=$(pwd)

# Clean and recreate package directory
rm -rf $PKG
mkdir $PKG

# First, build no-core version of profile
cd $PKG
cp -R $CWD $NAME
cd $NAME
find . -name '*.info' -exec sed -i -e "s/VERSION/$VERSION/" {} \;
# Before building, package basic profile
tar -C$PKG -czf $TMP/$NAME-$VERSION.tar.gz $NAME
# Now build and package no-core version
drush make --drupal-org $CWD/drupal-org.make .
cd $PKG
tar -czf $TMP/$NAME-$VERSION-nocore.tar.gz $NAME

# Build full release
cd $PKG
drush make --drupal-org=core $CWD/drupal-org-core.make $NAME-$VERSION
cd $NAME-$VERSION
cp -R $PKG/$NAME profiles/$NAME
cd $PKG
tar -czf $TMP/$NAME-$VERSION-core.tar.gz $NAME-$VERSION

