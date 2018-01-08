<?php
/**
 * @file
 * evergreen_policies.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function evergreen_policies_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|policy|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'policy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '9',
    'children' => array(
      0 => 'field_previous_version',
      1 => 'field_related_policies',
      2 => 'field_related_documents',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related|node|policy|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Related');

  return $field_groups;
}
