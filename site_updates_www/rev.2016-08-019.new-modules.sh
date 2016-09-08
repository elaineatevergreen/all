#!/usr/bin/env bash
drush dl --yes calendar

drush --yes @sites updb
