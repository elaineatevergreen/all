#!/usr/bin/env bash
drush @sites --yes up devel file_entity
drush cc all
