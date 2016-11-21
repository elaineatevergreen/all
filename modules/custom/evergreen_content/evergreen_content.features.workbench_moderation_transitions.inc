<?php
/**
 * @file
 * evergreen_content.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function evergreen_content_workbench_moderation_export_transitions() {
  $items = array(
    'draft:published' => array(
      'from_name' => 'draft',
      'to_name' => 'published',
      'name' => 'Quick Publish',
    ),
    'published:recycled' => array(
      'from_name' => 'published',
      'to_name' => 'recycled',
      'name' => 'Send to Trash',
    ),
    'recycled:published' => array(
      'from_name' => 'recycled',
      'to_name' => 'published',
      'name' => 'Remove from Trash',
    ),
  );
  return $items;
}
