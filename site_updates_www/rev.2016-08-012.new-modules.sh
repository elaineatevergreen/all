#!/usr/bin/env bash
# standalone modules
# rerunning with everything after Google Analytics because of module spelling issues
# and also stuff in rev 08-007 after entity
drush dl --yes multiform

drush --yes @sites updb
