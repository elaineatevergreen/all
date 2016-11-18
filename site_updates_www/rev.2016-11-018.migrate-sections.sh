#!/usr/bin/env bash
set -e
drush mi Sections --update --yes
drush --yes cc all

