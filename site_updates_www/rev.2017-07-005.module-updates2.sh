#!/usr/bin/env bash
drush --yes up file_entity
drush --yes up media
drush --yes up ckeditor
drush cc all
