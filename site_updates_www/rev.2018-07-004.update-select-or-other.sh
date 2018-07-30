#!/usr/bin/env bash
drush @sites --yes up select_or_other
drush cc all
