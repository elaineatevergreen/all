#!/usr/bin/env bash
drush dl --yes media_ckeditor-7.x-2.x-dev
drush --yes @sites updb
