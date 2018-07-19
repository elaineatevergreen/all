#!/usr/bin/env bash
drush @sites --yes up xmlsitemap
drush cc all
