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
 * Implements hook_node_info().
 */
function native_cases_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('News items for the site\'s home page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'case_study' => array(
      'name' => t('Case Study'),
      'base' => 'node_content',
      'description' => t('A <em>case study</em> tells a story about a problem and its history, then ends with a leading question so that students work through the case themselves.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('A <em>page</em> is a static content type, just text and images.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
