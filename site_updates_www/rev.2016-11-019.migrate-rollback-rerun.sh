#!/usr/bin/env bash
set -e
drush mi Sections --update --yes
drush mr SiteContent --yes
drush delete-all basic_page --reset --yes
drush mi SiteContent --yes
drush --yes cc all

