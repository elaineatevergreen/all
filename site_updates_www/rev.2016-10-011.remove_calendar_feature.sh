#!/usr/bin/env bash
set -e
# Remove campus calendar feature.
drush --yes dis campus_calendar
drush --yes pmu campus_calendar
rm -rf sites/all/modules/custom/campus_calendar
