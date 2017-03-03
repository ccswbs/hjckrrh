#!/bin/sh
# ---------------------------------------------------------------------
# NAME
#       deploy.sh - Drupal deployment script
#
# SYNOPSIS
#       deploy.sh [-r REF] [ENV ...]
#
# DESCRIPTION
#       Deploys code to servers in environment ENV, and runs 
#       database updates.
#
#       ENV may be any environment such as "dev", "stage", or "prod".
# 
#       REF is a reference environment. The last tag deployed to
#       the REF environment will be deployed to ENV. If REF is not
#       specified, the current branch will be deployed.

# ---------------------------------------------------------------------
# Exit immediately on errors.

set -euo pipefail

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
# Process arguments.

OPTIND=1	# Reset option index.
REF=""

while getopts "r:" opt ; do
  case "$opt" in
  r)
    REF=`git tag -l deploy-${OPTARG}-* | tail -1`
    if [ -z "${REF}" ]; then
      echo "Error: Reference environment ${OPTARG} not found." 
      exit 1
    fi
    ;;
  esac
done

shift $((OPTIND-1))

# ---------------------------------------------------------------------
# Sanity check.

if [[ $# -eq 0 ]]; then
  echo "No environments specified."
  exit 1
fi

# ---------------------------------------------------------------------
# Confirm.

printf "\nYou are about to deploy:\n\n"
printf "\t * ${REF:-`git rev-parse --abbrev-ref HEAD`}\n"
printf "\nto the following environment(s):\n\n"
for ENV in $@; do
  printf "\t * $ENV\n"
done
printf "\nContinue [y/n] ? "
read answer
if [ "${answer}" != "y" ]; then
  echo "Aborting..."
  exit 0
fi

# ---------------------------------------------------------------------
# Loop over target environments.

for ENV in $@; do

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
# End of environments loop.

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

