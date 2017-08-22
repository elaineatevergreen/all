#!/usr/bin/env bash

# update modules on Curriculum for the Bioregion
cd sites/collab${SITE_SUFFIX}.evergreen.edu.bioregion
drush up token webform webform_validation --y
drush cc all

# update modules on Native Cases
cd sites/collab${SITE_SUFFIX}.evergreen.edu.nativecases
drush up panels diff feeds token webform --y
drush cc all

# update modules on Washington Center
cd sites/collab${SITE_SUFFIX}.evergreen.edu.washingtoncenter
drush up better_exposed_filters diff feeds token webform webform_validation --y
drush cc all