#!/usr/bin/env bash
drush @sites --yes up entity cas ctools entityqueue file_entity job_scheduler media
drush cc all
