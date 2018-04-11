#!/usr/bin/env bash
drush @sites --yes up views
drush cc all
