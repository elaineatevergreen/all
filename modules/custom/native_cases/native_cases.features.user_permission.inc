<?php
/**
 * @file
 * native_cases.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function native_cases_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clear case_study feeds'.
  $permissions['clear case_study feeds'] = array(
    'name' => 'clear case_study feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear taxonomy feeds'.
  $permissions['clear taxonomy feeds'] = array(
    'name' => 'clear taxonomy feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear themes feeds'.
  $permissions['clear themes feeds'] = array(
    'name' => 'clear themes feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear tribes feeds'.
  $permissions['clear tribes feeds'] = array(
    'name' => 'clear tribes feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'create case_study content'.
  $permissions['create case_study content'] = array(
    'name' => 'create case_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any case_study content'.
  $permissions['delete any case_study content'] = array(
    'name' => 'delete any case_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own case_study content'.
  $permissions['delete own case_study content'] = array(
    'name' => 'delete own case_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in discipline'.
  $permissions['delete terms in discipline'] = array(
    'name' => 'delete terms in discipline',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in theme'.
  $permissions['delete terms in theme'] = array(
    'name' => 'delete terms in theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tribe'.
  $permissions['delete terms in tribe'] = array(
    'name' => 'delete terms in tribe',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any case_study content'.
  $permissions['edit any case_study content'] = array(
    'name' => 'edit any case_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own case_study content'.
  $permissions['edit own case_study content'] = array(
    'name' => 'edit own case_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in discipline'.
  $permissions['edit terms in discipline'] = array(
    'name' => 'edit terms in discipline',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in theme'.
  $permissions['edit terms in theme'] = array(
    'name' => 'edit terms in theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tribe'.
  $permissions['edit terms in tribe'] = array(
    'name' => 'edit terms in tribe',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'import case_study feeds'.
  $permissions['import case_study feeds'] = array(
    'name' => 'import case_study feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import taxonomy feeds'.
  $permissions['import taxonomy feeds'] = array(
    'name' => 'import taxonomy feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import themes feeds'.
  $permissions['import themes feeds'] = array(
    'name' => 'import themes feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import tribes feeds'.
  $permissions['import tribes feeds'] = array(
    'name' => 'import tribes feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'tamper case_study'.
  $permissions['tamper case_study'] = array(
    'name' => 'tamper case_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper taxonomy'.
  $permissions['tamper taxonomy'] = array(
    'name' => 'tamper taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper themes'.
  $permissions['tamper themes'] = array(
    'name' => 'tamper themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper tribes'.
  $permissions['tamper tribes'] = array(
    'name' => 'tamper tribes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock case_study feeds'.
  $permissions['unlock case_study feeds'] = array(
    'name' => 'unlock case_study feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock taxonomy feeds'.
  $permissions['unlock taxonomy feeds'] = array(
    'name' => 'unlock taxonomy feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock themes feeds'.
  $permissions['unlock themes feeds'] = array(
    'name' => 'unlock themes feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock tribes feeds'.
  $permissions['unlock tribes feeds'] = array(
    'name' => 'unlock tribes feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  return $permissions;
}
