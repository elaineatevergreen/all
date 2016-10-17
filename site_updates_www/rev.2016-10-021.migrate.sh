#!/usr/bin/env bash
set -e
drush mreg --yes --group=sites
drush mi Sections --update --y
drush mi SiteContent --update --yes
drush --yes cc all

