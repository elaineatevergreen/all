#!/usr/bin/env bash
drush dl --yes workbench_scheduler
drush --yes @sites updb
