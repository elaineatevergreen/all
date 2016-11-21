#!/usr/bin/env bash
set -e
drush --yes up
drush --yes @sites updb