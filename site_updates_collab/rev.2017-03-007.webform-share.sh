#!/usr/bin/env bash
cd sites/collab${SITE_SUFFIX}.evergreen.edu.forms
drush --yes dl webform_share
drush --yes up
