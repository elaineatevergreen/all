#!/usr/bin/env bash
drush @sites --yes up better_exposed_filters environment_indicator field_group file_entity
drush cc all
