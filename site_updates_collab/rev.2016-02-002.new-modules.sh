#!/usr/bin/env bash
drush dl --yes file_entity-7.x-2.0-beta2
drush collab${SITE_SUFFIX}.evergreen.edu.cms en file_entity
drush collab${SITE_SUFFIX}.evergreen.edu.policies en file_entity
drush dl --yes media-7.x-2.0-beta1
drush --yes @sites updb
