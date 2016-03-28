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
            'source' => 'address',
            'target' => 'field_address:thoroughfare',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'city',
            'target' => 'field_address:locality',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'state',
            'target' => 'field_address:administrative_area',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'zipcode',
            'target' => 'field_address:postal_code',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'country',
            'target' => 'field_address:country',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'institutionWebsite',
            'target' => 'field_institution_website:url',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'institutionType_PublicOrIndependent',
            'target' => 'field_public_or_private',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'institutionType_2Or4Year',
            'target' => 'field_two_or_four_year',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'institutionType_StudentsServed',
            'target' => 'field_population_served',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'undergradEnrollment_Fulltime',
            'target' => 'field_full_time_enrollment',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'undergradEnrollment_Parttime',
            'target' => 'field_part_time_enrollment',
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

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'programs';
  $feeds_importer->config = array(
    'name' => 'Programs',
    'description' => 'Starting import of the LC programs',
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
            'source' => 'institutionName',
            'target' => 'field_institution:label',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'LCOfferings',
            'target' => 'field_number_of_communities',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'LCStudentsEnrolled',
            'target' => 'field_number_of_students',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'LCFacultyStaff',
            'target' => 'field_number_of_faculty_staff',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'LCWebsite',
            'target' => 'field_program_website:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'learning_community_program',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['programs'] = $feeds_importer;

  return $export;
}
