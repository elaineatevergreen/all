#!/usr/bin/env bash
set -e
drush mr SiteFiles --yes
drush --yes cc all

