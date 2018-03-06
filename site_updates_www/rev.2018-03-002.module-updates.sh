#!/usr/bin/env bash
drush @sites --yes up ctools feeds_tamper_importer migrate search_api_solr_booster shs
drush cc all
