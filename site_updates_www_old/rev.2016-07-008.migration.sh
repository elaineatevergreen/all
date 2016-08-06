#!/usr/bin/env bash
drush mi Sections
drush mi SiteContent
drush --yes @sites updb
