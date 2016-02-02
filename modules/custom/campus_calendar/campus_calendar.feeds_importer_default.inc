<?php
/**
 * @file
 * campus_calendar.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function campus_calendar_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'google_calendar_ical';
  $feeds_importer->config = array(
    'name' => 'Google Calendar ical',
    'description' => 'Import the existing campus calendar from Google Calendar.',
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
      'plugin_key' => 'DateiCalFeedsParser',
      'config' => array(
        'indefinite_count' => '31',
        'indefinite_message_display' => 1,
        'until_not_utc' => 0,
        'skip_days' => '365',
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
            'source' => 'SUMMARY',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'DESCRIPTION',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'DTSTART',
            'target' => 'field_event_date:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'DTEND',
            'target' => 'field_event_date:end',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'RRULE',
            'target' => 'field_event_date:rrule',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'LOCATION',
            'target' => 'field_room',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'UID',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'event',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['google_calendar_ical'] = $feeds_importer;

  return $export;
}
