#!/usr/bin/env bash
drush dl --yes shs

drush --yes @sites updb
