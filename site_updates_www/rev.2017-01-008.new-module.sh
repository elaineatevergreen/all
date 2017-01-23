#!/usr/bin/env bash
set -e
drush en --yes css_injector
drush en --yes js_injector
drush --yes cc all

