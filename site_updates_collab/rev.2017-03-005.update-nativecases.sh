#!/usr/bin/env bash

# update modules on Native Case Studies
cd sites/collab${SITE_SUFFIX}.evergreen.edu.nativecases
drush up panels diff feeds --y
drush cc all