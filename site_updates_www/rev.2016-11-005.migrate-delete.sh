#!/usr/bin/env bash
set -e
drush mr SiteContent --yes
drush delete-all basic_page --reset --yes
drush --yes cc all

