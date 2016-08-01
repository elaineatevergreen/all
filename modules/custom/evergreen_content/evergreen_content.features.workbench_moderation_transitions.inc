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
    'published:recycled' => array(
      'from_name' => 'published',
      'to_name' => 'recycled',
      'name' => 'Send to Trash',
    ),
  );
  return $items;
}
