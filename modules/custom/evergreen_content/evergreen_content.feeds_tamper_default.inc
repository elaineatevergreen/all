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
  $feeds_tamper->id = 'academic_calendar_csv-end-strtotime';
  $feeds_tamper->importer = 'academic_calendar_csv';
  $feeds_tamper->source = 'End';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['academic_calendar_csv-end-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'academic_calendar_csv-start-strtotime';
  $feeds_tamper->importer = 'academic_calendar_csv';
  $feeds_tamper->source = 'Start';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['academic_calendar_csv-start-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_1-rewrite';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[xpathparser:11]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['catalog_multi_upload-blank_source_1-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_1-sprintf';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'sprintf';
  $feeds_tamper->settings = array(
    'format' => '%.4s',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Four characters only';
  $export['catalog_multi_upload-blank_source_1-sprintf'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_2-default_value';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Set value or default value';
  $export['catalog_multi_upload-blank_source_2-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_2-feeds_tamper_conditional';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'feeds_tamper_conditional';
  $feeds_tamper->settings = array(
    'conditional_field' => 'xpathparser:53',
    'operator' => 'empty',
    'negate' => 1,
    'value' => '',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Conditional';
  $export['catalog_multi_upload-blank_source_2-feeds_tamper_conditional'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_3-default_value';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 3';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['catalog_multi_upload-blank_source_3-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_3-feeds_tamper_conditional';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 3';
  $feeds_tamper->plugin_id = 'feeds_tamper_conditional';
  $feeds_tamper->settings = array(
    'conditional_field' => 'xpathparser:52',
    'operator' => 'empty',
    'negate' => 1,
    'value' => '',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Conditional';
  $export['catalog_multi_upload-blank_source_3-feeds_tamper_conditional'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_4-default_value';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 4';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['catalog_multi_upload-blank_source_4-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_4-feeds_tamper_conditional';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 4';
  $feeds_tamper->plugin_id = 'feeds_tamper_conditional';
  $feeds_tamper->settings = array(
    'conditional_field' => 'xpathparser:39',
    'operator' => 'empty',
    'negate' => 1,
    'value' => '',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Conditional';
  $export['catalog_multi_upload-blank_source_4-feeds_tamper_conditional'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_5-default_value';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 5';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['catalog_multi_upload-blank_source_5-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-blank_source_5-feeds_tamper_conditional';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'Blank source 5';
  $feeds_tamper->plugin_id = 'feeds_tamper_conditional';
  $feeds_tamper->settings = array(
    'conditional_field' => 'xpathparser:37',
    'operator' => 'empty',
    'negate' => 1,
    'value' => '',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Conditional';
  $export['catalog_multi_upload-blank_source_5-feeds_tamper_conditional'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_0-html_entity_decode';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'html_entity_decode';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'HTML entity decode';
  $export['catalog_multi_upload-xpathparser_0-html_entity_decode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_11-trim';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:11';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['catalog_multi_upload-xpathparser_11-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_12-trim';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim';
  $export['catalog_multi_upload-xpathparser_12-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_16-find_replace';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:16';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Summer',
    'replace' => 'Summer Full Session',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Summer$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace Summer (for grad programs)';
  $export['catalog_multi_upload-xpathparser_16-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_17-find_replace';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:17';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Summer',
    'replace' => 'Summer Full Session',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Summer$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace Summer (for grad programs)';
  $export['catalog_multi_upload-xpathparser_17-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_18-find_replace';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:18';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Day, Evening and Weekend',
    'replace' => 'Day, Evening, and Weekend',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'OXFORD COMMA, y\'all';
  $export['catalog_multi_upload-xpathparser_18-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_21-convert_case';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:21';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '0',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['catalog_multi_upload-xpathparser_21-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_22-explode';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:22';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ',',
    'limit' => '',
    'real_separator' => ',',
  );
  $feeds_tamper->weight = 5;
  $feeds_tamper->description = 'Explode';
  $export['catalog_multi_upload-xpathparser_22-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_22-trim';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:22';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 6;
  $feeds_tamper->description = 'Trim';
  $export['catalog_multi_upload-xpathparser_22-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_31-find_replace';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:31';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Confirmed',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Remove "Confirmed" status';
  $export['catalog_multi_upload-xpathparser_31-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_32-find_replace';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:32';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Summer',
    'replace' => 'UG',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite summer to UG';
  $export['catalog_multi_upload-xpathparser_32-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_44-find_replace';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:44';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Summer',
    'replace' => 'Summer Full Session',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Summer$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace Summer (for grad programs)';
  $export['catalog_multi_upload-xpathparser_44-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_45-convert_case';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:45';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '2',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['catalog_multi_upload-xpathparser_45-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_45-find_replace';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:45';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'wordpress',
    'replace' => 'WordPress',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Proper capitalization of WordPress';
  $export['catalog_multi_upload-xpathparser_45-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_48-unique';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:48';
  $feeds_tamper->plugin_id = 'unique';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Unique';
  $export['catalog_multi_upload-xpathparser_48-unique'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_50-implode';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:50';
  $feeds_tamper->plugin_id = 'implode';
  $feeds_tamper->settings = array(
    'glue' => '; ',
    'real_glue' => '; ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Implode';
  $export['catalog_multi_upload-xpathparser_50-implode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_58-convert_case';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:58';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '2',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['catalog_multi_upload-xpathparser_58-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_60-copy';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:60';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'xpathparser:32',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Copy source value';
  $export['catalog_multi_upload-xpathparser_60-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_60-find_replace';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:60';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Summer',
    'replace' => 'UG',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace Summer to UG';
  $export['catalog_multi_upload-xpathparser_60-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_62-default_value';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:62';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
    'only_if_empty' => 1,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Default publish state (for old feed)';
  $export['catalog_multi_upload-xpathparser_62-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_62-find_replace';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:62';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Unpublished',
    'replace' => '0',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Unpublished$/u',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Unpublished = 0';
  $export['catalog_multi_upload-xpathparser_62-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'catalog_multi_upload-xpathparser_62-find_replace2';
  $feeds_tamper->importer = 'catalog_multi_upload';
  $feeds_tamper->source = 'xpathparser:62';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'Published',
    'replace' => '1',
    'case_sensitive' => 1,
    'word_boundaries' => 1,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^Published$/u',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Published = 1';
  $export['catalog_multi_upload-xpathparser_62-find_replace2'] = $feeds_tamper;

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
  $feeds_tamper->id = 'faculty_directory-xpathparser_4-convert_case';
  $feeds_tamper->importer = 'faculty_directory';
  $feeds_tamper->source = 'xpathparser:4';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '0',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['faculty_directory-xpathparser_4-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'faculty_directory-xpathparser_6-rewrite';
  $feeds_tamper->importer = 'faculty_directory';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'public://faculty/images/portraits/[xpathparser:6].jpg',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['faculty_directory-xpathparser_6-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'faculty_directory-xpathparser_8-find_replace_regex';
  $feeds_tamper->importer = 'faculty_directory';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[^,]*, /',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'REGEX to remove last name';
  $export['faculty_directory-xpathparser_8-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'faculty_directory-xpathparser_9-find_replace_regex2';
  $feeds_tamper->importer = 'faculty_directory';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/, (.)*/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'REGEX to remove first name';
  $export['faculty_directory-xpathparser_9-find_replace_regex2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mailing_lists_feed_importer-xpathparser_3-community';
  $feeds_tamper->importer = 'mailing_lists_feed_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'community',
    'replace' => 'Community Lists',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'community';
  $export['mailing_lists_feed_importer-xpathparser_3-community'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mailing_lists_feed_importer-xpathparser_3-find_replace';
  $feeds_tamper->importer = 'mailing_lists_feed_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'programs',
    'replace' => 'Program Lists',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'programs';
  $export['mailing_lists_feed_importer-xpathparser_3-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mailing_lists_feed_importer-xpathparser_3-sponsored';
  $feeds_tamper->importer = 'mailing_lists_feed_importer';
  $feeds_tamper->source = 'xpathparser:3';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'tescsponsor',
    'replace' => 'Sponsored Lists',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'sponsored';
  $export['mailing_lists_feed_importer-xpathparser_3-sponsored'] = $feeds_tamper;

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
  $feeds_tamper->id = 'office_directory-xpathparser_12-find_replace';
  $feeds_tamper->importer = 'office_directory';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'CABrd Floor',
    'replace' => 'CAB',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Fix whole floor rooms in CAB';
  $export['office_directory-xpathparser_12-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory-xpathparser_12-find_replace_regex';
  $feeds_tamper->importer = 'office_directory';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/ ([ABCDEL](-)*)?[0-9]+([A-Z])*/',
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
  $feeds_tamper->id = 'office_directory-xpathparser_14-convert_case';
  $feeds_tamper->importer = 'office_directory';
  $feeds_tamper->source = 'xpathparser:14';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '0',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['office_directory-xpathparser_14-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory-xpathparser_9-find_replace';
  $feeds_tamper->importer = 'office_directory';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '3Floor',
    'replace' => '3rd Floor',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Fix whole floor rooms in CAB (3rd floor)';
  $export['office_directory-xpathparser_9-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'office_directory-xpathparser_9-find_replace2';
  $feeds_tamper->importer = 'office_directory';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '2Floor',
    'replace' => '2nd Floor',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Fix whole floor rooms in CAB (2nd floor)';
  $export['office_directory-xpathparser_9-find_replace2'] = $feeds_tamper;

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
  $feeds_tamper->id = 'office_directory_facility-blank_source_1-convert_boolean';
  $feeds_tamper->importer = 'office_directory_facility';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'true',
    'false_value' => 'false',
    'match_case' => 0,
    'no_match' => 'true',
    'other_text' => '',
    'no_match_value' => TRUE,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Convert to boolean (always true)';
  $export['office_directory_facility-blank_source_1-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
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
    'find' => '/ ([ABCDEL](-)*)?[0-9]+([A-Z])*/',
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
  $feeds_tamper->id = 'people_directory-blank_source_1-default_value';
  $feeds_tamper->importer = 'people_directory';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'US',
    'only_if_empty' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['people_directory-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'people_directory-xpathparser_10-convert_case';
  $feeds_tamper->importer = 'people_directory';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'convert_case';
  $feeds_tamper->settings = array(
    'mode' => '0',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert case';
  $export['people_directory-xpathparser_10-convert_case'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'people_directory-xpathparser_12-find_replace';
  $feeds_tamper->importer = 'people_directory';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '110 Fifth Avenue SE, Suite 214 PO Box 40999',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Remove WSIPP';
  $export['people_directory-xpathparser_12-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'people_directory-xpathparser_12-find_replace_regex';
  $feeds_tamper->importer = 'people_directory';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/ ([ABCDEL](-)*)?[0-9]+([A-Z])*/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 2;
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
    'find' => '/[^,]*, /',
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
    'find' => '/, (.)*/',
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
  $feeds_tamper->id = 'people_directory-xpathparser_9-find_replace';
  $feeds_tamper->importer = 'people_directory';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '110 Fifth Avenue SE, Suite 214 PO Box 40999',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Remove WSIPP';
  $export['people_directory-xpathparser_9-find_replace'] = $feeds_tamper;

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
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'REGEX to remove Building';
  $export['people_directory-xpathparser_9-find_replace_regex'] = $feeds_tamper;

  return $export;
}
