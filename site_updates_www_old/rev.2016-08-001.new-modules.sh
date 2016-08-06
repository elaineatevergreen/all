#!/usr/bin/env bash
drush dl --yes metatag
drush --yes @sites updb
