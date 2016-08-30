<?php
/**
 * @file
 * native_cases.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function native_cases_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'home';
  $page->admin_description = 'This is a home page to include chunks of custom text, plus the view of featured cases.';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Primary',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 1,
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'secondary',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'secondary' => array(
        'type' => 'region',
        'title' => 'Secondary',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'secondary' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fa28336d-0a85-4fc6-8c86-8f269b3553a6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f3b45162-5e27-4dd0-ad6e-3940ad1e50c2';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Intro content',
      'title' => '',
      'body' => '<p class="intro">Engage your students and expand your curriculum with case studies on Native American subjects.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f3b45162-5e27-4dd0-ad6e-3940ad1e50c2';
    $display->content['new-f3b45162-5e27-4dd0-ad6e-3940ad1e50c2'] = $pane;
    $display->panels['center'][0] = 'new-f3b45162-5e27-4dd0-ad6e-3940ad1e50c2';
    $pane = new stdClass();
    $pane->pid = 'new-2ffce4b7-5ce9-4508-a63a-18d8977b401a';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'all_cases';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '3',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2ffce4b7-5ce9-4508-a63a-18d8977b401a';
    $display->content['new-2ffce4b7-5ce9-4508-a63a-18d8977b401a'] = $pane;
    $display->panels['center'][1] = 'new-2ffce4b7-5ce9-4508-a63a-18d8977b401a';
    $pane = new stdClass();
    $pane->pid = 'new-d7b11769-2d95-4e68-a8bd-cf76afcf9480';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-case-facets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd7b11769-2d95-4e68-a8bd-cf76afcf9480';
    $display->content['new-d7b11769-2d95-4e68-a8bd-cf76afcf9480'] = $pane;
    $display->panels['center'][2] = 'new-d7b11769-2d95-4e68-a8bd-cf76afcf9480';
    $pane = new stdClass();
    $pane->pid = 'new-13417020-ecb1-4947-a3a9-0c7e85f81142';
    $pane->panel = 'secondary';
    $pane->type = 'views';
    $pane->subtype = 'news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'home',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '13417020-ecb1-4947-a3a9-0c7e85f81142';
    $display->content['new-13417020-ecb1-4947-a3a9-0c7e85f81142'] = $pane;
    $display->panels['secondary'][0] = 'new-13417020-ecb1-4947-a3a9-0c7e85f81142';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
