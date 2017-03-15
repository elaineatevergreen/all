#!/usr/bin/env bash
set -e
drush dl --yes maxlength
drush --yes cc all

