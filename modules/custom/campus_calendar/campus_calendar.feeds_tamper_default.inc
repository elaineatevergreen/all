<?php
/**
 * @file
 * campus_calendar.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function campus_calendar_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'academic_calendar_csv-category-academic';
  $feeds_tamper->importer = 'academic_calendar_csv';
  $feeds_tamper->source = 'Category';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'Academics',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Academic';
  $export['academic_calendar_csv-category-academic'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'academic_calendar_csv-end-strtotime_end';
  $feeds_tamper->importer = 'academic_calendar_csv';
  $feeds_tamper->source = 'End';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['academic_calendar_csv-end-strtotime_end'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'academic_calendar_csv-format-deadlines';
  $feeds_tamper->importer = 'academic_calendar_csv';
  $feeds_tamper->source = 'Format';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'Deadlines',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Deadlines';
  $export['academic_calendar_csv-format-deadlines'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'academic_calendar_csv-start-strtotime_start';
  $feeds_tamper->importer = 'academic_calendar_csv';
  $feeds_tamper->source = 'Start';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['academic_calendar_csv-start-strtotime_start'] = $feeds_tamper;

  return $export;
}
