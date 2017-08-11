<?php
/**
 * @file
 * basic_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function basic_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blog';
  $view->description = '';
  $view->tag = 'content';
  $view->base_table = 'node';
  $view->human_name = 'Blog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'article' => 'article',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'teasers');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Site Section (field_site_section) */
  $handler->display->display_options['arguments']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['arguments']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['vocabularies'] = array(
    'site_sections' => 'site_sections',
  );
  $handler->display->display_options['arguments']['field_site_section_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_section_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_section_tid']['summary_options']['items_per_page'] = '25';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'RSS Feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Site Section (field_site_section) */
  $handler->display->display_options['relationships']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['relationships']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['relationships']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_site_section_tid';
  $handler->display->display_options['arguments']['name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['title'] = '%1';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['path_case'] = 'lower';
  $handler->display->display_options['arguments']['name']['transform_dash'] = TRUE;
  $handler->display->display_options['path'] = 'feeds/%/feed';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Headlines Block */
  $handler = $view->new_display('block', 'Headlines Block', 'headlines');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Site Section (field_site_section) */
  $handler->display->display_options['arguments']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['arguments']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['vocabularies'] = array(
    'site_sections' => 'site_sections',
  );
  $handler->display->display_options['arguments']['field_site_section_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_section_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_section_tid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Site Section (field_site_section) */
  $handler->display->display_options['arguments']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['arguments']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_site_section_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_section_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_section_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'blogs/%';
  $export['blog'] = $view;

  $view = new view();
  $view->name = 'secondary_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Secondary Content';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Secondary Content */
  $handler->display->display_options['fields']['field_secondary_content']['id'] = 'field_secondary_content';
  $handler->display->display_options['fields']['field_secondary_content']['table'] = 'field_data_field_secondary_content';
  $handler->display->display_options['fields']['field_secondary_content']['field'] = 'field_secondary_content';
  $handler->display->display_options['fields']['field_secondary_content']['label'] = '';
  $handler->display->display_options['fields']['field_secondary_content']['element_type'] = '0';
  $handler->display->display_options['fields']['field_secondary_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_secondary_content']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_secondary_content']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_secondary_content']['field_api_classes'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['secondary_content'] = $view;

  $view = new view();
  $view->name = 'site_section_background';
  $view->description = '';
  $view->tag = 'site sections';
  $view->base_table = 'node';
  $view->human_name = 'Site Section Information';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Site Section Background';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Section (as relationship) */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['ui_name'] = 'Section (as relationship)';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'section';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'site_sections' => 'site_sections',
    'calendar_categories' => 0,
    'tags' => 0,
  );
  /* Field: Taxonomy term: Background Image */
  $handler->display->display_options['fields']['field_background_image']['id'] = 'field_background_image';
  $handler->display->display_options['fields']['field_background_image']['table'] = 'field_data_field_background_image';
  $handler->display->display_options['fields']['field_background_image']['field'] = 'field_background_image';
  $handler->display->display_options['fields']['field_background_image']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_background_image']['label'] = '';
  $handler->display->display_options['fields']['field_background_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_background_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_background_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_background_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_background_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_background_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Section Background Block */
  $handler = $view->new_display('block', 'Section Background Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Background Image */
  $handler->display->display_options['fields']['field_background_image']['id'] = 'field_background_image';
  $handler->display->display_options['fields']['field_background_image']['table'] = 'field_data_field_background_image';
  $handler->display->display_options['fields']['field_background_image']['field'] = 'field_background_image';
  $handler->display->display_options['fields']['field_background_image']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_background_image']['label'] = '';
  $handler->display->display_options['fields']['field_background_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_background_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_background_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_background_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_background_image']['empty'] = '<img src="http://evergreen.edu/sites/all/themes/wwwevergreen/images/background.jpg"/>';
  $handler->display->display_options['fields']['field_background_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_background_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );

  /* Display: Section Title Block */
  $handler = $view->new_display('block', 'Section Title Block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Site Section */
  $handler->display->display_options['fields']['field_site_section']['id'] = 'field_site_section';
  $handler->display->display_options['fields']['field_site_section']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['fields']['field_site_section']['field'] = 'field_site_section';
  $handler->display->display_options['fields']['field_site_section']['label'] = '';
  $handler->display->display_options['fields']['field_site_section']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_site_section']['element_type'] = 'h1';
  $handler->display->display_options['fields']['field_site_section']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_site_section']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_site_section']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_site_section']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Taxonomy term: Long Name */
  $handler->display->display_options['fields']['field_long_name']['id'] = 'field_long_name';
  $handler->display->display_options['fields']['field_long_name']['table'] = 'field_data_field_long_name';
  $handler->display->display_options['fields']['field_long_name']['field'] = 'field_long_name';
  $handler->display->display_options['fields']['field_long_name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_long_name']['label'] = '';
  $handler->display->display_options['fields']['field_long_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_long_name']['alter']['path'] = '[field_site_section]';
  $handler->display->display_options['fields']['field_long_name']['element_type'] = 'h1';
  $handler->display->display_options['fields']['field_long_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_long_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_long_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_long_name']['field_api_classes'] = TRUE;

  /* Display: Section Navigation */
  $handler = $view->new_display('block', 'Section Navigation', 'nav');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'no nav';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'there\'s no nav here. What now?';
  $handler->display->display_options['empty']['area']['format'] = 'basic_tags';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Section Navigation */
  $handler->display->display_options['fields']['field_section_navigation']['id'] = 'field_section_navigation';
  $handler->display->display_options['fields']['field_section_navigation']['table'] = 'field_data_field_section_navigation';
  $handler->display->display_options['fields']['field_section_navigation']['field'] = 'field_section_navigation';
  $handler->display->display_options['fields']['field_section_navigation']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_section_navigation']['label'] = '';
  $handler->display->display_options['fields']['field_section_navigation']['element_type'] = '0';
  $handler->display->display_options['fields']['field_section_navigation']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_section_navigation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_section_navigation']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_section_navigation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_section_navigation']['empty'] = ' ';
  $handler->display->display_options['fields']['field_section_navigation']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_section_navigation']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_section_navigation']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_section_navigation']['separator'] = '';
  $handler->display->display_options['fields']['field_section_navigation']['field_api_classes'] = TRUE;
  /* Field: Taxonomy term: Term edit link */
  $handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['edit_term']['label'] = '';
  $handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_term']['text'] = 'Edit this site\'s info';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $export['site_section_background'] = $view;

  return $export;
}
