#!/usr/bin/env bash
# Updates for security.
drush up --yes
drush --yes @sites updb
