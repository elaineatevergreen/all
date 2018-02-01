#!/usr/bin/env bash
drush @sites --yes up varnish media feeds_tamper entityqueue cas
drush cc all
