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
  $field_group->identifier = 'group_group|node|basic_page|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'group',
    'weight' => '3',
    'children' => array(
      0 => 'group_primary',
      1 => 'group_secondary',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-group field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_group|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_primary|node|basic_page|form';
  $field_group->group_name = 'group_primary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Primary Content',
    'weight' => '6',
    'children' => array(
      0 => 'body',
      1 => 'field_intro',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-primary field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_primary|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_secondary|node|basic_page|form';
  $field_group->group_name = 'group_secondary';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Secondary Content',
    'weight' => '7',
    'children' => array(
      0 => 'field_secondary_content',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-secondary field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_secondary|node|basic_page|form'] = $field_group;

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
  t('Primary Content');
  t('Secondary Content');
  t('Student Body');
  t('group');

  return $field_groups;
}
