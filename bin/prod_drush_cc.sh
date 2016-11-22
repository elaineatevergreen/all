#!/usr/bin/env bash
. $HOME/.bashrc
. bin/drupal_deploy_functions.sh
. bin/d7_migrations.sh
export STAGE=PROD
export WWW_CODE=/var/www/evergreen.edu/htdocs
export SITE_SUFFIX=""
cd $WWW_CODE
drush --yes cc $1
