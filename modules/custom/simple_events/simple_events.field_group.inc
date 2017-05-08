<?php
/**
 * @file
 * simple_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function simple_events_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|taxonomy_term|site_sections|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '1',
    'children' => array(
      0 => 'field_long_name',
      1 => 'field_background_image',
      2 => 'name',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basics field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_basics|taxonomy_term|site_sections|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|taxonomy_term|site_sections|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_basics',
      1 => 'group_navigation',
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
  $field_groups['group_group|taxonomy_term|site_sections|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_navigation|taxonomy_term|site_sections|form';
  $field_group->group_name = 'group_navigation';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Navigation',
    'weight' => '2',
    'children' => array(
      0 => 'field_section_navigation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-navigation field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_navigation|taxonomy_term|site_sections|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Basics');
  t('Group');
  t('Navigation');

  return $field_groups;
}
