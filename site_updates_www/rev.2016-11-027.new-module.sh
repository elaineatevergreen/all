#!/usr/bin/env bash
set -e
drush dl --yes scanner
drush --yes cc all

