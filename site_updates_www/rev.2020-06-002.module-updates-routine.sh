#!/usr/bin/env bash
drush @sites --yes up file_entity views_bulk_operations webform webform_validation
drush cc all
