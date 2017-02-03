#!/usr/bin/env bash
set -e
drush dl date-7.x-2.x-dev --y
drush --yes cc all

