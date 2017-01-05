#!/usr/bin/env bash
set -e
drush up --yes ctools diff multiform
drush --yes cc all

