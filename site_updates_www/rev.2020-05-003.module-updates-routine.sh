#!/usr/bin/env bash
drush @sites --yes up backup_migrate ctools fast_token_browser field_collection field_permissions file_entity google_tag link metatag minify multiform rules search_api search_api_solr search_api_solr_booster wordpress_migrate workbench_access
drush cc all
