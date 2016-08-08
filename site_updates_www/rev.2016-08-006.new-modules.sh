#!/usr/bin/env bash
# standalone modules
drush dl --yes addressfield better_exposed_filters ckeditor date_ical diff email entityqueue environment_indicator features fences field_group googleanalytics insert_view job_scheduler jquery_update link linkit module_filter panels pathauto phone plupload redirect security_review strongarm token

#views-ish things
drush dl --yes admin_views views_bulk_operations views_data_export

#workbench things
drush dl --yes workbench workbench_access workbench_media workbench_moderation workbench_scheduler workbench_webform_access

#webform things
drush dl --yes webform webform_phone webform_validation


#media-ish things
drush dl --yes media media_ckeditor media_wysiwyg

#feeds-ish things
drush dl --yes entityreference_feeds feeds feeds_tamper feeds_xpathparser field_collection_feeds

#context
drush dl --yes context context_addassets metatag_context 

#other projects that have extra modules (usually a "ui" module)
drush dl --yes bean migrate replicate rules
#the ui bits
#bean_admin_ui context_ui migrate_ui replicate_ui rules_admin


#misc commented out for now
# custom_search custom_search_blocks entity entity_token entity_view_mode entityreference fe_block fe_date fel fel_fields field_collection file_entity metatag metatag_opengraph metatag_twitter_cards metatag_views

drush --yes @sites updb
