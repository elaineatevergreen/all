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
  $environment->machine = 'collabtest';
  $environment->name = 'Test/Collabtest';
  $environment->regexurl = 'collabtest.*';
  $environment->settings = array(
    'color' => '#888888',
    'text_color' => '#ffffff',
    'weight' => '',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['collabtest'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'live_collab';
  $environment->name = 'Live/Collab';
  $environment->regexurl = 'collab\\..*';
  $environment->settings = array(
    'color' => '#a9a9a9',
    'text_color' => '#ffffff',
    'weight' => '',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['live_collab'] = $environment;

  $environment = new stdClass();
  $environment->disabled = FALSE; /* Edit this to true to make a default environment disabled initially */
  $environment->api_version = 1;
  $environment->machine = 'localhost';
  $environment->name = 'Dev/Localhost';
  $environment->regexurl = 'localhost*';
  $environment->settings = array(
    'color' => '#aa3333',
    'text_color' => '#ffffff',
    'weight' => '99',
    'position' => 'top',
    'fixed' => 0,
  );
  $export['localhost'] = $environment;

  return $export;
}
