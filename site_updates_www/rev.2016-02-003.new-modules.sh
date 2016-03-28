#!/usr/bin/env bash
drush dl --yes jquery_update-7.x-3.0-alpha3
drush --yes @sites updb
