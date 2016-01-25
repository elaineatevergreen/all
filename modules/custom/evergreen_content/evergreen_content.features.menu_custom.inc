<?php
/**
 * @file
 * evergreen_content.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function evergreen_content_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu contains the top links that appear on every page of Evergreen\'s site.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('The <em>Main</em> menu contains the top links that appear on every page of Evergreen\'s site.');

  return $menus;
}
