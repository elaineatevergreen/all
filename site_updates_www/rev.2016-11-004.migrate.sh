#!/usr/bin/env bash
set -e
drush mi SiteContent --update --yes
drush --yes cc all

