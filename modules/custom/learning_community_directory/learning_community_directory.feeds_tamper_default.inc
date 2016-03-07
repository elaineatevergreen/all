<?php
/**
 * @file
 * learning_community_directory.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function learning_community_directory_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'institutions-institutiontype_2or4year-find_replace_four';
  $feeds_tamper->importer = 'institutions';
  $feeds_tamper->source = 'institutionType_2Or4Year';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '4',
    'replace' => 'Four',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace 4/Four';
  $export['institutions-institutiontype_2or4year-find_replace_four'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'institutions-institutiontype_2or4year-find_replace_two';
  $feeds_tamper->importer = 'institutions';
  $feeds_tamper->source = 'institutionType_2Or4Year';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '2',
    'replace' => 'Two',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace 2/two';
  $export['institutions-institutiontype_2or4year-find_replace_two'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'institutions-institutiontype_publicorindependent-convert_case';
  $feeds_tamper->importer = 'institutions';
  $feeds_tamper->source = 'institutionType_PublicOrIndependent';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '2',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['institutions-institutiontype_publicorindependent-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'institutions-undergradenrollment_fulltime-find_replace_from';
  $feeds_tamper->importer = 'institutions';
  $feeds_tamper->source = 'undergradEnrollment_Fulltime';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'from ',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace "from"';
  $export['institutions-undergradenrollment_fulltime-find_replace_from'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'institutions-undergradenrollment_fulltime-find_replace_to';
  $feeds_tamper->importer = 'institutions';
  $feeds_tamper->source = 'undergradEnrollment_Fulltime';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => ' to ',
    'replace' => '-',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace "to"';
  $export['institutions-undergradenrollment_fulltime-find_replace_to'] = $feeds_tamper;

  return $export;
}
