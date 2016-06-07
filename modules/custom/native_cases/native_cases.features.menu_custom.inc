<?php
/**
 * @file
 * native_cases.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function native_cases_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-case-facets.
  $menus['menu-case-facets'] = array(
    'menu_name' => 'menu-case-facets',
    'title' => 'Case Facets',
    'description' => 'Different ways that the Case Study lists are organized.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Case Facets');
  t('Different ways that the Case Study lists are organized.');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
