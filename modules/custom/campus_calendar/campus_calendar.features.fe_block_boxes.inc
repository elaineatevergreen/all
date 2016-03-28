<?php
/**
 * @file
 * campus_calendar.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function campus_calendar_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HTML outlining upcoming school years. NOT AUTOMATIC.';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'academicyears';
  $fe_block_boxes->body = '<h3>2015-16</h3>

<ul>
	<li>Fall Quarter: September 28, 2015–December 18, 2015</li>
	<li>Winter Quarter: January 4, 2016–March 18, 2016</li>
	<li>Spring Quarter: March 28, 2016–June 10, 2016</li>
	<li>Summer Quarter: June 20, 2016–September 2, 2016</li>
</ul>

<h3>2016-17</h3>

<ul>
	<li>Fall Quarter: September 26, 2016 –December 16, 2016</li>
	<li>Winter Quarter: January 9, 2017–March 24, 2017</li>
	<li>Spring Quarter: April 3, 2017–June 16, 2017</li>
	<li>Summer Quarter: June 26, 2017–September 8, 2017</li>
</ul>
';

  $export['academicyears'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Background Image';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'placeholder_background';
  $fe_block_boxes->body = '<img alt="" class="main-background-img" src="http://evergreen.edu/news/images/background.jpg">';

  $export['placeholder_background'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Site Section title';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'placeholder_title';
  $fe_block_boxes->body = '<h1><a href="/calendar">Campus Calendar</a></h1>';

  $export['placeholder_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Fake menu with correct HTML.';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'pseudomenu';
  $fe_block_boxes->body = '<ul class="element-list"><li><input id="collapse-1" name="accordion-group" type="radio"><h4 class="accordion-h tertiary-nav-h"><label class="accordion-dismiss" for="collapse-all">Calendars</label><label class="accordion-toggle" for="collapse-1">Calendars</label></h4><div class="accordion-body"><ul class="accordion-inner tertiary-nav-list"><li><a href="/calendar">Campus Events Calendar</a></li><li><a href="/calendar/academic">Academic Calendar at-a-Glance</a></li><li><a href="/calendar/events/month">Events by Month</a></li><li><a href="/calendar/category">Events by Category</a></li><li><a href="/calendar/holidays">Holidays</a></li></ul></div></li><li><input id="collapse-2" name="accordion-group" type="radio"><h4 class="accordion-h tertiary-nav-h"><label class="accordion-dismiss" for="collapse-all">Instructions</label><label class="accordion-toggle" for="collapse-2">Instructions</label></h4><div class="accordion-body"><ul class="accordion-inner tertiary-nav-list"><li><a href="descriptions">Categories & Formats </a></li><li><a href="/calendar/guidelines">Submission Guidelines </a></li></ul></div></li></ul>';

  $export['pseudomenu'] = $fe_block_boxes;

  return $export;
}
