<?php
/**
 * @file
 * evergreen_archives.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function evergreen_archives_ctools_plugin_api($module = NULL, $api = NULL) {
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
function evergreen_archives_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function evergreen_archives_node_info() {
  $items = array(
    'accession' => array(
      'name' => t('Accession'),
      'base' => 'node_content',
      'description' => t('Create a new archival accession.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'name' => array(
      'name' => t('Name'),
      'base' => 'node_content',
      'description' => t('Create a new Name reference for a person or organization. '),
      'has_title' => '1',
      'title_label' => t('Name '),
      'help' => '',
    ),
    'resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'subject' => array(
      'name' => t('Subject'),
      'base' => 'node_content',
      'description' => t('Add a new subject.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
