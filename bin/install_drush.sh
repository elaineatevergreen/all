#!/usr/bin/env bash
# Install instructions per https://getcomposer.org/download/
cd $HOME
rm -f $HOME/bin/composer
mkdir -p bin
php -r "copy('https://getcomposer.org/installer', 'composer-setup.php');"
php composer-setup.php
php -r "unlink('composer-setup.php');"
mv $HOME/composer.phar $HOME/bin/composer
$HOME/bin/composer --version
composer global require drush/drush

