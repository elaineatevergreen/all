#!/usr/bin/env bash
export PATH=$HOME/bin:$HOME/.composer/vendor/bin:$PATH
. bin/drupal_deploy_functions.sh
. bin/d7_migrations.sh
export STAGE=PROD
export WWW_CODE=/var/www/evergreen.edu/htdocs
run_site_updates $WWW_CODE site_updates_www