<?php
/**
 * @file
 * campus_calendar.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function campus_calendar_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|event|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'group',
    'weight' => '2',
    'children' => array(
      0 => 'group_what',
      1 => 'group_when',
      2 => 'group_where',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-group field-group-htabs',
      ),
    ),
  );
  $field_groups['group_group|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_on_campus|node|event|form';
  $field_group->group_name = 'group_location_on_campus';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_where';
  $field_group->data = array(
    'label' => 'Location: On Campus',
    'weight' => '5',
    'children' => array(
      0 => 'field_building',
      1 => 'field_room',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-location-on-campus field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_location_on_campus|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_what|node|event|form';
  $field_group->group_name = 'group_what';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'What',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_category',
      2 => 'field_format',
      3 => 'field_image',
      4 => 'field_sponsored_by',
      5 => 'field_flyer',
      6 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_what|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_when|node|event|form';
  $field_group->group_name = 'group_when';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'When',
    'weight' => '5',
    'children' => array(
      0 => 'field_event_date',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_when|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_where|node|event|form';
  $field_group->group_name = 'group_where';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Where',
    'weight' => '6',
    'children' => array(
      0 => 'field_location_off_campus',
      1 => 'group_location_on_campus',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_where|node|event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Location: On Campus');
  t('What');
  t('When');
  t('Where');
  t('group');

  return $field_groups;
}
