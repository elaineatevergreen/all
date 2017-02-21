<?php
/**
 * @file
 * simple_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function simple_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function simple_events_node_info() {
  $items = array(
    'event_simple' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Use an <em>event</em> when you need to add something to an event calendar or create other date-based content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
