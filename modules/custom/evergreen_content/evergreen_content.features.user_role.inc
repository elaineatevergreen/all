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
    'weight' => 10,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 15,
  );

  // Exported role: advanced editor.
  $roles['advanced editor'] = array(
    'name' => 'advanced editor',
    'weight' => 13,
  );

  // Exported role: alumni programs.
  $roles['alumni programs'] = array(
    'name' => 'alumni programs',
    'weight' => 5,
  );

  // Exported role: calendar review.
  $roles['calendar review'] = array(
    'name' => 'calendar review',
    'weight' => 9,
  );

  // Exported role: committee organizer.
  $roles['committee organizer'] = array(
    'name' => 'committee organizer',
    'weight' => 4,
  );

  // Exported role: form results.
  $roles['form results'] = array(
    'name' => 'form results',
    'weight' => 2,
  );

  // Exported role: librarian.
  $roles['librarian'] = array(
    'name' => 'librarian',
    'weight' => 6,
  );

  // Exported role: news promoter.
  $roles['news promoter'] = array(
    'name' => 'news promoter',
    'weight' => 11,
  );

  // Exported role: site editor.
  $roles['site editor'] = array(
    'name' => 'site editor',
    'weight' => 12,
  );

  // Exported role: student groups.
  $roles['student groups'] = array(
    'name' => 'student groups',
    'weight' => 7,
  );

  // Exported role: student worker administrator.
  $roles['student worker administrator'] = array(
    'name' => 'student worker administrator',
    'weight' => 14,
  );

  return $roles;
}
