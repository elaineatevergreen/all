# Site update scripts
Place site update scripts for the collab sites here.

Each upgrade script must be placed in the schema folder and should be of 
the form rev.{revision}.{description}.sh, where {revision} is replaced 
with a version number invented by the developer, and {description} is replaced by 
a short description that talks about the upgrade. 

Our convention is to make revision numbers of the format YYYY-MM-NNN, 
where NNN is just a sequence number.

## Building rev scripts.

All site update scripts should begin with the following to make sure errors
stop further site updates and notify people of failures: 
````
set -e 
````
When trying to update code for a single collab site first change directories 
to the relative site folder like this: 
````
cd sites/collab${SITE_SUFFIX}.evergreen.edu.site_name
````
Then specify the drush command that you'd like to execute using the --yes
option: 

````
drush --yes fr my_custom_feature
````


## Examples script

````
# Make sure build errors are reported. 
set -e

# Download a project from drupal.org
drush --yes dl admin_views
# Update drupal to current release
drush --yes up drupal
# Run site database updates on all collab sites. 
drush --yes @sites updb
# Change driectories to run some commands on specific sites. 
cd sites/collab${SITE_SUFFIX}.evergreen.edu.bioregion
drush --yes en evergreen_cas
# Revert a feature 
drush --yes fr evergreen_cas
# Clear the caches
drush --yes cc all
````