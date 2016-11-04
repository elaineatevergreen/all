#!/usr/bin/env bash
set -e
drush mr SiteContent --yes
drush --yes cc all

