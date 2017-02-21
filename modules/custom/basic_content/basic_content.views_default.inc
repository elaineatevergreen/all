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

  return $export;
}
