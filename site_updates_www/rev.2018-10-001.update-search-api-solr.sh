#!/usr/bin/env bash
drush @sites --yes up search_api_solr
drush cc all
