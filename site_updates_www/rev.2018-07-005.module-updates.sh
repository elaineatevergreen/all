#!/usr/bin/env bash
drush @sites --yes up varnish search_api_solr_booster
drush cc all
