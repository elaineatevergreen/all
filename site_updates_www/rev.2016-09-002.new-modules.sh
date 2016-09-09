#!/usr/bin/env bash
drush dl --yes juicebox

drush --yes @sites updb
