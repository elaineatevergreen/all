<?php
/**
 * @file
 * evergreen_content.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function evergreen_content_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'evergreen_magazine';
  $queue->label = 'Evergreen Magazine';
  $queue->language = 'en';
  $queue->handler = 'multiple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'basic_page' => 'basic_page',
      'article' => 'article',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 1,
  );
  $export['evergreen_magazine'] = $queue;

  return $export;
}
