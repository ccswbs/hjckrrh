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

set -euo pipefail

# ---------------------------------------------------------------------
# Read configuration information from deploy.conf,
# ~/.drupal/deploy.conf, or /etc/drupal/deploy.conf

if [ -f ./deploy.conf ]; then
  . ./deploy.conf
elif [ -f ~/.drupal/deploy.conf ]; then
  . ~/.drupal/deploy.conf
elif [ -f /etc/drupal/deploy.conf ]; then
  . /etc/drupal/deploy.conf
else
  echo "No configuration file found. Exiting..."
  exit 1
fi

# ---------------------------------------------------------------------
# Process arguments.

OPTIND=1	# Reset option index.
ENV=""
REFENV=""

while getopts "e:r:" opt ; do
  case "$opt" in
  e)
    ENV=$OPTARG
    ;;
  r)
    REFENV=$OPTARG
    ;;
  esac
done

shift $((OPTIND-1))

# ---------------------------------------------------------------------
# Sanity check.

if [ -z "${ENV}" ]; then
  echo "No environment specified. Exiting..."
  exit 1
fi

if [[ $# -gt 0 ]]; then
  echo "Too many arguments provided."
  exit 1
fi

# ---------------------------------------------------------------------
# Lookup reference environment.

REF=""
if [ -n "${REFENV}" ]; then
  REF=`git tag -l deploy-${REFENV}-* | tail -1`
  if [ -z "${REF}" ]; then
    echo "Error: Reference environment ${REFENV} not found." 
    exit 1
  fi
fi

# ---------------------------------------------------------------------
# Create deploy tag.

STAMP=`date +%Y%m%d%H%M%S`
TAG="deploy-${ENV}-${STAMP}"
git tag ${TAG} ${REF}

# ---------------------------------------------------------------------
# Checkout branch to temporary directory.

PKG=`mktemp -d`
git --work-tree="${PKG}" checkout -f --quiet "${TAG}"

# ---------------------------------------------------------------------
# Deploy code and update db (with a maximum of 50 servers, but you
# can easily enlarge the server limit by adjusting MAXHOSTS.

RSYNCFLAGS="-r --delete --exclude=sites"
MAXHOSTS=${MAXHOSTS:-50}
i=0
while [ $i -lt $MAXHOSTS ]; do
  if [ "${ENVIRON[$i]}" = "${ENV}" ]; then
    rsync $RSYNCFLAGS "${PKG}/" "${HOSTNAM[$i]}:${DOCROOT[$i]}/"
    ssh "${HOSTNAM[$i]}" "drush -y -r ${DOCROOT[$i]} @sites updatedb"
  fi
  i=$(($i+1))
done

# ---------------------------------------------------------------------
# Clean up.

rm -rf "${PKG}"

