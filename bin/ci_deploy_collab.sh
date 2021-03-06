#!/bin/bash
set -e
export WWW_CODE='/var/www/html/www'
# Source adminweb environment.
. /opt/evergreen/ods/bin/collab_build_environment.sh
. drupal_deploy_functions.sh
. d7_migrations.sh
# Deploy Themes
deploy_d7_theme themes/wwwevergreen $COLLAB_CODE/drupal7

# Deploy Libraries
deploy_d7_library libraries/plupload $COLLAB_CODE/drupal7

# Deploy Features
deploy_d7_module modules/custom/learning_community_directory $COLLAB_CODE/drupal7
deploy_d7_module modules/custom/native_cases $COLLAB_CODE/drupal7
deploy_d7_module modules/custom/evergreen_cas $COLLAB_CODE/drupal7
deploy_d7_module modules/custom/basic_content $COLLAB_CODE/drupal7
deploy_d7_module modules/custom/simple_events $COLLAB_CODE/drupal7
echo "Collab Site updates"
run_site_updates $COLLAB_CODE/drupal7 site_updates_collab
# www deployment.

