#!/usr/bin/env bash
set -e
deploy_d7_library libraries/juicebox $WWW_CODE
drush --yes cc all

