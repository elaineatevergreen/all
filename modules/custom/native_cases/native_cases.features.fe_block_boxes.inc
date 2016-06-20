<?php
/**
 * @file
 * native_cases.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function native_cases_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Contact Information';
  $fe_block_boxes->format = 'plain_text';
  $fe_block_boxes->machine_name = 'native_cases_contact';
  $fe_block_boxes->body = 'Enduring Legacies Native Cases The Evergreen State College

2700 Evergreen Parkway NW Olympia, Washington 98505
(360) 765-3084 Email: Barbara Leigh Smith Email: Linda Moon Stumpff ';

  $export['native_cases_contact'] = $fe_block_boxes;

  return $export;
}
