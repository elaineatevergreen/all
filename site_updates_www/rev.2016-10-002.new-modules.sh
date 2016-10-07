#!/usr/bin/env bash
set -e
drush dl --yes path_redirect_import
drush dl --yes tabtamer
drush dl --yes cas_attributes
drush dl --yes formblock
drush dl --yes juicebox
drush --yes cc all

