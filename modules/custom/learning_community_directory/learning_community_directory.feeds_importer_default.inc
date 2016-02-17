<?php
/**
 * @file
 * learning_community_directory.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function learning_community_directory_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'institutions';
  $feeds_importer->config = array(
    'name' => 'Institutions',
    'description' => 'colleges imported from the old spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'institutionName',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'institutionWebsite',
            'target' => 'field_institution_website:url',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Public/Independent',
            'target' => 'field_public_or_private',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => '2Or4Year',
            'target' => 'field_two_or_four_year',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'StudentsServed',
            'target' => 'field_population_served',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'zipcode',
            'target' => 'field_address:postal_code',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'state',
            'target' => 'field_address:administrative_area',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'city',
            'target' => 'field_address:locality',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'address',
            'target' => 'field_address:thoroughfare',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'country',
            'target' => 'field_address:country',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'institution',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['institutions'] = $feeds_importer;

  return $export;
}
