#!/usr/bin/env bash
drush @sites --yes up search_api search_api_solr_booster
drush cc all
