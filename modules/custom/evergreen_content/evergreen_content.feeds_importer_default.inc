<?php
/**
 * @file
 * evergreen_content.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function evergreen_content_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'academic_calendar_csv';
  $feeds_importer->config = array(
    'name' => 'Academic Calendar CSV',
    'description' => 'Allows importing of academic calendar dates from a spreadsheet!',
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
        'encoding' => 'UTF-8',
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
            'source' => 'Published',
            'target' => 'status',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Quarter',
            'target' => 'field_academic_quarter',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'Start',
            'target' => 'field_event_date:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'End',
            'target' => 'field_event_date:end',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Format',
            'target' => 'field_format',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Category',
            'target' => 'field_category',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'event',
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
  $export['academic_calendar_csv'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'catalog';
  $feeds_importer->config = array(
    'name' => 'Catalog',
    'description' => 'Imports catalog from the CMD',
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
          'xpathparser:1' => 'description',
          'xpathparser:2' => '',
          'xpathparser:3' => 'time_of_day',
          'xpathparser:4' => '@id',
          'xpathparser:5' => '@id',
          'xpathparser:6' => '@offering_type',
          'xpathparser:7' => 'credits',
          'xpathparser:8' => 'location',
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
        ),
        'context' => '/programs/program',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'xpathparser:7' => 'xpathparser:7',
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:8' => 0,
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
            'unique' => FALSE,
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
            'target' => 'field_class_standing',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_time_offered',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_cmd_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_offering_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_credits',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_location',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'basic_tags',
        'skip_hash_check' => 0,
        'bundle' => 'catalog_entry',
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
  $export['catalog'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'e2campus';
  $feeds_importer->config = array(
    'name' => 'e2Campus',
    'description' => 'Generates alerts based on e2Campus announcements',
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
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
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
          ),
          1 => array(
            'source' => 'description',
            'target' => 'field_alert_message',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '0',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'alert',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['e2campus'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'faculty_directory';
  $feeds_importer->config = array(
    'name' => 'Faculty Directory',
    'description' => 'This (should) add more information for people who are also faculty.',
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
          'xpathparser:0' => '@user_name',
          'xpathparser:1' => 'bio',
          'xpathparser:2' => 'expertise',
          'xpathparser:3' => 'interests',
          'xpathparser:4' => 'name',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '/instructors/faculty',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'xpathparser:4' => 'xpathparser:4',
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_background',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_expertise',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_interests',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'title',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'Blank source 1',
            'target' => 'field_is_faculty',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'directory_individual',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['faculty_directory'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'office_directory';
  $feeds_importer->config = array(
    'name' => 'Office Directory',
    'description' => 'Imports offices from the adminweb directory.',
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
          'xpathparser:0' => 'phone_alt',
          'xpathparser:1' => 'email_addressable',
          'xpathparser:6' => 'mailstop',
          'xpathparser:7' => 'phone',
          'xpathparser:9' => 'location',
          'xpathparser:10' => 'name',
          'xpathparser:11' => 'fax',
          'xpathparser:12' => 'location',
          'xpathparser:13' => 'url',
          'xpathparser:14' => 'members/people/person/name',
          'xpathparser:15' => 'reference',
          'xpathparser:16' => 'members/offices/office/name',
          'xpathparser:17' => 'members/facilities/facility/name',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
        ),
        'context' => '/offices/office',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
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
            'target' => 'field_alternate_phone:url',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_mailstop',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_phone:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_room',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:10',
            'target' => 'title',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_fax:url',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_building_alt',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_websites:url',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_members:label',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_reference:label',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_related_offices:label',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_facilities:label',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'directory_office',
        'update_non_existent' => 'skip',
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
  $export['office_directory'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'office_directory_facility';
  $feeds_importer->config = array(
    'name' => 'Office Directory - Facility',
    'description' => 'These items are sub-sections of offices.',
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
          'xpathparser:0' => 'phone_alt',
          'xpathparser:1' => 'email_addressable',
          'xpathparser:6' => 'mailstop',
          'xpathparser:7' => 'phone',
          'xpathparser:9' => 'location',
          'xpathparser:10' => 'name',
          'xpathparser:11' => 'fax',
          'xpathparser:12' => 'location',
          'xpathparser:13' => 'url',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
        ),
        'context' => '/offices/office/members/facilities/facility',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
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
            'target' => 'field_alternate_phone:url',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_mailstop',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_phone:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_room',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:10',
            'target' => 'title',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_fax:url',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_building_alt',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_websites:url',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Blank source 1',
            'target' => 'field_facility',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'directory_office',
        'update_non_existent' => 'delete',
        'insert_new' => '1',
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
  $export['office_directory_facility'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'people_directory';
  $feeds_importer->config = array(
    'name' => 'People Directory',
    'description' => 'Imports individuals from the adminweb directory.',
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
          'xpathparser:0' => 'phone_alt',
          'xpathparser:1' => 'email_addressable',
          'xpathparser:2' => 'name',
          'xpathparser:3' => 'name',
          'xpathparser:4' => 'title',
          'xpathparser:5' => 'name',
          'xpathparser:6' => 'mailstop',
          'xpathparser:7' => 'phone',
          'xpathparser:9' => 'location',
          'xpathparser:10' => 'name',
          'xpathparser:11' => 'fax',
          'xpathparser:12' => 'location',
          'xpathparser:13' => 'email',
          'xpathparser:14' => 'reference/text()',
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
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
        ),
        'context' => '/people/person',
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
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
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
            'target' => 'field_alternate_phone:url',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_job_title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_mailstop',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_phone:url',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_room',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'title',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_fax:url',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_building_alt',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_cas_name',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_reference:label',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'directory_individual',
        'update_non_existent' => 'unpublish',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['people_directory'] = $feeds_importer;

  return $export;
}
