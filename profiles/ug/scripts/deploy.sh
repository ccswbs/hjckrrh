#!/bin/sh
# ---------------------------------------------------------------------
# NAME
#       deploy.sh - Drupal deployment script
#
# SYNOPSIS
#       deploy.sh ENV
#
# DESCRIPTION
#       Deploys code to servers in environment ENV, and runs 
#       database updates.
#
#       ENV may be an environment such as "dev", "test", or "live".
# 
#       When ENV is the dev environment, the default branch (master)
#       is deployed. When ENV is test, the most recent dev tag is 
#       deployed. When ENV is live, the most recent test tag is
#       deployed.
#

# ---------------------------------------------------------------------
# Exit immediately on errors.

set -euo pipefail

# ---------------------------------------------------------------------
# Environments

DEV="dev"
TEST="test"
LIVE="live"
BRANCH="master"

# ---------------------------------------------------------------------
# Read configuration information from deploy.conf,
# ~/.drupal/deploy.conf, or /etc/drupal/deploy.conf

LOCALCONF="./deploy.conf"
USERCONF="~/.drupal/deploy.conf"
GLOBALCONF="/etc/drupal/deploy.conf"

if [ -f $LOCALCONF ]; then
  CONF=$LOCALCONF
elif [ -f $USERCONF ]; then
  CONF=$USERCONF
elif [ -f $GLOBALCONF ]; then
  CONF=$GLOBALCONF
else
  echo "No configuration file found. Exiting..."
  exit 1
fi

. $CONF

# ---------------------------------------------------------------------
# Sanity check.

if [[ $# -eq 0 ]]; then
  echo "No environment specified."
  exit 1
fi

# ---------------------------------------------------------------------
# Set environment and ref.

ENV=${1}

REF=""
case $ENV in
  $DEV)
    REF=$BRANCH
    ;;
  $TEST)
    REF=`git tag -l deploy-$DEV-* | tail -1`
    ;;
  $LIVE)
    REF=`git tag -l deploy-$TEST-* | tail -1`
    ;;
  *)
    echo "$ENV is not a valid environment."
    echo "Try $DEV, $TEST, or $LIVE instead."
    exit 1
    ;;
esac

echo "Deploying $REF to $ENV"

# ---------------------------------------------------------------------
# Create deploy tag.

STAMP=`date +%Y%m%d%H%M%S`
TAG="deploy-${ENV}-${STAMP}"
git tag ${TAG} ${REF}

# ---------------------------------------------------------------------
# Checkout branch to temporary directory.

PKG=`mktemp -d`
TOPLEVEL=`git rev-parse --show-toplevel`
git clone --quiet ${TOPLEVEL} ${PKG}
cd ${PKG} && git checkout --quiet ${TAG}

# ---------------------------------------------------------------------
# Deploy code and update db (with a maximum of 50 servers, but you
# can easily increase the server limit by adjusting MAXHOSTS.

RSYNCFLAGS="-r --delete --cvs-exclude --exclude=sites"
MAXHOSTS=${MAXHOSTS:-50}
i=0
while [ $i -lt $MAXHOSTS ]; do
  set +u
  if [ "${ENVIRON[$i]}" = "${ENV}" ]; then
    set -u
    TARGET="${HOSTNAM[$i]}:${DOCROOT[$i]}"
    echo "[$TARGET] Deploying code ..."
    rsync $RSYNCFLAGS "${PKG}/" "${TARGET}/"
    echo "[$TARGET] Running database updates ..."
    ssh "${HOSTNAM[$i]}" "drush -y -r ${DOCROOT[$i]} @sites updatedb"
  fi
  i=$(($i+1))
done

# ---------------------------------------------------------------------
# Check for MAXHOSTS limit.

set +u
if [ -n "${ENVIRON[$i]}" ]; then
  echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
  echo "  WARNING:"
  echo "    You look to have exceeded the MAXHOSTS limit of $MAXHOSTS."
  echo "    Consider adding MAXHOSTS=$((MAXHOSTS + 10)) to ${CONF}."
  echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
fi
set -u

# ---------------------------------------------------------------------
# Clean up.

rm -rf "${PKG}"

