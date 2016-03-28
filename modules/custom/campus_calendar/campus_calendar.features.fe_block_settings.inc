<?php
/**
 * @file
 * campus_calendar.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function campus_calendar_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-academicyears'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'academicyears',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'academic',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -19,
      ),
    ),
    'title' => 'Academic Years',
    'visibility' => 1,
  );

  $export['block-placeholder_background'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'placeholder_background',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'background_image',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['block-placeholder_title'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'placeholder_title',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'section_title',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['block-pseudomenu'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'pseudomenu',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'section_nav',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -19,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['cas-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'cas',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -20,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-calendar-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-calendar-navigation',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-campus-calendar'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-campus-calendar',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -16,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -21,
      ),
    ),
    'title' => 'Search Events',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views--exp-calendar-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-calendar-page',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'category*',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -17,
      ),
    ),
    'title' => 'Filter Events',
    'visibility' => 1,
  );

  $export['views--exp-calendar_date_browser-page'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '-exp-calendar_date_browser-page',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>
calendar-date-browser',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-9813bc929be0ad92b8104bd809bcbbfb'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '9813bc929be0ad92b8104bd809bcbbfb',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'events/month/*',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -18,
      ),
    ),
    'title' => 'Filter Events by Category or Format',
    'visibility' => 1,
  );

  $export['views-9cf22433e0efbd8b206c8e4c2edb177c'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '9cf22433e0efbd8b206c8e4c2edb177c',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-calendar-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calendar-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-calendar-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calendar-block_2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-calendar-block_3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calendar-block_3',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-calendar-category_menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calendar-category_menu',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-calendar_date_browser-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'calendar_date_browser-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>
events/day*',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-workbench_current_user-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'workbench_current_user-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
