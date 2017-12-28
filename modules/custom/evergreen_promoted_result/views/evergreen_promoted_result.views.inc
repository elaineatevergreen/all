<?php

/**
 * @file
 * Views related hooks for evergreen_promoted_result.
 */

/**
 * Implements hook_views_data_alter().
 */
function evergreen_promoted_result_views_data_alter(&$data) {
  // Add a special handler to process node results inside search_api content
  // search views.
  $data['search_api_index_content_search']['eg_promoted_node'] = array(
    'title' => t('Evergreen - Promoted node'),
    'help' => t('Will link the result to the destination URL if it is a promoted node, otherwise will show the original content.'),
    'field' => array(
      'handler' => 'evergreen_promoted_result_handler_promoted_node',
    ),
  );
  $data['search_api_index_content_search']['eg_promoted_node_rendered'] = array(
    'title' => t('Evergreen - Promoted node (rendered)'),
    'help' => t('Will show the node rendered using a viewmode. This will be linked to a destination that will be either: 1) the node URL for regular nodes, or 2) the "Destination URL" field for promoted nodes.'),
    'field' => array(
      'handler' => 'evergreen_promoted_result_handler_promoted_node_rendered',
    ),
  );
}
