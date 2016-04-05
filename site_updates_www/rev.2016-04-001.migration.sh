#!/usr/bin/env bash
drush mi SiteContent
drush --yes @sites updb
