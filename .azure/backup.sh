#!/bin/bash

set -eu

ENV="dev"
TAG="live"
ORG="university-of-guelph"
TERMINUS="terminus"
TFLAGS="--no-interaction --no-ansi"

while [ $# -gt 0 ]
  do
    case $1 in
      -e|--env)
        ENV=$2
        shift
        shift
        ;;
      -t|--tag)
        TAG=$2
        shift
        shift
        ;;
      -o|--org)
        ORG=$2
        shift
        shift
        ;;
    esac
  done

SITES=$($TERMINUS $TFLAGS site:list --field=id)

for SITE in $SITES
  do
    TAGS=$($TERMINUS $TFLAGS tag:list $SITE $ORG --format=string)
    case "$TAGS" in
      *$TAG*)
        $TERMINUS $TFLAGS backup:automatic:enable --day=Sunday $SITE.$ENV
        ;;
    esac
  done

