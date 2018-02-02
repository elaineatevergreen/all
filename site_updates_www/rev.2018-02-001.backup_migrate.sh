#!/usr/bin/env bash
drush --yes dl backup_migrate 
drush cc all
