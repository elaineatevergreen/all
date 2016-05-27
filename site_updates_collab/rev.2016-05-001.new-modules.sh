#!/usr/bin/env bash
drush dl --yes email_registration
drush --yes @sites updb
