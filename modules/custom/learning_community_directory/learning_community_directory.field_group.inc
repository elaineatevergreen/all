<?php
/**
 * @file
 * learning_community_directory.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function learning_community_directory_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|institution|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '4',
    'children' => array(
      0 => 'field_address',
      1 => 'field_institution_website',
      2 => 'field_individual_contacts',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contact|node|institution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_students|node|institution|default';
  $field_group->group_name = 'group_students';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Student Body',
    'weight' => '3',
    'children' => array(
      0 => 'field_full_time_enrollment',
      1 => 'field_part_time_enrollment',
      2 => 'field_population_served',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Student Body',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-students field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_students|node|institution|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_students|node|institution|form';
  $field_group->group_name = 'group_students';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Student Body',
    'weight' => '2',
    'children' => array(
      0 => 'field_full_time_enrollment',
      1 => 'field_part_time_enrollment',
      2 => 'field_population_served',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-students field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_students|node|institution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_type|node|institution|default';
  $field_group->group_name = 'group_type';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Institution Type',
    'weight' => '2',
    'children' => array(
      0 => 'field_public_or_private',
      1 => 'field_two_or_four_year',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Institution Type',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-type field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_type|node|institution|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_type|node|institution|form';
  $field_group->group_name = 'group_type';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Institution Type',
    'weight' => '1',
    'children' => array(
      0 => 'field_public_or_private',
      1 => 'field_two_or_four_year',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-type field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_type|node|institution|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Institution Type');
  t('Student Body');

  return $field_groups;
}
