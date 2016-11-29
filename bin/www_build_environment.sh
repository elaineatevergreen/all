#!/usr/bin/env bash
export PATH=$HOME/bin:$HOME/.composer/vendor/bin:$PATH
export WWW_CODE='/var/www/wwwdev.evergreen.edu/htdocs'
case "$CI_BUILD_REF_NAME" in
  *test*)
    STAGE="test"
    export WWW_CODE='/var/www/wwwtest.evergreen.edu/htdocs'
    export SITE_SUqFIX="test";
    ;;
  *master*)
    STAGE="prod"
    export WWW_CODE='/var/www/evergreen.edu/htdocs'
    export SITE_SUFFIX="";
    ;;
  *)
    STAGE="dev"
    export SITE_SUFFIX="dev";
    export WWW_CODE='/var/www/wwwdev.evergreen.edu/htdocs'
    ;;
esac
