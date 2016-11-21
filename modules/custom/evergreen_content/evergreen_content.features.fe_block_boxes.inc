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
  $fe_block_boxes->info = 'Section Title: Calendar';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'calendar_section_title';
  $fe_block_boxes->body = '<h1><a href="/calendar">Campus Calendar</a></h1>';

  $export['calendar_section_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Section Title: Catalog';
  $fe_block_boxes->format = 'extended_tags';
  $fe_block_boxes->machine_name = 'catalog_section_title';
  $fe_block_boxes->body = '<h1><a href="/catalog">Academic Catalog</a></h1>';

  $export['catalog_section_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Section Title: Directory';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'directory_section_title';
  $fe_block_boxes->body = '<h1><a href="directory/home">Directories</a></h1>
';

  $export['directory_section_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Section Title: Fields';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'fields_section_title';
  $fe_block_boxes->body = '<h1><a href="/studies">Fields of Study</a></h1>';

  $export['fields_section_title'] = $fe_block_boxes;

  return $export;
}
