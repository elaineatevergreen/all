<?php
/**
 * @file
 * evergreen_content.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function evergreen_content_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Create short URLs'.
  $permissions['Create short URLs'] = array(
    'name' => 'Create short URLs',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'student worker administrator' => 'student worker administrator',
    ),
    'module' => 'shurly',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access environment indicator'.
  $permissions['access environment indicator'] = array(
    'name' => 'access environment indicator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator collabtest'.
  $permissions['access environment indicator collabtest'] = array(
    'name' => 'access environment indicator collabtest',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator default_environment'.
  $permissions['access environment indicator default_environment'] = array(
    'name' => 'access environment indicator default_environment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator live_collab'.
  $permissions['access environment indicator live_collab'] = array(
    'name' => 'access environment indicator live_collab',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator localhost'.
  $permissions['access environment indicator localhost'] = array(
    'name' => 'access environment indicator localhost',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator overwritten_environment'.
  $permissions['access environment indicator overwritten_environment'] = array(
    'name' => 'access environment indicator overwritten_environment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access security review list'.
  $permissions['access security review list'] = array(
    'name' => 'access security review list',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'security_review',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access statistics'.
  $permissions['access statistics'] = array(
    'name' => 'access statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'authenticated user' => 'authenticated user',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'access workbench access by role'.
  $permissions['access workbench access by role'] = array(
    'name' => 'access workbench access by role',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer custom search'.
  $permissions['administer custom search'] = array(
    'name' => 'administer custom search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'custom_search',
  );

  // Exported permission: 'administer custom search blocks'.
  $permissions['administer custom search blocks'] = array(
    'name' => 'administer custom search blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'custom_search_blocks',
  );

  // Exported permission: 'administer entity view modes'.
  $permissions['administer entity view modes'] = array(
    'name' => 'administer entity view modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_view_mode',
  );

  // Exported permission: 'administer entityqueue'.
  $permissions['administer entityqueue'] = array(
    'name' => 'administer entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'administer environment indicator settings'.
  $permissions['administer environment indicator settings'] = array(
    'name' => 'administer environment indicator settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer feeds_tamper'.
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkit',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer statistics'.
  $permissions['administer statistics'] = array(
    'name' => 'administer statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer unit tests'.
  $permissions['administer unit tests'] = array(
    'name' => 'administer unit tests',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'simpletest',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench access'.
  $permissions['administer workbench access'] = array(
    'name' => 'administer workbench access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'advanced migration information'.
  $permissions['advanced migration information'] = array(
    'name' => 'advanced migration information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'assign workbench access'.
  $permissions['assign workbench access'] = array(
    'name' => 'assign workbench access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'batch update workbench access'.
  $permissions['batch update workbench access'] = array(
    'name' => 'batch update workbench access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
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
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear catalog feeds'.
  $permissions['clear catalog feeds'] = array(
    'name' => 'clear catalog feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear e2campus feeds'.
  $permissions['clear e2campus feeds'] = array(
    'name' => 'clear e2campus feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear faculty_directory feeds'.
  $permissions['clear faculty_directory feeds'] = array(
    'name' => 'clear faculty_directory feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear office_directory feeds'.
  $permissions['clear office_directory feeds'] = array(
    'name' => 'clear office_directory feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear office_directory_facility feeds'.
  $permissions['clear office_directory_facility feeds'] = array(
    'name' => 'clear office_directory_facility feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear people_directory feeds'.
  $permissions['clear people_directory feeds'] = array(
    'name' => 'clear people_directory feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear scholarship_import feeds'.
  $permissions['clear scholarship_import feeds'] = array(
    'name' => 'clear scholarship_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'create alert content'.
  $permissions['create alert content'] = array(
    'name' => 'create alert content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create any alternate_background_image bean'.
  $permissions['create any alternate_background_image bean'] = array(
    'name' => 'create any alternate_background_image bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any section_menu bean'.
  $permissions['create any section_menu bean'] = array(
    'name' => 'create any section_menu bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create basic_page content'.
  $permissions['create basic_page content'] = array(
    'name' => 'create basic_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create blurb content'.
  $permissions['create blurb content'] = array(
    'name' => 'create blurb content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create catalog_entry content'.
  $permissions['create catalog_entry content'] = array(
    'name' => 'create catalog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create directory_individual content'.
  $permissions['create directory_individual content'] = array(
    'name' => 'create directory_individual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create directory_office content'.
  $permissions['create directory_office content'] = array(
    'name' => 'create directory_office content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create evergreen_magazine entityqueue'.
  $permissions['create evergreen_magazine entityqueue'] = array(
    'name' => 'create evergreen_magazine entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'create field_of_study content'.
  $permissions['create field_of_study content'] = array(
    'name' => 'create field_of_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create gallery content'.
  $permissions['create gallery content'] = array(
    'name' => 'create gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create home_page content'.
  $permissions['create home_page content'] = array(
    'name' => 'create home_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create home_page_hero content'.
  $permissions['create home_page_hero content'] = array(
    'name' => 'create home_page_hero content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create library_database content'.
  $permissions['create library_database content'] = array(
    'name' => 'create library_database content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create profile content'.
  $permissions['create profile content'] = array(
    'name' => 'create profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create scholarship content'.
  $permissions['create scholarship content'] = array(
    'name' => 'create scholarship content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create student_group content'.
  $permissions['create student_group content'] = array(
    'name' => 'create student_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'student groups' => 'student groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any alert content'.
  $permissions['delete any alert content'] = array(
    'name' => 'delete any alert content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any alternate_background_image bean'.
  $permissions['delete any alternate_background_image bean'] = array(
    'name' => 'delete any alternate_background_image bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any basic_page content'.
  $permissions['delete any basic_page content'] = array(
    'name' => 'delete any basic_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any blurb content'.
  $permissions['delete any blurb content'] = array(
    'name' => 'delete any blurb content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any catalog_entry content'.
  $permissions['delete any catalog_entry content'] = array(
    'name' => 'delete any catalog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any directory_individual content'.
  $permissions['delete any directory_individual content'] = array(
    'name' => 'delete any directory_individual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any directory_office content'.
  $permissions['delete any directory_office content'] = array(
    'name' => 'delete any directory_office content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any field_of_study content'.
  $permissions['delete any field_of_study content'] = array(
    'name' => 'delete any field_of_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any gallery content'.
  $permissions['delete any gallery content'] = array(
    'name' => 'delete any gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any home_page content'.
  $permissions['delete any home_page content'] = array(
    'name' => 'delete any home_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any home_page_hero content'.
  $permissions['delete any home_page_hero content'] = array(
    'name' => 'delete any home_page_hero content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any library_database content'.
  $permissions['delete any library_database content'] = array(
    'name' => 'delete any library_database content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any profile content'.
  $permissions['delete any profile content'] = array(
    'name' => 'delete any profile content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any scholarship content'.
  $permissions['delete any scholarship content'] = array(
    'name' => 'delete any scholarship content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any section_menu bean'.
  $permissions['delete any section_menu bean'] = array(
    'name' => 'delete any section_menu bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any student_group content'.
  $permissions['delete any student_group content'] = array(
    'name' => 'delete any student_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete evergreen_magazine entityqueue'.
  $permissions['delete evergreen_magazine entityqueue'] = array(
    'name' => 'delete evergreen_magazine entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'delete own alert content'.
  $permissions['delete own alert content'] = array(
    'name' => 'delete own alert content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own basic_page content'.
  $permissions['delete own basic_page content'] = array(
    'name' => 'delete own basic_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own blurb content'.
  $permissions['delete own blurb content'] = array(
    'name' => 'delete own blurb content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own catalog_entry content'.
  $permissions['delete own catalog_entry content'] = array(
    'name' => 'delete own catalog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own directory_individual content'.
  $permissions['delete own directory_individual content'] = array(
    'name' => 'delete own directory_individual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own directory_office content'.
  $permissions['delete own directory_office content'] = array(
    'name' => 'delete own directory_office content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own field_of_study content'.
  $permissions['delete own field_of_study content'] = array(
    'name' => 'delete own field_of_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own gallery content'.
  $permissions['delete own gallery content'] = array(
    'name' => 'delete own gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own home_page content'.
  $permissions['delete own home_page content'] = array(
    'name' => 'delete own home_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own home_page_hero content'.
  $permissions['delete own home_page_hero content'] = array(
    'name' => 'delete own home_page_hero content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own library_database content'.
  $permissions['delete own library_database content'] = array(
    'name' => 'delete own library_database content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own profile content'.
  $permissions['delete own profile content'] = array(
    'name' => 'delete own profile content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own scholarship content'.
  $permissions['delete own scholarship content'] = array(
    'name' => 'delete own scholarship content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own student_group content'.
  $permissions['delete own student_group content'] = array(
    'name' => 'delete own student_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in calendar_categories'.
  $permissions['delete terms in calendar_categories'] = array(
    'name' => 'delete terms in calendar_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in database_of_databases'.
  $permissions['delete terms in database_of_databases'] = array(
    'name' => 'delete terms in database_of_databases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_formats'.
  $permissions['delete terms in event_formats'] = array(
    'name' => 'delete terms in event_formats',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in faculty_directory_categories'.
  $permissions['delete terms in faculty_directory_categories'] = array(
    'name' => 'delete terms in faculty_directory_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in site_sections'.
  $permissions['delete terms in site_sections'] = array(
    'name' => 'delete terms in site_sections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any alert content'.
  $permissions['edit any alert content'] = array(
    'name' => 'edit any alert content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any alternate_background_image bean'.
  $permissions['edit any alternate_background_image bean'] = array(
    'name' => 'edit any alternate_background_image bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any basic_page content'.
  $permissions['edit any basic_page content'] = array(
    'name' => 'edit any basic_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any blurb content'.
  $permissions['edit any blurb content'] = array(
    'name' => 'edit any blurb content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any catalog_entry content'.
  $permissions['edit any catalog_entry content'] = array(
    'name' => 'edit any catalog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any directory_individual content'.
  $permissions['edit any directory_individual content'] = array(
    'name' => 'edit any directory_individual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any directory_office content'.
  $permissions['edit any directory_office content'] = array(
    'name' => 'edit any directory_office content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any field_of_study content'.
  $permissions['edit any field_of_study content'] = array(
    'name' => 'edit any field_of_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any gallery content'.
  $permissions['edit any gallery content'] = array(
    'name' => 'edit any gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any home_page content'.
  $permissions['edit any home_page content'] = array(
    'name' => 'edit any home_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any home_page_hero content'.
  $permissions['edit any home_page_hero content'] = array(
    'name' => 'edit any home_page_hero content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any library_database content'.
  $permissions['edit any library_database content'] = array(
    'name' => 'edit any library_database content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any profile content'.
  $permissions['edit any profile content'] = array(
    'name' => 'edit any profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any scholarship content'.
  $permissions['edit any scholarship content'] = array(
    'name' => 'edit any scholarship content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any section_menu bean'.
  $permissions['edit any section_menu bean'] = array(
    'name' => 'edit any section_menu bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any student_group content'.
  $permissions['edit any student_group content'] = array(
    'name' => 'edit any student_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'student groups' => 'student groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit meta tag: abstract'.
  $permissions['edit meta tag: abstract'] = array(
    'name' => 'edit meta tag: abstract',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: article:author'.
  $permissions['edit meta tag: article:author'] = array(
    'name' => 'edit meta tag: article:author',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: article:expiration_time'.
  $permissions['edit meta tag: article:expiration_time'] = array(
    'name' => 'edit meta tag: article:expiration_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: article:modified_time'.
  $permissions['edit meta tag: article:modified_time'] = array(
    'name' => 'edit meta tag: article:modified_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: article:published_time'.
  $permissions['edit meta tag: article:published_time'] = array(
    'name' => 'edit meta tag: article:published_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: article:publisher'.
  $permissions['edit meta tag: article:publisher'] = array(
    'name' => 'edit meta tag: article:publisher',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: article:section'.
  $permissions['edit meta tag: article:section'] = array(
    'name' => 'edit meta tag: article:section',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: article:tag'.
  $permissions['edit meta tag: article:tag'] = array(
    'name' => 'edit meta tag: article:tag',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: author'.
  $permissions['edit meta tag: author'] = array(
    'name' => 'edit meta tag: author',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: book:author'.
  $permissions['edit meta tag: book:author'] = array(
    'name' => 'edit meta tag: book:author',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: book:isbn'.
  $permissions['edit meta tag: book:isbn'] = array(
    'name' => 'edit meta tag: book:isbn',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: book:release_date'.
  $permissions['edit meta tag: book:release_date'] = array(
    'name' => 'edit meta tag: book:release_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: book:tag'.
  $permissions['edit meta tag: book:tag'] = array(
    'name' => 'edit meta tag: book:tag',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: cache-control'.
  $permissions['edit meta tag: cache-control'] = array(
    'name' => 'edit meta tag: cache-control',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: canonical'.
  $permissions['edit meta tag: canonical'] = array(
    'name' => 'edit meta tag: canonical',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: content-language'.
  $permissions['edit meta tag: content-language'] = array(
    'name' => 'edit meta tag: content-language',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: description'.
  $permissions['edit meta tag: description'] = array(
    'name' => 'edit meta tag: description',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: expires'.
  $permissions['edit meta tag: expires'] = array(
    'name' => 'edit meta tag: expires',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: generator'.
  $permissions['edit meta tag: generator'] = array(
    'name' => 'edit meta tag: generator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: geo.placename'.
  $permissions['edit meta tag: geo.placename'] = array(
    'name' => 'edit meta tag: geo.placename',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: geo.position'.
  $permissions['edit meta tag: geo.position'] = array(
    'name' => 'edit meta tag: geo.position',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: geo.region'.
  $permissions['edit meta tag: geo.region'] = array(
    'name' => 'edit meta tag: geo.region',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: icbm'.
  $permissions['edit meta tag: icbm'] = array(
    'name' => 'edit meta tag: icbm',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: image_src'.
  $permissions['edit meta tag: image_src'] = array(
    'name' => 'edit meta tag: image_src',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: keywords'.
  $permissions['edit meta tag: keywords'] = array(
    'name' => 'edit meta tag: keywords',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: news_keywords'.
  $permissions['edit meta tag: news_keywords'] = array(
    'name' => 'edit meta tag: news_keywords',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:audio'.
  $permissions['edit meta tag: og:audio'] = array(
    'name' => 'edit meta tag: og:audio',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:audio:secure_url'.
  $permissions['edit meta tag: og:audio:secure_url'] = array(
    'name' => 'edit meta tag: og:audio:secure_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:audio:type'.
  $permissions['edit meta tag: og:audio:type'] = array(
    'name' => 'edit meta tag: og:audio:type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:country_name'.
  $permissions['edit meta tag: og:country_name'] = array(
    'name' => 'edit meta tag: og:country_name',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:description'.
  $permissions['edit meta tag: og:description'] = array(
    'name' => 'edit meta tag: og:description',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:determiner'.
  $permissions['edit meta tag: og:determiner'] = array(
    'name' => 'edit meta tag: og:determiner',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:email'.
  $permissions['edit meta tag: og:email'] = array(
    'name' => 'edit meta tag: og:email',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:fax_number'.
  $permissions['edit meta tag: og:fax_number'] = array(
    'name' => 'edit meta tag: og:fax_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:image'.
  $permissions['edit meta tag: og:image'] = array(
    'name' => 'edit meta tag: og:image',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:image:height'.
  $permissions['edit meta tag: og:image:height'] = array(
    'name' => 'edit meta tag: og:image:height',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:image:type'.
  $permissions['edit meta tag: og:image:type'] = array(
    'name' => 'edit meta tag: og:image:type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:image:url'.
  $permissions['edit meta tag: og:image:url'] = array(
    'name' => 'edit meta tag: og:image:url',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:image:width'.
  $permissions['edit meta tag: og:image:width'] = array(
    'name' => 'edit meta tag: og:image:width',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:latitude'.
  $permissions['edit meta tag: og:latitude'] = array(
    'name' => 'edit meta tag: og:latitude',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:locale:alternate'.
  $permissions['edit meta tag: og:locale:alternate'] = array(
    'name' => 'edit meta tag: og:locale:alternate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:title'.
  $permissions['edit meta tag: og:title'] = array(
    'name' => 'edit meta tag: og:title',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:type'.
  $permissions['edit meta tag: og:type'] = array(
    'name' => 'edit meta tag: og:type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: og:updated_time'.
  $permissions['edit meta tag: og:updated_time'] = array(
    'name' => 'edit meta tag: og:updated_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: profile:first_name'.
  $permissions['edit meta tag: profile:first_name'] = array(
    'name' => 'edit meta tag: profile:first_name',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: profile:gender'.
  $permissions['edit meta tag: profile:gender'] = array(
    'name' => 'edit meta tag: profile:gender',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: profile:last_name'.
  $permissions['edit meta tag: profile:last_name'] = array(
    'name' => 'edit meta tag: profile:last_name',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: rating'.
  $permissions['edit meta tag: rating'] = array(
    'name' => 'edit meta tag: rating',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: standout'.
  $permissions['edit meta tag: standout'] = array(
    'name' => 'edit meta tag: standout',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:app:country'.
  $permissions['edit meta tag: twitter:app:country'] = array(
    'name' => 'edit meta tag: twitter:app:country',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:app:id:googleplay'.
  $permissions['edit meta tag: twitter:app:id:googleplay'] = array(
    'name' => 'edit meta tag: twitter:app:id:googleplay',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:app:name:googleplay'.
  $permissions['edit meta tag: twitter:app:name:googleplay'] = array(
    'name' => 'edit meta tag: twitter:app:name:googleplay',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:app:url:googleplay'.
  $permissions['edit meta tag: twitter:app:url:googleplay'] = array(
    'name' => 'edit meta tag: twitter:app:url:googleplay',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:creator'.
  $permissions['edit meta tag: twitter:creator'] = array(
    'name' => 'edit meta tag: twitter:creator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:creator:id'.
  $permissions['edit meta tag: twitter:creator:id'] = array(
    'name' => 'edit meta tag: twitter:creator:id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:data1'.
  $permissions['edit meta tag: twitter:data1'] = array(
    'name' => 'edit meta tag: twitter:data1',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:data2'.
  $permissions['edit meta tag: twitter:data2'] = array(
    'name' => 'edit meta tag: twitter:data2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:description'.
  $permissions['edit meta tag: twitter:description'] = array(
    'name' => 'edit meta tag: twitter:description',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:image'.
  $permissions['edit meta tag: twitter:image'] = array(
    'name' => 'edit meta tag: twitter:image',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:image0'.
  $permissions['edit meta tag: twitter:image0'] = array(
    'name' => 'edit meta tag: twitter:image0',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:image1'.
  $permissions['edit meta tag: twitter:image1'] = array(
    'name' => 'edit meta tag: twitter:image1',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:image2'.
  $permissions['edit meta tag: twitter:image2'] = array(
    'name' => 'edit meta tag: twitter:image2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:image3'.
  $permissions['edit meta tag: twitter:image3'] = array(
    'name' => 'edit meta tag: twitter:image3',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:image:alt'.
  $permissions['edit meta tag: twitter:image:alt'] = array(
    'name' => 'edit meta tag: twitter:image:alt',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:image:height'.
  $permissions['edit meta tag: twitter:image:height'] = array(
    'name' => 'edit meta tag: twitter:image:height',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:image:width'.
  $permissions['edit meta tag: twitter:image:width'] = array(
    'name' => 'edit meta tag: twitter:image:width',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:label1'.
  $permissions['edit meta tag: twitter:label1'] = array(
    'name' => 'edit meta tag: twitter:label1',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: twitter:label2'.
  $permissions['edit meta tag: twitter:label2'] = array(
    'name' => 'edit meta tag: twitter:label2',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: video:actor'.
  $permissions['edit meta tag: video:actor'] = array(
    'name' => 'edit meta tag: video:actor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: video:actor:role'.
  $permissions['edit meta tag: video:actor:role'] = array(
    'name' => 'edit meta tag: video:actor:role',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tag: video:director'.
  $permissions['edit meta tag: video:director'] = array(
    'name' => 'edit meta tag: video:director',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own alert content'.
  $permissions['edit own alert content'] = array(
    'name' => 'edit own alert content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own basic_page content'.
  $permissions['edit own basic_page content'] = array(
    'name' => 'edit own basic_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own blurb content'.
  $permissions['edit own blurb content'] = array(
    'name' => 'edit own blurb content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own catalog_entry content'.
  $permissions['edit own catalog_entry content'] = array(
    'name' => 'edit own catalog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own directory_individual content'.
  $permissions['edit own directory_individual content'] = array(
    'name' => 'edit own directory_individual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own directory_office content'.
  $permissions['edit own directory_office content'] = array(
    'name' => 'edit own directory_office content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_of_study content'.
  $permissions['edit own field_of_study content'] = array(
    'name' => 'edit own field_of_study content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own gallery content'.
  $permissions['edit own gallery content'] = array(
    'name' => 'edit own gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own home_page content'.
  $permissions['edit own home_page content'] = array(
    'name' => 'edit own home_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own home_page_hero content'.
  $permissions['edit own home_page_hero content'] = array(
    'name' => 'edit own home_page_hero content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own library_database content'.
  $permissions['edit own library_database content'] = array(
    'name' => 'edit own library_database content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own profile content'.
  $permissions['edit own profile content'] = array(
    'name' => 'edit own profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own scholarship content'.
  $permissions['edit own scholarship content'] = array(
    'name' => 'edit own scholarship content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own student_group content'.
  $permissions['edit own student_group content'] = array(
    'name' => 'edit own student_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'student groups' => 'student groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in calendar_categories'.
  $permissions['edit terms in calendar_categories'] = array(
    'name' => 'edit terms in calendar_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in database_of_databases'.
  $permissions['edit terms in database_of_databases'] = array(
    'name' => 'edit terms in database_of_databases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_formats'.
  $permissions['edit terms in event_formats'] = array(
    'name' => 'edit terms in event_formats',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in faculty_directory_categories'.
  $permissions['edit terms in faculty_directory_categories'] = array(
    'name' => 'edit terms in faculty_directory_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in site_sections'.
  $permissions['edit terms in site_sections'] = array(
    'name' => 'edit terms in site_sections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'administrator' => 'administrator',
      'site editor' => 'site editor',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import catalog feeds'.
  $permissions['import catalog feeds'] = array(
    'name' => 'import catalog feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import e2campus feeds'.
  $permissions['import e2campus feeds'] = array(
    'name' => 'import e2campus feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import faculty_directory feeds'.
  $permissions['import faculty_directory feeds'] = array(
    'name' => 'import faculty_directory feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media_bulk_upload',
  );

  // Exported permission: 'import office_directory feeds'.
  $permissions['import office_directory feeds'] = array(
    'name' => 'import office_directory feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import office_directory_facility feeds'.
  $permissions['import office_directory_facility feeds'] = array(
    'name' => 'import office_directory_facility feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import people_directory feeds'.
  $permissions['import people_directory feeds'] = array(
    'name' => 'import people_directory feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import scholarship_import feeds'.
  $permissions['import scholarship_import feeds'] = array(
    'name' => 'import scholarship_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manipulate all entityqueues'.
  $permissions['manipulate all entityqueues'] = array(
    'name' => 'manipulate all entityqueues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'manipulate entityqueues'.
  $permissions['manipulate entityqueues'] = array(
    'name' => 'manipulate entityqueues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'migration information'.
  $permissions['migration information'] = array(
    'name' => 'migration information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'migrate',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'authenticated user' => 'authenticated user',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'replicate entities'.
  $permissions['replicate entities'] = array(
    'name' => 'replicate entities',
    'roles' => array(
      'administrator' => 'administrator',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'replicate_ui',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'run security checks'.
  $permissions['run security checks'] = array(
    'name' => 'run security checks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'security_review',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'set workbench schedule for schedule_publishing'.
  $permissions['set workbench schedule for schedule_publishing'] = array(
    'name' => 'set workbench schedule for schedule_publishing',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
      'student worker administrator' => 'student worker administrator',
    ),
    'module' => 'workbench_scheduler',
  );

  // Exported permission: 'set workbench schedule for schedule_recycling'.
  $permissions['set workbench schedule for schedule_recycling'] = array(
    'name' => 'set workbench schedule for schedule_recycling',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
      'student worker administrator' => 'student worker administrator',
    ),
    'module' => 'workbench_scheduler',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'tamper catalog'.
  $permissions['tamper catalog'] = array(
    'name' => 'tamper catalog',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper e2campus'.
  $permissions['tamper e2campus'] = array(
    'name' => 'tamper e2campus',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper faculty_directory'.
  $permissions['tamper faculty_directory'] = array(
    'name' => 'tamper faculty_directory',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper office_directory'.
  $permissions['tamper office_directory'] = array(
    'name' => 'tamper office_directory',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper office_directory_facility'.
  $permissions['tamper office_directory_facility'] = array(
    'name' => 'tamper office_directory_facility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper people_directory'.
  $permissions['tamper people_directory'] = array(
    'name' => 'tamper people_directory',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper scholarship_import'.
  $permissions['tamper scholarship_import'] = array(
    'name' => 'tamper scholarship_import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock catalog feeds'.
  $permissions['unlock catalog feeds'] = array(
    'name' => 'unlock catalog feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock e2campus feeds'.
  $permissions['unlock e2campus feeds'] = array(
    'name' => 'unlock e2campus feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock faculty_directory feeds'.
  $permissions['unlock faculty_directory feeds'] = array(
    'name' => 'unlock faculty_directory feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock office_directory feeds'.
  $permissions['unlock office_directory feeds'] = array(
    'name' => 'unlock office_directory feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock office_directory_facility feeds'.
  $permissions['unlock office_directory_facility feeds'] = array(
    'name' => 'unlock office_directory_facility feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock people_directory feeds'.
  $permissions['unlock people_directory feeds'] = array(
    'name' => 'unlock people_directory feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock scholarship_import feeds'.
  $permissions['unlock scholarship_import feeds'] = array(
    'name' => 'unlock scholarship_import feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'update evergreen_magazine entityqueue'.
  $permissions['update evergreen_magazine entityqueue'] = array(
    'name' => 'update evergreen_magazine entityqueue',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use custom search'.
  $permissions['use custom search'] = array(
    'name' => 'use custom search',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'custom_search',
  );

  // Exported permission: 'use custom search blocks'.
  $permissions['use custom search blocks'] = array(
    'name' => 'use custom search blocks',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'custom_search_blocks',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use media wysiwyg'.
  $permissions['use media wysiwyg'] = array(
    'name' => 'use media wysiwyg',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'media_wysiwyg',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format basic_tags'.
  $permissions['use text format basic_tags'] = array(
    'name' => 'use text format basic_tags',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'authenticated user' => 'authenticated user',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
      'student worker administrator' => 'student worker administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format extended_tags'.
  $permissions['use text format extended_tags'] = array(
    'name' => 'use text format extended_tags',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use workbench_media add form'.
  $permissions['use workbench_media add form'] = array(
    'name' => 'use workbench_media add form',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_media',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view any alternate_background_image bean'.
  $permissions['view any alternate_background_image bean'] = array(
    'name' => 'view any alternate_background_image bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any section_menu bean'.
  $permissions['view any section_menu bean'] = array(
    'name' => 'view any section_menu bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view date repeats'.
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'date_repeat_field',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view post access counter'.
  $permissions['view post access counter'] = array(
    'name' => 'view post access counter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'academics editor' => 'academics editor',
      'administrator' => 'administrator',
      'advanced editor' => 'advanced editor',
      'calendar review' => 'calendar review',
      'news promoter' => 'news promoter',
      'site editor' => 'site editor',
      'student groups' => 'student groups',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view workbench access information'.
  $permissions['view workbench access information'] = array(
    'name' => 'view workbench access information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'view workbench taxonomy pages'.
  $permissions['view workbench taxonomy pages'] = array(
    'name' => 'view workbench taxonomy pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_access',
  );

  return $permissions;
}
