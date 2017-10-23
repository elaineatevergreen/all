<?php
/**
 * @file
 * evergreen_policies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function evergreen_policies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'policies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Policies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Policies - Bulk Editing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_categories',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_categories' => 'field_categories',
    'field_external_policy' => 'field_external_policy',
    'field_prefix' => 'field_prefix',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_categories' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_external_policy' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_prefix' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = '';
  $handler->display->display_options['fields']['field_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_categories']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Prefix */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: External Policy */
  $handler->display->display_options['fields']['field_external_policy']['id'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['table'] = 'field_data_field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['field'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_policy']['type'] = 'link_url';
  /* Sort criterion: Content: Categories (field_categories) */
  $handler->display->display_options['sorts']['field_categories_target_id']['id'] = 'field_categories_target_id';
  $handler->display->display_options['sorts']['field_categories_target_id']['table'] = 'field_data_field_categories';
  $handler->display->display_options['sorts']['field_categories_target_id']['field'] = 'field_categories_target_id';
  /* Sort criterion: Content: Prefix (field_prefix) */
  $handler->display->display_options['sorts']['field_prefix_value']['id'] = 'field_prefix_value';
  $handler->display->display_options['sorts']['field_prefix_value']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['sorts']['field_prefix_value']['field'] = 'field_prefix_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'policy' => 'policy',
  );

  /* Display: Index by Category */
  $handler = $view->new_display('page', 'Index by Category', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'College Policies';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_categories',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p class="intro">All current official versions of college policies are found here.</p> 

This web site replaces all previous printed Policy and Procedures Manuals. 

Each policy has a clearly identified Steward who keeps the policy current. For questions about a specific policy, please contact the Steward.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = '';
  $handler->display->display_options['fields']['field_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_categories']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Prefix */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: External Policy */
  $handler->display->display_options['fields']['field_external_policy']['id'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['table'] = 'field_data_field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['field'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['label'] = '';
  $handler->display->display_options['fields']['field_external_policy']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_external_policy']['alter']['text'] = '[field_prefix] <a href="[field_external_policy-url]">[title]</a> <small>[field_external_policy-url]</small>';
  $handler->display->display_options['fields']['field_external_policy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_external_policy']['empty'] = '[field_prefix] <a href="[path]">[title]</a>';
  $handler->display->display_options['fields']['field_external_policy']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_policy']['type'] = 'link_url';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'policy' => 'policy',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Archived (field_archived) */
  $handler->display->display_options['filters']['field_archived_value']['id'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['table'] = 'field_data_field_archived';
  $handler->display->display_options['filters']['field_archived_value']['field'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archived_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_archived_value']['group'] = 1;
  $handler->display->display_options['path'] = 'test/policies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Policies and Procedures Home';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'menu-polices-and-procedures';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Bulk Edit Page */
  $handler = $view->new_display('page', 'Bulk Edit Page', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Bulk Editing',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'policy::field_effective_date' => 'policy::field_effective_date',
          'policy::field_steward' => 'policy::field_steward',
          'policy::field_approval_authority' => 'policy::field_approval_authority',
          'policy::field_related_policies' => 'policy::field_related_policies',
          'policy::field_related_documents' => 'policy::field_related_documents',
          'policy::field_approval_date' => 'policy::field_approval_date',
          'policy::field_categories' => 'policy::field_categories',
          'policy::field_archived' => 'policy::field_archived',
        ),
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_categories']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_categories']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: External Policy */
  $handler->display->display_options['fields']['field_external_policy']['id'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['table'] = 'field_data_field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['field'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_policy']['type'] = 'link_url';
  /* Field: Content: Prefix */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['path'] = 'admin/policies/bulk-edit';

  /* Display: Entity Reference (active) */
  $handler = $view->new_display('entityreference', 'Entity Reference (active)', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_categories' => 0,
    'field_prefix' => 0,
    'path' => 0,
    'field_external_policy' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'policy' => 'policy',
  );
  /* Filter criterion: Content: Archived (field_archived) */
  $handler->display->display_options['filters']['field_archived_value']['id'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['table'] = 'field_data_field_archived';
  $handler->display->display_options['filters']['field_archived_value']['field'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archived_value']['value'] = array(
    1 => '1',
  );

  /* Display: Entity Reference (archived) */
  $handler = $view->new_display('entityreference', 'Entity Reference (archived)', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_categories' => 0,
    'field_prefix' => 0,
    'path' => 0,
    'field_external_policy' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'policy' => 'policy',
  );
  /* Filter criterion: Content: Archived (field_archived) */
  $handler->display->display_options['filters']['field_archived_value']['id'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['table'] = 'field_data_field_archived';
  $handler->display->display_options['filters']['field_archived_value']['field'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['value'] = array(
    1 => '1',
  );

  /* Display: A-Z Index */
  $handler = $view->new_display('page', 'A-Z Index', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Policies A-Z';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p class="intro">All current official versions of college policies are found here.</p> 

This web site replaces all previous printed Policy and Procedures Manuals. 

Each policy has a clearly identified Steward who keeps the policy current. For questions about a specific policy, please contact the Steward.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = '';
  $handler->display->display_options['fields']['field_categories']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_categories']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Prefix */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: External Policy */
  $handler->display->display_options['fields']['field_external_policy']['id'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['table'] = 'field_data_field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['field'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['label'] = '';
  $handler->display->display_options['fields']['field_external_policy']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_external_policy']['alter']['text'] = '[field_prefix] <a href="[field_external_policy-url]">[title]</a> <small>[field_external_policy-url]</small>';
  $handler->display->display_options['fields']['field_external_policy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_external_policy']['empty'] = '[field_prefix] <a href="[path]">[title]</a>';
  $handler->display->display_options['fields']['field_external_policy']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_policy']['type'] = 'link_url';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'default';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = 'a';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'policy' => 'policy',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Archived (field_archived) */
  $handler->display->display_options['filters']['field_archived_value']['id'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['table'] = 'field_data_field_archived';
  $handler->display->display_options['filters']['field_archived_value']['field'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archived_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_archived_value']['group'] = 1;
  $handler->display->display_options['path'] = 'test/policies/az';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Policies and Procedures Home';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'menu-polices-and-procedures';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['summary_options']['inline'] = TRUE;
  $handler->display->display_options['arguments']['title']['summary_options']['separator'] = ' | ';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'lower';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'policy' => 'policy',
  );
  /* Filter criterion: Content: Archived (field_archived) */
  $handler->display->display_options['filters']['field_archived_value']['id'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['table'] = 'field_data_field_archived';
  $handler->display->display_options['filters']['field_archived_value']['field'] = 'field_archived_value';
  $handler->display->display_options['filters']['field_archived_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_archived_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['displays'] = array(
    'page_3' => 'page_3',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $export['policies'] = $view;

  $view = new view();
  $view->name = 'policies_category_pages';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Policy Category Pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Prefix */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_prefix']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: External Policy */
  $handler->display->display_options['fields']['field_external_policy']['id'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['table'] = 'field_data_field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['field'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['label'] = '';
  $handler->display->display_options['fields']['field_external_policy']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_external_policy']['alter']['text'] = '[field_prefix] <a href="[field_external_policy-url]">[title]</a> <small>[field_external_policy-url]</small>';
  $handler->display->display_options['fields']['field_external_policy']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_external_policy']['empty'] = '[field_prefix] <a href="[path]">[title]</a>';
  $handler->display->display_options['fields']['field_external_policy']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_external_policy']['type'] = 'link_url';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Prefix (field_prefix) */
  $handler->display->display_options['sorts']['field_prefix_value']['id'] = 'field_prefix_value';
  $handler->display->display_options['sorts']['field_prefix_value']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['sorts']['field_prefix_value']['field'] = 'field_prefix_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['policies_category_pages'] = $view;

  $view = new view();
  $view->name = 'policies_menu';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Policy Categories Menu';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Policy Sections';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'policy_categories' => 'policy_categories',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['policies_menu'] = $view;

  $view = new view();
  $view->name = 'policy_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Policy Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Approval Authority */
  $handler->display->display_options['fields']['field_approval_authority']['id'] = 'field_approval_authority';
  $handler->display->display_options['fields']['field_approval_authority']['table'] = 'field_data_field_approval_authority';
  $handler->display->display_options['fields']['field_approval_authority']['field'] = 'field_approval_authority';
  /* Field: Content: Approval Date */
  $handler->display->display_options['fields']['field_approval_date']['id'] = 'field_approval_date';
  $handler->display->display_options['fields']['field_approval_date']['table'] = 'field_data_field_approval_date';
  $handler->display->display_options['fields']['field_approval_date']['field'] = 'field_approval_date';
  $handler->display->display_options['fields']['field_approval_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Archived */
  $handler->display->display_options['fields']['field_archived']['id'] = 'field_archived';
  $handler->display->display_options['fields']['field_archived']['table'] = 'field_data_field_archived';
  $handler->display->display_options['fields']['field_archived']['field'] = 'field_archived';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Effective Date */
  $handler->display->display_options['fields']['field_effective_date']['id'] = 'field_effective_date';
  $handler->display->display_options['fields']['field_effective_date']['table'] = 'field_data_field_effective_date';
  $handler->display->display_options['fields']['field_effective_date']['field'] = 'field_effective_date';
  $handler->display->display_options['fields']['field_effective_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: External Policy */
  $handler->display->display_options['fields']['field_external_policy']['id'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['table'] = 'field_data_field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['field'] = 'field_external_policy';
  $handler->display->display_options['fields']['field_external_policy']['click_sort_column'] = 'url';
  /* Field: Content: Prefix */
  $handler->display->display_options['fields']['field_prefix']['id'] = 'field_prefix';
  $handler->display->display_options['fields']['field_prefix']['table'] = 'field_data_field_prefix';
  $handler->display->display_options['fields']['field_prefix']['field'] = 'field_prefix';
  /* Field: Content: Previous Version */
  $handler->display->display_options['fields']['field_previous_version']['id'] = 'field_previous_version';
  $handler->display->display_options['fields']['field_previous_version']['table'] = 'field_data_field_previous_version';
  $handler->display->display_options['fields']['field_previous_version']['field'] = 'field_previous_version';
  $handler->display->display_options['fields']['field_previous_version']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Related Documents */
  $handler->display->display_options['fields']['field_related_documents']['id'] = 'field_related_documents';
  $handler->display->display_options['fields']['field_related_documents']['table'] = 'field_data_field_related_documents';
  $handler->display->display_options['fields']['field_related_documents']['field'] = 'field_related_documents';
  $handler->display->display_options['fields']['field_related_documents']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_related_documents']['delta_offset'] = '0';
  /* Field: Content: Related Documents (field_related_documents:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_related_documents';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  /* Field: Content: Related Policies */
  $handler->display->display_options['fields']['field_related_policies']['id'] = 'field_related_policies';
  $handler->display->display_options['fields']['field_related_policies']['table'] = 'field_data_field_related_policies';
  $handler->display->display_options['fields']['field_related_policies']['field'] = 'field_related_policies';
  $handler->display->display_options['fields']['field_related_policies']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_related_policies']['delta_offset'] = '0';
  /* Field: Content: Signature File */
  $handler->display->display_options['fields']['field_signature_file']['id'] = 'field_signature_file';
  $handler->display->display_options['fields']['field_signature_file']['table'] = 'field_data_field_signature_file';
  $handler->display->display_options['fields']['field_signature_file']['field'] = 'field_signature_file';
  $handler->display->display_options['fields']['field_signature_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_signature_file']['delta_offset'] = '0';
  /* Field: Content: Steward */
  $handler->display->display_options['fields']['field_steward']['id'] = 'field_steward';
  $handler->display->display_options['fields']['field_steward']['table'] = 'field_data_field_steward';
  $handler->display->display_options['fields']['field_steward']['field'] = 'field_steward';
  /* Field: Content: Stub */
  $handler->display->display_options['fields']['field_stub']['id'] = 'field_stub';
  $handler->display->display_options['fields']['field_stub']['table'] = 'field_data_field_stub';
  $handler->display->display_options['fields']['field_stub']['field'] = 'field_stub';
  /* Field: Content: Updated Version */
  $handler->display->display_options['fields']['field_updated_version']['id'] = 'field_updated_version';
  $handler->display->display_options['fields']['field_updated_version']['table'] = 'field_data_field_updated_version';
  $handler->display->display_options['fields']['field_updated_version']['field'] = 'field_updated_version';
  $handler->display->display_options['fields']['field_updated_version']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'policy' => 'policy',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/export/test';
  $export['policy_export'] = $view;

  return $export;
}
