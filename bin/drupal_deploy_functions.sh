#!/bin/bash
#
deploy_d7_module() {
  src="$1"
  dest="$2"
  if [[ "$STAGE" = 'dev' ]] ; then
    rsync -rtp --delete $src $dest/sites/all/modules/custom/
  else
    rsync -rtp --delete $src $dest/sites/all/modules/
  fi
}

deploy_d7_reports() {
  rsync -rtp --delete $1 $2/
}

deploy_block() {
  src="$1"
  dest="$2"
}

deploy_d7_custom_module() {
  src="$1"
  dest="$2"
  rsync -rtp --delete $src $dest/sites/all/modules/custom/
}

deploy_d7_theme() {
  src="$1"
  dest="$2"
  rsync -rtp --delete $src $dest/sites/all/themes/
}

deploy_d7_library() {
  src="$1"
  dest="$2"
  rsync -rtp --delete $src $dest/sites/all/libraries/
}

deploy_d7_cron() {
  src="$1"
  dest="$2"
  project="$3"
  mkdir -p $dest/sites/all/cron/$project
  rsync -rtp --delete $src/ $dest/sites/all/cron/$project/
  chmod -R +x $dest/sites/all/cron/$project
}

# Deploys Directory contents
deploy_files() {
  src="$1"
  dest="$2"
  if [ ! -z "$dest" ] ; then
    rsync -tp $src/* $dest
  fi
}

#
# Usage:
#    deploy_reports banner $ADMINWEB_CODE
deploy_reports() {
  src="reports/$1"
  dest="$2/reports/$1"
  rsync -rtp --delete $src/* $dest
}

deploy_report_blocks() {
  src="report_blocks/$1"
  dest="$2/report_blocks/$1"
  rsync -rtp --delete $src/* $dest
}

# Copy a site on the same server from one name to another.
# Assumes same connection strings/etc from the base.
drush_site_sync() {
  src_site="$1"
  dest_site="$2"
}

# Create a mysql database using admin_dba account
create_site_database() {
  site="$1"
  server="$2"
  if [ -z "$server" ]; then
   server="db-adminweb"
  fi
  if [ -z "$site" ]; then
    echo "No Site Specified"
    exit 1
  fi
  pass=`sudo pass ADMIN_DBA`
  mysqladmin -h $server -u admin_dba --password=$pass --default-character-set=utf8 create admin${STAGE}_${site}
}

# Copy the database to a new mysql server.
copy_to_server() {
  site="$1"
  server="$2"

  # Create on new server
  pass=`sudo pass ADMIN_DBA`
  echo "Drop destination database on $server"
  mysqladmin -h $server -f -u admin_dba --password="$pass" drop admin${STAGE}_${site}
  echo "Create destination database on $server"
  mysqladmin -h $server -f -u admin_dba --password="$pass" --default-character-set=utf8 create admin${STAGE}_${site}
  echo "Copying Database"
  mysqldump -h db-adminweb -u admin_dba --password="$pass" admin${STAGE}_${site} | mysql -h $server -u admin_dba --password="$pass" admin${STAGE}_${site}
  echo "Complete"
}

# Dump the site to a file
dump_site_database() {
  site="$1"
  server="$2"
  if [ -z "$server" ]; then
   server="db-adminweb"
  fi
  if [ -z "$site" ]; then
    echo "No Site Specified"
    exit 1
  fi
  file_name="$site.sql";
  if [ ! -z "$2" ]; then
    file_name="$2"
  fi
  pass=`sudo pass ADMIN_DBA`
  mysqldump -h $server -u admin_dba --password=$pass admin${STAGE}_${site} > $file_name
}

# Drop and recreate site database
recreate_site_database() {
  site="$1"
  server="$2"
  if [ -z "$server" ]; then
   server="db-adminweb"
  fi
  if [ -z "$site" ]; then
    echo "No Site Specified"
    exit 1
  fi
  pass=`sudo pass ADMIN_DBA`
  mysqladmin -h $server -f -u admin_dba --password=$pass drop admin${STAGE}_${site}
  create_site_database $site
}

# Restore site to the file
# Usage example:
#   restore_site_database <site_name> <filename>
restore_site_database() {
  site="$1"
  if [ -z "$site" ]; then
    echo "No Site Specified"
    exit 1
  fi
  server="$2"
  if [ -z "$server" ]; then
   server="db-adminweb"
  fi
  file_name="$site.sql";
  if [ ! -z "$2" ]; then
    file_name="$2"
  fi
  pass=`sudo pass ADMIN_DBA`
  recreate_site_database $site
  mysql -h $server -u admin_dba --password=$pass admin${STAGE}_${site} <$file_name
}

# Clone a database site
# Usage Example:
#   clone_site_database <source_site> <dest_site>
clone_site_database() {
  src_site="$1"
  dest_site="$2"
  if [ -z "$src_site" ]; then
    echo "No Source Site Specified"
    exit 1
  fi
  if [ -z "$dest_site" ]; then
    echo "No Destination Site Specified"
    exit 1
  fi
  dump_site_database $1
  restore_site_database $2 $1.sql
}

generate_d7_local_settings() {
  site="$1"
  if [ -z "$site" ]; then
   echo "No Site Specified"
   exit 1
  fi
  echo "<?php"
  echo '$database["default"]["default"]["database"]' "= '$site';"
  echo '$base_url =' "'http://$HOSTNAME.evergreen.edu/$site';"
}

create_d7_local_settings() {
  generate_d7_local_settings $1 > "/var/www/html/$1/sites/default/local.settings.php"
  chmod +x "/var/www/html/$1/sites/default/local.settings.php"
}

d7_upgrade_svggraph() {
  mkdir -p $HOME/dist
  lib=sites/all/libraries
  if [[ -z "$1" ]]; then
    rev=2.23
  else
    rev="$1"
  fi
  if [ -d "$lib/SVGGraph.old" ] ; then
    rm -rf "$lib/SVGGraph.old"
  fi
  # move the old copy
  if [ -d "$lib/SVGGraph" ]; then
    mv $lib/SVGGraph $lib/SVGGraph.old
  fi
  # Download the current rev and install.
  curl http://www.goat1000.com/downloads/SVGGraph${rev}.zip >$HOME/dist/SVGGraph${rev}.zip
  site_dir=`pwd`
  cd $lib
  unzip $HOME/dist/SVGGraph${rev}.zip
  rm $HOME/dist/SVGGraph${rev}.zip
  cd $site_dir
}

d7_upgrade_cas() {
  mkdir -p $HOME/dist
  lib=sites/all/libraries
  if [[ -z "$1" ]]; then
    rev=1.3.4
  else
    rev="$1"
  fi
  if [ -d "$lib/CAS.old" ] ; then
    rm -rf "$lib/CAS.old"
  fi
  # move the old copy
  if [ -d "$lib/CAS" ]; then
    mv $lib/CAS $lib/CAS.old
  fi
  mkdir -p $HOME/dist
  lib=sites/all/libraries
  mkdir -p $lib
  curl "https://developer.jasig.org/cas-clients/php/${rev}/CAS-${rev}.tgz" >$HOME/dist/CAS-${rev}.tgz
  site_dir=`pwd`
   cd $lib
  tar -xzf $HOME/dist/CAS-${rev}.tgz
  mv CAS-${rev} CAS
  rm $HOME/dist/CAS-${rev}.tgz
  cd $site_dir
  drush --yes up cas
}

d7_upgrade_d3() {
  mkdir -p $HOME/dist
  lib=sites/all/libraries
  if [[ -z "$1" ]]; then
    rev=3.5.17
  else
    rev="$1"
  fi
  if [ -d "$lib/d3.old" ] ; then
    rm -rf "$lib/d3.old"
  fi
  # move the old copy
  if [ -d "$lib/d3" ]; then
    mv $lib/d3 $lib/d3.old
  fi
  mkdir -p $HOME/dist
  lib=sites/all/libraries
  mkdir -p $lib/d3
  curl -L "https://github.com/d3/d3/releases/download/v${rev}/d3.zip" >$HOME/dist/d3-${rev}.zip
  site_dir=`pwd`
  cd $lib/d3
  unzip $HOME/dist/d3-${rev}
  rm $HOME/dist/d3-${rev}.zip
  cd $site_dir
}