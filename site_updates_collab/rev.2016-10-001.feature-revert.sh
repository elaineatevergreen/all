#!/usr/bin/env bash
# Should fix issue with Evergreen CAS settings Feature
drush --yes dl admin_views
drush fr evergreen_cas --yes
drush cc all
