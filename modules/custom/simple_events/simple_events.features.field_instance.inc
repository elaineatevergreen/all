<?php
/**
 * @file
 * simple_events.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function simple_events_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_section_navigation-field_group_title'.
  $field_instances['field_collection_item-field_section_navigation-field_group_title'] = array(
    'bundle' => 'field_section_navigation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_group_title',
    'label' => 'Group Title',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'field_collection_item-field_section_navigation-field_links'.
  $field_instances['field_collection_item-field_section_navigation-field_links'] = array(
    'bundle' => 'field_section_navigation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Most of the time, keep it to other pages in the same site section.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_links',
    'label' => 'Links',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'description_display' => 'before',
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 1,
        'profile' => 'nav_links',
      ),
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 2,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-event_simple-field_event_date'.
  $field_instances['node-event_simple-field_event_date'] = array(
    'bundle' => 'event_simple',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_event_date',
    'label' => 'Event Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'description_display' => 'before',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 1,
        'increment' => 15,
        'input_format' => 'm/d/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'repeat_collapsed' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 2,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-event_simple-field_event_description'.
  $field_instances['node-event_simple-field_event_description'] = array(
    'bundle' => 'event_simple',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_event_description',
    'label' => 'Event Description',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-event_simple-field_site_section'.
  $field_instances['node-event_simple-field_site_section'] = array(
    'bundle' => 'event_simple',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_site_section',
    'label' => 'Site Section',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-site_sections-field_background_image'.
  $field_instances['taxonomy_term-site_sections-field_background_image'] = array(
    'bundle' => 'site_sections',
    'deleted' => 0,
    'description' => 'This image appears in the background/header off all pages in this section and provides a visual cue. If not uploaded here, a default image will appear instead.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_background_image',
    'label' => 'Background Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'description_display' => 'before',
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '200 KB',
      'max_resolution' => '800x800',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 4,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'taxonomy_term-site_sections-field_long_name'.
  $field_instances['taxonomy_term-site_sections-field_long_name'] = array(
    'bundle' => 'site_sections',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This is the site\'s formal name as it appears in the header and navigation.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_long_name',
    'label' => 'Long Name',
    'required' => 0,
    'settings' => array(
      'description_display' => 'after',
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-site_sections-field_section_navigation'.
  $field_instances['taxonomy_term-site_sections-field_section_navigation'] = array(
    'bundle' => 'site_sections',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Each of these chunks creates one piece of the site section navigation. You can make UP TO four, but that\'s probably too many for most site. The last chunk should be "Related Links".',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_section_navigation',
    'label' => 'Section Navigation',
    'required' => 0,
    'settings' => array(
      'description_display' => 'before',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 6,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Background Image');
  t('Each of these chunks creates one piece of the site section navigation. You can make UP TO four, but that\'s probably too many for most site. The last chunk should be "Related Links".');
  t('Event Date');
  t('Event Description');
  t('Group Title');
  t('Links');
  t('Long Name');
  t('Most of the time, keep it to other pages in the same site section.');
  t('Section Navigation');
  t('Site Section');
  t('This image appears in the background/header off all pages in this section and provides a visual cue. If not uploaded here, a default image will appear instead.');
  t('This is the site\'s formal name as it appears in the header and navigation.');

  return $field_instances;
}
