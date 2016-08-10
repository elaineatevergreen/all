#!/usr/bin/env bash
drush migrate-deregister Faculty
drush migrate-deregister Individual
drush migrate-deregister Offices
drush migrate-deregister CatalogTerms
drush migrate-deregister Catalog
drush migrate-reset-status --all
drush --yes @sites updb
