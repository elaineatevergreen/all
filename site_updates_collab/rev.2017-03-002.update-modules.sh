#!/usr/bin/env bash
drush --yes up media
drush --yes up token
drush --yes up webform
drush --yes up webform_validation
drush cc all
