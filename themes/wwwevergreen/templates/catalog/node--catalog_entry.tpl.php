<?php
/**
 * Catalog Listing Page
 *
 **/
/**
 * @file
 */
//dpm($content['field_summer_session']);

// TODO
// bolding issues /inconsistant inputted content with advertised schedule:




// For catalog entries, let's make a nice-looking description of the quarters offered.
//getting the current year for the course, and year -1 for our fall course
$threequarters = $content['field_academic_year']['#items'][0]['safe_value'];
$fall = $threequarters-1;
$quarters_intro = ""; // init

// Putting the correct year at the end of each Fall/Winter/Spring/etc
foreach($content['field_quarters_offered']['#items'] as $q) {
	$quarter = $q['value'];
	if($quarter == 'Fall') {
		$quarters[] = 'Fall ' . $fall; // this adds Fall 2017 since it's not 2018 like the rest
	} else {
		$quarters[] = $quarter . ' ' . $threequarters;
	};
}
// Generating our string nicely and storing it in $quarters_intro ex: "Fall 2016, Winter 2017, and Spring 2017"
if(count($quarters) == 1) {
	$quarters_intro = $quarters[0];
}elseif(count($quarters) == 2) {
	$quarters_intro .= $quarters[0] . '<br/>' . $quarters[1];
}elseif(count($quarters) == 3) {
	$quarters_intro .= $quarters[0] . '<br/>' . $quarters[1] . '<br/>' . $quarters[2];
}elseif(count($quarters) == 4) {
	$quarters_intro .= $quarters[0] . '<br/>' . $quarters[1]  . '<br/>' . $quarters[2] . '<br/>' . $quarters[3] ;
}; ?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php print $user_picture; ?>

