#!/usr/bin/env bash
set -e
drush dl --yes options_element
drush --yes cc all

