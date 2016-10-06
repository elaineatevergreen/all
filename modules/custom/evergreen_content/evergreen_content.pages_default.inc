<?php
/**
 * @file
 * evergreen_content.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function evergreen_content_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'myworkbench__panel_context_9f331727-0a27-4b21-a454-c3c3e46fa5f8';
  $handler->task = 'myworkbench';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 101;
  $handler->conf = array(
    'title' => 'My Workbech With Help',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol_bricks';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Evergreen.edu Workbench';
  $display->uuid = 'dd6452e9-a281-4941-b7d2-0ecf0027ac69';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'myworkbench__panel_context_9f331727-0a27-4b21-a454-c3c3e46fa5f8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-01128484-59de-48ad-a5da-74b04005f5cb';
  $pane->panel = 'left_above';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Placeholder Workbench Help',
    'title' => 'CMS Help',
    'body' => '<p>See the Canvas course "<a href="https://canvas.evergreen.edu/courses/1257">Website Editor Training</a>" for tutorials and other materials.</p>
',
    'format' => 'basic_tags',
    'substitute' => TRUE,
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '01128484-59de-48ad-a5da-74b04005f5cb';
  $display->content['new-01128484-59de-48ad-a5da-74b04005f5cb'] = $pane;
  $display->panels['left_above'][0] = 'new-01128484-59de-48ad-a5da-74b04005f5cb';
  $pane = new stdClass();
  $pane->pid = 'new-d056af79-4c98-493e-a2d2-5e3cc9acd522';
  $pane->panel = 'left_above';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Site News',
    'body' => '<p>This is a placeholder for any upcoming downtime, upgrades, new sites launched, and so on.</p>
',
    'format' => 'basic_tags',
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
  $pane->uuid = 'd056af79-4c98-493e-a2d2-5e3cc9acd522';
  $display->content['new-d056af79-4c98-493e-a2d2-5e3cc9acd522'] = $pane;
  $display->panels['left_above'][1] = 'new-d056af79-4c98-493e-a2d2-5e3cc9acd522';
  $pane = new stdClass();
  $pane->pid = 'new-535f198c-afc8-4c97-a6ff-db27d544eb29';
  $pane->panel = 'left_above';
  $pane->type = 'views';
  $pane->subtype = 'workbench_current_user';
  $pane->shown = FALSE;
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
    'display' => 'default',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = '';
  $pane->uuid = '535f198c-afc8-4c97-a6ff-db27d544eb29';
  $display->content['new-535f198c-afc8-4c97-a6ff-db27d544eb29'] = $pane;
  $display->panels['left_above'][2] = 'new-535f198c-afc8-4c97-a6ff-db27d544eb29';
  $pane = new stdClass();
  $pane->pid = 'new-042db4d8-e5f2-44c4-9495-ff0b6814d9c6';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'workbench_recent_content';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 1,
    'use_pager' => 1,
    'nodes_per_page' => '20',
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
  $pane->position = 0;
  $pane->locks = '';
  $pane->uuid = '042db4d8-e5f2-44c4-9495-ff0b6814d9c6';
  $display->content['new-042db4d8-e5f2-44c4-9495-ff0b6814d9c6'] = $pane;
  $display->panels['middle'][0] = 'new-042db4d8-e5f2-44c4-9495-ff0b6814d9c6';
  $pane = new stdClass();
  $pane->pid = 'new-52cc24a7-0ba8-4c6a-8720-cceaa5691fa5';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'workbench_recent_content_with_recycling_';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 1,
    'use_pager' => 1,
    'nodes_per_page' => '20',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '52cc24a7-0ba8-4c6a-8720-cceaa5691fa5';
  $display->content['new-52cc24a7-0ba8-4c6a-8720-cceaa5691fa5'] = $pane;
  $display->panels['middle'][1] = 'new-52cc24a7-0ba8-4c6a-8720-cceaa5691fa5';
  $pane = new stdClass();
  $pane->pid = 'new-4011dcb3-7025-4a3b-89f6-eb3f40397338';
  $pane->panel = 'right_above';
  $pane->type = 'views';
  $pane->subtype = 'workbench_edited';
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
    'display' => 'block_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $pane->uuid = '4011dcb3-7025-4a3b-89f6-eb3f40397338';
  $display->content['new-4011dcb3-7025-4a3b-89f6-eb3f40397338'] = $pane;
  $display->panels['right_above'][0] = 'new-4011dcb3-7025-4a3b-89f6-eb3f40397338';
  $pane = new stdClass();
  $pane->pid = 'new-0b45f32a-c7f9-405b-9ed9-c2bbc850bb8f';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Sample Variant',
    'title' => 'My Workbench created through Panels.',
    'body' => '<em>You are viewing "My Workbench" as created by Page Manager and Panels. The module Views Content Panes is also recommended. Please read the <a href="http://drupal.org/node/1226174" target="_blank">Workbench documentation</a> for the best practices in using Panels and Page Manager with Workbench.</em>',
    'format' => 'filtered_html',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = '';
  $pane->uuid = '0b45f32a-c7f9-405b-9ed9-c2bbc850bb8f';
  $display->content['new-0b45f32a-c7f9-405b-9ed9-c2bbc850bb8f'] = $pane;
  $display->panels['top'][0] = 'new-0b45f32a-c7f9-405b-9ed9-c2bbc850bb8f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-042db4d8-e5f2-44c4-9495-ff0b6814d9c6';
  $handler->conf['display'] = $display;
  $export['myworkbench__panel_context_9f331727-0a27-4b21-a454-c3c3e46fa5f8'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function evergreen_content_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'marketing_tools';
  $page->task = 'page';
  $page->admin_title = 'Marketing Tools';
  $page->admin_description = 'A variety of tools for the communications department';
  $page->path = 'admin/workbench/content/shurly';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 7,
            1 => 10,
            2 => 4,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Short URLs',
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
  $handler->name = 'page_marketing_tools__panel';
  $handler->task = 'page';
  $handler->subtask = 'marketing_tools';
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
  $display->title = 'Short URLs';
  $display->uuid = '11b113d9-f7ef-4db9-af3d-2fc62cbfe213';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_marketing_tools__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a9f32690-517b-4a19-a9bd-dffc5f56cbfa';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Link to other URL options',
    'title' => 'More Redirects and Alternate URLs',
    'title_heading' => 'h2',
    'body' => '<p>
	See&nbsp;<a href="admin/config/search/redirect">URL Redirects</a> for hand-created non-advertising addresses or <a href="admin/config/search/path">URL Aliases</a> for automatically generated addresses and URL patterns.</p>
',
    'format' => 'extended_tags',
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
  $pane->uuid = 'a9f32690-517b-4a19-a9bd-dffc5f56cbfa';
  $display->content['new-a9f32690-517b-4a19-a9bd-dffc5f56cbfa'] = $pane;
  $display->panels['center'][0] = 'new-a9f32690-517b-4a19-a9bd-dffc5f56cbfa';
  $pane = new stdClass();
  $pane->pid = 'new-2173d7b0-a80f-40ad-b44d-b2e4b71c2255';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'shurly-form';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2173d7b0-a80f-40ad-b44d-b2e4b71c2255';
  $display->content['new-2173d7b0-a80f-40ad-b44d-b2e4b71c2255'] = $pane;
  $display->panels['center'][1] = 'new-2173d7b0-a80f-40ad-b44d-b2e4b71c2255';
  $pane = new stdClass();
  $pane->pid = 'new-0dd29423-fe80-4953-9ed2-610d6dc593eb';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'shurly_admin';
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
    'display' => 'page_1',
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
  $pane->uuid = '0dd29423-fe80-4953-9ed2-610d6dc593eb';
  $display->content['new-0dd29423-fe80-4953-9ed2-610d6dc593eb'] = $pane;
  $display->panels['center'][2] = 'new-0dd29423-fe80-4953-9ed2-610d6dc593eb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0dd29423-fe80-4953-9ed2-610d6dc593eb';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['marketing_tools'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_o_matic';
  $page->task = 'page';
  $page->admin_title = 'News-o-matic';
  $page->admin_description = 'Administrative interface for home page news.';
  $page->path = 'admin/workbench/content/news';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 7,
            1 => 10,
            2 => 4,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'News-O-Matic',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => 'My Content',
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
  $handler->name = 'page_news_o_matic__panel';
  $handler->task = 'page';
  $handler->subtask = 'news_o_matic';
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
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 2,
          1 => 3,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'lower',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'lower' => array(
        'type' => 'region',
        'title' => 'Lower',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 4,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 5,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'first',
        ),
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
      'first' => array(
        'type' => 'region',
        'title' => 'First',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'second',
        ),
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
      'second' => array(
        'type' => 'region',
        'title' => 'Second',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'lower' => NULL,
      'first' => NULL,
      'second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'News-O-Matic';
  $display->uuid = '02ecfed7-ac0b-4287-a913-3f0a3c022d5f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_news_o_matic__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-39c21e23-0b78-4528-8770-9df7abce6d3c';
  $pane->panel = 'first';
  $pane->type = 'block';
  $pane->subtype = 'formblock-blurb';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '39c21e23-0b78-4528-8770-9df7abce6d3c';
  $display->content['new-39c21e23-0b78-4528-8770-9df7abce6d3c'] = $pane;
  $display->panels['first'][0] = 'new-39c21e23-0b78-4528-8770-9df7abce6d3c';
  $pane = new stdClass();
  $pane->pid = 'new-eef19525-fcda-42bd-bca2-ac1e9a4255d9';
  $pane->panel = 'lower';
  $pane->type = 'views';
  $pane->subtype = 'blog';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '20',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page_3',
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
  $pane->uuid = 'eef19525-fcda-42bd-bca2-ac1e9a4255d9';
  $display->content['new-eef19525-fcda-42bd-bca2-ac1e9a4255d9'] = $pane;
  $display->panels['lower'][0] = 'new-eef19525-fcda-42bd-bca2-ac1e9a4255d9';
  $pane = new stdClass();
  $pane->pid = 'new-b86cfbe3-e048-470f-9b32-77c37f411e73';
  $pane->panel = 'second';
  $pane->type = 'views';
  $pane->subtype = 'news_o_matic';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '6',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 1,
    'override_title_text' => 'Live Items',
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
  $pane->uuid = 'b86cfbe3-e048-470f-9b32-77c37f411e73';
  $display->content['new-b86cfbe3-e048-470f-9b32-77c37f411e73'] = $pane;
  $display->panels['second'][0] = 'new-b86cfbe3-e048-470f-9b32-77c37f411e73';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b86cfbe3-e048-470f-9b32-77c37f411e73';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_o_matic'] = $page;

  return $pages;

}
