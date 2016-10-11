<?php
/**
 * @file
 * evergreen_migration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function evergreen_migration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clear alumni_circle_import feeds'.
  $permissions['clear alumni_circle_import feeds'] = array(
    'name' => 'clear alumni_circle_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear author_directory feeds'.
  $permissions['clear author_directory feeds'] = array(
    'name' => 'clear author_directory feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear calendar_events feeds'.
  $permissions['clear calendar_events feeds'] = array(
    'name' => 'clear calendar_events feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear campus_locations feeds'.
  $permissions['clear campus_locations feeds'] = array(
    'name' => 'clear campus_locations feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear entrepreneur_directory feeds'.
  $permissions['clear entrepreneur_directory feeds'] = array(
    'name' => 'clear entrepreneur_directory feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear fields_of_study_import feeds'.
  $permissions['clear fields_of_study_import feeds'] = array(
    'name' => 'clear fields_of_study_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear hero_images feeds'.
  $permissions['clear hero_images feeds'] = array(
    'name' => 'clear hero_images feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear library_database_subjects feeds'.
  $permissions['clear library_database_subjects feeds'] = array(
    'name' => 'clear library_database_subjects feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear library_databases feeds'.
  $permissions['clear library_databases feeds'] = array(
    'name' => 'clear library_databases feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear navigation_import feeds'.
  $permissions['clear navigation_import feeds'] = array(
    'name' => 'clear navigation_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import alumni_circle_import feeds'.
  $permissions['import alumni_circle_import feeds'] = array(
    'name' => 'import alumni_circle_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import author_directory feeds'.
  $permissions['import author_directory feeds'] = array(
    'name' => 'import author_directory feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import calendar_events feeds'.
  $permissions['import calendar_events feeds'] = array(
    'name' => 'import calendar_events feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import campus_locations feeds'.
  $permissions['import campus_locations feeds'] = array(
    'name' => 'import campus_locations feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import entrepreneur_directory feeds'.
  $permissions['import entrepreneur_directory feeds'] = array(
    'name' => 'import entrepreneur_directory feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import fields_of_study_import feeds'.
  $permissions['import fields_of_study_import feeds'] = array(
    'name' => 'import fields_of_study_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import hero_images feeds'.
  $permissions['import hero_images feeds'] = array(
    'name' => 'import hero_images feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import library_database_subjects feeds'.
  $permissions['import library_database_subjects feeds'] = array(
    'name' => 'import library_database_subjects feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import library_databases feeds'.
  $permissions['import library_databases feeds'] = array(
    'name' => 'import library_databases feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import navigation_import feeds'.
  $permissions['import navigation_import feeds'] = array(
    'name' => 'import navigation_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'tamper alumni_circle_import'.
  $permissions['tamper alumni_circle_import'] = array(
    'name' => 'tamper alumni_circle_import',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper author_directory'.
  $permissions['tamper author_directory'] = array(
    'name' => 'tamper author_directory',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper calendar_events'.
  $permissions['tamper calendar_events'] = array(
    'name' => 'tamper calendar_events',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper campus_locations'.
  $permissions['tamper campus_locations'] = array(
    'name' => 'tamper campus_locations',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper entrepreneur_directory'.
  $permissions['tamper entrepreneur_directory'] = array(
    'name' => 'tamper entrepreneur_directory',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper fields_of_study_import'.
  $permissions['tamper fields_of_study_import'] = array(
    'name' => 'tamper fields_of_study_import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper hero_images'.
  $permissions['tamper hero_images'] = array(
    'name' => 'tamper hero_images',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper library_database_subjects'.
  $permissions['tamper library_database_subjects'] = array(
    'name' => 'tamper library_database_subjects',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper library_databases'.
  $permissions['tamper library_databases'] = array(
    'name' => 'tamper library_databases',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper navigation_import'.
  $permissions['tamper navigation_import'] = array(
    'name' => 'tamper navigation_import',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock alumni_circle_import feeds'.
  $permissions['unlock alumni_circle_import feeds'] = array(
    'name' => 'unlock alumni_circle_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock author_directory feeds'.
  $permissions['unlock author_directory feeds'] = array(
    'name' => 'unlock author_directory feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock calendar_events feeds'.
  $permissions['unlock calendar_events feeds'] = array(
    'name' => 'unlock calendar_events feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock campus_locations feeds'.
  $permissions['unlock campus_locations feeds'] = array(
    'name' => 'unlock campus_locations feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock entrepreneur_directory feeds'.
  $permissions['unlock entrepreneur_directory feeds'] = array(
    'name' => 'unlock entrepreneur_directory feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock hero_images feeds'.
  $permissions['unlock hero_images feeds'] = array(
    'name' => 'unlock hero_images feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock library_database_subjects feeds'.
  $permissions['unlock library_database_subjects feeds'] = array(
    'name' => 'unlock library_database_subjects feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock library_databases feeds'.
  $permissions['unlock library_databases feeds'] = array(
    'name' => 'unlock library_databases feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock navigation_import feeds'.
  $permissions['unlock navigation_import feeds'] = array(
    'name' => 'unlock navigation_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  return $permissions;
}
