#!/usr/bin/env bash
drush --yes dl webform_share
drush --yes up
drush cc all
