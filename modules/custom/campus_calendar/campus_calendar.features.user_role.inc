<?php
/**
 * @file
 * campus_calendar.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function campus_calendar_user_default_roles() {
  $roles = array();

  // Exported role: academic calendar.
  $roles['academic calendar'] = array(
    'name' => 'academic calendar',
    'weight' => 4,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: calendar approval.
  $roles['calendar approval'] = array(
    'name' => 'calendar approval',
    'weight' => 3,
  );

  return $roles;
}
