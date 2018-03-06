#!/usr/bin/env bash
drush @sites --yes dl wysiwyg_a11ychecker
drush cc all
