<?php
/**
 * @file
 * learning_community_directory.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function learning_community_directory_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'bypass user restriction rules'.
  $permissions['bypass user restriction rules'] = array(
    'name' => 'bypass user restriction rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user_restrictions',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear programs feeds'.
  $permissions['clear programs feeds'] = array(
    'name' => 'clear programs feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'create institution content'.
  $permissions['create institution content'] = array(
    'name' => 'create institution content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create learning_community_program content'.
  $permissions['create learning_community_program content'] = array(
    'name' => 'create learning_community_program content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any institution content'.
  $permissions['delete any institution content'] = array(
    'name' => 'delete any institution content',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any learning_community_program content'.
  $permissions['delete any learning_community_program content'] = array(
    'name' => 'delete any learning_community_program content',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own institution content'.
  $permissions['delete own institution content'] = array(
    'name' => 'delete own institution content',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own learning_community_program content'.
  $permissions['delete own learning_community_program content'] = array(
    'name' => 'delete own learning_community_program content',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any institution content'.
  $permissions['edit any institution content'] = array(
    'name' => 'edit any institution content',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any learning_community_program content'.
  $permissions['edit any learning_community_program content'] = array(
    'name' => 'edit any learning_community_program content',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own institution content'.
  $permissions['edit own institution content'] = array(
    'name' => 'edit own institution content',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own learning_community_program content'.
  $permissions['edit own learning_community_program content'] = array(
    'name' => 'edit own learning_community_program content',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit user restriction rules'.
  $permissions['edit user restriction rules'] = array(
    'name' => 'edit user restriction rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user_restrictions',
  );

  // Exported permission: 'import programs feeds'.
  $permissions['import programs feeds'] = array(
    'name' => 'import programs feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'tamper institutions'.
  $permissions['tamper institutions'] = array(
    'name' => 'tamper institutions',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper programs'.
  $permissions['tamper programs'] = array(
    'name' => 'tamper programs',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock institutions feeds'.
  $permissions['unlock institutions feeds'] = array(
    'name' => 'unlock institutions feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock programs feeds'.
  $permissions['unlock programs feeds'] = array(
    'name' => 'unlock programs feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'LC staff' => 'LC staff',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view similar titles suggestion'.
  $permissions['view similar titles suggestion'] = array(
    'name' => 'view similar titles suggestion',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'suggest_similar_titles',
  );

  return $permissions;
}
