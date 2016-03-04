#!/usr/bin/env bash
drush --yes collab${SITE_SUFFIX}.evergreen.edu.www mr SiteSections
drush --yes collab${SITE_SUFFIX}.evergreen.edu.www mr SiteContent
drush --yes collab${SITE_SUFFIX}.evergreen.edu.www mi SiteSections
drush --yes collab${SITE_SUFFIX}.evergreen.edu.www mi SiteContent