<?php
/**
 * @file
 * evergreen_cas.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function evergreen_cas_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer cas'.
  $permissions['administer cas'] = array(
    'name' => 'administer cas',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'cas',
  );

  return $permissions;
}
