#!/usr/bin/env bash
drush dl --yes tabtamer

drush --yes @sites updb
