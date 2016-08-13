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

  // Exported role: academics editor.
  $roles['academics editor'] = array(
    'name' => 'academics editor',
    'weight' => 8,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: advanced editor.
  $roles['advanced editor'] = array(
    'name' => 'advanced editor',
    'weight' => 4,
  );

  // Exported role: calendar review.
  $roles['calendar review'] = array(
    'name' => 'calendar review',
    'weight' => 7,
  );

  // Exported role: news promoter.
  $roles['news promoter'] = array(
    'name' => 'news promoter',
    'weight' => 6,
  );

  // Exported role: site editor.
  $roles['site editor'] = array(
    'name' => 'site editor',
    'weight' => 3,
  );

  // Exported role: student groups.
  $roles['student groups'] = array(
    'name' => 'student groups',
    'weight' => 5,
  );

  return $roles;
}
