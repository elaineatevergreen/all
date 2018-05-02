#!/usr/bin/env bash
drush pm-update --yes 
drush @sites updatedb --yes
drush cc all
