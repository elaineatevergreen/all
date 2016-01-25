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
      'body' => 'This is placeholder content until actual help exists in a useful format.

We\'ll link to some articles about how to make things, how to write gooder, etc.',
      'format' => 'plain_text',
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
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '042db4d8-e5f2-44c4-9495-ff0b6814d9c6';
    $display->content['new-042db4d8-e5f2-44c4-9495-ff0b6814d9c6'] = $pane;
    $display->panels['middle'][0] = 'new-042db4d8-e5f2-44c4-9495-ff0b6814d9c6';
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
