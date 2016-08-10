#!/usr/bin/env bash
drush dl --yes path_redirect_import pathologic
drush --yes @sites updb
