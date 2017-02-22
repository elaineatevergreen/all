<?php
/**
 * @file
 * learning_community_directory.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function learning_community_directory_ctools_plugin_api($module = NULL, $api = NULL) {
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
function learning_community_directory_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function learning_community_directory_node_info() {
  $items = array(
    'institution' => array(
      'name' => t('Institution'),
      'base' => 'node_content',
      'description' => t('An <em>institution</em> is a college, university, or similar. An institution may host one or more learning community programs.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'learning_community_program' => array(
      'name' => t('Learning Community Program'),
      'base' => 'node_content',
      'description' => t('A <em>Learning Community Program</em> is a specific project connected with an institution.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
