#!/usr/bin/env bash
drush @sites --yes up search_or_other
drush cc all
