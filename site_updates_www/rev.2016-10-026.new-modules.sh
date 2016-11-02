#!/usr/bin/env bash
set -e
drush dl --yes field_default_token
drush --yes cc all

