#!/usr/bin/env bash
drush @sites --yes up entityqueue file_entity
drush cc all
