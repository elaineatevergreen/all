#!/usr/bin/env bash
drush @sites --yes up webform
drush cc all
