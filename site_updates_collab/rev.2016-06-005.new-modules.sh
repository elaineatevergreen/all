#!/usr/bin/env bash
drush dl --yes better_exposed_filters
drush --yes @sites updb
