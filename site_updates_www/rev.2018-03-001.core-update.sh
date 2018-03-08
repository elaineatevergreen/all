#!/usr/bin/env bash
drush @sites --yes up drupal
drush cc all
