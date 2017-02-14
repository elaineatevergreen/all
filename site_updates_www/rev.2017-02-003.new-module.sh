#!/usr/bin/env bash
set -e
drush en --yes feeds_tamper_conditional
drush --yes cc all

