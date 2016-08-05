#!/usr/bin/env bash
drush dl --yes better_exposed_filters-7.x-3.x-dev
drush --yes @sites updb
