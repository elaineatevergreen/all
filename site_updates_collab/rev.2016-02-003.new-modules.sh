#!/usr/bin/env bash
drush dl --yes file_entity
drush dl --yes media_ckeditor-7.x-2.0-alpha1
drush --yes @sites updb
