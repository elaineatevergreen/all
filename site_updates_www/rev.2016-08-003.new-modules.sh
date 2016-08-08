#!/usr/bin/env bash
drush dl --yes addressfield admin_views bean bean_admin_ui better_exposed_filters ckeditor context context_addassets context_ui custom_search custom_search_blocks date_ical diff email entity entity_token entity_view_mode entityqueue entityreference entityreference_feeds environment_indicator fe_block fe_date features feeds feeds_tamper feeds_tamper_ui feeds_xpathparser fel fel_fields fences field_collection field_collection_feeds field_group file_entity googleanalytics insert_view job_scheduler jquery_update link linkit media media_bulk_upload media_ckeditor media_wysiwyg metatag metatag_context metatag_opengraph metatag_twitter_cards metatag_views migrate migrate_ui module_filter panels pathauto phone plupload redirect replicate replicate_ui rules rules_admin security_review strongarm token views_bulk_operations views_data_export webform webform_phone webform_validation workbench workbench_access workbench_media workbench_moderation workbench_scheduler workbench_webform_access
drush --yes @sites updb
