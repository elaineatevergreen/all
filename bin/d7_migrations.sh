#!/usr/bin/env bash
# ------------------------
# Schema revision tracker for drupal 7
#
# Source the drupal deployment library.
. bin/drupal_deploy_functions.sh
#------------
# global vars for schema management.
#
schema_setting="evergreen_site_revision"
schema_dir="site_updates"
export REVISION=""

# Save a schma revision
update_schema_revision() {
  drush vset --exact "$schema_setting" "$1"
  export REVISION="$1"
}

get_schema_revision() {
  export REVISION=`drush vget --format=string $schema_setting`
  if [ -z "$REVISION" ]; then
    drush vset --exact "$schema_setting" "0"
  fi
}

revert_site_to() {
  project_dir=`pwd`
  drupal_site_dir="$1"
  cd "$drupal_site_dir"
  update_schema_revision $2
  cd "$project_dir"
}

# Run all deployment scripts that have not been run.
run_site_updates() {
  if [[ ! -z "$2" ]] ; then
    schema_dir="$2"
  fi
  if [[ ! -z "$3" ]] ; then
    schema_setting="evergreen_${3}_revision"
  fi
  project_dir=`pwd`
  drupal_site_dir="$1"
  echo "Site updates for: $drupal_site_dir"
  cd $drupal_site_dir
  get_schema_revision
  echo "Site Revision: $REVISION"
  if [[ -d "$project_dir/$schema_dir" ]]; then
    # Iterate each file
    for file in $project_dir/$schema_dir/rev.*.sh; do
      # echo $file;
      filename="${file##*/}"
      IFS=. read -ra parts <<<"$filename"
      cur_rev="${parts[1]}"
      if [[ $cur_rev > $REVISION ]]; then
        echo "Executing $filename"
        echo "___________________"
        bash $file "$cur_rev"
        if (( $? )); then
          echo "Error detected: Aborting site updates"
          exit 1;
        else
          update_schema_revision $cur_rev
        fi
        echo "___________________"
      fi
    done
  fi
  cd $project_dir
}

# Main code execution

