#!/usr/bin/env bash
set -e
drush migrate-deregister --yes
drush mreg --yes
drush mi Sections --yes
drush mi SiteContent --yes
drush mi News --yes
drush --yes cc all

