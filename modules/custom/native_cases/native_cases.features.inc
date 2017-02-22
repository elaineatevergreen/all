<?php
/**
 * @file
 * native_cases.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function native_cases_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function native_cases_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function native_cases_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['M j'] = 'M j';
  $custom_date_formats['Y'] = 'Y';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function native_cases_date_format_types() {
  $format_types = array();
  // Exported date format type: monthday
  $format_types['monthday'] = 'MonthDay';
  // Exported date format type: year
  $format_types['year'] = 'Year';
  return $format_types;
}

/**
 * Implements hook_node_info().
 */
function native_cases_node_info() {
  $items = array(
    'case_study' => array(
      'name' => t('Case Study'),
      'base' => 'node_content',
      'description' => t('A <em>case study</em> tells a story about a problem and its history, then ends with a leading question so that students work through the case themselves.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
