#!/usr/bin/env bash
drush @sites --yes up migrate rules scanner views_bulk_operations
drush cc all
