#!/usr/bin/env bash
set -e
drush mi SiteFiles --yes
drush --yes cc all

