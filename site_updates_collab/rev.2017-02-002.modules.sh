#!/usr/bin/env bash
drush --yes en ckeditor
drush --yes en field_collection
drush --yes en insert_view
drush --yes en redirect
drush --yes en workbench_media
drush --yes up
