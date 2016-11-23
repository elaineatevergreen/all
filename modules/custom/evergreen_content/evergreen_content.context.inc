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
  $context->description = 'Sets section design for events';
  $context->tag = 'sections';
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
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sets section design for events');
  t('sections');
  $export['calendar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'catalog';
  $context->description = 'Catalog home/lists ONLY, not individual items?';
  $context->tag = 'sections';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'catalog_entry' => 'catalog_entry',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'catalog:page' => 'catalog:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'section_title',
          'weight' => '-10',
        ),
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
        'sites/all/themes/wwwevergreen/css/dist/custom-css/catalog.css' => 'sites/all/themes/wwwevergreen/css/dist/custom-css/catalog.css',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Catalog home/lists ONLY, not individual items?');
  t('sections');
  $export['catalog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'directories';
  $context->description = 'Covers both indexes and individual items.';
  $context->tag = 'sections';
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
        'views-catalog-offerings_by_faculty' => array(
          'module' => 'views',
          'delta' => 'catalog-offerings_by_faculty',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'css' => array(
      'www.evergreen.edu' => array(
        'sites/all/themes/wwwevergreen/css/dist/custom-css/directories.css' => 'sites/all/themes/wwwevergreen/css/dist/custom-css/directories.css',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Covers both indexes and individual items.');
  t('sections');
  $export['directories'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'fields_of_study';
  $context->description = 'Sets section design for Fields of Study pages';
  $context->tag = 'sections';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'studies' => 'studies',
      ),
    ),
    'taxonomy_term' => array(
      'values' => array(
        'fields_of_study' => 'fields_of_study',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'section_title',
          'weight' => '-10',
        ),
        'bean-section-navigation-fields-of-stu' => array(
          'module' => 'bean',
          'delta' => 'section-navigation-fields-of-stu',
          'region' => 'section_nav',
          'weight' => '-10',
        ),
        'views-ed3eb47c482a2d265dabe239adf98fbb' => array(
          'module' => 'views',
          'delta' => 'ed3eb47c482a2d265dabe239adf98fbb',
          'region' => 'secondary_content',
          'weight' => '-10',
        ),
        'views-2de9bc6b43b597ba3ae30595ad6f8266' => array(
          'module' => 'views',
          'delta' => '2de9bc6b43b597ba3ae30595ad6f8266',
          'region' => 'background_image',
          'weight' => '-10',
        ),
      ),
    ),
    'css' => array(
      'www.evergreen.edu' => array(
        'sites/all/themes/wwwevergreen/css/dist/custom-css/studies.css' => 'sites/all/themes/wwwevergreen/css/dist/custom-css/studies.css',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sets section design for Fields of Study pages');
  t('sections');
  $export['fields_of_study'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Adds design elements/CSS for home page';
  $context->tag = 'design';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'home_page' => 'home_page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'css' => array(
      'www.evergreen.edu' => array(
        'sites/all/themes/wwwevergreen/css/dist/custom-css/home.css' => 'sites/all/themes/wwwevergreen/css/dist/custom-css/home.css',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds design elements/CSS for home page');
  t('design');
  $export['home'] = $context;

  return $export;
}
