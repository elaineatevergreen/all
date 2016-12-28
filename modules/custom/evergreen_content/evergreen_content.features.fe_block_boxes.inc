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

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Library Search Form';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'library_search';
  $fe_block_boxes->body = '<style type="text/css"><!--
a.button.prime, a.button.prime:visited {
background: #6e597e;
}
a.button.prime:hover, a.button.prime:focus  {
color: #FFFFFF;
background: #b6acbf;
}
--></style>
<form action="http://alliance-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/dlSearch.do?" class="base ui-group" enctype="application/x-www-form-urlencoded; charset=utf-8" id="simple" method="get" name="searchForm"><!-- form should have  role="search" -->
<h2>Library Catalog</h2>
<input name="institution" value="Alliance_EVSC" type="hidden" /> <input name="vid" value="EVSC" type="hidden" /> <input name="group" value="GUEST" type="hidden" /> <input name="onCampus" value="true" type="hidden" /> <input name="displayMode" value="full" type="hidden" /> <input id="primoQuery" name="query" type="hidden" />
<div><label for="queryTemp">Search for:</label> <input id="primoQueryTemp" name="queryTemp" onkeypress="searchKeyPress(event);" value="" type="text" /> <label for="search_scope"> In:</label><select id="search_scope" name="search_scope">
<option value="tesc_alma_summit">Evergreen + Summit</option>
<option value="tesc_alma">Evergreen Only</option>
<option value="everything">Articles, Books, and More</option>
</select>&#160;<input alt="Search" class="prime" id="go" onclick="searchPrimo()" title="Search" value="Search" type="button" /></div>
<p><a href="http://alliance-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/login.do?loginFn=signin&amp;vid=EVSC&amp;targetURL=http://alliance-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/myAccountMenu.do?vid=EVSC" title="Log into your library account, renew items, check due dates.">My Account</a> &#8226; <a href="https://clio.evergreen.edu/illiad/EVER/" title="Interlibrary loan login">Interlibrary Loan</a>&#160;&#8226; <a href="http://alliance-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/search.do?mode=Advanced&amp;ct=AdvancedSearch&amp;dscnt=0&amp;fromLogin=true&amp;dstmp=1388508776718&amp;filler=GUEST&amp;vid=EVSC" title="Use this search for narrowing results by language, material type, etc.">Advanced Search</a> &#8226; <a href="http://alliance-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/search.do?mode=Basic&amp;ct=BasicSearch&amp;vl(457139437UI5)=all_items&amp;vl(309590236UI6)=00&amp;vl(D309590230UI2)=any&amp;dscnt=0&amp;vl(1UIStartWith0)=contains&amp;vl(1UIStartWith1)=contains&amp;vl(464222367UI0)=any&amp;vl(309590234UI6)=00&amp;vl(1UIStartWith2)=contains&amp;vid=EVSC&amp;vl(309590238UI6)=Year&amp;vl(boolOperator1)=AND&amp;tab=course_reserves&amp;vl(boolOperator0)=AND&amp;vl(D309590232UI1)=any&amp;vl(739997557UI4)=all_items&amp;vl(D309590229UI3)=all_items&amp;vl(boolOperator2)=AND&amp;vl(309590237UI6)=00&amp;vl(309590235UI6)=Year&amp;vl(309590233UI6)=00&amp;dstmp=1453498857210" title="program reserves">Program Reserves</a> &#8226;&#160;<strong><a href="/library/databases" title="Explore our electronic article indexes, databases, websites and more.">Research Databases</a>&#160;&#8226; <a href="http://evergreen.worldcat.org/" title="WorldCat - search for items held by libraries all over the world">WorldCat</a></strong></p>
</form>';

  $export['library_search'] = $fe_block_boxes;

  return $export;
}
