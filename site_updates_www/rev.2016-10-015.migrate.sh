#!/usr/bin/env bash
set -e
drush mreg --yes
drush mr SiteContent --yes
drush --yes cc all

