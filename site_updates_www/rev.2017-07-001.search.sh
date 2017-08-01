#!/usr/bin/env bash
drush --yes dl search_api
drush --yes dl facet_api
drush --yes dl search_api_solr
drush cc all
