<?php
/**
 * @file
 * evergreen_content.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function evergreen_content_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Academic years in brief';
  $fe_block_boxes->format = 'extended_tags';
  $fe_block_boxes->machine_name = 'academic_years';
  $fe_block_boxes->body = '<p>
	See <a href="/calendar/academic/all">past Academic Calendar dates</a>.</p>

<h3>
	2016–17</h3>

<ul>
	<li>
		<a href="/calendar/academic/all/fall-2016">Fall Quarter</a>: September 26, 2016 –December 16, 2016</li>
	<li>
		<a href="/calendar/academic/all/winter-2017">Winter Quarter</a>: January 9, 2017–March 24, 2017</li>
	<li>
		<a href="/calendar/academic/all/spring-2017">Spring Quarter</a>: April 3, 2017–June 16, 2017</li>
	<li>
		<a href="/calendar/academic/all/summer-2017">Summer Quarter</a>: June 26, 2017–September 8, 2017</li>
</ul>

<h3>
	2017–18</h3>

<ul>
	<li>
		<a href="/calendar/academic/all/fall-2017">Fall Quarter</a>: September 25, 2017 – December 15, 2017</li>
	<li>
		<a href="/calendar/academic/all/winter-2018">Winter Quarter</a>: January 8, 2018 – March 23, 2018</li>
	<li>
		<a href="/calendar/academic/all/spring-2018">Spring Quarter</a>: April 2, 2018–June 15, 2018</li>
	<li>
		<a href="/calendar/academic/all/summer-2018">Summer Quarter</a>: June 25, 2018–September 7, 2018</li>
</ul>
';

  $export['academic_years'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Section Title: Calendar';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'calendar_section_title';
  $fe_block_boxes->body = '<h1><a href="/calendar">Campus Calendar</a></h1>';

  $export['calendar_section_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Section Title: Catalog';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'catalog_section_title';
  $fe_block_boxes->body = '<h1>
	<a href="/catalog">Academic Catalog</a></h1>
';

  $export['catalog_section_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Section Title: Directory';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'directory_section_title';
  $fe_block_boxes->body = '<h1><a href="directory/home">Directories</a></h1>
';

  $export['directory_section_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Secondary content for Faculty Directory';
  $fe_block_boxes->format = 'extended_tags';
  $fe_block_boxes->machine_name = 'faculty_directory_secondary';
  $fe_block_boxes->body = '<p>
	Evergreen’s faculty also organize themselves into Planning Units to develop our curriculum. Learn more about the <a href="/faculty/planning/home">Planning Units</a>.</p>

<h2>
	Related Information</h2>

<ul>
	<li>
		<a href="http://www.evergreen.edu/deans">Academic Deans</a></li>
	<li>
		<a href="http://www.evergreen.edu/policies/category/faculty.htm">Faculty Handbook</a></li>
	<li>
		<a href="http://www.evergreen.edu/facultyhiring">Faculty Hiring</a></li>
	<li>
		<a href="http://www.evergreen.edu/provost/">Provost\'s Office</a></li>
</ul>

<h2>
	Questions?</h2>

<p>
	Questions about the faculty directory or our faculty:</p>

<p>
	<strong>Academic Deans Offices</strong><br />
	<strong>Location:</strong> Library 2002<br />
	<strong>Phone</strong>: (360) 867-6810<br />
	<strong>Fax</strong>: (360) 867-6794<br />
	<strong>Email</strong>: deans@evergreen.edu</p>
';

  $export['faculty_directory_secondary'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Section Title: Fields';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'fields_section_title';
  $fe_block_boxes->body = '<h1><a href="/studies">Fields of Study</a></h1>';

  $export['fields_section_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'iCal link for campus calendar';
  $fe_block_boxes->format = 'extended_tags';
  $fe_block_boxes->machine_name = 'ical_link';
  $fe_block_boxes->body = '<p>
	<a href="/calendar/event/all/ical.ics">Export the Campus Calendar in iCal format</a> and add events to your Google, Outlook, or other personal calendar.</p>
';

  $export['ical_link'] = $fe_block_boxes;

  return $export;
}
