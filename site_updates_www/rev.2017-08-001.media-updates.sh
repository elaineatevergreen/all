#!/usr/bin/env bash
drush --yes up media
drush --yes up media_ckeditor
drush cc all
