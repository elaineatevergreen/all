#!/usr/bin/env bash
drush dl --yes field_collection_feeds
drush --yes @sites updb
