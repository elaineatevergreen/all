#!/usr/bin/env bash
. $HOME/.bashrc
. bin/drupal_deploy_functions.sh
. bin/d7_migrations.sh
export STAGE=PROD
export WWW_CODE=/var/www/evergreen.edu/htdocs
export SITE_SUFFIX=""
# push the site files to production
rsync -rtp --delete $WWW_CODE/sites/all/modules/custom/ 860elwb01:$WWW_CODE/sites/all/modules/custom
rsync -rtp --delete $WWW_CODE/sites/all/themes/ 860elwb01:$WWW_CODE/sites/all/themes
rsync -rpt --delete $WWW_CODE/sites/all/libraries/ 860elwb01:$WWW_CODE/sites/all/libraries
ssh 860elwb01 "bin/prod_site_updates.sh"
rsync -rtp --delete 860elwb01:$WWW_CODE/sites/all/ $WWW_CODE/sites/all
rsync -rtp --delete $WWW_CODE/sites/all/ 860elwb02:$WWW_CODE/sites/all
ssh 860elwb01 "bin/prod_drush_cc.sh all"
ssh 860elwb02 "bin/prod_drush_cc.sh all"
