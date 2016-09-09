#!/usr/bin/env bash
drush dl --yes cas_attributes

drush --yes @sites updb
