#!/usr/bin/env bash
# standalone modules
drush dl --yes replicate_ui custom_search custom_search_blocks entity entity_token entity_view_mode entityreference features_extra fel field_collection file_entity metatag 

drush --yes @sites updb
