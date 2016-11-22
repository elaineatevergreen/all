#!/usr/bin/env bash
. $HOME/.bashrc
. bin/drupal_deploy_functions.sh
. bin/d7_migrations.sh
export STAGE=PROD
export WWW_CODE=/var/www/evergreen.edu/htdocs
export SITE_SUFFIX=""
# push the site files to production
pwd
rsync -rtp --delete $WWW_CODE/sites/all/modules/custom/ 860elwb01:$WWW_CODE/sites/all/modules/custom
rsync -rvtp --delete $WWW_CODE/sites/all/themes/ 860elwb01:$WWW_CODE/sites/all/themes
ssh 860elwb01 "bin/prod_site_updates.sh"
rsync -rvtp --delete 860elwb01:$WWW_CODE/sites/all/ $WWW_CODE/sites/all
rsync -rvtp --delete $WWW_CODE/sites/all/ 860elwb01:$WWW_CODE/sites/all
