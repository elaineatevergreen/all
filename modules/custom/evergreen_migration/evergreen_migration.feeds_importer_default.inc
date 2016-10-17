<?php
/**
 * @file
 * evergreen_migration.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function evergreen_migration_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'alumni_circle_import';
  $feeds_importer->config = array(
    'name' => '_Migration Upload: Alumni Circle Import',
    'description' => 'Import existing circles from other Drupal\'s XML',
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
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'title',
          'xpathparser:1' => 'websites/div/ul/li/a/text()',
          'xpathparser:2' => 'websites/div/ul/li/a/@href',
          'xpathparser:3' => 'email/div/ul/li/a/@href',
          'xpathparser:4' => 'phone',
          'xpathparser:5' => 'content',
          'xpathparser:6' => 'teaser',
          'xpathparser:7' => 'meetingtimelong',
        ),
        'rawXML' => array(
          'xpathparser:5' => 'xpathparser:5',
          'xpathparser:6' => 'xpathparser:6',
          'xpathparser:7' => 'xpathparser:7',
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '/groups/group',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_websites:title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_websites:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_email',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_phone:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'body:summary',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_meetings',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'basic_tags',
        'skip_hash_check' => 0,
        'bundle' => 'alumni_circles',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['alumni_circle_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'author_directory';
  $feeds_importer->config = array(
    'name' => '_Migration: Author Directory',
    'description' => 'Importing authors from blobby HTML',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:5' => 'id',
          'xpathparser:0' => 'lastname',
          'xpathparser:1' => 'firstname',
          'xpathparser:2' => 'gradyear',
          'xpathparser:3' => 'bio',
          'xpathparser:6' => 'email',
          'xpathparser:7' => 'role',
        ),
        'rawXML' => array(
          'xpathparser:3' => 'xpathparser:3',
          'xpathparser:5' => 0,
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
        ),
        'context' => '/authors/author',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:5' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_last_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_first_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_graduated_alt',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:3',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Blank source 1',
            'target' => 'field_display',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_email',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_roles',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'basic_tags',
        'skip_hash_check' => 0,
        'bundle' => 'profile',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['author_directory'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'calendar_events';
  $feeds_importer->config = array(
    'name' => '_Migration: Calendar Events',
    'description' => 'Import existing events from CSV',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Start Date',
            'target' => 'field_event_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'End Date',
            'target' => 'field_event_date:end',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'quarter',
            'target' => 'field_academic_quarter',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'building',
            'target' => 'field_building',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'room',
            'target' => 'field_room',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'sponsor',
            'target' => 'field_sponsored_by',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'promote',
            'target' => 'promote',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'nid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'created',
            'target' => 'created',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'null',
            'target' => 'status',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'category',
            'target' => 'field_calendar_categories',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          13 => array(
            'source' => 'format',
            'target' => 'field_event_format',
            'term_search' => '0',
            'autocreate' => 1,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'basic_tags',
        'skip_hash_check' => 0,
        'bundle' => 'event',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['calendar_events'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'campus_locations';
  $feeds_importer->config = array(
    'name' => '_Migration Upload: Campus Locations',
    'description' => 'Means we only have to input this info once!',
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
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Nid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Official Name',
            'target' => 'field_official_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Abbreviated Building Name',
            'target' => 'field_abbreviated_building_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Description',
            'target' => 'body',
            'format' => 'full_html',
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Location Category',
            'target' => 'field_location_category',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Building History',
            'target' => 'field_building_history',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Square Footage',
            'target' => 'field_square_footage',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'location',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['campus_locations'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'entrepreneur_directory';
  $feeds_importer->config = array(
    'name' => '_Migration Upload: Entrepreneur Directory',
    'description' => 'Converts wufoo form data to nodes',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Field41',
          'xpathparser:1' => 'Field42',
          'xpathparser:2' => 'Field3',
          'xpathparser:3' => 'Field49',
          'xpathparser:4' => 'Field37',
          'xpathparser:5' => 'EntryId',
          'xpathparser:6' => 'Field375',
          'xpathparser:7' => 'Field7',
          'xpathparser:8' => 'Field9',
          'xpathparser:9' => 'Field10',
          'xpathparser:10' => 'Field34',
          'xpathparser:11' => 'Field6',
          'xpathparser:12' => 'Field23',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
        ),
        'context' => '/Entries/Entry',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_first_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_last_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_business_name',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_business_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Blank source 1',
            'target' => 'field_display',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_how_did_your_evergreen_edu',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_business_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_business_address:thoroughfare',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_business_address:locality',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_business_address:administrative_area',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Blank source 2',
            'target' => 'field_business_address:country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_graduated_alt',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_dates_of_operation',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_email',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Blank source 3',
            'target' => 'field_roles',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'profile',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['entrepreneur_directory'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'faculty_categories_import';
  $feeds_importer->config = array(
    'name' => '_Migration Upload: Faculty Categories Import',
    'description' => 'Brings terms in from directory',
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
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Term Name',
            'target' => 'name',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'faculty_directory_categories',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['faculty_categories_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'fields_of_study_import';
  $feeds_importer->config = array(
    'name' => '_Migration Upload: Fields of Study Basic Import',
    'description' => 'Imports existing field codes, relationships, and blurbs from collabtest/cms',
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
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'code',
            'target' => 'name',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Description',
            'target' => 'description',
            'format' => 'full_html',
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Related field',
            'target' => 'parent',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'faculty_directory_categories',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['fields_of_study_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'hero_images';
  $feeds_importer->config = array(
    'name' => '_Migration: Hero Images',
    'description' => 'Add the current items to the home page.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'caption',
          'xpathparser:1' => 'classes',
          'xpathparser:2' => 'link',
          'xpathparser:3' => 'link',
          'xpathparser:4' => 'link',
          'xpathparser:5' => 'link',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
        ),
        'context' => '/images/image',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_classes',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_hero_image:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_hero_image_large:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_hero_image_medium:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_hero_image_small:uri',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'home_page_hero',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['hero_images'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'library_database_subjects';
  $feeds_importer->config = array(
    'name' => '_Migration Upload: Library Database Subjects',
    'description' => 'Imported from spreadsheet',
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
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Term',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Parent',
            'target' => 'parent',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'database_of_databases',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['library_database_subjects'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'library_databases';
  $feeds_importer->config = array(
    'name' => '_Migration Upload: Library Databases',
    'description' => 'Initial importer',
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
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'title',
          'xpathparser:1' => 'link',
          'xpathparser:2' => 'description',
          'xpathparser:3' => 'bayredirect',
          'xpathparser:4' => 'featured',
          'xpathparser:5' => 'narrowsubject/div/ul/li',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
        ),
        'context' => '/databases/resources',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_resource_link:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_proxy',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_featured',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_resource_subject',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'library_database',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['library_databases'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'navigation_import';
  $feeds_importer->config = array(
    'name' => '_Migration Upload: Navigation Import',
    'description' => 'For moving navigations from site to site (live to dev etc)',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'sitename/text()',
          'xpathparser:1' => 'sitename/text()',
          'xpathparser:2' => 'id',
          'xpathparser:3' => 'group/text()',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
        ),
        'context' => '/sections/section',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'xpathparser:0' => 'xpathparser:0',
            'xpathparser:1' => 'xpathparser:1',
            'xpathparser:2' => 'xpathparser:2',
            'xpathparser:3' => 'xpathparser:3',
            'context' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFieldCollectionProcessor',
      'config' => array(
        'field_name' => 'field_section_navigation',
        'host_entity_type' => 'taxonomy_term',
        'is_field' => 1,
        'guid_field_name' => 'name',
        'identifier_field_name' => 'name',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'identifier_field',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_group_title',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_section_navigation',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['navigation_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'scholarship_import';
  $feeds_importer->config = array(
    'name' => '_Migration: Scholarship Import',
    'description' => 'Imports XML from Cascade',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'title',
          'xpathparser:1' => 'system-data-structure/description',
          'xpathparser:2' => 'system-data-structure/amount',
          'xpathparser:3' => 'system-data-structure/requirements/standing/value',
          'xpathparser:4' => 'system-data-structure/requirements/fafsa/value',
          'xpathparser:5' => 'system-data-structure/deadline',
          'xpathparser:6' => 'system-data-structure/requirements/criteria/value',
          'xpathparser:7' => 'system-data-structure/give/cashnet',
          'xpathparser:8' => 'path',
          'xpathparser:9' => 'system-data-structure/requirements/needbased',
          'xpathparser:10' => 'system-data-structure/requirements/newOrCurrent',
          'xpathparser:11' => 'system-data-structure/tuitionAward',
          'xpathparser:12' => 'system-data-structure/requirements/criteria',
          'xpathparser:13' => 'system-data-structure/requirements/underrepresented/underrepresented',
        ),
        'rawXML' => array(
          'xpathparser:1' => 'xpathparser:1',
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
        ),
        'context' => '/system-index-block/system-page',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_amount',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_class_standing',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_fafsa_or_wasfa_required',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_deadline:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_short_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_cashnet_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_site_section',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_need_based',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_new_or_current',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_tuition_award',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_short_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_under_represented',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'scholarship',
        'insert_new' => 1,
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['scholarship_import'] = $feeds_importer;

  return $export;
}
