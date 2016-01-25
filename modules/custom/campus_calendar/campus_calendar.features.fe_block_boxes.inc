<?php
/**
 * @file
 * campus_calendar.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function campus_calendar_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Background Image';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'placeholder_background';
  $fe_block_boxes->body = '<img alt="" class="main-background-img" src="http://evergreen.edu/news/images/background.jpg">';

  $export['placeholder_background'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Site Section title';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'placeholder_title';
  $fe_block_boxes->body = '<h1><a href="/calendar">Campus Calendar</a></h1>';

  $export['placeholder_title'] = $fe_block_boxes;

  return $export;
}
