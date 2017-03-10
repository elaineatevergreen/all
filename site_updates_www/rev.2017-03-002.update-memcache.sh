#!/usr/bin/env bash
set -e
drush up --yes memcache
drush --yes cc all

