#!/usr/bin/env bash
drush dl --yes formblock

drush --yes @sites updb
