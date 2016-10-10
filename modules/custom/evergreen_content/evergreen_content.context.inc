<?php
/**
 * @file
 * evergreen_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function evergreen_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calendar';
  $context->description = 'Used in place of Workbench Access Views for calendar events';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'calendar:page' => 'calendar:page',
        'calendar:page_3' => 'calendar:page_3',
        'calendar:page_4' => 'calendar:page_4',
        'calendar:page_5' => 'calendar:page_5',
        'calendar:page_6' => 'calendar:page_6',
        'calendar:page_7' => 'calendar:page_7',
        'calendar:page_8' => 'calendar:page_8',
        'calendar_by_date' => 'calendar_by_date',
        'calendar_by_date:day' => 'calendar_by_date:day',
        'calendar_by_date:page' => 'calendar_by_date:page',
        'calendar_by_date:page_1' => 'calendar_by_date:page_1',
        'calendar_by_date:page_2' => 'calendar_by_date:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'section_title',
          'weight' => '-9',
        ),
        'bean-calendar-nav' => array(
          'module' => 'bean',
          'delta' => 'calendar-nav',
          'region' => 'section_nav',
          'weight' => '-10',
        ),
      ),
    ),
    'css' => array(
      'www.evergreen.edu' => array(
        'sites/all/themes/wwwevergreen/css/directories.css' => 'sites/all/themes/wwwevergreen/css/directories.css',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Used in place of Workbench Access Views for calendar events');
  $export['calendar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'catalog';
  $context->description = 'Used in place of Workbench Access to set blocks for the Catalog index';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'catalog:page' => 'catalog:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-catalog-page' => array(
          'module' => 'views',
          'delta' => '-exp-catalog-page',
          'region' => 'filters',
          'weight' => '-10',
        ),
      ),
    ),
    'css' => array(
      'www.evergreen.edu' => array(
        'sites/all/themes/wwwevergreen/css/catalog.css' => 'sites/all/themes/wwwevergreen/css/catalog.css',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Used in place of Workbench Access to set blocks for the Catalog index');
  $export['catalog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'directories';
  $context->description = 'Used in place of Workbench Access View for directory pages';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'directory_individual' => 'directory_individual',
        'directory_office' => 'directory_office',
        'location' => 'location',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'directory' => 'directory',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'section_title',
          'weight' => '-10',
        ),
        'bean-directory-menu' => array(
          'module' => 'bean',
          'delta' => 'directory-menu',
          'region' => 'section_nav',
          'weight' => '-10',
        ),
      ),
    ),
    'css' => array(
      'www.evergreen.edu' => array(
        'sites/all/themes/wwwevergreen/css/directories.css' => 'sites/all/themes/wwwevergreen/css/directories.css',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Used in place of Workbench Access View for directory pages');
  $export['directories'] = $context;

  return $export;
}
