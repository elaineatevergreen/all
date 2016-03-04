#!/bin/bash
# Source adminweb environment.
. /opt/evergreen/ods/bin/collab_build_environment.sh
. drupal_deploy_functions.sh
. d7_migrations.sh
# Deploy Themes
deploy_d7_theme themes/wwwevergreen $COLLAB_CODE/drupal7
deploy_d7_module modules/custom/learning_community_directory $COLLAB_CODE/drupal7
run_site_updates $COLLAB_CODE/drupal7 site_updates_collab
# The new www7 sites are not on collab yet.
if [ "$STAGE"=='dev' ] ; then
  # Required Libraries
  deploy_d7_library libraries/iCalcreator $COLLAB_CODE/www7
  deploy_d7_library libraries/plupload $COLLAB_CODE/www7
  # Feature modules
  deploy_d7_theme themes/wwwevergreen $COLLAB_CODE/www7
  deploy_d7_custom_module modules/custom/evergreen_content $COLLAB_CODE/www7
  deploy_d7_custom_module modules/custom/campus_calendar $COLLAB_CODE/www7
  run_site_updates $COLLAB_CODE/www7 site_updates_www
fi
