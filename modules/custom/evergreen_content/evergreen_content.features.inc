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
 * Implements hook_fe_date_custom_date_formats().
 */
function evergreen_content_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['D, M j - g:i a'] = 'D, M j - g:i a';
  $custom_date_formats['F Y'] = 'F Y';
  $custom_date_formats['F j, Y'] = 'F j, Y';
  $custom_date_formats['M'] = 'M';
  $custom_date_formats['M j - g:i a'] = 'M j - g:i a';
  $custom_date_formats['U'] = 'U';
  $custom_date_formats['Y'] = 'Y';
  $custom_date_formats['Y-m-d'] = 'Y-m-d';
  $custom_date_formats['g:i a'] = 'g:i a';
  $custom_date_formats['j'] = 'j';
  $custom_date_formats['l, F j, Y'] = 'l, F j, Y';
  $custom_date_formats['l, F j, Y - g:i a'] = 'l, F j, Y - g:i a';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function evergreen_content_date_format_types() {
  $format_types = array();
  // Exported date format type: day
  $format_types['day'] = 'Day';
  // Exported date format type: long_notime
  $format_types['long_notime'] = 'Long/NoTime';
  // Exported date format type: longdate
  $format_types['longdate'] = 'LongDate';
  // Exported date format type: month
  $format_types['month'] = 'Month';
  // Exported date format type: month_year
  $format_types['month_year'] = 'Month/Year';
  // Exported date format type: time
  $format_types['time'] = 'Time';
  // Exported date format type: url
  $format_types['url'] = 'URL';
  // Exported date format type: year
  $format_types['year'] = 'Year';
  return $format_types;
}

/**
 * Implements hook_flag_default_flags().
 */
function evergreen_content_flag_default_flags() {
  $flags = array();
  // Exported flag: "Catalog Save List".
  $flags['catalog_save_list'] = array(
    'entity_type' => 'node',
    'title' => 'Catalog Save List',
    'global' => 0,
    'types' => array(
      0 => 'catalog_entry',
    ),
    'flag_short' => 'Save to list',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove from list',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'ical' => 0,
      'diff_standard' => 0,
      'full_name' => 0,
      'contact_block' => 0,
      'contact_row' => 0,
      'faculty_blurb' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'evergreen_content',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function evergreen_content_image_default_styles() {
  $styles = array();

  // Exported image style: event_image__345px_wide_.
  $styles['event_image__345px_wide_'] = array(
    'label' => 'Event image (345px wide)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 345,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image.
  $styles['image'] = array(
    'label' => 'Image',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => 800,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image_class.
  $styles['image_class'] = array(
    'label' => 'Image Class',
    'effects' => array(),
  );

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

  // Exported image style: portrait_thumbnail.
  $styles['portrait_thumbnail'] = array(
    'label' => 'Portrait Thumbnail (64x64)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 64,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 64,
          'height' => 64,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: portrait_thumbnail2.
  $styles['portrait_thumbnail2'] = array(
    'label' => 'Portrait Thumbnail (100px)',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
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
    'alumni_circles' => array(
      'name' => t('Alumni Circles'),
      'base' => 'node_content',
      'description' => t('Use an <em>Alumni Circle</em> to share information about alumni groups and their gatherings.'),
      'has_title' => '1',
      'title_label' => t('Group Name'),
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
    'blurb' => array(
      'name' => t('News Feed'),
      'base' => 'node_content',
      'description' => t('Use a <em>news feed</em> item to create a special highlight on an article on the website, a link from another site, or a social media mention.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'catalog_entry' => array(
      'name' => t('Catalog Entry'),
      'base' => 'node_content',
      'description' => t('<em>Catalog entries</em> should ONLY be generated via the CMD.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'committee_page' => array(
      'name' => t('Committee Page'),
      'base' => 'node_content',
      'description' => t('Use a <em>committee page</em> to list information about committees, their members, and their meetings. This includes disappearing task forces (DTFs).'),
      'has_title' => '1',
      'title_label' => t('Committee Name'),
      'help' => t('If you have information that does NOT fit this format, contact the Web Team. Your committee\'s work may need an additional web presence.'),
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
    'faculty_update' => array(
      'name' => t('Faculty Update'),
      'base' => 'node_content',
      'description' => t('Use a <em>Faculty Update</em> to add news about things that one or more faculty have done that is of interest to other faculty, students, or the general public.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Your submission will be edited and not all submissions will be published.'),
    ),
    'feed_importer' => array(
      'name' => t('Feed Importer'),
      'base' => 'node_content',
      'description' => t('Use a <em>Feed Importer</em> for importing items via Feeds. (These are used when multiple feeds are running off of the same importer.) If none of that makes sense, don\'t even think about this.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('Create a <em>gallery</em> to display a sequence of images with descriptions.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
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
    'job_post' => array(
      'name' => t('Job Post'),
      'base' => 'node_content',
      'description' => t('Use a <em>job post</em> to list openings. This should be deprecated by a new system sometime in 2017.'),
      'has_title' => '1',
      'title_label' => t('Job Title'),
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
    'location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => t('Use a <em>location</em> to share information about a building or other facility on campus.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'mailing_list_link' => array(
      'name' => t('Mailing List Link'),
      'base' => 'node_content',
      'description' => t('Exported from duc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
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
