#!/usr/bin/env bash
set -e
drush dl --yes xmlsitemap
drush --yes cc all

