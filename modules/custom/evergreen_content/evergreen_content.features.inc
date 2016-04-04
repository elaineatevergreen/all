<?php
/**
 * @file
 * evergreen_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function evergreen_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "environment_indicator" && $api == "default_environment_indicator_environments") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_entityqueue_api().
 */
function evergreen_content_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function evergreen_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function evergreen_content_image_default_styles() {
  $styles = array();

  // Exported image style: large__800px_wide_.
  $styles['large__800px_wide_'] = array(
    'label' => 'Large (800px wide)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: medium__500px_wide_.
  $styles['medium__500px_wide_'] = array(
    'label' => 'Medium (500px wide)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function evergreen_content_node_info() {
  $items = array(
    'alert' => array(
      'name' => t('Alert'),
      'base' => 'node_content',
      'description' => t('<em>Alerts</em> are used on the college home page to announce emergencies. Only create a manual alert if the event is NOT being announced via e2Campus.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('News or Blog Post'),
      'base' => 'node_content',
      'description' => t('Use <em>a news story or blog post</em> for time-sensitive content like news, press releases or blog posts. Contact the Web Team to find out how to display lists of articles in your site section.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'basic_page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use a <em>basic page</em> for most of your website content needs.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Before you create a new page, consider: who is this page for? Is that your site\'s main audience? How is this information related to the rest of the page on your site?'),
    ),
    'catalog_entry' => array(
      'name' => t('Catalog Entry'),
      'base' => 'node_content',
      'description' => t('<em>Catalog entries</em> should ONLY be generated via the CMD.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'directory_individual' => array(
      'name' => t('Directory Individual'),
      'base' => 'node_content',
      'description' => t('This content type is used to show contact information for individual staff and faculty in the college and to build related contact information. Entries should ONLY be created via import from Adminweb.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'directory_office' => array(
      'name' => t('Directory Office'),
      'base' => 'node_content',
      'description' => t('This content type is used to show contact information for offices at the college. Entries should ONLY be created via import from Adminweb.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Use an <em>event</em> when you need to add something to an event calendar or create other date-based content, including deadlines, instruction start and end dates, and holidays.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'field_of_study' => array(
      'name' => t('Field of Study'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('If this field is not for a "page" field, then the name MUST match a field in the CMD in order to correctly pull offerings out of the catalog!'),
    ),
    'home_page' => array(
      'name' => t('Home Page'),
      'base' => 'node_content',
      'description' => t('It\'s the <em>HOME PAGE</em>, y\'all.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'home_page_hero' => array(
      'name' => t('Home Page Hero'),
      'base' => 'node_content',
      'description' => t('Create a <em>home page hero</em> item to generate an image and caption to appear on the college\' home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'library_database' => array(
      'name' => t('Library Database'),
      'base' => 'node_content',
      'description' => t('Use this for posting links to databases on the library\'s website.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'profile' => array(
      'name' => t('Profile'),
      'base' => 'node_content',
      'description' => t('A <em>profile</em> is a piece about a person who is connected to Evergreen. Profile content may be used in the magazine, in recruitment-focused content, on Fields of Study pages, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('This content type is still under development. Have ideas for making it better? Contact your local CMS Specialist!'),
    ),
    'scholarship' => array(
      'name' => t('Scholarship'),
      'base' => 'node_content',
      'description' => t('Use a <em>scholarship</em> to list both actively offered scholarships and those being developed.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'student_group' => array(
      'name' => t('Student Group'),
      'base' => 'node_content',
      'description' => t('Use a <em>student group</em> to create a page for a Registered Student Organization.'),
      'has_title' => '1',
      'title_label' => t('Group Name'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
