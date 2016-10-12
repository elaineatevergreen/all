<?php
/**
 * @file
 * evergreen_content.default_environment_indicator_environments.inc
 */

/**
 * Implements hook_default_environment_indicator_environment().
 */
function evergreen_content_default_environment_indicator_environment() {
  $export = array();

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'dev';
  $environment->name = 'dev';
  $environment->regexurl = 'wwwdev.*';
  $environment->settings = array(
    'color' => '#0e1af2',
    'text_color' => '#ffffff',
    'weight' => '',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['dev'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'live';
  $environment->name = 'Live';
  $environment->regexurl = 'www.*';
  $environment->settings = array(
    'color' => '#2d8625',
    'text_color' => '#ffffff',
    'weight' => '',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['live'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'localhost';
  $environment->name = 'Dev/Localhost';
  $environment->regexurl = 'localhost*';
  $environment->settings = array(
    'color' => '#aa33a0',
    'text_color' => '#ffffff',
    'weight' => '99',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['localhost'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'test';
  $environment->name = 'Test';
  $environment->regexurl = 'wwwtest.*';
  $environment->settings = array(
    'color' => '#113dc2',
    'text_color' => '#ffffff',
    'weight' => '',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['test'] = $environment;

  return $export;
}
