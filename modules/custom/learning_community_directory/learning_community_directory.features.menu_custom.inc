<?php
/**
 * @file
 * learning_community_directory.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function learning_community_directory_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-directory-navigation.
  $menus['menu-directory-navigation'] = array(
    'menu_name' => 'menu-directory-navigation',
    'title' => 'Directory Navigation',
    'description' => 'Links specifically for navigating the Learning Communities Directory.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Directory Navigation');
  t('Links specifically for navigating the Learning Communities Directory.');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
