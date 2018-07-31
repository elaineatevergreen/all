#!/usr/bin/env bash
drush @sites --yes up xmlsitemap-7.x-2.x-dev
drush cc all
