#!/usr/bin/env bash
# Should fix issue with Evergreen CAS settings Feature
drush --yes dl admin_views
# commenting this out because it would only apply to the main site.
# drush fr evergreen_cas --yes
# drush cc all
