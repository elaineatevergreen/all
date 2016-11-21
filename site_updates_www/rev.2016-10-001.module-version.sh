#!/usr/bin/env bash
drush dl --yes workbench_media-7.x-2.1

drush --yes @sites updb
