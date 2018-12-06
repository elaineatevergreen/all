#!/usr/bin/env bash
drush @sites --yes up addressfield diff features file_upload_security google_tag libraries search_api webform_validation xmlsitemap
drush cc all
