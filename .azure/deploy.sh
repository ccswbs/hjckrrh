#!/bin/bash

set -eu

ENV=$1

if [ -z "$ENV" ]
  then
    echo "Usage: $0 ENV" 
    exit 1
  fi

TAG="live"
ORG="university-of-guelph"
TERMINUS="terminus"
TFLAGS="--no-interaction --no-ansi"

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

