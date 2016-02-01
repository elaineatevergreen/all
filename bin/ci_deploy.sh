#!/bin/bash
# Source adminweb environment.
. /opt/evergreen/ods/bin/adminweb_build_environment.sh
. drupal_deploy_functions.sh
# Deploy Themes
deploy_d7_theme themes/wwwevergreen $COLLAB_CODE/drupal7
deploy_d7_module modules/custom/learning_community_directory $COLLAB_CODE/drupal7
# The new www7 sites are not on collab yet.
if [ "$STAGE"=='dev' ] ; then
  # Required Libraries
  deploy_d7_library libraries/iCalcreator $COLLAB_CODE/www7
  deploy_d7_library libraries/plupload $COLLAB_CODE/www7
  # Feature modules
  deploy_d7_theme themes/wwwevergreen $COLLAB_CODE/www7
  deploy_d7_custom_module modules/custom/evergreen_content $COLLAB_CODE/www7
  deploy_d7_custom_module modules/custom/campus_calendar $COLLAB_CODE/www7
fi
