#!/usr/bin/env bash
drush @sites --yes up media file_entity metatag
drush cc all
