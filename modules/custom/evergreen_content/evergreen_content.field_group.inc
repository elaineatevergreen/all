<?php
/**
 * @file
 * evergreen_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function evergreen_content_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|committee_page|default';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About this Committee',
    'weight' => '5',
    'children' => array(
      0 => 'body',
      1 => 'field_members',
      2 => 'field_other_members',
      3 => 'field_charge',
      4 => 'field_contact_information',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'About this Committee',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_about|node|committee_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|committee_page|form';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About this Committee',
    'weight' => '7',
    'children' => array(
      0 => 'body',
      1 => 'field_short_description',
      2 => 'field_charge',
      3 => 'field_contact_information',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_about|node|committee_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|location|form';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About the Building',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_square_footage',
      2 => 'field_building_history',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-about field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_about|node|location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|node|catalog_entry|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced Opportunities',
    'weight' => '48',
    'children' => array(
      0 => 'field_internship_boolean',
      1 => 'field_research_boolean',
      2 => 'field_study_abroad_boolean',
      3 => 'field_upper_division_boolean',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced|node|catalog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|node|event|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_categories';
  $field_group->data = array(
    'label' => 'Additional Settings',
    'weight' => '4',
    'children' => array(
      0 => 'field_academic_quarter',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'description' => 'Most events do not require this information.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_advanced|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_applicant|node|scholarship|form';
  $field_group->group_name = 'group_applicant';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'scholarship';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Applicant Criteria',
    'weight' => '5',
    'children' => array(
      0 => 'field_deadline',
      1 => 'field_new_or_current',
      2 => 'field_class_standing',
      3 => 'field_need_based',
      4 => 'field_fafsa_or_wasfa_required',
      5 => 'field_under_represented',
      6 => 'field_short_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-applicant field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_applicant|node|scholarship|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_archived|node|committee_page|default';
  $field_group->group_name = 'group_archived';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Archived Materials',
    'weight' => '6',
    'children' => array(
      0 => 'field_historical_agendas',
      1 => 'field_historical_minutes',
      2 => 'field_web_page_reports',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Archived Materials',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-archived field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_archived|node|committee_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_archived|node|committee_page|form';
  $field_group->group_name = 'group_archived';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Archived Materials',
    'weight' => '10',
    'children' => array(
      0 => 'field_historical_agendas',
      1 => 'field_historical_minutes',
      2 => 'field_web_page_reports',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Archived Materials',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-archived field-group-fieldset',
        'description' => 'These fields should only be used for items prior to 2017 that are stored on archives.evergreen.edu.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_archived|node|committee_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_info|node|blurb|form';
  $field_group->group_name = 'group_article_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blurb';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Article Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_article_link',
      1 => 'field_publication_title',
      2 => 'field_article_author',
      3 => 'field_article_date',
      4 => 'field_pitched',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-article-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_article_info|node|blurb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attachments|node|event|form';
  $field_group->group_name = 'group_attachments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '14',
    'children' => array(
      0 => 'body',
      1 => 'field_flyer',
      2 => 'field_image',
      3 => 'group_sponsor',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_attachments|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_author|node|profile|default';
  $field_group->group_name = 'group_author';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Author Information',
    'weight' => '12',
    'children' => array(
      0 => 'field_excerpt',
      1 => 'field_publication_type',
      2 => 'field_publications',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-author field-group-div',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_author|node|profile|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_author|node|profile|form';
  $field_group->group_name = 'group_author';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_directories';
  $field_group->data = array(
    'label' => 'Author Info',
    'weight' => '19',
    'children' => array(
      0 => 'field_excerpt',
      1 => 'field_publication_type',
      2 => 'field_publications',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-author field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_author|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|node|catalog_entry|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_cmd_id',
      2 => 'field_faculty',
      3 => 'field_maximum_credits',
      4 => 'field_minimum_credits',
      5 => 'field_offering_type',
      6 => 'field_status_date',
      7 => 'field_fields_of_study',
      8 => 'field_preparatory_for',
      9 => 'field_offering_status',
      10 => 'field_credits',
      11 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basics field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_basics|node|catalog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|node|directory_individual|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_individual';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '6',
    'children' => array(
      0 => 'group_contact',
      1 => 'group_faculty',
      2 => 'group_identity',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_basics|node|directory_individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|node|scholarship|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'scholarship';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_tuition_award',
      2 => 'field_common_application',
      3 => 'field_amount',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basics field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_basics|node|scholarship|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|taxonomy_term|site_sections|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_top';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '1',
    'children' => array(
      0 => 'field_background_image',
      1 => 'field_long_name',
      2 => 'field_section_contact_info',
      3 => 'name',
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
  $field_groups['group_basics|taxonomy_term|site_sections|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bio|node|profile|form';
  $field_group->group_name = 'group_bio';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Biographical Details',
    'weight' => '34',
    'children' => array(
      0 => 'field_current_location',
      1 => 'field_current_profession',
      2 => 'field_first_name',
      3 => 'field_hometown',
      4 => 'field_last_name',
      5 => 'field_roles',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bio field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_bio|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_business|node|profile|default';
  $field_group->group_name = 'group_business';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Business Information',
    'weight' => '11',
    'children' => array(
      0 => 'field_business_address',
      1 => 'field_business_description',
      2 => 'field_business_name',
      3 => 'field_business_phone',
      4 => 'field_business_type',
      5 => 'field_dates_of_operation',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-business field-group-div',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_business|node|profile|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|event|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '16',
    'children' => array(
      0 => 'field_calendar_categories',
      1 => 'field_event_format',
      2 => 'group_advanced',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_categories|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|directory_individual|default';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_individual';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_alternate_phone',
      1 => 'field_building_alt',
      2 => 'field_email',
      3 => 'field_fax',
      4 => 'field_location_off_campus',
      5 => 'field_mailstop',
      6 => 'field_phone',
      7 => 'field_room',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_contact|node|directory_individual|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|directory_individual|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_individual';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basics';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '9',
    'children' => array(
      0 => 'field_alternate_phone',
      1 => 'field_building',
      2 => 'field_building_alt',
      3 => 'field_email',
      4 => 'field_fax',
      5 => 'field_location_off_campus',
      6 => 'field_mailstop',
      7 => 'field_phone',
      8 => 'field_room',
      9 => 'field_website',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-contact field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_contact|node|directory_individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|student_group|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'student_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_email',
      1 => 'field_websites',
      2 => 'field_meetings',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_contact|node|student_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|profile|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Articles & Images',
    'weight' => '36',
    'children' => array(
      0 => 'body',
      1 => 'field_image',
      2 => 'field_related_pieces',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_content|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_custom|node|directory_office|form';
  $field_group->group_name = 'group_custom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_office';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Website-Specific Content',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_facebook',
      2 => 'field_hours',
      3 => 'field_site_section',
      4 => 'field_twitter',
      5 => 'field_staff_page',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-custom field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_custom|node|directory_office|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|event|default';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description Wrapper',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'group_image',
      2 => 'group_sponsor',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Description Wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'event-description',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_description|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|library_database|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'library_database';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_resource_type',
      2 => 'field_resource_subject',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-description field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_description|node|library_database|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|node|student_group|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'student_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_image',
      2 => 'field_group_categories',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-description field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_description|node|student_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|catalog_entry|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_entry';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Program Details',
    'weight' => '11',
    'children' => array(
      0 => 'field_fields_of_study',
      1 => 'field_preparatory_for',
      2 => 'field_websites',
      3 => 'group_location_schedule',
      4 => 'group_more',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Program Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_details|node|catalog_entry|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|event|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '0',
    'children' => array(
      0 => 'field_event_date',
      1 => 'field_location_off_campus',
      2 => 'group_on_campus',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'event-details',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_details|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|field_of_study|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'field_of_study';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Extended Subject Details',
    'weight' => '7',
    'children' => array(
      0 => 'field_sample_program',
      1 => 'field_after_graduation',
      2 => 'field_facilities_resources',
      3 => 'field_recent_student_projects',
      4 => 'field_faculty_bios',
      5 => 'field_sample_program_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Extended Subject Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_details|node|field_of_study|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|location|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'location';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_building_history',
      1 => 'field_official_name',
      2 => 'field_square_footage',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-details field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_details|node|location|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_directories|node|profile|form';
  $field_group->group_name = 'group_directories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Alumni Directories',
    'weight' => '37',
    'children' => array(
      0 => 'field_display',
      1 => 'field_how_did_your_evergreen_edu',
      2 => 'field_email',
      3 => 'group_author',
      4 => 'group_entrepreneur',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-directories field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_directories|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_donor|node|scholarship|form';
  $field_group->group_name = 'group_donor';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'scholarship';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Donor Info',
    'weight' => '6',
    'children' => array(
      0 => 'field_funding_status',
      1 => 'field_cashnet_code',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-donor field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_donor|node|scholarship|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entrepreneur|node|profile|form';
  $field_group->group_name = 'group_entrepreneur';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_directories';
  $field_group->data = array(
    'label' => 'Entrepreneur Info',
    'weight' => '20',
    'children' => array(
      0 => 'field_business_address',
      1 => 'field_business_description',
      2 => 'field_business_name',
      3 => 'field_business_phone',
      4 => 'field_business_type',
      5 => 'field_dates_of_operation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-entrepreneur field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_entrepreneur|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_faculty|node|directory_individual|form';
  $field_group->group_name = 'group_faculty';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_individual';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basics';
  $field_group->data = array(
    'label' => 'Faculty Information',
    'weight' => '10',
    'children' => array(
      0 => 'field_background',
      1 => 'field_expertise',
      2 => 'field_interests',
      3 => 'field_is_faculty',
      4 => 'field_related_subjects_directory',
      5 => 'field_faculty_directory_subject_',
      6 => 'field_planning_unit_puc',
      7 => 'body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-faculty field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_faculty|node|directory_individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding|node|committee_page|default';
  $field_group->group_name = 'group_funding';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Funding',
    'weight' => '2',
    'children' => array(
      0 => 'field_eligibility',
      1 => 'field_upcoming_deadlines',
      2 => 'webform',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Funding',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_funding|node|committee_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding|node|committee_page|form';
  $field_group->group_name = 'group_funding';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Funding',
    'weight' => '6',
    'children' => array(
      0 => 'field_eligibility',
      1 => 'field_upcoming_deadlines',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Funding',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-funding field-group-fieldset',
        'description' => 'If this committee distributes funding, provide the details here. Otherwise, you may skip this section.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_funding|node|committee_page|form'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'group_primary',
      1 => 'group_secondary',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-group field-group-htabs',
      ),
    ),
  );
  $field_groups['group_group|node|basic_page|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'group_attachments',
      1 => 'group_categories',
      2 => 'group_what',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'group',
      'instance_settings' => array(
        'classes' => '',
        'page_header' => '3',
        'page_counter' => '1',
        'move_button' => '1',
        'move_additional' => '1',
      ),
    ),
  );
  $field_groups['group_group|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|profile|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'group',
    'weight' => '3',
    'children' => array(
      0 => 'group_bio',
      1 => 'group_content',
      2 => 'group_directories',
      3 => 'group_studies',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-group field-group-htabs',
      ),
    ),
  );
  $field_groups['group_group|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|student_group|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'student_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'group',
    'weight' => '2',
    'children' => array(
      0 => 'group_description',
      1 => 'group_contact',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-group field-group-htabs',
      ),
    ),
  );
  $field_groups['group_group|node|student_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identity|node|directory_individual|form';
  $field_group->group_name = 'group_identity';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_individual';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basics';
  $field_group->data = array(
    'label' => 'Identity',
    'weight' => '8',
    'children' => array(
      0 => 'field_cas_name',
      1 => 'field_first_name',
      2 => 'field_job_title',
      3 => 'field_last_name',
      4 => 'field_department',
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
  $field_groups['group_identity|node|directory_individual|form'] = $field_group;

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
      0 => 'field_image',
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
  $field_group->identifier = 'group_image|node|event|default';
  $field_group->group_name = 'group_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_description';
  $field_group->data = array(
    'label' => 'Image float',
    'weight' => '12',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Image float',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'supplement',
        'element' => 'figure',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_image|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imported|node|directory_office|form';
  $field_group->group_name = 'group_imported';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_office';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Imported Content',
    'weight' => '3',
    'children' => array(
      0 => 'field_alternate_phone',
      1 => 'field_building_alt',
      2 => 'field_email',
      3 => 'field_facilities',
      4 => 'field_fax',
      5 => 'field_mailstop',
      6 => 'field_members',
      7 => 'field_phone',
      8 => 'field_reference',
      9 => 'field_related_offices',
      10 => 'field_room',
      11 => 'field_websites',
      12 => 'field_last_name',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Imported Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imported field-group-tab',
        'description' => 'Don\'t override this unless you know what you\'re doing!',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imported|node|directory_office|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_internal_info|node|blurb|form';
  $field_group->group_name = 'group_internal_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blurb';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Our Annotations',
    'weight' => '1',
    'children' => array(
      0 => 'field_description_plain',
      1 => 'field_add_to_sections',
      2 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Our Annotations',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-internal-info field-group-fieldset',
        'description' => 'This title and description will be shown to website visitors.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_internal_info|node|blurb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_link|node|library_database|form';
  $field_group->group_name = 'group_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'library_database';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Link',
    'weight' => '3',
    'children' => array(
      0 => 'field_proxy',
      1 => 'field_resource_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-link field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_link|node|library_database|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location_on_campus|node|event|form';
  $field_group->group_name = 'group_location_on_campus';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_what';
  $field_group->data = array(
    'label' => 'Location: On Campus',
    'weight' => '2',
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
  $field_group->identifier = 'group_location_schedule|node|catalog_entry|default';
  $field_group->group_name = 'group_location_schedule';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_entry';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Location and Schedule',
    'weight' => '8',
    'children' => array(
      0 => 'field_advertised_schedule',
      1 => 'field_location',
      2 => 'field_off_campus_location',
      3 => 'field_study_abroad',
      4 => 'field_time_offered',
      5 => 'field_final_schedule',
      6 => 'field_additional_schedule_detail',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Location and Schedule',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_location_schedule|node|catalog_entry|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meetings|node|committee_page|default';
  $field_group->group_name = 'group_meetings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meetings',
    'weight' => '4',
    'children' => array(
      0 => 'field_agendas',
      1 => 'field_minutes',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Meetings',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_meetings|node|committee_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meetings|node|committee_page|form';
  $field_group->group_name = 'group_meetings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meetings',
    'weight' => '2',
    'children' => array(
      0 => 'field_meetings',
      1 => 'field_agendas',
      2 => 'field_minutes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meetings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_meetings|node|committee_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_misc|node|catalog_entry|form';
  $field_group->group_name = 'group_misc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Misc Options',
    'weight' => '3',
    'children' => array(
      0 => 'field_next_offered',
      1 => 'field_prerequisites',
      2 => 'field_special_expenses',
      3 => 'field_study_abroad',
      4 => 'field_upper_division',
      5 => 'field_fees',
      6 => 'field_variable_credit_options',
      7 => 'field_enrollment_conditions',
      8 => 'field_research_opportunities',
      9 => 'field_internship_opportunities',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-misc field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_misc|node|catalog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_more|node|catalog_entry|default';
  $field_group->group_name = 'group_more';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_entry';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '9',
    'children' => array(
      0 => 'field_next_offered',
      1 => 'field_online_learning',
      2 => 'field_special_expenses',
      3 => 'field_fees',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-more field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_more|node|catalog_entry|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_names|node|location|form';
  $field_group->group_name = 'group_names';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'location';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Names',
    'weight' => '3',
    'children' => array(
      0 => 'field_abbreviated_building_name',
      1 => 'field_official_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-names field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_names|node|location|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_navigation|taxonomy_term|site_sections|form';
  $field_group->group_name = 'group_navigation';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_top';
  $field_group->data = array(
    'label' => 'Navigation',
    'weight' => '2',
    'children' => array(
      0 => 'field_section_navigation',
      1 => 'description',
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
  $field_groups['group_navigation|taxonomy_term|site_sections|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nav|node|home_page|form';
  $field_group->group_name = 'group_nav';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'home_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prospective Student Nav',
    'weight' => '5',
    'children' => array(
      0 => 'field_section_navigation',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-nav field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_nav|node|home_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_on_campus|node|event|default';
  $field_group->group_name = 'group_on_campus';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Location: On Campus',
    'weight' => '7',
    'children' => array(
      0 => 'field_building',
      1 => 'field_room',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Location: On Campus',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_on_campus|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_participants|node|committee_page|form';
  $field_group->group_name = 'group_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Participants',
    'weight' => '5',
    'children' => array(
      0 => 'field_members',
      1 => 'field_other_members',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-participants field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_participants|node|committee_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_phone|node|directory_office|default';
  $field_group->group_name = 'group_phone';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_office';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Phone Numbers',
    'weight' => '4',
    'children' => array(
      0 => 'field_alternate_phone',
      1 => 'field_fax',
      2 => 'field_phone',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-phone field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_phone|node|directory_office|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photos|node|directory_individual|form';
  $field_group->group_name = 'group_photos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_individual';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Photos',
    'weight' => '1',
    'children' => array(
      0 => 'field_headshot',
      1 => 'field_square_portrait',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-photos field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_photos|node|directory_individual|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prerequisites|node|catalog_entry|default';
  $field_group->group_name = 'group_prerequisites';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_entry';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prerequisites',
    'weight' => '7',
    'children' => array(
      0 => 'field_prerequisites',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Prerequisites',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'box program-prerequisites',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_prerequisites|node|catalog_entry|default'] = $field_group;

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
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_intro',
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
  $field_groups['group_primary|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quarters|node|catalog_entry|form';
  $field_group->group_name = 'group_quarters';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Quarters',
    'weight' => '2',
    'children' => array(
      0 => 'field_academic_year',
      1 => 'field_begin_term',
      2 => 'field_end_term',
      3 => 'field_number_of_quarters',
      4 => 'field_quarters_offered',
      5 => 'field_quarters_open',
      6 => 'field_fall_registration',
      7 => 'field_winter_registration',
      8 => 'field_spring_registration',
      9 => 'field_quarters_signature',
      10 => 'field_quarters_conditional',
      11 => 'field_quarters_closed',
      12 => 'field_summer_registration',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-quarters field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_quarters|node|catalog_entry|form'] = $field_group;

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
    'weight' => '3',
    'children' => array(
      0 => 'field_secondary_content',
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
  $field_groups['group_secondary|node|basic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social|node|directory_office|default';
  $field_group->group_name = 'group_social';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'directory_office';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Find Online',
    'weight' => '9',
    'children' => array(
      0 => 'field_facebook',
      1 => 'field_twitter',
      2 => 'field_websites',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Find Online',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-social field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_social|node|directory_office|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsor|node|event|default';
  $field_group->group_name = 'group_sponsor';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_description';
  $field_group->data = array(
    'label' => 'Sponsor',
    'weight' => '14',
    'children' => array(
      0 => 'field_sponsored_by',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Sponsor',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'event-sponsor',
        'element' => 'p',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_sponsor|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsor|node|event|form';
  $field_group->group_name = 'group_sponsor';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attachments';
  $field_group->data = array(
    'label' => 'Sponsor',
    'weight' => '6',
    'children' => array(
      0 => 'field_add_to_sections',
      1 => 'field_sponsored_by',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sponsor',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-sponsor field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_sponsor|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_studies|node|profile|form';
  $field_group->group_name = 'group_studies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Studies',
    'weight' => '35',
    'children' => array(
      0 => 'field_degrees',
      1 => 'field_other_institutions',
      2 => 'field_graduated_alt',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-studies field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_studies|node|profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title_wrapper|field_collection_item|field_section_navigation|data_export';
  $field_group->group_name = 'group_title_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_section_navigation';
  $field_group->mode = 'data_export';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title Wrapper',
    'weight' => '4',
    'children' => array(
      0 => 'field_group_title',
      1 => 'field_links',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-title-wrapper field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_title_wrapper|field_collection_item|field_section_navigation|data_export'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_top|taxonomy_term|site_sections|form';
  $field_group->group_name = 'group_top';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'site_sections';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Top Level',
    'weight' => '0',
    'children' => array(
      0 => 'group_basics',
      1 => 'group_navigation',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-top field-group-htabs',
      ),
    ),
  );
  $field_groups['group_top|taxonomy_term|site_sections|form'] = $field_group;

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
    'label' => 'Title, Time, and Place',
    'weight' => '12',
    'children' => array(
      0 => 'field_event_date',
      1 => 'field_location_off_campus',
      2 => 'title',
      3 => 'group_location_on_campus',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Title, Time, and Place',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'no-start',
    ),
  );
  $field_groups['group_what|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_where|node|event|form';
  $field_group->group_name = 'group_where';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Where',
    'weight' => '13',
    'children' => array(
      0 => 'field_location_off_campus',
      1 => 'group_location_on_campus',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-where field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_where|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_whowhenwhere|node|catalog_entry|form';
  $field_group->group_name = 'group_whowhenwhere';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog_entry';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Who, When, and Where',
    'weight' => '1',
    'children' => array(
      0 => 'field_advertised_schedule',
      1 => 'field_class_standing',
      2 => 'field_location',
      3 => 'field_maximum_enrollment',
      4 => 'field_off_campus_location',
      5 => 'field_online_learning',
      6 => 'field_percent_freshman',
      7 => 'field_time_offered',
      8 => 'field_curricular_area',
      9 => 'field_final_schedule',
      10 => 'field_days_of_the_week',
      11 => 'field_additional_schedule_detail',
      12 => 'field_theme_codes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-whowhenwhere field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_whowhenwhere|node|catalog_entry|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work|node|committee_page|default';
  $field_group->group_name = 'group_work';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work Products',
    'weight' => '3',
    'children' => array(
      0 => 'field_proposal',
      1 => 'field_reports',
      2 => 'field_documents',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-work field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_work|node|committee_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work|node|committee_page|form';
  $field_group->group_name = 'group_work';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'committee_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work Products',
    'weight' => '9',
    'children' => array(
      0 => 'field_proposal',
      1 => 'field_reports',
      2 => 'field_documents',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Work Products',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-work field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_work|node|committee_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About the Building');
  t('About this Committee');
  t('Additional Names');
  t('Additional Settings');
  t('Advanced Opportunities');
  t('Alumni Directories');
  t('Applicant Criteria');
  t('Archived Materials');
  t('Article Information');
  t('Articles & Images');
  t('Author Info');
  t('Author Information');
  t('Basics');
  t('Biographical Details');
  t('Business Information');
  t('Categories');
  t('Contact Information');
  t('Description');
  t('Description Wrapper');
  t('Details');
  t('Donor Info');
  t('Entrepreneur Info');
  t('Extended Subject Details');
  t('Faculty Information');
  t('Find Online');
  t('Funding');
  t('Identity');
  t('Image float');
  t('Images');
  t('Imported Content');
  t('Link');
  t('Location and Schedule');
  t('Location: On Campus');
  t('Meetings');
  t('Misc Options');
  t('More');
  t('Navigation');
  t('Our Annotations');
  t('Participants');
  t('Phone Numbers');
  t('Photos');
  t('Prerequisites');
  t('Primary Content');
  t('Program Details');
  t('Prospective Student Nav');
  t('Quarters');
  t('Secondary Content');
  t('Sponsor');
  t('Studies');
  t('Title Wrapper');
  t('Title, Time, and Place');
  t('Top Level');
  t('Website-Specific Content');
  t('Where');
  t('Who, When, and Where');
  t('Work Products');
  t('group');

  return $field_groups;
}
