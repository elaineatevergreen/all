#!/usr/bin/env bash
drush --yes dl select_or_other
drush --yes dl telephone
drush --yes dl user_restrictions
drush cc all
