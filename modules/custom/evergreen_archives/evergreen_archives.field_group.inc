<?php
/**
 * @file
 * evergreen_archives.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function evergreen_archives_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin_information|node|resource|default';
  $field_group->group_name = 'group_admin_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Administrative Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_arrangement',
      1 => 'field_location_of_collection',
      2 => 'field_accruals',
      3 => 'field_custodial_history',
      4 => 'field_dimensions',
      5 => 'field_other_copies',
      6 => 'field_existence_of_originals',
      7 => 'field_file_plan',
      8 => 'field_general',
      9 => 'field_physical_description',
      10 => 'field_source_of_acquisition',
      11 => 'field_language_of_materials',
      12 => 'field_material_specific_details',
      13 => 'field_other_finding_aids',
      14 => 'field_field_tech_requirements',
      15 => 'field_processing_information',
      16 => 'field_related_archival_materials',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin-information field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_collection_use|node|resource|default';
  $field_group->group_name = 'group_collection_use';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Use of the Collection',
    'weight' => '4',
    'children' => array(
      0 => 'field_restrictions_on_use',
      1 => 'field_preferred_citation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-collection-use field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_description|node|resource|default';
  $field_group->group_name = 'group_content_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Description',
    'weight' => '3',
    'children' => array(
      0 => 'field_scope_and_contents',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content-description field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_detailed_description|node|resource|default';
  $field_group->group_name = 'group_detailed_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Detailed Description of the Collection',
    'weight' => '19',
    'children' => array(
      0 => 'field_detailed_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-detailed-description field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_find_related_collections|node|resource|default';
  $field_group->group_name = 'group_find_related_collections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Find Related Collections',
    'weight' => '1',
    'children' => array(
      0 => 'field_res_related_subjects',
      1 => 'field_res_related_names',
      2 => 'field_res_related_accessions',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-find-related-collections field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_find_related_materials|node|accession|default';
  $field_group->group_name = 'group_find_related_materials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'accession';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Find Related Materials',
    'weight' => '10',
    'children' => array(
      0 => 'field_related_subjects',
      1 => 'field_related_names',
      2 => 'field_acc_related_resources',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-find-related-materials field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_historical_note|node|resource|default';
  $field_group->group_name = 'group_historical_note';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Historical Note',
    'weight' => '2',
    'children' => array(
      0 => 'field_historical_note',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-historical-note field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notes|node|resource|form';
  $field_group->group_name = 'group_notes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notes',
    'weight' => '11',
    'children' => array(
      0 => 'field_resource_summary',
      1 => 'field_res_access_restrictions',
      2 => 'field_historical_note',
      3 => 'field_scope_and_contents',
      4 => 'field_restrictions_on_use',
      5 => 'field_preferred_citation',
      6 => 'field_arrangement',
      7 => 'field_location_of_collection',
      8 => 'field_accruals',
      9 => 'field_custodial_history',
      10 => 'field_dimensions',
      11 => 'field_other_copies',
      12 => 'field_existence_of_originals',
      13 => 'field_file_plan',
      14 => 'field_general',
      15 => 'field_physical_description',
      16 => 'field_source_of_acquisition',
      17 => 'field_language_of_materials',
      18 => 'field_material_specific_details',
      19 => 'field_other_finding_aids',
      20 => 'field_field_tech_requirements',
      21 => 'field_processing_information',
      22 => 'field_related_archival_materials',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-notes field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overview_of_the_accession|node|accession|default';
  $field_group->group_name = 'group_overview_of_the_accession';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'accession';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overview',
    'weight' => '0',
    'children' => array(
      0 => 'field_dates',
      1 => 'field_collection_location',
      2 => 'field_quantity',
      3 => 'field_creator',
      4 => 'field_collection_number',
      5 => 'field_access_restrictions',
      6 => 'field_use_restrictions',
      7 => 'field_accession_date',
      8 => 'field_summary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-overview-of-the-accession field-group-fieldset',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overview_of_the_collection|node|resource|default';
  $field_group->group_name = 'group_overview_of_the_collection';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overview of the Collection',
    'weight' => '0',
    'children' => array(
      0 => 'field_resource_creator',
      1 => 'field_resource_dates',
      2 => 'field_resource_quantity',
      3 => 'field_resource_collection_number',
      4 => 'field_resource_summary',
      5 => 'field_res_access_restrictions',
      6 => 'field_languages',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Overview of the Collection',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-overview-of-the-collection field-group-fieldset ',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Administrative Information');
  t('Content Description');
  t('Detailed Description of the Collection');
  t('Find Related Collections');
  t('Find Related Materials');
  t('Historical Note');
  t('Notes');
  t('Overview');
  t('Overview of the Collection');
  t('Use of the Collection');

  return $field_groups;
}
