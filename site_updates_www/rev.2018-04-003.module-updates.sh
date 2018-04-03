#!/usr/bin/env bash
drush @sites --yes up metatag
drush cc all
