#!/usr/bin/env bash
set -e
drush en --yes suggest_similar_titles
drush --yes cc all

