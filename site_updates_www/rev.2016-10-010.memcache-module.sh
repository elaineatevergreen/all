#!/usr/bin/env bash
set -e
drush --yes dl memcache
drush --yes rr
