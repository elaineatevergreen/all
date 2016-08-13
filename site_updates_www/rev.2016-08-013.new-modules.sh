#!/usr/bin/env bash
# standalone modules
# rerunning with everything after Google Analytics because of module spelling issues
# and also stuff in rev 08-007 after entity
drush dl --yes jquery_update-7.x-3.x-alpha3 media_ckeditor-7.x-2.x-dev ckeditor-7.x-1.x-dev

drush --yes @sites updb
