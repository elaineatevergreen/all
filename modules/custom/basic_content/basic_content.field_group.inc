<?php
/**
 * @file
 * basic_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function basic_content_field_group_info() {
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
  $field_group->identifier = 'group_group|node|basic_page|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'basic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'group',
    'weight' => '2',
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
  $field_group->identifier = 'group_images|node|article|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '4',
    'children' => array(
      0 => 'field_highlight',
      1 => 'field_thumbnail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-images field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_images|node|article|form'] = $field_group;

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
    'weight' => '4',
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
    'weight' => '5',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Basics');
  t('Group');
  t('Images');
  t('Navigation');
  t('Primary Content');
  t('Secondary Content');
  t('group');

  return $field_groups;
}
