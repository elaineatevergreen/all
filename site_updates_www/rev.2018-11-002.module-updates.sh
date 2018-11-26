#!/usr/bin/env bash
drush @sites --yes up context file_entity media media_ckeditor scanner
drush cc all
