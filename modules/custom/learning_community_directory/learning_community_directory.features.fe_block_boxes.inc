<?php
/**
 * @file
 * learning_community_directory.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function learning_community_directory_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Washington Center footer';
  $fe_block_boxes->format = 'plain_text';
  $fe_block_boxes->machine_name = 'wa_center_footer';
  $fe_block_boxes->body = 'The Washington Center | 2700 Evergreen Pkwy NW, Olympia, WA, 98505 | (360) 867-6611';

  $export['wa_center_footer'] = $fe_block_boxes;

  return $export;
}
