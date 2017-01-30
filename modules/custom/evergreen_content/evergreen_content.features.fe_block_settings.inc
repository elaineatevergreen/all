<?php
/**
 * @file
 * evergreen_content.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function evergreen_content_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-catalog_section_title'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'js' => NULL,
    'machine_name' => 'catalog_section_title',
    'module' => 'block',
    'node_types' => array(),
    'noscript' => NULL,
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['block-directory_section_title'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'js' => NULL,
    'machine_name' => 'directory_section_title',
    'module' => 'block',
    'node_types' => array(),
    'noscript' => NULL,
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['block-faculty_directory_secondary'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'js' => NULL,
    'machine_name' => 'faculty_directory_secondary',
    'module' => 'block',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => 'faculty',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['block-fields_section_title'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'js' => NULL,
    'machine_name' => 'fields_section_title',
    'module' => 'block',
    'node_types' => array(),
    'noscript' => NULL,
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'form',
    'js' => NULL,
    'module' => 'search',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'navigation',
    'js' => NULL,
    'module' => 'system',
    'node_types' => array(),
    'noscript' => NULL,
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

  $export['system-powered-by'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'powered-by',
    'js' => NULL,
    'module' => 'system',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -12,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views--exp-calendar-page'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => '-exp-calendar-page',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => 'calendar/category*',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views--exp-calendar_by_date-page_1'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => '-exp-calendar_by_date-page_1',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => 'calendar/month*',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-alerts-only_alerts'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'alerts-only_alerts',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'home_page',
    ),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -42,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-blog-home'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'blog-home',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'home_page',
    ),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -35,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-catalog-offerings_by_faculty'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'catalog-offerings_by_faculty',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'directory_individual',
    ),
    'noscript' => NULL,
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

  $export['views-catalog-offerings_by_field'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'catalog-offerings_by_field',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'field_of_study',
    ),
    'noscript' => NULL,
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

  $export['views-home_page_hero-block'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'home_page_hero-block',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'home_page',
    ),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -41,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-news_o_matic-block'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'news_o_matic-block',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'home_page',
    ),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'wwwevergreen',
        'weight' => -36,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-secondary_content-block'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'secondary_content-block',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-site_section_background-block'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'site_section_background-block',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'article',
      1 => 'basic_page',
      2 => 'directory_individual',
      3 => 'event',
      4 => 'gallery',
      5 => 'job_post',
      6 => 'scholarship',
      7 => 'webform',
    ),
    'noscript' => NULL,
    'pages' => 'directory*
catalog*
calendar*
faculty
faculty/retired',
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

  $export['views-site_section_background-block_1'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'site_section_background-block_1',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'article',
      1 => 'basic_page',
      2 => 'event',
      3 => 'gallery',
      4 => 'job_post',
      5 => 'scholarship',
      6 => 'webform',
    ),
    'noscript' => NULL,
    'pages' => 'directory*
catalog*
calendar*
studies*
faculty/retired
faculty',
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

  $export['views-site_section_background-block_3'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'site_section_background-block_3',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'article',
      1 => 'basic_page',
      2 => 'directory_individual',
      3 => 'event',
      4 => 'home_page',
      5 => 'scholarship',
      6 => 'webform',
    ),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'secondary_content',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -16,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-site_section_background-nav'] = array(
    'cache' => -1,
    'css' => NULL,
    'custom' => 0,
    'delta' => 'site_section_background-nav',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(
      0 => 'article',
      1 => 'basic_page',
      2 => 'event',
      3 => 'gallery',
      4 => 'job_post',
      5 => 'scholarship',
      6 => 'webform',
    ),
    'noscript' => NULL,
    'pages' => 'directory*
catalog*
calendar*
studies*
faculty
faculty/retired',
    'roles' => array(),
    'themes' => array(
      'wwwevergreen' => array(
        'region' => 'section_nav',
        'status' => 1,
        'theme' => 'wwwevergreen',
        'weight' => -17,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
