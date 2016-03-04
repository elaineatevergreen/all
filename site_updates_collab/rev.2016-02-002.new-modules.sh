#!/usr/bin/env bash
drush dl --yes file_entity-7.x-2.0-beta2
drush dl --yes media-7.x-2.0-beta1
drush --yes @sites updb
