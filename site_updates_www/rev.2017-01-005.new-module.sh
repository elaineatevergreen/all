#!/usr/bin/env bash
set -e
drush en --yes flag
drush en --yes session_api
drush --yes cc all

