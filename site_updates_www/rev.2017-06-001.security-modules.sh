#!/usr/bin/env bash
drush --yes dl r4032login
drush --yes dl node_view_permissions
drush cc all
