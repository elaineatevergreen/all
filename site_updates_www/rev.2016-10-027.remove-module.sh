#!/usr/bin/env bash
set -e
drush pm-disable custom_search_blocks --yes
drush pm-uninstall custom_search_blocks --yes
drush pm-disable custom_search --yes
drush pm-uninstall custom_search --yes
drush --yes cc all

