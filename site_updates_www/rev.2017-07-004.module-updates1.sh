#!/usr/bin/env bash
drush --yes up security_review
drush --yes up module_filter
drush --yes up metatag
drush cc all
