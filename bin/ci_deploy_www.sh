#!/usr/bin/env bash
set -e
. bin/www_build_environment.sh
. bin/drupal_deploy_functions.sh
. bin/d7_migrations.sh
# Deploy Themes
echo "Beginning WWW Deployment"
rsync -rtp --delete etc/ $HOME/etc
rsync -rtp bin/ $HOME/bin
#
# Required Libraries
deploy_d7_library libraries/iCalcreator $WWW_CODE
deploy_d7_library libraries/plupload $WWW_CODE
# Feature modules
deploy_d7_theme themes/wwwevergreen $WWW_CODE
deploy_d7_custom_module modules/custom/evergreen_content $WWW_CODE
deploy_d7_custom_module modules/custom/evergreen_migration $WWW_CODE
deploy_d7_custom_module modules/custom/evergreen_cas $WWW_CODE
echo "www site updates"
run_site_updates $WWW_CODE site_updates_www
