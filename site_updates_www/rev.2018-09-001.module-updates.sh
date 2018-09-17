#!/usr/bin/env bash
drush @sites --yes up bean better_exposed_filters field_collection libraries media xmlsitemap
drush cc all
