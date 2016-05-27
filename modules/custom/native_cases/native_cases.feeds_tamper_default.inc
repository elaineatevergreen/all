<?php
/**
 * @file
 * native_cases.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function native_cases_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'case_study-xpathparser_10-rewrite';
  $feeds_tamper->importer = 'case_study';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'http://nativecases.evergreen.edu[xpathparser:10]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['case_study-xpathparser_10-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'case_study-xpathparser_8-convert_boolean';
  $feeds_tamper->importer = 'case_study';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'yes',
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert to boolean';
  $export['case_study-xpathparser_8-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'case_study-xpathparser_9-rewrite';
  $feeds_tamper->importer = 'case_study';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'http://nativecases.evergreen.edu[xpathparser:9]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['case_study-xpathparser_9-rewrite'] = $feeds_tamper;

  return $export;
}
