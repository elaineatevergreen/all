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
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fa28336d-0a85-4fc6-8c86-8f269b3553a6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ce977a04-7329-4ec9-9659-668a16e07696';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'all_cases';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ce977a04-7329-4ec9-9659-668a16e07696';
    $display->content['new-ce977a04-7329-4ec9-9659-668a16e07696'] = $pane;
    $display->panels['center'][0] = 'new-ce977a04-7329-4ec9-9659-668a16e07696';
    $pane = new stdClass();
    $pane->pid = 'new-6d00bdc0-8989-4f72-a6ee-e8e2c7a20850';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Why Cases',
      'title' => 'Why Native Cases?',
      'body' => 'Teaching with cases has great results!

    Students are more engaged in class
    Students demonstrate stronger critical thinking skills
    Students view issues from multiple perspectives
    Students develop positive peer relations
    Students develop a deeper understanding of content
    Non-Native students increase awareness of Native perspectives & issues
    Students feel curriculum is more culturally relevant
',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6d00bdc0-8989-4f72-a6ee-e8e2c7a20850';
    $display->content['new-6d00bdc0-8989-4f72-a6ee-e8e2c7a20850'] = $pane;
    $display->panels['center'][1] = 'new-6d00bdc0-8989-4f72-a6ee-e8e2c7a20850';
    $pane = new stdClass();
    $pane->pid = 'new-b25a343b-1381-4b73-97d2-0bc614552f41';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Mission',
      'title' => '',
      'body' => '

The mission of the Enduring Legacies Native Cases Initiative is to develop culturally relevant curriculum and teaching resources in the form of case studies on key issues in Indian Country.

Culturally relevant curriculum is a key factor in student success and essential to prepare students for leadership roles. Key topics of our cases have been identified by Native leaders. Our partners in developing and using these cases are Northwest Indian College, Salish Kootenai College, and Grays Harbor College. Field tests at Evergreen began in Fall 2006 in our Reservation Based/Community Determined program. We welcome you to use our extensive collection of cases and tell us how they worked for you.',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b25a343b-1381-4b73-97d2-0bc614552f41';
    $display->content['new-b25a343b-1381-4b73-97d2-0bc614552f41'] = $pane;
    $display->panels['center'][2] = 'new-b25a343b-1381-4b73-97d2-0bc614552f41';
    $pane = new stdClass();
    $pane->pid = 'new-619a88b8-638a-44a5-bcf2-a9962ce4f0aa';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'all_cases';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '619a88b8-638a-44a5-bcf2-a9962ce4f0aa';
    $display->content['new-619a88b8-638a-44a5-bcf2-a9962ce4f0aa'] = $pane;
    $display->panels['center'][3] = 'new-619a88b8-638a-44a5-bcf2-a9962ce4f0aa';
    $pane = new stdClass();
    $pane->pid = 'new-13417020-ecb1-4947-a3a9-0c7e85f81142';
    $pane->panel = 'center';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '13417020-ecb1-4947-a3a9-0c7e85f81142';
    $display->content['new-13417020-ecb1-4947-a3a9-0c7e85f81142'] = $pane;
    $display->panels['center'][4] = 'new-13417020-ecb1-4947-a3a9-0c7e85f81142';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
