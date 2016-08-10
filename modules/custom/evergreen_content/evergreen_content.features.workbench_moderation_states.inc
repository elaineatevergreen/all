<?php
/**
 * @file
 * evergreen_content.features.workbench_moderation_states.inc
 */

/**
 * Implements hook_workbench_moderation_export_states().
 */
function evergreen_content_workbench_moderation_export_states() {
  $items = array(
    'recycled' => array(
      'name' => 'recycled',
      'label' => 'Recycled',
      'description' => 'Remove this from public view',
      'weight' => 0,
    ),
  );
  return $items;
}
