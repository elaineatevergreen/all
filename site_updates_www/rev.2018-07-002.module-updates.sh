#!/usr/bin/env bash
drush @sites --yes up file_entity google_analytics
drush cc all