<?php // TESTING HEADER ZONE ?>
<header class="listing-header">
	<?php // Month/Year standin ?>
	<div class="listing-property">
		<div class="listing-property-img">
		<?php // printing the correct quarter icon
			if($content)

			// Drawing the images for the different quarters?>
			<?php if (strpos($quarters_intro,"Fall") !== false) {?>
				<img alt=""
				     class="listing-icon-fall"
						 src="/sites/all/themes/wwwevergreen/images/icons/catalog/fall.svg"
						 title="Fall"/>
			<?php } ?>
			<?php if (strpos($quarters_intro,"Winter") !== false) { ?>
				<img alt=""
				     class="listing-icon-winter"
						 src="/sites/all/themes/wwwevergreen/images/icons/catalog/winter.svg"
						 title="Winter"/>
			<?php } ?>
			<?php if (strpos($quarters_intro,"Spring") !== false) { ?>
				<img alt=""
				     class="listing-icon-spring"
						 src="/sites/all/themes/wwwevergreen/images/icons/catalog/spring.svg"
						 title="Spring"/>
			<?php } ?>
			<?php if (strpos($quarters_intro,"Summer") !== false) { ?>
				<img alt=""
				     class="listing-icon-summer"
						 src="/sites/all/themes/wwwevergreen/images/icons/catalog/summer.svg"
						 title="Summer"/>
			<?php } ?>
		</div>
		<div class="listing-property-body">
			<?php
			if(render($content['field_summer_session']) != '') {
				print(render($quarters_intro)); // print "summer"
				print(" (");
				//getting the summer session variable without the mystical leading ghost space
				print_r($content['field_summer_session']['#items'][0]["value"]);
				print(" Session)");
			}else{
				print render($quarters_intro);
			} ?>
		</div>
	</div>

	<?php // Campus location standin ?>
	<div class="listing-property">
		<div class="listing-property-img">
			<!-- Printing the location based on where we are -->
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Olympia")!== false) {?>
					<img alt=""
					     src="/sites/all/themes/wwwevergreen/images/icons/catalog/olympia.svg"
							 title="Olympia"/>
			<?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tacoma")!== false) {?>
					<img alt=""
					     src="/sites/all/themes/wwwevergreen/images/icons/catalog/tacoma.svg"
							 title="Tacoma"/>
			<?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Grays Harbor")!== false) {?>
					<img alt=""
					     src="/sites/all/themes/wwwevergreen/images/icons/catalog/grays-harbor.svg"
							 title="Grays Harbor"/>
			<?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal")!== false) {?>
					<img alt=""
					     src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg"
							 title="Tribal"/>
			<?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal MPA")!== false) {?>
					<img alt=""
					     src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg"
							 title="Tribal MPA"/>
			<?php } ?>



			<?php // Study abroad standin with additional details
			      // Include Study Abroad icon, if relevant
			if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) { ?>
				<img alt=""
				     src="/sites/all/themes/wwwevergreen/images/icons/catalog/study-abroad.svg"
						 title="Study Abroad"/>
			<?php }; ?>
		</div>


		<div class="listing-property-body">
			<?php print render($content['group_details']['group_location_schedule']['field_location']);
			// Include Study Abroad label, if relevant
			if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) {
				print "&nbsp;+<br/>study abroad option";
				}; ?>
		</div>

	</div>

	<?php // Time offered, This can have multiple properties, for example, Day, Evening, and Weekend. ?>
	<div class="listing-property">
		<div class="listing-property-img">
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_time_offered']),"Day")!== false) {?>
					<img alt=""
					     class="listing-icon-time-offered listing-icon-day"
					     src="/sites/all/themes/wwwevergreen/images/icons/catalog/daytime.svg"
							 title="Daytime"/>
		  <?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_time_offered']),"Evening")!== false) {?>
					<img alt=""
					     class="listing-icon-time-offered listing-icon-evening"
					     src="/sites/all/themes/wwwevergreen/images/icons/catalog/evening.svg"
							 title="Evening"/>
			<?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_time_offered']),"Weekend")!== false) {?>
					<img alt=""
					     class="listing-icon-time-offered listing-icon-weekend"
					     src="/sites/all/themes/wwwevergreen/images/icons/catalog/weekend.svg"
							 title="Weekend"/>
			<?php } ?>
		</div>

		<div class="listing-property-body">
			<?php if(isset($content['group_details']['group_location_schedule']['field_time_offered'])) { ?>
				<?php print render($content['group_details']['group_location_schedule']['field_time_offered']); ?>
			<?php }; ?>
		</div>
	</div>

	<?php // Class standing standin ?>
	<div class="listing-property">
		<?php //Translating our curricular area into our image path name for grad courses
		      // if graduate
		if (render($content['field_class_standing'][0]) == "Graduate"){ // rendering our grad image + title?>
			<div class="listing-property-img">
				<img alt=""
				     src="/sites/all/themes/wwwevergreen/images/icons/catalog/<?php print(render($content['field_curricular_area'][0]));?>.svg" />
			</div>
			<div class="listing-property-body">
				<?php // printing our word Graduate
					print(render($content['field_class_standing'][0]));
				?>
			</div>
		<?php
		} else {
			// if it's an undergrad course
		  // take the first element and the last element, and use them to make the file name for the class standing range
		  // Render our undergrad image and title?>
		  <div class="listing-property-img">
				<?php // If we have  undergrad course that extends through graduate, print the logos together with the correct title ?>
				<?php if(render(end($content['field_class_standing'])) == "Graduate" ){
					//printing the undergrad bars from the first through senior?>
					<img alt=""
							 src="/sites/all/themes/wwwevergreen/images/icons/catalog/<?php print(render($content['field_class_standing'][0])) . "-Senior.svg";?>"
							 title="<?php print(render($content['field_class_standing'][0]));?>-Senior" />

					<?php // adding the grad+ icon after our bars for undergrad years?>
					<img alt=""
						   src="/sites/all/themes/wwwevergreen/images/icons/catalog/grad.svg"
							 title="Graduate" />
				<?php } else { // if it's a normal undergrad course?>
					<img alt=""
						   src="/sites/all/themes/wwwevergreen/images/icons/catalog/<?php print(render($content['field_class_standing'][0])) . "-" . render(end($content['field_class_standing']));?>.svg"
						   title="<?php print(render($content['field_class_standing'][0]));?>-<?php print(render(end($content['field_class_standing'])));?>" />

				<?php }?>
			</div>
			<div class="listing-property-body">
				<?php // Printing youngest class standing
					if(isset($content['field_class_standing'])) {
						print_r(render($content['field_class_standing'][0]));
						// if our eldest class standing is not also the same thing as our youngest, put a dash and display the range ex: freshman-senior
					if(end($content['field_class_standing']) != ($content['field_class_standing']) ){
						print("–");
						print_r( render(end($content['field_class_standing'])));
					}else{
						print(" Only");
					};
				}
					// if there is a % freshmen, display it
					if(isset($content['field_percent_freshman'])){
						print("<br/><small class='small'> " . render($content['field_percent_freshman'][0]) . " Reserved for Freshmen</small>");
					} ?>
			</div>
		<?php	}?>
	</div>
	<?php // Credits amount standin ?>
	<div class="listing-property">
		<div class="listing-property-img">
			<?php if(render($content['group_details']['field_credits'][0]) == '0'){?>
				<img alt="Variable"
			       src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-variable.svg"/>
			<?php } else {
				for($i = 0; $i < sizeof($content['group_details']['field_credits']['#items']); ++$i){
					if(isset($content['group_details']['field_credits'][$i])){  ?>
						<img alt="<?php print(render($content['group_details']['field_credits'][$i]))?>"
						     src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-<?php print(render($content['group_details']['field_credits'][$i]))?>.svg"/>
					<?php }
				}
			} ?>

			<?php 		// adding the variable credit V if we already havent (credit = 0)
			if(isset($content['field_variable_credit_options'][0]) and (render($content['group_details']['field_credits'][0]) != '0')) { ?>
				<img alt="Variable"
				     src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-variable.svg"/>
			<?php } ?>

		</div>
		<div class="listing-property-body"> <?php
			if(isset($content['group_details']['field_credits'][0])) {
				// check to see if credit data value is 0, and if set, display v credits
				if(render($content['group_details']['field_credits'][0]) == '0'){
					print("Variable credit. <br/><small class='small'>See below for more info.</small>");
				// if it's 1 credit, say "credit" and not "credits"
				}elseif(render($content['group_details']['field_credits'][0]) == '1'){
					print " Credit per quarter";
				// printing plural credits
				}else {
					print " Credits per quarter";
				}
			}else{  // If the value isn't set, print no credit Available
				print ("Credit information not available.<br/><small class='small'>See below for more info.</small>");
			}
			# if the variable credit option exists, but it's not (0cred) version, print the text below the default credit value text
			if(isset($content['field_variable_credit_options'][0]) and (render($content['group_details']['field_credits'][0]) != '0')) {
					print ("</br><small class='small'>Variable Credit Options Available</small>");
				}
			?>
		</div>
	</div>
