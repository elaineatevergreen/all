#!/usr/bin/env bash
drush dl --yes google_analytics
drush --yes @sites updb
