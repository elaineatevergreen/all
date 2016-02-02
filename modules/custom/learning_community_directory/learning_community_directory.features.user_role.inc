<?php
/**
 * @file
 * learning_community_directory.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function learning_community_directory_user_default_roles() {
  $roles = array();

  // Exported role: LC staff.
  $roles['LC staff'] = array(
    'name' => 'LC staff',
    'weight' => 3,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
