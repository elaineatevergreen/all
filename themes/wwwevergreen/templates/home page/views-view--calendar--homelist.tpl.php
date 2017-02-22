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
				
							<div class="unit-1-7" aria-hidden="true" style="">
								<div class="media media-column">
									<div class="media-img">
										<div class="calendar-dt calendar-dt-null">
											<span class="calendar-month">
												<span class="date-display-single" property="dc:date" datatype="xsd:dateTime" content="2017-03-07T09:30:00-08:00">&nbsp;</span>
											</span>
											<span class="calendar-day">
												<span class="date-display-single" property="dc:date" datatype="xsd:dateTime" content="2017-03-07T09:30:00-08:00">&nbsp;</span>
											</span>
										</div>
									</div>
									<div class="media-body">
										<p>
											<a href="/calendar">More Upcoming Events…</a>
										</p>
									</div>
								</div><!-- /.media.media-column -->
							</div><!-- /.unit-1-7 -->
						</div>
					</div>
	      </div><!-- /.unit-1-1 -->
        
        <!--<div class="unit-1-1">
          <div class="grid">
            <div class="unit-1-2">
              <p><a href="campuscalendar/home.htm"><img alt="" class="inline-icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/dark/calendar.png"/> Campus Events Calendar </a></p>
            </div>
            <div class="unit-1-2">
              <p><a href="campuscalendar/ataglance.htm"><img alt="" class="inline-icon" src="<?php print base_path() . path_to_theme() ?>/images/icons/dark/academics.png"/> Academic Calendar at a Glance </a></p>
            </div>
          </div>
        </div>--><!-- /.unit-1-1 -->
        
      </div><!-- /.grid -->
    </div><!-- /.upcoing-events-homepage2.wrapper -->
  </section><!-- /.box.upcoming-events -->
</section><!-- /.row -->
<!--End Upcoming Events Section-->