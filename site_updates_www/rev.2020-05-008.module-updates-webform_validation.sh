#!/usr/bin/env bash
drush @sites --yes up webform_validation
drush cc all
