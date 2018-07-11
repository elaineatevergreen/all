#!/usr/bin/env bash
drush @sites --yes up media
drush cc all
