#!/usr/bin/env bash
drush dl --yes shurly

drush --yes @sites updb
