#!/usr/bin/env bash
set -e
drush mr News --yes
drush dl delete_all --yes 
drush en delete_all --yes 
drush delete-all all --reset --yes
drush mi SiteContent --yes
drush mi News --yes
drush --yes cc all

