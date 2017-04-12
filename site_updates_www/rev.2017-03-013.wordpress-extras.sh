#!/usr/bin/env bash
drush --yes dl migrate_extras
drush cc all
