#!/usr/bin/env bash
drush @sites --yes dl search_api-7.x-1.22
drush cc all
