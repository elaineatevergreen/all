#!/usr/bin/env bash
. $HOME/.bashrc
. bin/drupal_deploy_functions.sh
. bin/d7_migrations.sh
export STAGE='prod'
export WWW_CODE='/var/www/evergreen.edu/htdocs'
export SITE_SUFFIX="";
pwd
run_site_updates $WWW_CODE site_updates_www