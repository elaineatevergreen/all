#!/usr/bin/env bash
set -e
drush dl --yes media_oembed media_internet
drush --yes cc all

