<?php
/**
 * @file
 * evergreen_content.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function evergreen_content_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Calendar Section Title';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'calendar_section_title';
  $fe_block_boxes->body = '<h1><a href="/evergreen.edu/calendar">Campus Calendar</a></h1>';

  $export['calendar_section_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Directory Section Title';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'directory_section_title';
  $fe_block_boxes->body = '<h1><a href="/evergreen.edu/directories">Directories</a></h1>
';

  $export['directory_section_title'] = $fe_block_boxes;

  return $export;
}
