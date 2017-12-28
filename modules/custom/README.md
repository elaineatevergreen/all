How to add a Feature to the sites

* Check the module into version control
* Modify the deploy scripts to deploy the module folder (deploy_d7_module in ci_deploy_www.sh or ci_deploy_collab.sh)
* Create a site update script to enable the module (drush en new_feature_module)