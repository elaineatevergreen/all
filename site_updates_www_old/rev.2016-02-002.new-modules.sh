#!/usr/bin/env bash
drush dl --yes custom_search entityqueue entityreference_feeds scheduler
drush --yes @sites updb
