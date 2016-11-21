#!/usr/bin/env bash
set -e
drush --yes dl varnish
drush --yes en varnish