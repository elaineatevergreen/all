<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<!--Upcoming Events-->
<section class="row">
  <section class="box upcoming-events">
    <div class="upcoming-events-homepage2 wrapper">
    <h3>Upcoming Events</h3>
      <div class="grid">
        <div class="unit-1-1">
          <div class="upcoming-events-list-wrapper">
            <div class="grid upcoming-events-list" id="upcoming-events-list">

<?php 
	if ($rows): 
	   print $rows; 
	elseif ($empty): 
		print $empty; 
	endif; 
?>

            </div>
          </div>
        <div class="unit-1-1">
          <div class="grid">
            <div class="unit-1-2">
              <p><a href="campuscalendar/home.htm"><img alt="" class="inline-icon" src="http://www.evergreen.edu/_inc/images/icons/dark/calendar.png"/> Campus Events Calendar </a></p>
            </div>
            <div class="unit-1-2">
              <p><a href="campuscalendar/ataglance.htm"><img alt="" class="inline-icon" src="http://www.evergreen.edu/_inc/images/icons/dark/academics.png"/> Academic Calendar at a Glance </a></p>
            </div>
          </div>
        </div>
      </div>
    </div>
  </section>
</section>
<!--End Upcoming Events Section-->