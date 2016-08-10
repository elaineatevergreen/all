#!/usr/bin/env bash
drush dl --yes ckeditor-7.x-1.x-dev
drush --yes @sites updb
