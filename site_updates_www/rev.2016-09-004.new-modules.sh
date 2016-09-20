#!/usr/bin/env bash
drush dl --yes path_redirect_import

drush --yes @sites updb
