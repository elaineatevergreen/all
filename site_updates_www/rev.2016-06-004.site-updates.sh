#!/usr/bin/env bash
drush up --yes
drush dl --yes date-7.x-2.10-rc1
drush --yes @sites updb
