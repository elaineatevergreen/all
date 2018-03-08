#!/usr/bin/env bash
drush @sites --yes up backup_migrate
drush cc all
