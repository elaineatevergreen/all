#!/usr/bin/env bash
set -e
drush dl --yes field_collection_table
drush en --yes field_collection_table
drush dis --yes field_collection_table
drush pm-uninstall --yes field_collection_table
drush --yes cc all

