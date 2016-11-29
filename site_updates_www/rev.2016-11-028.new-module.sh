#!/usr/bin/env bash
set -e
drush dl --yes views_conditional
drush --yes cc all

