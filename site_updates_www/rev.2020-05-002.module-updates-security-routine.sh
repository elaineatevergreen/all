#!/usr/bin/env bash
drush @sites --yes up maxlength admin_views module_filter
drush cc all
