#!/usr/bin/env bash
drush @sites --yes up google_analytics
drush cc all
