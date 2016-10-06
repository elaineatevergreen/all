#!/usr/bin/env bash
# Should fix issue with Evergreen CAS settings Feature
drush fr evergreen_cas --yes
drush cc all
