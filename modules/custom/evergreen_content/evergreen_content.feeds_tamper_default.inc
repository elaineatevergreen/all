<?php
/**
 * @file
 * evergreen_content.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function evergreen_content_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'author_directory-blank_source_1-default_value';
  $feeds_tamper->importer = 'author_directory';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['author_directory-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'author_directory-xpathparser_6-find_replace';
  $feeds_tamper->importer = 'author_directory';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'http://www.evergreen.edu/scripts/contact.php?sm=',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Strip contact script link';
  $export['author_directory-xpathparser_6-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'author_directory-xpathparser_6-find_replace2';
  $feeds_tamper->importer = 'author_directory';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '&sub=&sub=Email%20from%20Authors%20Directory&title=Contact%20',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Strip first part of script variables';
  $export['author_directory-xpathparser_6-find_replace2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'author_directory-xpathparser_6-find_replace3';
  $feeds_tamper->importer = 'author_directory';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '&sub=&title=',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'More script stripping';
  $export['author_directory-xpathparser_6-find_replace3'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'author_directory-xpathparser_6-find_replace_regex';
  $feeds_tamper->importer = 'author_directory';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/([A-Z%20])\\w+/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Remove rest of script link';
  $export['author_directory-xpathparser_6-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'calendar_events-null-default_value';
  $feeds_tamper->importer = 'calendar_events';
  $feeds_tamper->source = 'null';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Publish by default';
  $export['calendar_events-null-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'calendar_events-promote-convert_boolean';
  $feeds_tamper->importer = 'calendar_events';
  $feeds_tamper->source = 'promote';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'yes',
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['calendar_events-promote-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'campus_locations-abbreviated_building_name-trim';
  $feeds_tamper->importer = 'campus_locations';
  $feeds_tamper->source = 'Abbreviated Building Name';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim whitespace';
  $export['campus_locations-abbreviated_building_name-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'campus_locations-building_history-trim';
  $feeds_tamper->importer = 'campus_locations';
  $feeds_tamper->source = 'Building History';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim whitespace';
  $export['campus_locations-building_history-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'campus_locations-description-trim';
  $feeds_tamper->importer = 'campus_locations';
  $feeds_tamper->source = 'Description';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim whitespace';
  $export['campus_locations-description-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'campus_locations-official_name-trim';
  $feeds_tamper->importer = 'campus_locations';
  $feeds_tamper->source = 'Official Name';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim whitespace';
  $export['campus_locations-official_name-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'campus_locations-square_footage-trim';
  $feeds_tamper->importer = 'campus_locations';
  $feeds_tamper->source = 'Square Footage';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim whitespace';
  $export['campus_locations-square_footage-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'campus_locations-title-trim';
  $feeds_tamper->importer = 'campus_locations';
  $feeds_tamper->source = 'Title';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim whitespace';
  $export['campus_locations-title-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog-xpathparser_7-explode';
  $feeds_tamper->importer = 'catalog';
  $feeds_tamper->source = 'xpathparser:7';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode credits!';
  $export['catalog-xpathparser_7-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'entrepreneur_directory-blank_source_1-default_value';
  $feeds_tamper->importer = 'entrepreneur_directory';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['entrepreneur_directory-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'entrepreneur_directory-blank_source_2-default_value';
  $feeds_tamper->importer = 'entrepreneur_directory';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'US',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'USA';
  $export['entrepreneur_directory-blank_source_2-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'entrepreneur_directory-blank_source_3-default_value';
  $feeds_tamper->importer = 'entrepreneur_directory';
  $feeds_tamper->source = 'Blank source 3';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'Student/Alumnus',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['entrepreneur_directory-blank_source_3-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'entrepreneur_directory-xpathparser_1-trim';
  $feeds_tamper->importer = 'entrepreneur_directory';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['entrepreneur_directory-xpathparser_1-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'entrepreneur_directory-xpathparser_8-convert_case';
  $feeds_tamper->importer = 'entrepreneur_directory';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '2',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['entrepreneur_directory-xpathparser_8-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'entrepreneur_directory-xpathparser_9-convert_case';
  $feeds_tamper->importer = 'entrepreneur_directory';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '0',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert case';
  $export['entrepreneur_directory-xpathparser_9-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'entrepreneur_directory-xpathparser_9-state_to_abbrev';
  $feeds_tamper->importer = 'entrepreneur_directory';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'state_to_abbrev';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Full state name to abbrev';
  $export['entrepreneur_directory-xpathparser_9-state_to_abbrev'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'faculty_directory-blank_source_1-default_value';
  $feeds_tamper->importer = 'faculty_directory';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default for faculty importing';
  $export['faculty_directory-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hero_images-xpathparser_2-sprintf';
  $feeds_tamper->importer = 'hero_images';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => 'http://evergreen.edu%s',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Prepend URL';
  $export['hero_images-xpathparser_2-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hero_images-xpathparser_3-find_replace';
  $feeds_tamper->importer = 'hero_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '-x.jpg',
    'replace' => '-l.jpg',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Switch size';
  $export['hero_images-xpathparser_3-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hero_images-xpathparser_3-sprintf';
  $feeds_tamper->importer = 'hero_images';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => 'http://evergreen.edu%s',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Prepend URL';
  $export['hero_images-xpathparser_3-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hero_images-xpathparser_4-find_replace';
  $feeds_tamper->importer = 'hero_images';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '-x.jpg',
    'replace' => '-m.jpg',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Switch size';
  $export['hero_images-xpathparser_4-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hero_images-xpathparser_4-sprintf';
  $feeds_tamper->importer = 'hero_images';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => 'http://evergreen.edu%s',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Prepend URL';
  $export['hero_images-xpathparser_4-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hero_images-xpathparser_5-find_replace';
  $feeds_tamper->importer = 'hero_images';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '-x.jpg',
    'replace' => '-s.jpg',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Switch size';
  $export['hero_images-xpathparser_5-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'hero_images-xpathparser_5-sprintf';
  $feeds_tamper->importer = 'hero_images';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => 'http://evergreen.edu%s',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Prepend URL';
  $export['hero_images-xpathparser_5-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'library_databases-xpathparser_4-convert_boolean';
  $feeds_tamper->importer = 'library_databases';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'featured',
    'false_value' => 'not featured',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['library_databases-xpathparser_4-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory-xpathparser_10-trim';
  $feeds_tamper->importer = 'office_directory';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim whitespace';
  $export['office_directory-xpathparser_10-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory-xpathparser_12-find_replace_regex';
  $feeds_tamper->importer = 'office_directory';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/ ([ABCDE]-)?[0-9]+([A-Z])*/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'REGEX to remove Room';
  $export['office_directory-xpathparser_12-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory-xpathparser_9-find_replace_regex';
  $feeds_tamper->importer = 'office_directory';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[a-zA-Z ]* /',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'REGEX to remove Building';
  $export['office_directory-xpathparser_9-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory_facility-blank_source_1-default_value';
  $feeds_tamper->importer = 'office_directory_facility';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['office_directory_facility-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory_facility-xpathparser_10-trim';
  $feeds_tamper->importer = 'office_directory_facility';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim whitespace';
  $export['office_directory_facility-xpathparser_10-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory_facility-xpathparser_12-find_replace_regex';
  $feeds_tamper->importer = 'office_directory_facility';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/ ([ABCDE]-)?[0-9]+([A-Z])*/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'REGEX to remove Room';
  $export['office_directory_facility-xpathparser_12-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory_facility-xpathparser_9-find_replace_regex';
  $feeds_tamper->importer = 'office_directory_facility';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[a-zA-Z ]* /',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'REGEX to remove Building';
  $export['office_directory_facility-xpathparser_9-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'people_directory-xpathparser_12-find_replace_regex';
  $feeds_tamper->importer = 'people_directory';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/ ([ABCDE]-)?[0-9]+([A-Z])*/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'REGEX to remove Room';
  $export['people_directory-xpathparser_12-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'people_directory-xpathparser_2-find_replace_regex';
  $feeds_tamper->importer = 'people_directory';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[a-zA-Z ()\']*, /',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'REGEX to remove last name';
  $export['people_directory-xpathparser_2-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'people_directory-xpathparser_5-find_replace_regex';
  $feeds_tamper->importer = 'people_directory';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/, [a-zA-Z ()\']*/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'REGEX to remove first name';
  $export['people_directory-xpathparser_5-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'people_directory-xpathparser_9-find_replace_regex';
  $feeds_tamper->importer = 'people_directory';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[a-zA-Z ]* /',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'REGEX to remove Building';
  $export['people_directory-xpathparser_9-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'scholarship_import-xpathparser_10-find_replace';
  $feeds_tamper->importer = 'scholarship_import';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'No preference',
    'replace' => 'BOTH',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^No preference$/ui',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'If no pref, check both -- for later overriding';
  $export['scholarship_import-xpathparser_10-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'scholarship_import-xpathparser_10-find_replace3';
  $feeds_tamper->importer = 'scholarship_import';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'only',
    'replace' => ' ',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Remove "only"';
  $export['scholarship_import-xpathparser_10-find_replace3'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'scholarship_import-xpathparser_13-convert_case';
  $feeds_tamper->importer = 'scholarship_import';
  $feeds_tamper->source = 'xpathparser:13';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => 'ucfirst',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Convert case';
  $export['scholarship_import-xpathparser_13-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'scholarship_import-xpathparser_13-find_replace';
  $feeds_tamper->importer = 'scholarship_import';
  $feeds_tamper->source = 'xpathparser:13';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'One or more',
    'replace' => ' ',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace "one or more"';
  $export['scholarship_import-xpathparser_13-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'scholarship_import-xpathparser_13-find_replace2';
  $feeds_tamper->importer = 'scholarship_import';
  $feeds_tamper->source = 'xpathparser:13';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'All criteria',
    'replace' => ' ',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace "all criteria"';
  $export['scholarship_import-xpathparser_13-find_replace2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'scholarship_import-xpathparser_13-trim';
  $feeds_tamper->importer = 'scholarship_import';
  $feeds_tamper->source = 'xpathparser:13';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Trim';
  $export['scholarship_import-xpathparser_13-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'scholarship_import-xpathparser_8-find_replace_regex';
  $feeds_tamper->importer = 'scholarship_import';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\/([a-z-])+/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Strip after the slash';
  $export['scholarship_import-xpathparser_8-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'scholarship_import-xpathparser_8-trim';
  $feeds_tamper->importer = 'scholarship_import';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '/',
    'side' => 'ltrim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Remove leading slash';
  $export['scholarship_import-xpathparser_8-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'scholarship_import-xpathparser_9-find_replace';
  $feeds_tamper->importer = 'scholarship_import';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'No',
    'replace' => 'Not need-based',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^No$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['scholarship_import-xpathparser_9-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'student_group_import-meeting_location-rewrite';
  $feeds_tamper->importer = 'student_group_import';
  $feeds_tamper->source = 'Meeting Location';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[meeting times]
[meeting location]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Combine meeting time and location';
  $export['student_group_import-meeting_location-rewrite'] = $feeds_tamper;

  return $export;
}
