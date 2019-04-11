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
        case "$ENV" in
          dev)
            $TERMINUS $TFLAGS upstream:updates:apply --updatedb --accept-upstream $SITE.$ENV
            ;;
          test)
            $TERMINUS $TFLAGS env:deploy --sync-content --updatedb --cc $SITE.$ENV
            ;;
          live)
            $TERMINUS $TFLAGS env:deploy --updatedb --cc $SITE.$ENV
            ;;
        esac
      ;;
    esac
  done

