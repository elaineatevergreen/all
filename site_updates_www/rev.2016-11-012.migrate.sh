#!/usr/bin/env bash
set -e
drush mi SiteContent --yes
drush --yes cc all

