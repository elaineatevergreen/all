#!/usr/bin/env bash
drush @sites --yes up backup_migrate-7.x-3.x-dev
drush cc all
