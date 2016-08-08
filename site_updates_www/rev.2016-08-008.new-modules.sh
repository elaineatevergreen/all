#!/usr/bin/env bash
# standalone modules
# rerunning with everything after Google Analytics because of module spelling issues
# and also stuff in rev 08-007 after entity
drush dl --yes google_analytics insert_view job_scheduler jquery_update link linkit module_filter panels pathauto phone plupload redirect security_review strongarm token entity entity_token entity_view_mode entityreference features_extra fel field_collection file_entity metatag 





#misc commented out for now
# custom_search custom_search_blocks entity entity_token entity_view_mode entityreference fe_block fe_date fel fel_fields field_collection file_entity metatag metatag_opengraph metatag_twitter_cards metatag_views

drush --yes @sites updb
