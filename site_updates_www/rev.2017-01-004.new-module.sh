#!/usr/bin/env bash
set -e
drush dl --yes media_oembed
drush --yes cc all

