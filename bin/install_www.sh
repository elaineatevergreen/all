#!/usr/bin/env bash
. /opt/evergreen/ods/bin/drupal_deploy_functions.sh
cd /var/www/html
drush dl drupal-7.50
mv drupal-7.50 www
cd www
cp sites/default/default.settings.php sites/default/settings.php
sudo chown apache_my:apache_my sites/default/settings.php
mkdir -p sites/default/files
sudo chown apache_my:apache_my sites/default/files




