<?php
/**
 * @file
 * evergreen_content.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function evergreen_content_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: advanced editor.
  $roles['advanced editor'] = array(
    'name' => 'advanced editor',
    'weight' => 6,
  );

  // Exported role: news promoter.
  $roles['news promoter'] = array(
    'name' => 'news promoter',
    'weight' => 5,
  );

  // Exported role: site editor.
  $roles['site editor'] = array(
    'name' => 'site editor',
    'weight' => 3,
  );

  // Exported role: student groups.
  $roles['student groups'] = array(
    'name' => 'student groups',
    'weight' => 4,
  );

  return $roles;
}
