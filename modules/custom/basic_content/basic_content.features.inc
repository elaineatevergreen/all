<?php
/**
 * @file
 * basic_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function basic_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function basic_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function basic_content_node_info() {
  $items = array(
    'article' => array(
      'name' => t('News or Blog Post'),
      'base' => 'node_content',
      'description' => t('Use <em>a news story or blog post</em> for time-sensitive content like news, press releases or blog posts. Contact the Web Team to find out how to display lists of articles in your site section.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'basic_page' => array(
      'name' => t('Basic Page'),
      'base' => 'node_content',
      'description' => t('Use a <em>basic page</em> for most of your website content needs.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
