#!/usr/bin/env bash
drush --yes dl drafty
# should probably enable this.
drush --yes en drafty
drush --yes up
