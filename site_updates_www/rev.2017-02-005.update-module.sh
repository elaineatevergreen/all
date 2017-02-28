#!/usr/bin/env bash
set -e
drush up --yes webform_validation
drush --yes cc all

