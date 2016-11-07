<?php
/**
 * @file
 * evergreen_migration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function evergreen_migration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'navigation_export';
  $view->description = 'Used to create migration of navigation from dev to live, etc.';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Navigation Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Navigation Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Section Navigation */
  $handler->display->display_options['fields']['field_section_navigation']['id'] = 'field_section_navigation';
  $handler->display->display_options['fields']['field_section_navigation']['table'] = 'field_data_field_section_navigation';
  $handler->display->display_options['fields']['field_section_navigation']['field'] = 'field_section_navigation';
  $handler->display->display_options['fields']['field_section_navigation']['element_type'] = '0';
  $handler->display->display_options['fields']['field_section_navigation']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_section_navigation']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_section_navigation']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_section_navigation']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_section_navigation']['field_api_classes'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'site_sections' => 'site_sections',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['root_node'] = 'sections';
  $handler->display->display_options['style_options']['item_node'] = 'section';
  $handler->display->display_options['path'] = 'export/navigation';
  $export['navigation_export'] = $view;

  return $export;
}
