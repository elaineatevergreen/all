#!/usr/bin/env bash
drush migrate-deregister SiteSections
drush migrate-register Sections
drush mr SiteContent
drush delete-all basic-page --reset 
drush migrate-reset-status --all
drush --yes @sites updb
