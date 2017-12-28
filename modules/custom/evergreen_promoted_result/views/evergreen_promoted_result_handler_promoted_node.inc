<?php

/**
 * @file
 * Definition of evergreen_promoted_result_handler_promoted_node.
 */

/**
 * Renders the title of the node linked to the destination URL, if promoted.
 *
 * @ingroup views_field_handlers
 */
class evergreen_promoted_result_handler_promoted_node extends views_handler_field {

  function query() {
    // Nothing, but needs to be here.
  }

  function render($values) {
    $output = NULL;
    // If this result corresponds to a "promoted_search_result" node type, we
    // output its title linked to whatever URL is in the
    // "field_promoted_destination_url" field. Return empty otherwise.
    if (!empty($values->_entity_properties['entity object']->type) && $values->_entity_properties['entity object']->type === 'promoted_search_result') {
      $url_item = field_get_items('node', $values->_entity_properties['entity object'], 'field_promoted_destination_url');
      if (!empty($url_item[0]['url'])) {
        $output = l(check_plain($values->_entity_properties['entity object']->title), $url_item[0]['url']);
      }
    }
    return $output;
  }

}
