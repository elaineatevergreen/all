#!/bin/bash
set -e
export WWW_CODE='/var/www/html/www'
# Source adminweb environment.
. /opt/evergreen/ods/bin/collab_build_environment.sh
. drupal_deploy_functions.sh
. d7_migrations.sh
# Deploy Themes
deploy_d7_theme themes/wwwevergreen $COLLAB_CODE/drupal7
deploy_d7_module modules/custom/learning_community_directory $COLLAB_CODE/drupal7
deploy_d7_module modules/custom/native_cases $COLLAB_CODE/drupal7
deploy_d7_module modules/custom/evergreen_cas $COLLAB_CODE/drupal7
echo "Collab Site updates"
run_site_updates $COLLAB_CODE/drupal7 site_updates_collab
# www deployment.
echo "Beginning WWW Deployment"
if [ -f $WWW_CODE/index.php ] && [[ "$STAGE" != "dev" ]] ; then
  # Required Libraries
  deploy_d7_library libraries/iCalcreator $WWW_CODE
  deploy_d7_library libraries/plupload $WWW_CODE
  # Feature modules
  deploy_d7_theme themes/wwwevergreen $WWW_CODE
  deploy_d7_custom_module modules/custom/evergreen_content $WWW_CODE
  deploy_d7_custom_module modules/custom/campus_calendar $WWW_CODE
  echo "www site updates"
  run_site_updates $WWW_CODE site_updates_www
fi

