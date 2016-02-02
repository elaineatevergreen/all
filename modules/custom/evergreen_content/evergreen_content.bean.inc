<?php
/**
 * @file
 * evergreen_content.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function evergreen_content_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'alternate_background_image';
  $bean_type->label = 'Alternate Background Image';
  $bean_type->options = '';
  $bean_type->description = 'This is used for site sections that are determined via Context or otherwise not attached to a Site Section taxonomy term.';
  $export['alternate_background_image'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'section_menu';
  $bean_type->label = 'Section Menu';
  $bean_type->options = '';
  $bean_type->description = 'Used in very rare situations to override, or instead of, menus set via Workbench Access.';
  $export['section_menu'] = $bean_type;

  return $export;
}
