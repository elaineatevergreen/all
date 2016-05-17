#!/usr/bin/env bash
drush dl --yes user_restrictions
drush --yes @sites updb
