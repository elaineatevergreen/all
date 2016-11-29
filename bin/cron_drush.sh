#!/usr/bin/env bash
export CI_BUILD_REF_NAME="$1"
if [[ -z "$CI_BUILD_REF_NAME" ]] ; then
  export CI_BUILD_REF_NAME="dev"
fi
. $HOME/bin/www_build_environment.sh
cd $WWW_CODE
echo "Running cron for $WWW_CODE: $CI_BUILD_REF_NAME : $1"
drush --yes cron