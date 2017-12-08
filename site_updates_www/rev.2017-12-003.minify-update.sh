#!/usr/bin/env bash
drush @sites --yes up minify
drush cc all
