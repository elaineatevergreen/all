#!/usr/bin/env bash
set -e
drush up --yes views
drush up --yes better_exposed_filters
drush up --yes metatag
drush up --yes drafty
drush up --yes fel
drush up --yes media
drush up --yes panels
drush up --yes token
drush up --yes views_bulk_operations
drush up --yes workbench_access
drush --yes cc all

