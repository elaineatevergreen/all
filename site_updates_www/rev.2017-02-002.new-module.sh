#!/usr/bin/env bash
set -e
drush en --yes facebook_tracking_pixel
drush --yes cc all

