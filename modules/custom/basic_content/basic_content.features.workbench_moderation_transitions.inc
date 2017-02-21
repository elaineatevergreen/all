<?php
/**
 * @file
 * basic_content.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function basic_content_workbench_moderation_export_transitions() {
  $items = array(
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'name' => 'Submit for Review',
    ),
    'draft:published' => array(
      'from_name' => 'draft',
      'to_name' => 'published',
      'name' => 'Quick Publish',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Reject',
    ),
    'needs_review:published' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
      'name' => 'Publish',
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
