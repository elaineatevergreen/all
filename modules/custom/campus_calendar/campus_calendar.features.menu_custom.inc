<?php
/**
 * @file
 * campus_calendar.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function campus_calendar_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-calendar-navigation.
  $menus['menu-calendar-navigation'] = array(
    'menu_name' => 'menu-calendar-navigation',
    'title' => 'Instructions',
    'description' => 'This is used specifically for the campus events calendar. It doesn\'t actually do the expando-collapso thing.',
  );
  // Exported menu: menu-campus-calendar.
  $menus['menu-campus-calendar'] = array(
    'menu_name' => 'menu-campus-calendar',
    'title' => 'Campus Calendar',
    'description' => 'Mimics the "Calendars" navigation section on the old campus calendar',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Campus Calendar');
  t('Instructions');
  t('Main menu');
  t('Mimics the "Calendars" navigation section on the old campus calendar');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('This is used specifically for the campus events calendar. It doesn\'t actually do the expando-collapso thing.');

  return $menus;
}
