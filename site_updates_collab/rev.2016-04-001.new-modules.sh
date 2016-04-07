#!/usr/bin/env bash
drush dl --yes fel
drush --yes @sites updb
