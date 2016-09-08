#!/usr/bin/env bash
drush mr SiteContent
drush mi SiteContent
drush --yes @sites updb
