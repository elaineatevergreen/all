<?php

/**
 * @file
 * Contains the evergreen_promoted_result_handler_promoted_node_rendered class.
 */

/**
 * Renders the full node.
 *
 * Will always be wrapped in a link. The link href will be the node URL for a
 * standard node, or the destination URL field value, for a promoted node.
 *
 * @ingroup views_field_handlers
 */
class evergreen_promoted_result_handler_promoted_node_rendered extends views_handler_field {

  public function option_definition() {
    $options = parent::option_definition();

    $options['view_mode'] = array('default' => 'default');

    return $options;
  }

  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Stolen from entity_views_plugin_row_entity_view.
    $entity_info = entity_get_info('node');
    $options = array();
    if (!empty($entity_info['view modes'])) {
      foreach ($entity_info['view modes'] as $mode => $settings) {
        $options[$mode] = $settings['label'];
      }
    }

    if (count($options) > 1) {
      $form['view_mode'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#title' => t('View mode'),
        '#default_value' => $this->options['view_mode'],
        '#dependency' => array('edit-options-display' => array('view')),
      );
    }
    else {
      $form['view_mode'] = array(
        '#type' => 'value',
        '#value' => $options ? key($options) : 'default',
      );
    }
  }

  function query() {
    // Nothing, but needs to be here.
  }

  public function render($values) {
    $output = NULL;
    $href = NULL;
    if (!empty($this->options['view_mode']) && !empty($values->_entity_properties['entity object']->type)) {
      $node_build = node_view($values->_entity_properties['entity object'], $this->options['view_mode']);
      if ($values->_entity_properties['entity object']->type === 'promoted_search_result') {
        $url_item = field_get_items('node', $values->_entity_properties['entity object'], 'field_promoted_destination_url');
        $href = !empty($url_item[0]['url']) ? $url_item[0]['url'] : NULL;
      }
      else {
        $href = url('node/' . $values->_entity_properties['entity object']->nid);
      }
      $output = '<a href="' . $href . '">' . drupal_render($node_build) . '</a>';
    }
    return $output;
  }

}