</header>

<?php
/**
 * Call to Action (Save to List)
 */
 ?>
<div class="box action-box">
	<div class="action-item-1-2">
		<?php print render($content['links']); ?>
		<?php print("<p><small class='small'>Compare offerings and share your lists with others.</small></p>");?>
	</div>
	<div class="action-item-2-2">
		<p><a href="/catalog/index?flagged=1">See all saved items</a></p>
	</div>
</div>

<?php
// "Header" ends here
//* - $title_prefix (array): An array containing additional output populated by
//*   modules, intended to be displayed in front of the main title tag that
//*   appears in the template.
print render($title_prefix);

//* - $title: The page title, for use in the actual HTML content.

if (!$page){ ?>
	<h2<?php print $title_attributes; ?>>
		<a href="<?php print $node_url; ?>"><?php print $title; ?></a>
	</h2>
<?php } ?>

<?php
//* - $title_suffix (array): An array containing additional output populated by
//*   modules, intended to be displayed after the main title tag that appears in
//*   the template. ?>
<?php print render($title_suffix); ?>

<div class="content"<?php print $content_attributes; ?>>
  <?php
	// We hide the comments and links now so that we can render them later.
	hide($content['comments']);
	hide($content['links']);
	hide($content['field_academic_year']);
	hide($content['field_quarters_offered']);
	hide($content['field_faculty']);
	hide($content['field_revisions']);
	hide($content['group_details']['group_location_schedule']);
	hide($content['group_details']['group_more']);

	$updatestatus = '';
	if(strstr(render($content['field_offering_status']),'Cancelled')) {
		$updatestatus = 'CANCELLED';
	}elseif((time()-(60*60*24*30)) < strtotime($content['field_status_date']['#items'][0]['value'])) {
		$updatestatus = 'NEW';
	}elseif((time()-(60*60*24*30)) < strtotime($content['field_revision_date']['#items'][0]['value'])) {
		$updatestatus = 'REVISED';
	};

	if($updatestatus != '') { ?>
		<div class="box note program-status">
			<p class="program-status-revised">
				<?php print $updatestatus ?>
			</p>
		</div>
	<?php }; ?>

	<?php
	/**
	 * Program Description
	 */
	?>
	<div class="program-description">
		<?php
		/**
		 * Faculty List
		 */ 		?>

		<p>Taught by</p>
		<div class="grid">
			<?php print render($content['field_faculty']); ?>
		</div>
		<?php
		/**
		 * Main Program Description
		 *
		 * This section prints the longhand program description as
		 * provided by faculty.
		 */
 	 	 // changed $content to now just print the body content without the save link attached ?>
		 <?php print render($content['body'][0]); ?>

			<?php
			/**
			 * Additional Program Details
			 */
			?>


			<?php // Study abroad standin with additional details ?>
			<?php if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) { ?>
				<div class="listing-property">
					<div class="listing-property-img">
						<img alt=""
						     src="/sites/all/themes/wwwevergreen/images/icons/catalog/study-abroad.svg"/>
					</div>
					<div class="listing-property-body">
						<p><b>Study abroad:</b></p>
						<?php printEach($content['group_details']['group_location_schedule']['field_study_abroad']); ?>
					</div>
				</div>
			<?php }; ?>

			<?php
			// Fields of study standin
			// field_fields_of_study ?>
     	<?php if(isset($content['group_details']['field_fields_of_study'][0])) { ?>
				<div class="fos keyword-list">
					<b><?php print ("Fields of study:")?></b> 
					<ul class="field-fields-of-study element-list">
					<?php printEach($content['group_details']['field_fields_of_study'], "<li>", "</li>"); ?>
				</ul>
				</div>
	    <?php }; ?>

	    <?php
			// Preparatory Fields standin
			// field_preparatory_for ?>
			<?php if(isset($content['group_details']['field_preparatory_for'][0])) { ?>
				<p><b><?php print ("This offering will prepare you for careers and advanced study in: ")?></b>
					<?php printEach($content['group_details']['field_preparatory_for']); ?></p>
			<?php }; ?>

			<?php // Maximum enrollment standin
			// field_maximum_enrollment ?>
			<?php if(isset($content['field_maximum_enrollment'][0])) { ?>
				<p><b><?php print ("Maximum enrollment:")?></b>
					<?php printEach($content['field_maximum_enrollment']); ?></p>
	    <?php }; ?>

			<?php
				/**
				 * Online Learning standin
				 * TODO: move this out of the template to a tamper or something]
				 */
				 // field_online_learning ?>
	 			<?php if(isset($content['group_details']['group_more']['field_online_learning'][0])) { ?>
	 				<div><b><?php print ("Online learning:"); ?></b>
	 				<?php
		 				
		 				/* $ol_format_flag = False; //using a flag to find if we've applied any of our custom formatting rules?>
	 						<?php render($content['group_details']['group_more']['field_online_learning'][0]); #making this accessible?>
	 						<?php $ol_content_array = explode(",",$content['group_details']['group_more']['field_online_learning'][0]['#children']); ?>
	 						<?php $ol_content_array[0] = " " . $ol_content_array[0] # adding a space to the first value so they're consistant ?>
	 						<?php for($i = 0; $i < count($ol_content_array); ++$i){?>
	 							<?php if (strpos($ol_content_array[$i], '(F)') !== false) {  # if it says fall ?>
	 								<li><?php print("Fall:")?><?php print(render(substr($ol_content_array[$i],0,-3))); #remove the (F) ?></li>
	 								<?php $ol_format_flag = True; //flag if we've custom formatted?>
	 							<?php } ?>
	 							<?php if (strpos($ol_content_array[$i], '(FW)') !== false) {  # if it says fall-winter ?>
	 								<li><?php print("Fall and Winter:")?><?php print(render(substr($ol_content_array[$i],0,-4))); #remove the (FW)?></li>
	 								<?php $ol_format_flag = True; //flag if we've custom formatted?>
	 							<?php } ?>
	 							<?php if (strpos($ol_content_array[$i], '(W)') !== false) {  # if it says winter ?>
	 								<li><?php print("Winter:")?><?php print(render(substr($ol_content_array[$i],0,-3))); #remove the (W) ?></li>
	 								<?php $ol_format_flag = True; //flag if we've custom formatted?>
	 							<?php } ?>
	 							<?php if (strpos($ol_content_array[$i], '(WS)') !== false) {  # if it says winter-spring ?>
	 								<li><?php print("Winter and Spring:")?><?php print(render(substr($ol_content_array[$i],0,-4))); #remove the (WS)?></li>
	 								<?php $ol_format_flag = True; //flag if we've custom formatted?>
	 							<?php } ?>
	 							<?php if (strpos($ol_content_array[$i], '(S)') !== false) {  # if it says spring ?>
	 								<li><?php print("Spring:")?><?php print(render(substr($ol_content_array[$i],0,-3))); #remove the (S)?></li>
	 								<?php $ol_format_flag = True; //flag if we've custom formatted?>
	 							<?php } ?>
	 							<?php if (strpos($ol_content_array[$i], '(FS)') !== false) {  # if it says fall-spring ?>
	 								<li><?php print("Fall and Spring:")?><?php print(render(substr($ol_content_array[$i],0,-4)));  #remove the (FS)?></li>
	 								<?php $ol_format_flag = True; //flag if we've custom formatted?>
	 							<?php } ?>
	 							<?php if (strpos($ol_content_array[$i], '(SU)') !== false) {  # if it says summer ?>
	 								<li><?php print("Summer:")?><?php print(render(substr($ol_content_array[$i],0,-4)));  #remove the (SU)?></li>
	 								<?php $ol_format_flag = True; //flag if we've custom formatted?>
	 							<?php } ?>
	 					<?php } // end formatting loop ?>
	 					<?php if ($ol_format_flag == False){ // if we had no custom formatting applied, print the whole thing normally
	 						printEach($content['group_details']['group_more']['field_online_learning']);
	 					}*/ ?>
	 			<?php 
		 			if(count($content['group_details']['group_more']['field_online_learning']) == 1) { print "just one."; };
		 		print(render($content['group_details']['group_more']['field_online_learning']));	
		 			
		 		}; // end check for existence of online learning field
	 			
	 			
	 			
	 			?></div>

	    <?php
			// Special expenses standin
     	// field_special_expenses ?>
     	<?php if(isset($content['group_details']['group_more']['field_special_expenses'][0])) { ?>
				<div><b><?php print ("Special expenses:")?></b>
					<?php printEach($content['group_details']['group_more']['field_special_expenses']); ?></div>
	    <?php }; ?>

			<?php
			// Fees standin
			// field_fees (can be 0?) TODO fix p tags?>
			<?php if(isset($content['group_details']['group_more']['field_fees'][0])) { ?>
				<div><b><?php print ("Fees:") // have to do a substr to get rid of annoying paragraph tabs below ?></b>
					<?php printEach($content['group_details']['group_more']['field_fees']); ?></div>
	    <?php }; ?>

	    <?php
			// Upper division science credit standin TODO fix p tags
			// field_upper_division (field_upper_division_boolean seems to be 1 on classes without upper credit too?) ?>
			<?php if(isset($content['field_upper_division'][0])) { ?>
				<p><b><?php print ("Upper division science credit:") // also getting rid of annoying p tags below?></b>
					 <?php printEach($content['field_upper_division']); ?></p>
	    <?php }; ?>

			<?php
			// Website field standin
			// field_websites ?>
			<?php if(isset($content['group_details']['field_websites'][0])) { ?>
				<div><b><?php print ("Website:")?></b> <?
					printEach($content['group_details']['field_websites']);?>
					</div>
				<?php }; ?>

			<?php
			// Internship op field standin
			// field_internship_opportunities ?>
			<?php if(isset($content['field_internship_opportunities'][0])) { ?>
				<div><b><?php print ("Internship Opportunities:")?></b>
					<?php printEach($content['field_internship_opportunities']); ?></div>
			<?php }; ?>
			<?php
			// Website field standin
			// field_websites ?>
			<?php if(isset($content['field_research_opportunities'][0])) { ?>
				<div><b><?php print ("Research Opportunities:")?></b>
					<?php printEach($content['field_research_opportunities']); ?></div>
			<?php }; ?>
			<?php
			// prereq field standin
			// field_prerequisites ?>
			<?php if(isset($content['group_prerequisites']['field_prerequisites'][0])) { ?>
				<div><b><?php print ("Prerequisites:")?></b>
					<?php printEach($content['group_prerequisites']['field_prerequisites']); ?></div>
			<?php }; ?>




			<?php // Image for the Scheduled for: section in body ?>
				<?php
					/**
					 * [bug] If there is more than one icon, they drop down below
					 *       each other, and shift the text body to no longer be left
					 *       aligned with the paragraphs above.
					 *      —jkm
				   * -- fixed for now? -stevenm
					 */
				?>
				<div class="listing-property">
				<?php // Time offered, This can have multiple properties, for example, Day, Evening, and Weekend. ?>
					<div class="listing-property-img">
						<?php if (strpos(render($content['group_details']['group_location_schedule']['field_time_offered']),"Day")!== false) {?>
								<img alt=""
								     class="listing-icon-time-offered listing-icon-day"
								     src="/sites/all/themes/wwwevergreen/images/icons/catalog/daytime.svg" title="Daytime"/>
					  <?php } ?>
						<?php if (strpos(render($content['group_details']['group_location_schedule']['field_time_offered']),"Evening")!== false) {?>
								<img alt=""
								     class="listing-icon-time-offered listing-icon-evening"
								     src="/sites/all/themes/wwwevergreen/images/icons/catalog/evening.svg" title="Evening"/>
						<?php } ?>
						<?php if (strpos(render($content['group_details']['group_location_schedule']['field_time_offered']),"Weekend")!== false) {?>
								<img alt=""
								     class="listing-icon-time-offered listing-icon-weekend"
								     src="/sites/all/themes/wwwevergreen/images/icons/catalog/weekend.svg" title="Weekend"/>
						<?php } ?>
					</div>

					<div class="listing-property-body">
						<?php if(isset($content['group_details']['group_location_schedule']['field_time_offered'])) { ?>
							<p><b>Scheduled for:</b> <?php printEach($content['group_details']['group_location_schedule']['field_time_offered']); ?>
						<?php }; ?>
						</div>
					</div>
					<div class="listing-property">
						<div class="listing-property-img">
							<!-- Printing the location based on where we are -->
							<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Olympia")!== false) {?>
									<img alt=""
									     src="/sites/all/themes/wwwevergreen/images/icons/catalog/olympia.svg"
											 title="Olympia"/>
							<?php } ?>
							<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tacoma")!== false) {?>
									<img alt=""
									     src="/sites/all/themes/wwwevergreen/images/icons/catalog/tacoma.svg"
											 title="Tacoma"/>
							<?php } ?>
							<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Grays Harbor")!== false) {?>
									<img alt=""
									     src="/sites/all/themes/wwwevergreen/images/icons/catalog/grays-harbor.svg"
											 title="Grays Harbor"/>
							<?php } ?>
							<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal")!== false) {?>
									<img alt=""
									     src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg"
											 title="Tribal"/>
							<?php } ?>
							<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal MPA")!== false) {?>
									<img alt=""
									     src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg"
											 title="Tribal MPA"/>
							<?php } ?>
						</div>
						<div class="listing-property-body">
							<p><b>Located in:</b> <?php printEach($content['group_details']['group_location_schedule']['field_location']); ?></p>
							<?php // Off-campus location standin - FYI, no programs in 2017–18 and ’18–19 have this flag set, so it’s kinda hard to test right now. —jkm
								if(isset($content['group_details']['group_location_schedule']['field_off_campus_location'])) { ?>
								<p><b>Off-campus location:</b> <?php printEach($content['group_details']['group_location_schedule']['field_off_campus_location']); ?></p>
							<?php }; ?>
						</div>
				</div>

				<?php
			 /**
				* Location and Schedule
				*/
			 ?>

		<div class="listing-property">
			<div class="listing-property-body">

				<?php if(isset($content['group_details']['group_location_schedule']['field_final_schedule'])) { ?>
					<p><b>Final schedule and room assignment:</b></p>
					<?php printEach($content['group_details']['group_location_schedule']['field_final_schedule']); ?>
				<?php }; ?>

				<?php if(isset($content['group_details']['group_location_schedule']['field_advertised_schedule'])) { ?>
					<p><b>Advertised schedule:</b></p>
					<?php printEach($content['group_details']['group_location_schedule']['field_advertised_schedule']); ?>
				<?php }; ?>

				<?php if(isset($content['group_details']['group_location_schedule']['field_additional_schedule_detail'])) { ?>
					<p><b>Additional details:</b></p>
					<?php printEach($content['group_details']['group_location_schedule']['field_additional_schedule_detail']); ?>
				<?php }; ?>


			</div>
		</div>
			<!--The “May be offered again” standin here. -->
			<div class="box note">
				<?php if(isset($content['group_details']['group_more']['field_next_offered'])) { ?>
					<p>
						<?php printEach($content['group_details']['group_more']['field_next_offered']); ?>
					</p>
				<?php }; ?>
			</div>
		</div> <!-- /.program-description -->

		<?php
		/**
		 * Revisions
		 */
		?>
		<?php // revisions, do we want these in the new design? ?>
		<?php printEach($content['field_revisions']); ?>


		<?php
		function printEach($passedcontent, $put_front = "", $put_after= "")
		//takes a content (not yet rendered) renderable array and prints all the items out
		// put_front will be put in front of each element, and put after, after
		// front and after are optional parameters and default to ""
		{
			for($i = 0; $i < sizeof($passedcontent['#items']); ++$i){
				if(isset($passedcontent[$i])){
					print($put_front);
					print(render($passedcontent[$i]));
					print($put_after);
				}
			}
		}
		?>
	</div> <!-- /.content -->

</div>
