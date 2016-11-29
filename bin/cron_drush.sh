#!/usr/bin/env bash
export CI_BUILD_REF="$1"
if [[ -z "$CI_BUILD_REF" ]] ; then
  export CI_BUILD_REF="dev"
fi
. bin/www_build_environment.sh
cd $WWW_CODE
echo "Running cron for $WWW_CODE"
drush --yes cron