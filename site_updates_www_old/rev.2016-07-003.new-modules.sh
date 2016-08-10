#!/usr/bin/env bash
drush dl --yes context_addassets googleanalytics
drush --yes @sites updb
