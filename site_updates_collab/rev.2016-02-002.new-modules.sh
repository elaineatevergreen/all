#!/usr/bin/env bash
drush dl --yes media-7.x-2.0-beta1
drush --yes @sites updb
