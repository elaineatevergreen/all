#!/usr/bin/env bash
set -e
. /opt/evergreen/ods/bin/drupal_deploy_functions.sh
mkdir -p sites/all/modules/custom
mkdir -p sites/all/modules/contrib
mkdir -p sites/all/libraries
mkdir -p sites/all/themes
d7_upgrade_cas
drush --yes dl cas
# Set cas configuration.
drush --yes en libraries
drush --yes en cas
drush --yes en views views_ui date
drush --yes vset cas_access 0
drush --yes vset cas_exclude "services/*"
drush --yes vset cas_domain "evergreen.edu"
drush --yes vset format=string cas_login_form '3'
drush --yes vset cas_Hide_password 1
drush --yes vset cas_login_invite "Evergreen.edu"
drush --yes vset cas_login_message "Logged in via CAS as %cas_username."
drush --yes vset cas_login_redir_message "Use your Evergreen username & password to edit web content."
drush --yes vset cas_pages "user/*\r\nadmin/*\r\nnode/add/*"
drush --yes vset cas_pgtformat "plain"
drush --yes vset cas_server "cas.evergreen.edu"
drush --yes vset cas_uri "cas"
drush --yes vset --format=integer cas_user_register 1
drush --yes vset --format=string cas_version "2.0"
drush --yes sqlq "DELETE FROM cas_user"
drush --yes sqlq "INSERT into cas_user (uid,cas_name) VALUES (1,'metzlerd')"
drush --yes sqlq "INSERT into cas_user (uid,cas_name) VALUES (1,'nelsone')"
