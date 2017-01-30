#!/usr/bin/env bash
set -e
drush up --yes media
drush up --yes media_ckeditor
drush --yes cc all

