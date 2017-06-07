#!/usr/bin/env bash
set -e
. bin/www_build_environment.sh
. bin/drupal_deploy_functions.sh
. bin/d7_migrations.sh
# Deploy Themes
echo "Beginning WWW Deployment"
rsync -rtp --delete etc/ $HOME/etc
# Because dev and test are on the same box, only update these scripts on dev updates.
if [[ $STAGE != "test" ]] ; then
  rsync -rtp bin/ $HOME/bin
fi
#
# Required Libraries
deploy_d7_library libraries/iCalcreator $WWW_CODE
deploy_d7_library libraries/plupload $WWW_CODE
deploy_d7_library libraries/juicebox $WWW_CODE
deploy_d7_library libraries/flowplayer5 $WWW_CODE
# Feature modules
deploy_d7_theme themes/wwwevergreen $WWW_CODE
deploy_d7_custom_module modules/custom/evergreen_content $WWW_CODE
deploy_d7_custom_module modules/custom/evergreen_migration $WWW_CODE
deploy_d7_custom_module modules/custom/evergreen_cas $WWW_CODE
deploy_d7_custom_module modules/custom/basic_content $WWW_CODE
deploy_d7_custom_module modules/custom/learning_community_directory $WWW_CODE
deploy_d7_custom_module modules/custom/native_cases $WWW_CODE
deploy_d7_custom_module modules/custom/simple_events $WWW_CODE
rsync .htaccess $WWW_CODE/

# Perform Production updates.
if [[ "$STAGE" = "prod" ]] ; then
  rsync -rtp --delete $HOME/bin/ www_deploy@860elwb01:./bin
  rsync -rtp --delete $HOME/bin/ www_deploy@860elwb02:./bin
  rsync -rtp --delete $HOME/etc/ www_deploy@860elwb01:./etc
  rsync -rtp --delete $HOME/etc/ www_deploy@860elwb02:./etc
  rsync -rtp --delete site_updates_www/ www_deploy@860elwb01:./site_updates_www
  rsync .htaccess www_deploy@860elwb01:$WWW_CODE/
  rsync .htaccess www_deploy@860elwb02:$WWW_CODE/
  echo "execute Remote production updates"
  bin/execute_prod_updates.sh
else
  run_site_updates $WWW_CODE site_updates_www
  cd $WWW_CODE
  drush cc all
fi