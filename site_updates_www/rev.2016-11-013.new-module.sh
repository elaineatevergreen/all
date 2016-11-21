#!/usr/bin/env bash
set -e
drush dl --yes views_field_view
drush --yes cc all

