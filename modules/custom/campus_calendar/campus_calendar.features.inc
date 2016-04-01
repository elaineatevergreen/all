<?php
/**
 * @file
 * campus_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function campus_calendar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function campus_calendar_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function campus_calendar_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Use an <em>event</em> when you need to add something to an event calendar or create other date-based content, including deadlines, instruction start and end dates, and holidays.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('<p>Evergreen\'s Campus Calendars provide a comprehensive list of college-sponsored events on campus. <strong>Posting an event on the Campus Calendars does not reserve space for the event.</strong></p>
<p>Before you post an event:</p>
<ul><li><a href="/calendar/guidelines">Review the submission guidelines.</a></li>
<li><a href="http://www.evergreen.edu/facilities/spacescheduling.htm">Reserve your space with Evergreen Facilities</a></li></ul>'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
