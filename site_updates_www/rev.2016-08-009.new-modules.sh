#!/usr/bin/env bash
# standalone modules
# rerunning with everything after Google Analytics because of module spelling issues
# and also stuff in rev 08-007 after entity
drush dl --yes google_analytics 
drush dl --yes google_analytics insert_view 
drush dl --yes google_analytics job_scheduler 
drush dl --yes google_analytics jquery_update 
drush dl --yes google_analytics link 
drush dl --yes google_analytics linkit 
drush dl --yes google_analytics module_filter 
drush dl --yes google_analytics panels 
drush dl --yes google_analytics pathauto 
drush dl --yes google_analytics phone
drush dl --yes google_analytics plupload 
drush dl --yes google_analytics redirect 
drush dl --yes google_analytics security_review 
drush dl --yes google_analytics strongarm 
drush dl --yes google_analytics token 
drush dl --yes google_analytics entity 
drush dl --yes google_analytics entity_token 
drush dl --yes google_analytics entity_view_mode 
drush dl --yes google_analytics entityreference 
drush dl --yes google_analytics features_extra 
drush dl --yes google_analytics fel 
drush dl --yes google_analytics field_collection 
drush dl --yes google_analytics file_entity 
drush dl --yes google_analytics metatag 

drush --yes @sites updb
