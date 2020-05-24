#!/usr/bin/env bash
drush @sites --yes up ckeditor media media_ckeditor
drush cc all
