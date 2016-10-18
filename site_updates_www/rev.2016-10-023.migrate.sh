#!/usr/bin/env bash
set -e
drush mi Sections --yes
drush mi SiteContent --yes
drush --yes cc all

