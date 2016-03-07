#!/usr/bin/env bash
drush dl --yes feeds_tamper
drush --yes @sites updb
