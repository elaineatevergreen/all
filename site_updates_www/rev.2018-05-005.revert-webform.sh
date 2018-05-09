#!/usr/bin/env bash
drush @sites --yes dl webform-7.x-4.16
drush cc all
