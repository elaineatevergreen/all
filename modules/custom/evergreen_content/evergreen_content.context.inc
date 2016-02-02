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
  $context->name = 'catalog';
  $context->description = '';
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
          'region' => 'section_nav',
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
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'directory' => 'directory',
        'directory:page_1' => 'directory:page_1',
        'directory:page_2' => 'directory:page_2',
        'directory:page_3' => 'directory:page_3',
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
        'bean-directories' => array(
          'module' => 'bean',
          'delta' => 'directories',
          'region' => 'background_image',
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
