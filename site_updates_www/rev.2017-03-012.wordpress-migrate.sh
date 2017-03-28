#!/usr/bin/env bash
drush --yes dl wordpress_migrate
drush cc all
