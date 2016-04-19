#!/usr/bin/env bash
drush mr SiteContent
drush delete-all basic-page --reset 
drush mi SiteContent
drush --yes @sites updb
