<?php
/**
 * @file
 * campus_calendar.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function campus_calendar_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_academics:http://evergreen.edu/academics/.
  $menu_links['main-menu_academics:http://evergreen.edu/academics/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://evergreen.edu/academics/',
    'router_path' => '',
    'link_title' => 'Academics',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_academics:http://evergreen.edu/academics/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_admissions:http://evergreen.edu/admissions/.
  $menu_links['main-menu_admissions:http://evergreen.edu/admissions/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://evergreen.edu/admissions/',
    'router_path' => '',
    'link_title' => 'Admissions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_admissions:http://evergreen.edu/admissions/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_campus-life:http://evergreen.edu/campuslife/.
  $menu_links['main-menu_campus-life:http://evergreen.edu/campuslife/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://evergreen.edu/campuslife/',
    'router_path' => '',
    'link_title' => 'Campus Life',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_campus-life:http://evergreen.edu/campuslife/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_costs--aid:http://evergreen.edu/costs.
  $menu_links['main-menu_costs--aid:http://evergreen.edu/costs'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://evergreen.edu/costs',
    'router_path' => '',
    'link_title' => 'Costs & Aid',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_costs--aid:http://evergreen.edu/costs',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:http://evergreen.edu.
  $menu_links['main-menu_home:http://evergreen.edu'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://evergreen.edu',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_home:http://evergreen.edu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-campus-calendar_campus-events-calendar:<front>.
  $menu_links['menu-campus-calendar_campus-events-calendar:<front>'] = array(
    'menu_name' => 'menu-campus-calendar',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Campus Events Calendar',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-campus-calendar_campus-events-calendar:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-campus-calendar_class-schedules:http://www.evergreen.edu/classschedules/home.htm.
  $menu_links['menu-campus-calendar_class-schedules:http://www.evergreen.edu/classschedules/home.htm'] = array(
    'menu_name' => 'menu-campus-calendar',
    'link_path' => 'http://www.evergreen.edu/classschedules/home.htm',
    'router_path' => '',
    'link_title' => 'Class Schedules',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-campus-calendar_class-schedules:http://www.evergreen.edu/classschedules/home.htm',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-campus-calendar_for-testing-calendar-ish-view:calendar-node-field-event-date.
  $menu_links['menu-campus-calendar_for-testing-calendar-ish-view:calendar-node-field-event-date'] = array(
    'menu_name' => 'menu-campus-calendar',
    'link_path' => 'calendar-node-field-event-date',
    'router_path' => 'calendar-node-field-event-date',
    'link_title' => 'For testing: Calendar-ish View',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-campus-calendar_for-testing-calendar-ish-view:calendar-node-field-event-date',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Academics');
  t('Admissions');
  t('Campus Events Calendar');
  t('Campus Life');
  t('Class Schedules');
  t('Costs & Aid');
  t('For testing: Calendar-ish View');
  t('Home');

  return $menu_links;
}
