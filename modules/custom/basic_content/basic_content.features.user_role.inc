<?php
/**
 * @file
 * basic_content.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function basic_content_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 6,
  );

  // Exported role: advanced editor.
  $roles['advanced editor'] = array(
    'name' => 'advanced editor',
    'weight' => 4,
  );

  // Exported role: form results reviewer.
  $roles['form results reviewer'] = array(
    'name' => 'form results reviewer',
    'weight' => 2,
  );

  // Exported role: site editor.
  $roles['site editor'] = array(
    'name' => 'site editor',
    'weight' => 3,
  );

  // Exported role: student worker administrator.
  $roles['student worker administrator'] = array(
    'name' => 'student worker administrator',
    'weight' => 5,
  );

  return $roles;
}
