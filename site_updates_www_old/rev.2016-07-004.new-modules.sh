#!/usr/bin/env bash
drush dl --yes googleanalytics
drush --yes @sites updb
