<?php
/**
 * @file
 * evergreen_promoted_result.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function evergreen_promoted_result_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function evergreen_promoted_result_node_info() {
  $items = array(
    'promoted_search_result' => array(
      'name' => t('Promoted Search Result'),
      'base' => 'node_content',
      'description' => t('Create a node of this type to allow an arbitrary URL to appear as the first result when a given term is searched.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
