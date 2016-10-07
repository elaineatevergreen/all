#!/usr/bin/env bash
set -e
# Should fix issue with Evergreen CAS settings Feature
drush --yes dl admin_views
# commenting this out because it would only apply to the main site.
# drush fr evergreen_cas --yes
# drush cc all
drush --yes collab${SITE_SUFFIX}.evergreen.edu.bioregion fr evergreen_cas
drush --yes collab${SITE_SUFFIX}.evergreen.edu.bioregion cc all