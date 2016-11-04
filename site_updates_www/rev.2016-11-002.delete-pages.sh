#!/usr/bin/env bash
set -e
drush delete-all basic_page --yes
drush --yes cc all

