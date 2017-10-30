#!/usr/bin/env bash
drush --yes dl feeds_tamper_importer
drush cc all
