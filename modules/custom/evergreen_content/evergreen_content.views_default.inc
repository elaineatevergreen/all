<?php
/**
 * @file
 * evergreen_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function evergreen_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'alerts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Alerts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
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
    'alert' => 'alert',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['alerts'] = $view;

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

  /* Display: Home Page News */
  $handler = $view->new_display('block', 'Home Page News', 'home');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Evergreen News';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'unit-1-3';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Published';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Read More.';
  $handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[view_node]';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read the whole story.';
  /* Field: Content: Blurb */
  $handler->display->display_options['fields']['field_blurb']['id'] = 'field_blurb';
  $handler->display->display_options['fields']['field_blurb']['table'] = 'field_data_field_blurb';
  $handler->display->display_options['fields']['field_blurb']['field'] = 'field_blurb';
  $handler->display->display_options['fields']['field_blurb']['label'] = '';
  $handler->display->display_options['fields']['field_blurb']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blurb']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['field_blurb']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_blurb']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_blurb']['element_type'] = '0';
  $handler->display->display_options['fields']['field_blurb']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blurb']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_blurb']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_blurb']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['field_blurb']['field_api_classes'] = TRUE;
  /* Field: Content with wrapping HTML */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Content with wrapping HTML';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<article class="news-story">
<div class="media media-column">
<div class="media-img">[field_image]</div>
<div class="media-body">
<h4>[title]</h4>
<p><small>Published: [created]</small></p>
[field_blurb]
<p>[view_node]</p>
</div>
</div>
</article>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
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
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Site Section (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    0 => '189',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'site_sections';

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
  $view->name = 'calendar';
  $view->description = '';
  $view->tag = 'content';
  $view->base_table = 'node';
  $view->human_name = 'Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Official Holidays';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date']['field_api_classes'] = TRUE;
  /* Sort criterion: Content: Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value2']['group'] = 1;

  /* Display: Home Page */
  $handler = $view->new_display('page', 'Home Page', 'page_home');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Campus Events Calendar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'unit-1-6';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'element-list grid upcoming-events-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'unit-6-7';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Month */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Month';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Day */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['ui_name'] = 'Day';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'day',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Formatted Date */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Formatted Date';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="calendar-dt"><span class="calendar-month">[field_date_1]</span> <span class="calendar-day">[field_date]</span></div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'media-img';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'p';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'media-body';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Formatted All The Things */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Formatted All The Things';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[nothing] [title]';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'media media-column';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Date - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value2']['group'] = 1;
  $handler->display->display_options['path'] = 'home-calendar';

  /* Display: Headlines Block */
  $handler = $view->new_display('block', 'Headlines Block', 'headlines');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Site Section (field_site_section) */
  $handler->display->display_options['arguments']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['arguments']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_site_section_tid']['exception']['value'] = '20';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_site_section_tid']['default_argument_options']['vocabularies'] = array(
    'site_sections' => 'site_sections',
  );
  $handler->display->display_options['arguments']['field_site_section_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_site_section_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_site_section_tid']['summary_options']['items_per_page'] = '25';

  /* Display: Holidays */
  $handler = $view->new_display('block', 'Holidays', 'holidays');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_date' => 'field_date',
  );
  $handler->display->display_options['row_options']['separator'] = ': ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long_no_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Year */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Year';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['click_sort_column'] = 'value2';
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Configured text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Configured text';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title]: [field_date]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'event' => 'event',
  );
  /* Filter criterion: Content: Date -  start date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  /* Filter criterion: Content: Calendar Categories (field_calendar_categories) */
  $handler->display->display_options['filters']['field_calendar_categories_tid']['id'] = 'field_calendar_categories_tid';
  $handler->display->display_options['filters']['field_calendar_categories_tid']['table'] = 'field_data_field_calendar_categories';
  $handler->display->display_options['filters']['field_calendar_categories_tid']['field'] = 'field_calendar_categories_tid';
  $handler->display->display_options['filters']['field_calendar_categories_tid']['value'] = array(
    25 => '25',
  );
  $handler->display->display_options['filters']['field_calendar_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_calendar_categories_tid']['vocabulary'] = 'calendar_categories';

  /* Display: Academic Calendar */
  $handler = $view->new_display('block', 'Academic Calendar', 'academic');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_date' => 'field_date',
    'field_building' => 'field_date',
    'field_room' => 'field_date',
    'body' => 'field_date',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_building' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_room' => array(
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
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
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long_no_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date']['field_api_classes'] = TRUE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Calendar Categories (field_calendar_categories) */
  $handler->display->display_options['filters']['field_calendar_categories_tid']['id'] = 'field_calendar_categories_tid';
  $handler->display->display_options['filters']['field_calendar_categories_tid']['table'] = 'field_data_field_calendar_categories';
  $handler->display->display_options['filters']['field_calendar_categories_tid']['field'] = 'field_calendar_categories_tid';
  $handler->display->display_options['filters']['field_calendar_categories_tid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['field_calendar_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_calendar_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_calendar_categories_tid']['vocabulary'] = 'calendar_categories';
  /* Filter criterion: Content: Date - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value2']['group'] = 1;

  /* Display: Home Block */
  $handler = $view->new_display('block', 'Home Block', 'home');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'unit-1-7';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Month */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['ui_name'] = 'Month';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_date']['element_class'] = 'calendar-month';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'monthabbr',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Day */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Day';
  $handler->display->display_options['fields']['field_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_date_1']['element_class'] = 'calendar-day';
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'day',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'p';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'media-body';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="media media-column">
	<div class="media-img"><div class="calendar-dt">
		<span class="calendar-month">[field_date]</span>
		<span class="calendar-day">[field_date_1]</span>
	</div></div>
	<div class="media-body">
		<p>[title]</p>
	</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date - end date (field_date:value2) */
  $handler->display->display_options['filters']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value2']['field'] = 'field_date_value2';
  $handler->display->display_options['filters']['field_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value2']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $export['calendar'] = $view;

  $view = new view();
  $view->name = 'catalog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Catalog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Academic Catalog (2015-16 Undergrad)';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_offering_type' => 'field_offering_type',
    'field_class_standing' => 'field_class_standing',
    'field_time_offered' => 'field_time_offered',
    'field_faculty' => 'title',
    'field_terms' => 'field_terms',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
    'field_offering_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_class_standing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_time_offered' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_faculty' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_terms' => array(
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
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'program-title';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Offering Type */
  $handler->display->display_options['fields']['field_offering_type']['id'] = 'field_offering_type';
  $handler->display->display_options['fields']['field_offering_type']['table'] = 'field_data_field_offering_type';
  $handler->display->display_options['fields']['field_offering_type']['field'] = 'field_offering_type';
  $handler->display->display_options['fields']['field_offering_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_offering_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_offering_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_offering_type']['field_api_classes'] = TRUE;
  /* Field: Content: Class Standing */
  $handler->display->display_options['fields']['field_class_standing']['id'] = 'field_class_standing';
  $handler->display->display_options['fields']['field_class_standing']['table'] = 'field_data_field_class_standing';
  $handler->display->display_options['fields']['field_class_standing']['field'] = 'field_class_standing';
  $handler->display->display_options['fields']['field_class_standing']['element_type'] = '0';
  $handler->display->display_options['fields']['field_class_standing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_class_standing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_class_standing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_class_standing']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_class_standing']['field_api_classes'] = TRUE;
  /* Field: Content: Time Offered */
  $handler->display->display_options['fields']['field_time_offered']['id'] = 'field_time_offered';
  $handler->display->display_options['fields']['field_time_offered']['table'] = 'field_data_field_time_offered';
  $handler->display->display_options['fields']['field_time_offered']['field'] = 'field_time_offered';
  $handler->display->display_options['fields']['field_time_offered']['element_type'] = '0';
  $handler->display->display_options['fields']['field_time_offered']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_time_offered']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_time_offered']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_time_offered']['field_api_classes'] = TRUE;
  /* Field: Content: Faculty */
  $handler->display->display_options['fields']['field_faculty']['id'] = 'field_faculty';
  $handler->display->display_options['fields']['field_faculty']['table'] = 'field_data_field_faculty';
  $handler->display->display_options['fields']['field_faculty']['field'] = 'field_faculty';
  $handler->display->display_options['fields']['field_faculty']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_faculty']['element_class'] = 'faculty';
  $handler->display->display_options['fields']['field_faculty']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_faculty']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_faculty']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty']['separator'] = '; ';
  /* Field: Content: Terms */
  $handler->display->display_options['fields']['field_terms']['id'] = 'field_terms';
  $handler->display->display_options['fields']['field_terms']['table'] = 'field_data_field_terms';
  $handler->display->display_options['fields']['field_terms']['field'] = 'field_terms';
  $handler->display->display_options['fields']['field_terms']['label'] = 'Quarters Offered';
  $handler->display->display_options['fields']['field_terms']['element_type'] = '0';
  $handler->display->display_options['fields']['field_terms']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_terms']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_terms']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_terms']['settings'] = array(
    'view_mode' => 'summary',
  );
  $handler->display->display_options['fields']['field_terms']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_terms']['field_api_classes'] = TRUE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
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
    'catalog_entry' => 'catalog_entry',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Class Standing (field_class_standing) */
  $handler->display->display_options['filters']['field_class_standing_value']['id'] = 'field_class_standing_value';
  $handler->display->display_options['filters']['field_class_standing_value']['table'] = 'field_data_field_class_standing';
  $handler->display->display_options['filters']['field_class_standing_value']['field'] = 'field_class_standing_value';
  $handler->display->display_options['filters']['field_class_standing_value']['group'] = 1;
  $handler->display->display_options['filters']['field_class_standing_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['operator_id'] = 'field_class_standing_value_op';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['label'] = 'Class Standing';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['operator'] = 'field_class_standing_value_op';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['identifier'] = 'field_class_standing_value';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Time Offered (field_time_offered) */
  $handler->display->display_options['filters']['field_time_offered_value']['id'] = 'field_time_offered_value';
  $handler->display->display_options['filters']['field_time_offered_value']['table'] = 'field_data_field_time_offered';
  $handler->display->display_options['filters']['field_time_offered_value']['field'] = 'field_time_offered_value';
  $handler->display->display_options['filters']['field_time_offered_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_time_offered_value']['expose']['operator_id'] = 'field_time_offered_value_op';
  $handler->display->display_options['filters']['field_time_offered_value']['expose']['label'] = 'Offered During';
  $handler->display->display_options['filters']['field_time_offered_value']['expose']['operator'] = 'field_time_offered_value_op';
  $handler->display->display_options['filters']['field_time_offered_value']['expose']['identifier'] = 'field_time_offered_value';
  $handler->display->display_options['filters']['field_time_offered_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search title/description';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'catalog/index';
  $export['catalog'] = $view;

  $view = new view();
  $view->name = 'content_audits';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content Audits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content Audits';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'content-audits';

  /* Display: Duplicate Titles */
  $handler = $view->new_display('page', 'Duplicate Titles', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Duplicate Page Titles';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary with an additional token to change the items/page */
  $handler->display->display_options['header']['webform_result']['id'] = 'webform_result';
  $handler->display->display_options['header']['webform_result']['table'] = 'views';
  $handler->display->display_options['header']['webform_result']['field'] = 'webform_result';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: COUNT(Content: Nid) */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group_type'] = 'count';
  $handler->display->display_options['filters']['nid']['operator'] = '>';
  $handler->display->display_options['filters']['nid']['value']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'basic_page' => 'basic_page',
  );
  $handler->display->display_options['path'] = 'duplicate-titles';
  $export['content_audits'] = $view;

  $view = new view();
  $view->name = 'database_of_databases';
  $view->description = '';
  $view->tag = 'content';
  $view->base_table = 'node';
  $view->human_name = 'Database of Databases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Database of Databases';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'promote' => 'promote',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'promote' => array(
      'sortable' => 1,
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
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Promoted to front page */
  $handler->display->display_options['fields']['promote']['id'] = 'promote';
  $handler->display->display_options['fields']['promote']['table'] = 'node';
  $handler->display->display_options['fields']['promote']['field'] = 'promote';
  $handler->display->display_options['fields']['promote']['label'] = '★';
  $handler->display->display_options['fields']['promote']['type'] = 'custom';
  $handler->display->display_options['fields']['promote']['type_custom_true'] = '★';
  $handler->display->display_options['fields']['promote']['not'] = 0;
  /* Field: Content: Resource Link */
  $handler->display->display_options['fields']['field_resource_link']['id'] = 'field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['table'] = 'field_data_field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['field'] = 'field_resource_link';
  $handler->display->display_options['fields']['field_resource_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_resource_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_resource_link']['type'] = 'link_plain';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Name and Description';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<strong><a href="[field_resource_link]">[title]</a></strong>
[body]';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Content: Promoted to front page */
  $handler->display->display_options['sorts']['promote']['id'] = 'promote';
  $handler->display->display_options['sorts']['promote']['table'] = 'node';
  $handler->display->display_options['sorts']['promote']['field'] = 'promote';
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
    'library_database' => 'library_database',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_resource_subject_value']['id'] = 'field_resource_subject_value';
  $handler->display->display_options['filters']['field_resource_subject_value']['table'] = 'field_data_field_resource_subject';
  $handler->display->display_options['filters']['field_resource_subject_value']['field'] = 'field_resource_subject_value';
  $handler->display->display_options['filters']['field_resource_subject_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resource_subject_value']['expose']['operator_id'] = 'field_resource_subject_value_op';
  $handler->display->display_options['filters']['field_resource_subject_value']['expose']['label'] = 'Subjects';
  $handler->display->display_options['filters']['field_resource_subject_value']['expose']['operator'] = 'field_resource_subject_value_op';
  $handler->display->display_options['filters']['field_resource_subject_value']['expose']['identifier'] = 'field_resource_subject_value';
  $handler->display->display_options['filters']['field_resource_subject_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['database_of_databases'] = $view;

  $view = new view();
  $view->name = 'directory';
  $view->description = '';
  $view->tag = 'content';
  $view->base_table = 'node';
  $view->human_name = 'Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Directory';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_last_name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_job_title' => 'title',
    'field_email' => 'field_email',
    'field_building_alt' => 'field_room',
    'field_room' => 'field_room',
    'field_mailstop' => 'field_mailstop',
    'field_phone' => 'field_phone',
    'field_alternate_phone' => 'field_alternate_phone',
    'field_fax' => 'field_fax',
    'nothing' => 'nothing',
    'field_last_name' => 'field_last_name',
    'field_website' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'field_job_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_building_alt' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_room' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_mailstop' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_alternate_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fax' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_website' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['alter']['text'] = ', [field_job_title]';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['delta_offset'] = '0';
  /* Field: Content: Building */
  $handler->display->display_options['fields']['field_building_alt']['id'] = 'field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['table'] = 'field_data_field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['field'] = 'field_building_alt';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['label'] = 'Location';
  /* Field: Content: Mailstop */
  $handler->display->display_options['fields']['field_mailstop']['id'] = 'field_mailstop';
  $handler->display->display_options['fields']['field_mailstop']['table'] = 'field_data_field_mailstop';
  $handler->display->display_options['fields']['field_mailstop']['field'] = 'field_mailstop';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  /* Field: Content: Alternate Phone */
  $handler->display->display_options['fields']['field_alternate_phone']['id'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['table'] = 'field_data_field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['field'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_phone']['alter']['text'] = '<abbr title="Alternate phone number">Alt.</abbr>: [field_alternate_phone]';
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['text'] = 'Fax: [field_fax]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Phone';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_phone]<br/>
[field_alternate_phone]<br/>
[field_fax]';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Last initial';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_last_name']['settings'] = array(
    'trim_length' => '1',
  );
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['element_type'] = '0';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_website']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_url';
  $handler->display->display_options['fields']['field_website']['field_api_classes'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Last name (field_last_name) */
  $handler->display->display_options['arguments']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['arguments']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['arguments']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['arguments']['field_last_name_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_last_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_last_name_value']['default_argument_options']['argument'] = 'A';
  $handler->display->display_options['arguments']['field_last_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_last_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_last_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_last_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_last_name_value']['limit'] = '1';
  $handler->display->display_options['arguments']['field_last_name_value']['path_case'] = 'lower';
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
    'directory_individual' => 'directory_individual',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: People Page */
  $handler = $view->new_display('page', 'People Page', 'people_page');
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
    'directory_individual' => 'directory_individual',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search by name or title';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_job_title' => 'field_job_title',
  );
  $handler->display->display_options['path'] = 'directory/people';

  /* Display: People A-Z Index */
  $handler = $view->new_display('attachment', 'People A-Z Index', 'people_index');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_job_title' => 'field_job_title',
    'field_email' => 'field_email',
    'field_room' => 'field_room',
    'field_mailstop' => 'field_mailstop',
    'field_phone' => 'field_phone',
    'field_alternate_phone' => 'field_alternate_phone',
    'nothing' => 'nothing',
    'field_last_name' => 'field_last_name',
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
    'field_job_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_room' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mailstop' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_alternate_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'People';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Last name (field_last_name) */
  $handler->display->display_options['arguments']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['arguments']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['arguments']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['arguments']['field_last_name_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_last_name_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_last_name_value']['default_argument_options']['argument'] = 'A';
  $handler->display->display_options['arguments']['field_last_name_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_last_name_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_last_name_value']['summary_options']['base_path'] = 'directory/people';
  $handler->display->display_options['arguments']['field_last_name_value']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['field_last_name_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_last_name_value']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['field_last_name_value']['limit'] = '1';
  $handler->display->display_options['displays'] = array(
    'people_page' => 'people_page',
    'default' => 0,
    'block' => 0,
    'staff_table' => 0,
    'staff_list' => 0,
    'office_page' => 0,
    'faculty_page' => 0,
    'faculty_missing_directory' => 0,
    'page_1' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: Staff Table Block */
  $handler = $view->new_display('block', 'Staff Table Block', 'staff_table');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Our Staff';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_job_title' => 'title',
    'field_email' => 'field_email',
    'field_building_alt' => 'field_room',
    'field_room' => 'field_room',
    'field_mailstop' => 'field_mailstop',
    'field_phone' => 'field_phone',
    'field_alternate_phone' => 'field_alternate_phone',
    'field_fax' => 'field_fax',
    'nothing' => 'nothing',
    'field_last_name' => 'field_last_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'field_job_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_building_alt' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_room' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_mailstop' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_alternate_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fax' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['alter']['text'] = ', [field_job_title]';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['delta_offset'] = '0';
  /* Field: Content: Building */
  $handler->display->display_options['fields']['field_building_alt']['id'] = 'field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['table'] = 'field_data_field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['field'] = 'field_building_alt';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['label'] = 'Location';
  /* Field: Content: Mailstop */
  $handler->display->display_options['fields']['field_mailstop']['id'] = 'field_mailstop';
  $handler->display->display_options['fields']['field_mailstop']['table'] = 'field_data_field_mailstop';
  $handler->display->display_options['fields']['field_mailstop']['field'] = 'field_mailstop';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  /* Field: Content: Alternate Phone */
  $handler->display->display_options['fields']['field_alternate_phone']['id'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['table'] = 'field_data_field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['field'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_phone']['alter']['text'] = 'Alt: [field_alternate_phone]';
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['text'] = 'Fax: [field_fax]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Phone';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_phone]<br/>
[field_alternate_phone]<br/>
[field_fax]';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Last initial';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_last_name']['settings'] = array(
    'trim_length' => '1',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Feeds item: Item GUID */
  $handler->display->display_options['arguments']['guid']['id'] = 'guid';
  $handler->display->display_options['arguments']['guid']['table'] = 'feeds_item';
  $handler->display->display_options['arguments']['guid']['field'] = 'guid';
  $handler->display->display_options['arguments']['guid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['guid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['guid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['guid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['guid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['guid']['limit'] = '0';
  $handler->display->display_options['arguments']['guid']['break_phrase'] = TRUE;

  /* Display: Staff List Block */
  $handler = $view->new_display('block', 'Staff List Block', 'staff_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Our Staff';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name_1' => 'field_last_name_1',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_last_name_1']['id'] = 'field_last_name_1';
  $handler->display->display_options['fields']['field_last_name_1']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['label'] = '';
  $handler->display->display_options['fields']['field_last_name_1']['element_label_colon'] = FALSE;
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['alter']['text'] = ', [field_job_title]';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['delta_offset'] = '0';
  /* Field: Content: Building */
  $handler->display->display_options['fields']['field_building_alt']['id'] = 'field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['table'] = 'field_data_field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['field'] = 'field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['label'] = '';
  $handler->display->display_options['fields']['field_building_alt']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_building_alt']['element_label_colon'] = FALSE;
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['label'] = 'Location';
  $handler->display->display_options['fields']['field_room']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_room']['alter']['text'] = '[field_building_alt] [field_room]';
  $handler->display->display_options['fields']['field_room']['element_type'] = '0';
  $handler->display->display_options['fields']['field_room']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_room']['element_default_classes'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  /* Field: Content: Alternate Phone */
  $handler->display->display_options['fields']['field_alternate_phone']['id'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['table'] = 'field_data_field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['field'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_phone']['alter']['text'] = 'Alt: [field_alternate_phone]';
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['text'] = 'Fax: [field_fax]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Phone';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_phone]<br/>
[field_alternate_phone]<br/>
[field_fax]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Feeds item: Item GUID */
  $handler->display->display_options['arguments']['guid']['id'] = 'guid';
  $handler->display->display_options['arguments']['guid']['table'] = 'feeds_item';
  $handler->display->display_options['arguments']['guid']['field'] = 'guid';
  $handler->display->display_options['arguments']['guid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['guid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['guid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['guid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['guid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['guid']['limit'] = '0';
  $handler->display->display_options['arguments']['guid']['break_phrase'] = TRUE;

  /* Display: Office Page */
  $handler = $view->new_display('page', 'Office Page', 'office_page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'ui-group';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_reference' => 'field_reference',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Reference */
  $handler->display->display_options['fields']['field_reference']['id'] = 'field_reference';
  $handler->display->display_options['fields']['field_reference']['table'] = 'field_data_field_reference';
  $handler->display->display_options['fields']['field_reference']['field'] = 'field_reference';
  $handler->display->display_options['fields']['field_reference']['label'] = 'See';
  $handler->display->display_options['fields']['field_reference']['element_type'] = '0';
  $handler->display->display_options['fields']['field_reference']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_reference']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_reference']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_reference']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Building */
  $handler->display->display_options['fields']['field_building_alt']['id'] = 'field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['table'] = 'field_data_field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['field'] = 'field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_building_alt']['hide_empty'] = TRUE;
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['label'] = 'Office';
  $handler->display->display_options['fields']['field_room']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_room']['alter']['text'] = '[field_building_alt] [field_room]';
  $handler->display->display_options['fields']['field_room']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_room']['element_class'] = 'p-name';
  $handler->display->display_options['fields']['field_room']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_room']['element_label_class'] = 'dir-key';
  $handler->display->display_options['fields']['field_room']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_room']['hide_empty'] = TRUE;
  /* Field: Content: Mailstop */
  $handler->display->display_options['fields']['field_mailstop']['id'] = 'field_mailstop';
  $handler->display->display_options['fields']['field_mailstop']['table'] = 'field_data_field_mailstop';
  $handler->display->display_options['fields']['field_mailstop']['field'] = 'field_mailstop';
  $handler->display->display_options['fields']['field_mailstop']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_mailstop']['element_class'] = 'p-extended-address';
  $handler->display->display_options['fields']['field_mailstop']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_mailstop']['element_label_class'] = 'dir-key';
  $handler->display->display_options['fields']['field_mailstop']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mailstop']['hide_empty'] = TRUE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_email']['element_class'] = 'u-email';
  $handler->display->display_options['fields']['field_email']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_email']['element_label_class'] = 'dir-key';
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_email']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_email']['delta_offset'] = '0';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_phone']['element_class'] = 'p-tel';
  $handler->display->display_options['fields']['field_phone']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_phone']['element_label_class'] = 'dir-key';
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['hide_empty'] = TRUE;
  /* Field: Content: Alternate Phone */
  $handler->display->display_options['fields']['field_alternate_phone']['id'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['table'] = 'field_data_field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['field'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['alter']['text'] = '<abbr title="Alternate phone number">Alt.</abbr>: [field_alternate_phone]';
  $handler->display->display_options['fields']['field_alternate_phone']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_alternate_phone']['element_class'] = 'p-tel';
  $handler->display->display_options['fields']['field_alternate_phone']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_alternate_phone']['element_label_class'] = 'dir-key';
  $handler->display->display_options['fields']['field_alternate_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_phone']['hide_empty'] = TRUE;
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['alter']['text'] = 'Fax: [field_fax]';
  $handler->display->display_options['fields']['field_fax']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_fax']['element_class'] = 'p-tel';
  $handler->display->display_options['fields']['field_fax']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_fax']['element_label_class'] = 'dir-key';
  $handler->display->display_options['fields']['field_fax']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_fax']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Office Title First Initial';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '1';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Websites */
  $handler->display->display_options['fields']['field_websites']['id'] = 'field_websites';
  $handler->display->display_options['fields']['field_websites']['table'] = 'field_data_field_websites';
  $handler->display->display_options['fields']['field_websites']['field'] = 'field_websites';
  $handler->display->display_options['fields']['field_websites']['label'] = 'URL';
  $handler->display->display_options['fields']['field_websites']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_websites']['element_class'] = 'u-url';
  $handler->display->display_options['fields']['field_websites']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_websites']['element_label_class'] = 'dir-key';
  $handler->display->display_options['fields']['field_websites']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_websites']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_websites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_websites']['delta_offset'] = '0';
  /* Field: Content: Related Offices */
  $handler->display->display_options['fields']['field_related_offices']['id'] = 'field_related_offices';
  $handler->display->display_options['fields']['field_related_offices']['table'] = 'field_data_field_related_offices';
  $handler->display->display_options['fields']['field_related_offices']['field'] = 'field_related_offices';
  $handler->display->display_options['fields']['field_related_offices']['element_type'] = '0';
  $handler->display->display_options['fields']['field_related_offices']['element_label_type'] = 'h3';
  $handler->display->display_options['fields']['field_related_offices']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_offices']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_related_offices']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_related_offices']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_related_offices']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_related_offices']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_related_offices']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_related_offices']['field_api_classes'] = TRUE;
  /* Field: Content: Members */
  $handler->display->display_options['fields']['field_members']['id'] = 'field_members';
  $handler->display->display_options['fields']['field_members']['table'] = 'field_data_field_members';
  $handler->display->display_options['fields']['field_members']['field'] = 'field_members';
  $handler->display->display_options['fields']['field_members']['label'] = 'People In This Office';
  $handler->display->display_options['fields']['field_members']['element_type'] = '0';
  $handler->display->display_options['fields']['field_members']['element_label_type'] = 'h3';
  $handler->display->display_options['fields']['field_members']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_members']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_members']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_members']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_members']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_members']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_members']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'default';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_options']['argument'] = 'A';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
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
    'directory_office' => 'directory_office',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'directory/offices';

  /* Display: Office A-Z Index */
  $handler = $view->new_display('attachment', 'Office A-Z Index', 'office_index');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_job_title' => 'field_job_title',
    'field_email' => 'field_email',
    'field_room' => 'field_room',
    'field_mailstop' => 'field_mailstop',
    'field_phone' => 'field_phone',
    'field_alternate_phone' => 'field_alternate_phone',
    'nothing' => 'nothing',
    'field_last_name' => 'field_last_name',
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
    'field_job_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_room' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mailstop' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_alternate_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Offices';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Job Title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['alter']['text'] = ', [field_job_title]';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['delta_offset'] = '0';
  /* Field: Content: Building */
  $handler->display->display_options['fields']['field_building_alt']['id'] = 'field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['table'] = 'field_data_field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['field'] = 'field_building_alt';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['label'] = 'Location';
  /* Field: Content: Mailstop */
  $handler->display->display_options['fields']['field_mailstop']['id'] = 'field_mailstop';
  $handler->display->display_options['fields']['field_mailstop']['table'] = 'field_data_field_mailstop';
  $handler->display->display_options['fields']['field_mailstop']['field'] = 'field_mailstop';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  /* Field: Content: Alternate Phone */
  $handler->display->display_options['fields']['field_alternate_phone']['id'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['table'] = 'field_data_field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['field'] = 'field_alternate_phone';
  $handler->display->display_options['fields']['field_alternate_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_phone']['alter']['text'] = '<abbr title="Alternate phone number">Alt.</abbr>: [field_alternate_phone]';
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_fax']['alter']['text'] = 'Fax: [field_fax]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Phone';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_phone]<br/>
[field_alternate_phone]<br/>
[field_fax]';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Last initial';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_last_name']['settings'] = array(
    'trim_length' => '1',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Office First Initial';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '1';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['base_path'] = 'directory/offices';
  $handler->display->display_options['arguments']['title']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
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
    'directory_office' => 'directory_office',
  );
  $handler->display->display_options['displays'] = array(
    'office_page' => 'office_page',
    'default' => 0,
    'block' => 0,
    'people_page' => 0,
    'staff_table' => 0,
    'staff_list' => 0,
    'faculty_page' => 0,
    'faculty_missing_directory' => 0,
    'combined_page' => 0,
    'page_1' => 0,
    'page_2' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: Faculty Page */
  $handler = $view->new_display('page', 'Faculty Page', 'faculty_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Faculty Directory';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_expertise' => 'title',
    'field_phone' => 'field_phone',
    'field_email' => 'field_email',
    'field_building_alt' => 'field_room',
    'field_room' => 'field_room',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
    'field_expertise' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_building_alt' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_room' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Headshot */
  $handler->display->display_options['fields']['field_headshot']['id'] = 'field_headshot';
  $handler->display->display_options['fields']['field_headshot']['table'] = 'field_data_field_headshot';
  $handler->display->display_options['fields']['field_headshot']['field'] = 'field_headshot';
  $handler->display->display_options['fields']['field_headshot']['label'] = '';
  $handler->display->display_options['fields']['field_headshot']['element_type'] = '0';
  $handler->display->display_options['fields']['field_headshot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_headshot']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_headshot']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_headshot']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_headshot']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_headshot']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'p-name';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Expertise */
  $handler->display->display_options['fields']['field_expertise']['id'] = 'field_expertise';
  $handler->display->display_options['fields']['field_expertise']['table'] = 'field_data_field_expertise';
  $handler->display->display_options['fields']['field_expertise']['field'] = 'field_expertise';
  $handler->display->display_options['fields']['field_expertise']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_expertise']['alter']['text'] = '<strong>Expertise:</strong> [field_expertise]';
  $handler->display->display_options['fields']['field_expertise']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_expertise']['element_class'] = 'p-role';
  $handler->display->display_options['fields']['field_expertise']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_expertise']['element_default_classes'] = FALSE;
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['delta_offset'] = '0';
  /* Field: Content: Building */
  $handler->display->display_options['fields']['field_building_alt']['id'] = 'field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['table'] = 'field_data_field_building_alt';
  $handler->display->display_options['fields']['field_building_alt']['field'] = 'field_building_alt';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['label'] = 'Location';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'directory_individual' => 'directory_individual',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is Faculty (field_is_faculty) */
  $handler->display->display_options['filters']['field_is_faculty_value']['id'] = 'field_is_faculty_value';
  $handler->display->display_options['filters']['field_is_faculty_value']['table'] = 'field_data_field_is_faculty';
  $handler->display->display_options['filters']['field_is_faculty_value']['field'] = 'field_is_faculty_value';
  $handler->display->display_options['filters']['field_is_faculty_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['path'] = 'faculty';

  /* Display: Faculty not in directory */
  $handler = $view->new_display('block', 'Faculty not in directory', 'faculty_missing_directory');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'directory_individual' => 'directory_individual',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is Faculty (field_is_faculty) */
  $handler->display->display_options['filters']['field_is_faculty_value']['id'] = 'field_is_faculty_value';
  $handler->display->display_options['filters']['field_is_faculty_value']['table'] = 'field_data_field_is_faculty';
  $handler->display->display_options['filters']['field_is_faculty_value']['field'] = 'field_is_faculty_value';
  $handler->display->display_options['filters']['field_is_faculty_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_faculty_value']['group'] = 1;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = '!=';
  $handler->display->display_options['filters']['name']['value'] = 'Admin';
  $handler->display->display_options['filters']['name']['group'] = 1;

  /* Display: Combined */
  $handler = $view->new_display('page', 'Combined', 'combined_page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_job_title' => 'title',
    'field_email' => 'field_email',
    'field_building_alt' => 'field_room',
    'field_room' => 'field_room',
    'field_mailstop' => 'field_mailstop',
    'field_phone' => 'field_phone',
    'field_alternate_phone' => 'field_alternate_phone',
    'field_fax' => 'field_fax',
    'nothing' => 'nothing',
    'field_last_name' => 'field_last_name',
    'field_website' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'field_job_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_building_alt' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_room' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_mailstop' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_alternate_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fax' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_website' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'directory_individual' => 'directory_individual',
    'directory_office' => 'directory_office',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'directory/combined';

  /* Display: Fax Page */
  $handler = $view->new_display('page', 'Fax Page', 'fax_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Fax Numbers';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_fax' => 'field_fax',
  );
  $handler->display->display_options['row_options']['separator'] = ': ';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Fax */
  $handler->display->display_options['fields']['field_fax']['id'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['table'] = 'field_data_field_fax';
  $handler->display->display_options['fields']['field_fax']['field'] = 'field_fax';
  $handler->display->display_options['fields']['field_fax']['label'] = '';
  $handler->display->display_options['fields']['field_fax']['alter']['text'] = 'Fax: [field_fax]';
  $handler->display->display_options['fields']['field_fax']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_fax']['element_class'] = 'p-tel';
  $handler->display->display_options['fields']['field_fax']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fax']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_fax']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'directory_office' => 'directory_office',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Fax (field_fax) */
  $handler->display->display_options['filters']['field_fax_value']['id'] = 'field_fax_value';
  $handler->display->display_options['filters']['field_fax_value']['table'] = 'field_data_field_fax';
  $handler->display->display_options['filters']['field_fax_value']['field'] = 'field_fax_value';
  $handler->display->display_options['filters']['field_fax_value']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'directory/fax';
  $export['directory'] = $view;

  $view = new view();
  $view->name = 'home_page_hero';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home Page Hero';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Home Page Hero';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
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
    'home_page_hero' => 'home_page_hero',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'home_page_hero' => 'home_page_hero',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'home-page-hero';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $export['home_page_hero'] = $view;

  $view = new view();
  $view->name = 'magazine';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Magazine';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Magazine';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['required'] = TRUE;
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 0;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'magazine' => 'magazine',
    'winter_2016' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Subqueue: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'entityqueue_subqueue';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'entityqueue_relationship';
  $handler->display->display_options['fields']['name']['label'] = 'Subqueue Name';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: Subqueue: Queue Name */
  $handler->display->display_options['fields']['queue']['id'] = 'queue';
  $handler->display->display_options['fields']['queue']['table'] = 'entityqueue_subqueue';
  $handler->display->display_options['fields']['queue']['field'] = 'queue';
  $handler->display->display_options['fields']['queue']['relationship'] = 'entityqueue_relationship';
  $handler->display->display_options['fields']['queue']['label'] = 'Top Level Queue Name';
  $handler->display->display_options['fields']['queue']['exclude'] = TRUE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = TRUE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Contextual filter: Subqueue: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'entityqueue_subqueue';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'entityqueue_relationship';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
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
  /* Filter criterion: Content: Site Section (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    0 => '179',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'site_sections';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['magazine'] = $view;

  $view = new view();
  $view->name = 'page_picker';
  $view->description = 'This is used for selecting pages or offices that are associated with a specific site.';
  $view->tag = 'site sections';
  $view->base_table = 'node';
  $view->human_name = 'Content Picker';
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
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'site_sections' => 'site_sections',
    'calendar_categories' => 0,
    'tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'site_sections' => 'site_sections',
    'calendar_categories' => 0,
    'tags' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
    'basic_page' => 'basic_page',
  );

  /* Display: Page Picker */
  $handler = $view->new_display('entityreference', 'Page Picker', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'term_node_tid',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'term_node_tid' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Office Picker */
  $handler = $view->new_display('entityreference', 'Office Picker', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'term_node_tid',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'term_node_tid' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
    'directory_office' => 'directory_office',
  );
  $export['page_picker'] = $view;

  $view = new view();
  $view->name = 'scholarships';
  $view->description = '';
  $view->tag = 'content';
  $view->base_table = 'node';
  $view->human_name = 'Scholarships';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Scholarships for Applicants';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_amount' => 'title',
    'field_tuition_award' => 'title',
    'field_new_or_current' => 'field_new_or_current',
    'field_class_standing' => 'field_class_standing',
    'field_need_based' => 'field_need_based',
    'field_short_description' => 'field_short_description',
    'field_under_represented' => 'field_short_description',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_amount' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tuition_award' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_new_or_current' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_class_standing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_need_based' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_under_represented' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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
    'scholarship' => 'scholarship',
  );
  /* Filter criterion: Content: Class Standing (field_class_standing) */
  $handler->display->display_options['filters']['field_class_standing_value']['id'] = 'field_class_standing_value';
  $handler->display->display_options['filters']['field_class_standing_value']['table'] = 'field_data_field_class_standing';
  $handler->display->display_options['filters']['field_class_standing_value']['field'] = 'field_class_standing_value';
  $handler->display->display_options['filters']['field_class_standing_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['operator_id'] = 'field_class_standing_value_op';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['label'] = 'Class Standing';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['operator'] = 'field_class_standing_value_op';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['identifier'] = 'field_class_standing_value';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: New or Current (field_new_or_current) */
  $handler->display->display_options['filters']['field_new_or_current_value']['id'] = 'field_new_or_current_value';
  $handler->display->display_options['filters']['field_new_or_current_value']['table'] = 'field_data_field_new_or_current';
  $handler->display->display_options['filters']['field_new_or_current_value']['field'] = 'field_new_or_current_value';
  $handler->display->display_options['filters']['field_new_or_current_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['operator_id'] = 'field_new_or_current_value_op';
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['label'] = 'New or Current';
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['operator'] = 'field_new_or_current_value_op';
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['identifier'] = 'field_new_or_current_value';
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Applicant View */
  $handler = $view->new_display('block', 'Applicant View', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Amount */
  $handler->display->display_options['fields']['field_amount']['id'] = 'field_amount';
  $handler->display->display_options['fields']['field_amount']['table'] = 'field_data_field_amount';
  $handler->display->display_options['fields']['field_amount']['field'] = 'field_amount';
  /* Field: Content: Tuition Award */
  $handler->display->display_options['fields']['field_tuition_award']['id'] = 'field_tuition_award';
  $handler->display->display_options['fields']['field_tuition_award']['table'] = 'field_data_field_tuition_award';
  $handler->display->display_options['fields']['field_tuition_award']['field'] = 'field_tuition_award';
  /* Field: Content: New or Current */
  $handler->display->display_options['fields']['field_new_or_current']['id'] = 'field_new_or_current';
  $handler->display->display_options['fields']['field_new_or_current']['table'] = 'field_data_field_new_or_current';
  $handler->display->display_options['fields']['field_new_or_current']['field'] = 'field_new_or_current';
  $handler->display->display_options['fields']['field_new_or_current']['delta_offset'] = '0';
  /* Field: Content: Class Standing */
  $handler->display->display_options['fields']['field_class_standing']['id'] = 'field_class_standing';
  $handler->display->display_options['fields']['field_class_standing']['table'] = 'field_data_field_class_standing';
  $handler->display->display_options['fields']['field_class_standing']['field'] = 'field_class_standing';
  $handler->display->display_options['fields']['field_class_standing']['delta_offset'] = '0';
  /* Field: Content: Need-Based */
  $handler->display->display_options['fields']['field_need_based']['id'] = 'field_need_based';
  $handler->display->display_options['fields']['field_need_based']['table'] = 'field_data_field_need_based';
  $handler->display->display_options['fields']['field_need_based']['field'] = 'field_need_based';
  /* Field: Content: Short Description */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  /* Field: Content: Under-represented */
  $handler->display->display_options['fields']['field_under_represented']['id'] = 'field_under_represented';
  $handler->display->display_options['fields']['field_under_represented']['table'] = 'field_data_field_under_represented';
  $handler->display->display_options['fields']['field_under_represented']['field'] = 'field_under_represented';
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
    'scholarship' => 'scholarship',
  );
  /* Filter criterion: Content: Class Standing (field_class_standing) */
  $handler->display->display_options['filters']['field_class_standing_value']['id'] = 'field_class_standing_value';
  $handler->display->display_options['filters']['field_class_standing_value']['table'] = 'field_data_field_class_standing';
  $handler->display->display_options['filters']['field_class_standing_value']['field'] = 'field_class_standing_value';
  $handler->display->display_options['filters']['field_class_standing_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['operator_id'] = 'field_class_standing_value_op';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['label'] = 'Class Standing';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['operator'] = 'field_class_standing_value_op';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['identifier'] = 'field_class_standing_value';
  $handler->display->display_options['filters']['field_class_standing_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: New or Current (field_new_or_current) */
  $handler->display->display_options['filters']['field_new_or_current_value']['id'] = 'field_new_or_current_value';
  $handler->display->display_options['filters']['field_new_or_current_value']['table'] = 'field_data_field_new_or_current';
  $handler->display->display_options['filters']['field_new_or_current_value']['field'] = 'field_new_or_current_value';
  $handler->display->display_options['filters']['field_new_or_current_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['operator_id'] = 'field_new_or_current_value_op';
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['label'] = 'New or Current';
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['operator'] = 'field_new_or_current_value_op';
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['identifier'] = 'field_new_or_current_value';
  $handler->display->display_options['filters']['field_new_or_current_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Funding Status (field_funding_status) */
  $handler->display->display_options['filters']['field_funding_status_value']['id'] = 'field_funding_status_value';
  $handler->display->display_options['filters']['field_funding_status_value']['table'] = 'field_data_field_funding_status';
  $handler->display->display_options['filters']['field_funding_status_value']['field'] = 'field_funding_status_value';
  $handler->display->display_options['filters']['field_funding_status_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_funding_status_value']['value'] = array(
    2 => '2',
  );

  /* Display: Donor View */
  $handler = $view->new_display('block', 'Donor View', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scholarships for Donors';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Cashnet Code */
  $handler->display->display_options['fields']['field_cashnet_code']['id'] = 'field_cashnet_code';
  $handler->display->display_options['fields']['field_cashnet_code']['table'] = 'field_data_field_cashnet_code';
  $handler->display->display_options['fields']['field_cashnet_code']['field'] = 'field_cashnet_code';
  $handler->display->display_options['fields']['field_cashnet_code']['label'] = '';
  $handler->display->display_options['fields']['field_cashnet_code']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cashnet_code']['alter']['text'] = '<a href=https://commerce.cashnet.com/givetoevergreen?itemcode=[field_cashnet_code]">Donate</a>';
  $handler->display->display_options['fields']['field_cashnet_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cashnet_code']['type'] = 'text_plain';
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
    'scholarship' => 'scholarship',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Funding Status (field_funding_status) */
  $handler->display->display_options['filters']['field_funding_status_value']['id'] = 'field_funding_status_value';
  $handler->display->display_options['filters']['field_funding_status_value']['table'] = 'field_data_field_funding_status';
  $handler->display->display_options['filters']['field_funding_status_value']['field'] = 'field_funding_status_value';
  $handler->display->display_options['filters']['field_funding_status_value']['value'] = array(
    1 => '1',
  );

  /* Display: Scholarship Review Page */
  $handler = $view->new_display('page', 'Scholarship Review Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Review Scholarships';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_amount' => 'field_amount',
    'field_cashnet_code' => 'field_cashnet_code',
    'field_class_standing' => 'field_class_standing',
    'field_common_application' => 'field_common_application',
    'field_deadline' => 'field_deadline',
    'field_fafsa_or_wasfa_required' => 'field_fafsa_or_wasfa_required',
    'field_funding_status' => 'field_funding_status',
    'field_need_based' => 'field_need_based',
    'field_new_or_current' => 'field_new_or_current',
    'field_short_description' => 'field_short_description',
    'field_tuition_award' => 'field_tuition_award',
    'field_under_represented' => 'field_short_description',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_amount' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cashnet_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_class_standing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_common_application' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_deadline' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fafsa_or_wasfa_required' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_funding_status' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_need_based' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_new_or_current' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tuition_award' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_under_represented' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Amount */
  $handler->display->display_options['fields']['field_amount']['id'] = 'field_amount';
  $handler->display->display_options['fields']['field_amount']['table'] = 'field_data_field_amount';
  $handler->display->display_options['fields']['field_amount']['field'] = 'field_amount';
  $handler->display->display_options['fields']['field_amount']['element_type'] = '0';
  $handler->display->display_options['fields']['field_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_amount']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_amount']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_amount']['field_api_classes'] = TRUE;
  /* Field: Content: Cashnet Code */
  $handler->display->display_options['fields']['field_cashnet_code']['id'] = 'field_cashnet_code';
  $handler->display->display_options['fields']['field_cashnet_code']['table'] = 'field_data_field_cashnet_code';
  $handler->display->display_options['fields']['field_cashnet_code']['field'] = 'field_cashnet_code';
  $handler->display->display_options['fields']['field_cashnet_code']['element_type'] = '0';
  $handler->display->display_options['fields']['field_cashnet_code']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_cashnet_code']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cashnet_code']['field_api_classes'] = TRUE;
  /* Field: Content: Class Standing */
  $handler->display->display_options['fields']['field_class_standing']['id'] = 'field_class_standing';
  $handler->display->display_options['fields']['field_class_standing']['table'] = 'field_data_field_class_standing';
  $handler->display->display_options['fields']['field_class_standing']['field'] = 'field_class_standing';
  $handler->display->display_options['fields']['field_class_standing']['element_type'] = '0';
  $handler->display->display_options['fields']['field_class_standing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_class_standing']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_class_standing']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_class_standing']['field_api_classes'] = TRUE;
  /* Field: Content: Common Application */
  $handler->display->display_options['fields']['field_common_application']['id'] = 'field_common_application';
  $handler->display->display_options['fields']['field_common_application']['table'] = 'field_data_field_common_application';
  $handler->display->display_options['fields']['field_common_application']['field'] = 'field_common_application';
  $handler->display->display_options['fields']['field_common_application']['element_type'] = '0';
  $handler->display->display_options['fields']['field_common_application']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_common_application']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_common_application']['field_api_classes'] = TRUE;
  /* Field: Content: Deadline */
  $handler->display->display_options['fields']['field_deadline']['id'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['table'] = 'field_data_field_deadline';
  $handler->display->display_options['fields']['field_deadline']['field'] = 'field_deadline';
  $handler->display->display_options['fields']['field_deadline']['element_type'] = '0';
  $handler->display->display_options['fields']['field_deadline']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_deadline']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_deadline']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_deadline']['field_api_classes'] = TRUE;
  /* Field: Content: FAFSA or WASFA Required */
  $handler->display->display_options['fields']['field_fafsa_or_wasfa_required']['id'] = 'field_fafsa_or_wasfa_required';
  $handler->display->display_options['fields']['field_fafsa_or_wasfa_required']['table'] = 'field_data_field_fafsa_or_wasfa_required';
  $handler->display->display_options['fields']['field_fafsa_or_wasfa_required']['field'] = 'field_fafsa_or_wasfa_required';
  $handler->display->display_options['fields']['field_fafsa_or_wasfa_required']['element_type'] = '0';
  $handler->display->display_options['fields']['field_fafsa_or_wasfa_required']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_fafsa_or_wasfa_required']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_fafsa_or_wasfa_required']['field_api_classes'] = TRUE;
  /* Field: Content: Funding Status */
  $handler->display->display_options['fields']['field_funding_status']['id'] = 'field_funding_status';
  $handler->display->display_options['fields']['field_funding_status']['table'] = 'field_data_field_funding_status';
  $handler->display->display_options['fields']['field_funding_status']['field'] = 'field_funding_status';
  $handler->display->display_options['fields']['field_funding_status']['element_type'] = '0';
  $handler->display->display_options['fields']['field_funding_status']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_funding_status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_funding_status']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_funding_status']['field_api_classes'] = TRUE;
  /* Field: Content: Need-Based */
  $handler->display->display_options['fields']['field_need_based']['id'] = 'field_need_based';
  $handler->display->display_options['fields']['field_need_based']['table'] = 'field_data_field_need_based';
  $handler->display->display_options['fields']['field_need_based']['field'] = 'field_need_based';
  $handler->display->display_options['fields']['field_need_based']['element_type'] = '0';
  $handler->display->display_options['fields']['field_need_based']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_need_based']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_need_based']['field_api_classes'] = TRUE;
  /* Field: Content: New or Current */
  $handler->display->display_options['fields']['field_new_or_current']['id'] = 'field_new_or_current';
  $handler->display->display_options['fields']['field_new_or_current']['table'] = 'field_data_field_new_or_current';
  $handler->display->display_options['fields']['field_new_or_current']['field'] = 'field_new_or_current';
  $handler->display->display_options['fields']['field_new_or_current']['element_type'] = '0';
  $handler->display->display_options['fields']['field_new_or_current']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_new_or_current']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_new_or_current']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_new_or_current']['field_api_classes'] = TRUE;
  /* Field: Content: Short Description */
  $handler->display->display_options['fields']['field_short_description']['id'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['table'] = 'field_data_field_short_description';
  $handler->display->display_options['fields']['field_short_description']['field'] = 'field_short_description';
  $handler->display->display_options['fields']['field_short_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_short_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_short_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_short_description']['field_api_classes'] = TRUE;
  /* Field: Content: Tuition Award */
  $handler->display->display_options['fields']['field_tuition_award']['id'] = 'field_tuition_award';
  $handler->display->display_options['fields']['field_tuition_award']['table'] = 'field_data_field_tuition_award';
  $handler->display->display_options['fields']['field_tuition_award']['field'] = 'field_tuition_award';
  $handler->display->display_options['fields']['field_tuition_award']['element_type'] = '0';
  $handler->display->display_options['fields']['field_tuition_award']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_tuition_award']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tuition_award']['field_api_classes'] = TRUE;
  /* Field: Content: Under-represented */
  $handler->display->display_options['fields']['field_under_represented']['id'] = 'field_under_represented';
  $handler->display->display_options['fields']['field_under_represented']['table'] = 'field_data_field_under_represented';
  $handler->display->display_options['fields']['field_under_represented']['field'] = 'field_under_represented';
  $handler->display->display_options['fields']['field_under_represented']['element_type'] = '0';
  $handler->display->display_options['fields']['field_under_represented']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_under_represented']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_under_represented']['field_api_classes'] = TRUE;
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
    'scholarship' => 'scholarship',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/workbench/scholarships';
  $export['scholarships'] = $view;

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
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

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
  /* Field: Field: Background Image */
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
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Section Background Block */
  $handler = $view->new_display('block', 'Section Background Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Background Image */
  $handler->display->display_options['fields']['field_background_image']['id'] = 'field_background_image';
  $handler->display->display_options['fields']['field_background_image']['table'] = 'field_data_field_background_image';
  $handler->display->display_options['fields']['field_background_image']['field'] = 'field_background_image';
  $handler->display->display_options['fields']['field_background_image']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_background_image']['label'] = '';
  $handler->display->display_options['fields']['field_background_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_background_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_background_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_background_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_background_image']['empty'] = '<img src="http://www.evergreen.edu/_inc/images/hero.jpg"/>';
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
  /* Field: Taxonomy term: Long name */
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
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'element-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
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
  /* Field: Field: Section Navigation */
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
  $handler->display->display_options['fields']['field_section_navigation']['type'] = 'field_collection_view';
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
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Section Contact Office */
  $handler = $view->new_display('block', 'Section Contact Office', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Site Section Contact Office';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'element-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Section Contact Info */
  $handler->display->display_options['fields']['field_section_contact_info']['id'] = 'field_section_contact_info';
  $handler->display->display_options['fields']['field_section_contact_info']['table'] = 'field_data_field_section_contact_info';
  $handler->display->display_options['fields']['field_section_contact_info']['field'] = 'field_section_contact_info';
  $handler->display->display_options['fields']['field_section_contact_info']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_section_contact_info']['label'] = 'Contact';
  $handler->display->display_options['fields']['field_section_contact_info']['element_type'] = '0';
  $handler->display->display_options['fields']['field_section_contact_info']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_section_contact_info']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_section_contact_info']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_section_contact_info']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_section_contact_info']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_section_contact_info']['settings'] = array(
    'view_mode' => 'full',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_section_contact_info']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $export['site_section_background'] = $view;

  $view = new view();
  $view->name = 'student_groups';
  $view->description = '';
  $view->tag = 'content';
  $view->base_table = 'node';
  $view->human_name = 'Student Groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Student Groups';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
  /* Field: Content: Meetings */
  $handler->display->display_options['fields']['field_meetings']['id'] = 'field_meetings';
  $handler->display->display_options['fields']['field_meetings']['table'] = 'field_data_field_meetings';
  $handler->display->display_options['fields']['field_meetings']['field'] = 'field_meetings';
  $handler->display->display_options['fields']['field_meetings']['element_type'] = '0';
  $handler->display->display_options['fields']['field_meetings']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_meetings']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_meetings']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_meetings']['field_api_classes'] = TRUE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['element_type'] = '0';
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_email']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_email']['field_api_classes'] = TRUE;
  /* Field: Content: Websites */
  $handler->display->display_options['fields']['field_websites']['id'] = 'field_websites';
  $handler->display->display_options['fields']['field_websites']['table'] = 'field_data_field_websites';
  $handler->display->display_options['fields']['field_websites']['field'] = 'field_websites';
  $handler->display->display_options['fields']['field_websites']['element_type'] = '0';
  $handler->display->display_options['fields']['field_websites']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_websites']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_websites']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_websites']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_websites']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_websites']['field_api_classes'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
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
    'student_group' => 'student_group',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: All Groups */
  $handler = $view->new_display('block', 'All Groups', 'all');

  /* Display: Governance */
  $handler = $view->new_display('block', 'Governance', 'governance');
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
    'student_group' => 'student_group',
  );
  /* Filter criterion: Content: Group Categories (field_group_categories) */
  $handler->display->display_options['filters']['field_group_categories_value']['id'] = 'field_group_categories_value';
  $handler->display->display_options['filters']['field_group_categories_value']['table'] = 'field_data_field_group_categories';
  $handler->display->display_options['filters']['field_group_categories_value']['field'] = 'field_group_categories_value';
  $handler->display->display_options['filters']['field_group_categories_value']['value'] = array(
    'Governance' => 'Governance',
  );

  /* Display: Featured */
  $handler = $view->new_display('block', 'Featured', 'featured');
  $handler->display->display_options['display_description'] = 'This isn\'t actually done yet.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'element-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
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
  $export['student_groups'] = $view;

  return $export;
}
