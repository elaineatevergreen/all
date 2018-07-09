#!/usr/bin/env bash
drush @sites --yes up link
drush cc all
