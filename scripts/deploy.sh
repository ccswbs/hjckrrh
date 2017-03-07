#!/bin/sh
# ---------------------------------------------------------------------
# NAME
#       deploy.sh - Drupal deployment script
#
# SYNOPSIS
#       deploy.sh ENV [BRANCH]
#
# DESCRIPTION
#       Deploys the given code BRANCH to servers in environment ENV,
#       and runs database updates.
#
#       ENV may be any environment defined below, such as "dev",
#       "stage", or "prod".
# 
#       BRANCH is any git branch in the current repository. Defaults
#       to "master".

# ---------------------------------------------------------------------
# Exit immediately on errors.

set -e

# ---------------------------------------------------------------------
# Read configuration information from /etc/drupal/deploy.conf or
# ~/.drupal/deploy.conf

if [ -f ~/.drupal/deploy.conf ]; then
  . ~/.drupal/deploy.conf
elif [ -f /etc/drupal/deploy.conf ]; then
  . /etc/drupal/deploy.conf
else
  echo "No configuration file found. Exiting..."
  exit 1
fi

# ---------------------------------------------------------------------
# Set environment and branch.

ENV="${1}"
REF="${2:-master}"

# ---------------------------------------------------------------------
# Sanity check.

if [ -z "${ENV}" ]; then
  echo "No environment specified. Exiting..."
  exit 1
fi

# ---------------------------------------------------------------------
# Checkout branch to temporary directory.

PKG=`mktemp -d`
git --work-tree="${PKG}" checkout -f "${BRANCH[$i]:-$2}"

# ---------------------------------------------------------------------
# Deploy code and update db (with a maximum of 50 servers, but you
# can easily enlarge the server limit by adjusting MAXHOSTS.

MAXHOSTS=${MAXHOSTS:-50}
i=0
while [ $i -lt $MAXHOSTS ]; do
  if [ "${ENVIRON[$i]}" = "${ENV}" ]; then
    rsync -r "${PKG}" "${HOSTNAM[$i]}:${DOCROOT[$i]}"
    ssh "${HOSTNAM[$i]}" "drush -y -r ${DOCROOT[$i]} @sites updatedb"
  fi
  i=$(($i+1))
done

# ---------------------------------------------------------------------
# Clean up.

rm -rf "${PKG}"

