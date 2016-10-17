<?php
/**
 * @file
 * evergreen_content.features.workbench_scheduler.inc
 */

/**
 * Implements hook_workbench_scheduler_export_schedules().
 */
function evergreen_content_workbench_scheduler_export_schedules() {
  $items = array(
    'schedule_publishing' => array(
      'name' => 'schedule_publishing',
      'label' => 'Schedule Publishing',
      'start_state' => 'published',
      'end_state' => '',
      'types' => array(
        0 => 'alert',
        1 => 'article',
        2 => 'basic_page',
        3 => 'event',
        4 => 'gallery',
        5 => 'location',
        6 => 'webform',
      ),
    ),
    'schedule_recycling' => array(
      'name' => 'schedule_recycling',
      'label' => 'Schedule Recycling',
      'start_state' => '',
      'end_state' => 'recycled',
      'types' => array(
        0 => 'alert',
        1 => 'article',
        2 => 'basic_page',
        3 => 'gallery',
        4 => 'location',
        5 => 'webform',
      ),
    ),
  );
  return $items;
}
