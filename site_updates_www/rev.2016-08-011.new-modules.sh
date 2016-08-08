#!/usr/bin/env bash
# standalone modules
# rerunning with everything after Google Analytics because of module spelling issues
# and also stuff in rev 08-007 after entity
drush dl --yes  google_analytics
drush dl --yes insert_view 
drush dl --yes  job_scheduler 
drush dl --yes  jquery_update 
drush dl --yes  link 
drush dl --yes  linkit 
drush dl --yes  module_filter 
drush dl --yes  panels 
drush dl --yes  pathauto 
drush dl --yes  phone
drush dl --yes  plupload 
drush dl --yes  redirect 
drush dl --yes  security_review 
drush dl --yes  strongarm 
drush dl --yes  token 
drush dl --yes  entity 
drush dl --yes  entity_token 
drush dl --yes  entity_view_mode 
drush dl --yes  entityreference 
drush dl --yes  features_extra 
drush dl --yes  fel 
drush dl --yes  field_collection 
drush dl --yes  file_entity 
drush dl --yes  metatag 

drush --yes @sites updb
