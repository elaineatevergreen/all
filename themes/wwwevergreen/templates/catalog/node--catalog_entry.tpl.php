<?php
/**
 * Catalog Listing Page
 *
 **/
/**
 * @file
 */
//dpm($content['group_details']);




// For catalog entries, let's make a nice-looking description of the quarters offered.
//getting the current year for the course, and year -1 for our fall course
$threequarters = $content['field_academic_year']['#items'][0]['safe_value'];
$fall = $threequarters-1;
$quarters_intro = ""; // init
$summer_icon_render_flag = false;

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

			<?php if ( (strpos($quarters_intro,"Summer") !== false) and ($summer_icon_render_flag == false) ) {
				// so if we have a summer session, iterate through all values in field_summer_session and print
				// them all out. Then set a flag so if "Summer" is in quarters intro twice for some reason
				// we don't get all of the summer icons printed twice
				$summer_icon_render_flag = true;
				for($i = 0; $i < sizeof($content['field_summer_session']['#items'][0]["value"]); ++$i){
					if(isset($content['field_summer_session'][$i])){
						// if it's full session
						if (strpos((string)$content['field_summer_session']['#items'][0]["value"] ,"Full") !== false) { ?>
						<img alt=""
						     class="listing-icon-summer"
							 src="/sites/all/themes/wwwevergreen/images/icons/catalog/summer.svg"
							 title="Summer"/>
						<?php } // endif
						// if it's session 1
						if (strpos((string)$content['field_summer_session']['#items'][$i]["value"] ,"First") !== false) { ?>
						<img alt=""
						     class="listing-icon-summer"
								 src="/sites/all/themes/wwwevergreen/images/icons/catalog/summer-session-1.svg"
								 title="Summer"/>
						<?php } //endif
						// if it's session 2
						if (strpos((string)$content['field_summer_session']['#items'][$i]["value"] ,"Second") !== false) { ?>
						<img alt=""
						     class="listing-icon-summer"
								 src="/sites/all/themes/wwwevergreen/images/icons/catalog/summer-session-2.svg"
								 title="Summer"/>
						<?php } //endif?>

				<?php } // if that value is actually set to anything?>
			<?php } // loop going through all values in field_summer_session?>

			<?php // adding extra fallback for summer sessions with no field_summer_session set but who have a quarters_intro set to "Summer"
			if(isset($content['field_summer_session']) == false){?>
				<img alt=""
				     class="listing-icon-summer"
					 src="/sites/all/themes/wwwevergreen/images/icons/catalog/summer.svg"
					 title="Summer"/>
				<?php } ?>

		<?php } // summer is in $quarters_intro?>
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
					<img alt="Olympia" src="/sites/all/themes/wwwevergreen/images/icons/catalog/olympia.svg"/>
			<?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tacoma")!== false) {?>
					<img alt="Tacoma" src="/sites/all/themes/wwwevergreen/images/icons/catalog/tacoma.svg" />
			<?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Grays Harbor")!== false) {?>
					<img alt="Grays Harbor" src="/sites/all/themes/wwwevergreen/images/icons/catalog/grays-harbor.svg"/>
			<?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal")!== false) {?>
					<img alt="Tribal" src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg"/>
			<?php } ?>
			<?php if (strpos(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal MPA")!== false) {?>
					<img alt="Tribal MPA" src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg"/>
			<?php } ?>



			<?php // Study abroad standin with additional details
			      // Include Study Abroad icon, if relevant
			if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) { ?>
				<img alt="Study Abroad" src="/sites/all/themes/wwwevergreen/images/icons/catalog/study-abroad.svg" />
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
		if (render($content['field_class_standing'][0]) == "Graduate"){ // rendering our grad image + title	?>
			<div class="listing-property-img">
				<img alt=""
				     src="/sites/all/themes/wwwevergreen/images/icons/catalog/<?php print(render($content['field_curricular_area'][0]));?>.svg" />
		<?php if($content['field_curricular_area'][1]) { //allow for cross-listed MES/MPA electives ?>
			&nbsp;<img alt=""
				     src="/sites/all/themes/wwwevergreen/images/icons/catalog/<?php print(render($content['field_curricular_area'][1]));?>.svg" />

		<?php };?>
			</div>
			<div class="listing-property-body">
				<?php // printing our word Graduate
					print(render($content['field_class_standing'][0]));
					// display class size
					if(isset($content['field_maximum_enrollment'])){
						print("<br/>" . "Class Size: ") . render($content['field_maximum_enrollment'][0]);
					}?>
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
					if(end($content['field_class_standing']) != ($content['field_class_standing'][0]) ){
						print("–");
						print_r( render(end($content['field_class_standing'])));
					}else{
						print(" Only");
					};
				}
					// display class size
					if(isset($content['field_maximum_enrollment'])){
						print("<br/>" . "Class Size: ") . render($content['field_maximum_enrollment'][0]);
					}
					// if there is a % freshmen, display it
					if(isset($content['field_percent_freshman'])){
						print("<br/><small class='small'> " . render($content['field_percent_freshman'][0]) . " Reserved for Freshmen</small>");
					} ?>
			</div>
		<?php	}?>
	</div>

	<?php // Credits amount standin  ?>
	<div class="listing-property">
		<div class="listing-property-img">
			<?php
				// if the only amount of credits is 0, that means this is a purely variable credits offering.
				if(render($content['group_details']['field_credits'][0]) == '0'){
			?>
				<img alt="Variable" src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-variable.svg"/>
			<?php
				// otherwise, iterate through the credit options and get the svg for that number
				} else {
				for($i = 0; $i < sizeof($content['group_details']['field_credits']['#items']); ++$i){
					if(isset($content['group_details']['field_credits'][$i])){  ?>
						<img alt="<?php print(render($content['group_details']['field_credits'][$i]))?>"
						     src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-<?php print(render($content['group_details']['field_credits'][$i]))?>.svg"/>
			<?php
					} // end check for whether value exists
				} //end loop for values
			} // end check for 0 credits
		?>

			<?php
			// if there's a variable credit option in an offering with other credit options, display variable credit image
			// adding the variable credit V if we already haven't (credit = 0)
			if(isset($content['field_variable_credit_options'][0]) and (render($content['group_details']['field_credits'][0]) != '0')) { ?>
				<img alt="Variable"
				     src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-variable.svg"/>
			<?php } ?>
		</div> <!-- end #listing-property-image -->

		<div class="listing-property-body">
		<?php
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
			}else{  // If the value isn't set, print no credit available
				print ("Credit information not available.<br/><small class='small'>See below for more info.</small>");
			}
			# if the variable credit option exists, but it's not (0cred) version, print the text below the default credit value text
			if(isset($content['field_variable_credit_options'][0]) and (render($content['group_details']['field_credits'][0]) != '0')) {
					print ("</br><small class='small'>Variable Credit Options Available</small>");
				}
			?>
		</div> <!-- end #listing-property-body -->
	</div> <!-- end #listing-property (credits) -->
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

	<?php
	// Preparatory Fields standin
	// field_preparatory_for ?>
	<?php if(isset($content['group_details']['field_preparatory_for'][0])) { ?>
		<p><b><?php print ("This offering will prepare you for careers and advanced study in: ")?></b>
			<?php print(render(($content['group_details']['field_preparatory_for']))); ?></p>
	<?php }; ?>

	<?php // Credits amount standin ?>
	<div class="listing-property">
		<div class="listing-property-img">
			<?php
				// if the only amount of credits is 0, that means this is a purely variable credits offering.
				if(render($content['group_details']['field_credits'][0]) == '0'){
			?>
				<img alt="Variable" src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-variable.svg"/>
			<?php
				// otherwise, iterate through the credit options and get the svg for that number
				} else {
				for($i = 0; $i < sizeof($content['group_details']['field_credits']['#items']); ++$i){
					if(isset($content['group_details']['field_credits'][$i])){  ?>
						<img alt="<?php print(render($content['group_details']['field_credits'][$i]))?>"
						     src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-<?php print(render($content['group_details']['field_credits'][$i]))?>.svg"/>

				<?php } // end check for whether value exists
				} //end loop for values
			} // end check for 0 credits
			// if there's a variable credit option in an offering with other credit options, display variable credit image
			// adding the variable credit V if we already haven't (credit = 0)
			if(isset($content['field_variable_credit_options'][0]) and (render($content['group_details']['field_credits'][0]) != '0')) { ?>
				<img alt="Variable"
				     src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-variable.svg"/>
			<?php } ?>
		</div> <!-- end #listing-property-image -->
		<div class="listing-property-body">
		<?php
			if(isset($content['group_details']['field_credits'][0])) {
				// check to see if credit data value is 0, and if set, display v credits
				if(render($content['group_details']['field_credits'][0]) == '0'){
					print("Variable credit. <br/><small class='small'>See below for more info.</small>");
				// if it's 1 credit, say "credit" and not "credits"
				}elseif(render($content['group_details']['field_credits'][0]) == '1'){
					print " Credit per quarter";
				// printing plural credits
				}else {
					print "<p><b> Credits per quarter </b>";
				}
			}else{  // If the value isn't set, print no credit available
				print ("Credit information not available.<br/><small class='small'>See below for more info.</small>");
			}
			# if the variable credit option exists, but it's not (0cred) version, print the text below the default credit value text
			if(isset($content['field_variable_credit_options'][0]) and (render($content['group_details']['field_credits'][0]) != '0')) {
					print ("</br><small class='small'>Variable Credit Options Available</small>");
				}
			?>
			<?php
			// Variable Credit standin
			//  ?>
			<?php if(isset($content['field_variable_credit_options'][0])) { ?>
				<div><b><?php print ("Variable Credit Options:")?></b>
					<?php print(render($content['field_variable_credit_options'])); ?></div>
			<?php }; ?>

			<?php // Study abroad standin with additional details ?>
			<?php if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) { ?>
				<div class="listing-property">
					<div class="listing-property-img">
						<img alt=""
						     src="/sites/all/themes/wwwevergreen/images/icons/catalog/study-abroad.svg"/>
					</div>
					<div class="listing-property-body">
						<p><b>Study abroad:</b></p>
						<?php print(render($content['group_details']['group_location_schedule']['field_study_abroad'])); ?>
					</div>
				</div>
			<?php }; ?>

			<?php
			// Fields of study standin
			// field_fields_of_study ?>
     	<?php if(isset($content['group_details']['field_fields_of_study'][0])) { ?>
			<?php print(render($content['group_details']['field_fields_of_study'][$i]));?>
		<?php }; // field fields of study?>
			<?php
			// prereq field standin
			// field_prerequisites ?>
			<?php if(isset($content['group_prerequisites']['field_prerequisites'][0])) { ?>
				<div><b><?php print ("Prerequisites:")?></b>
					<?php print(render($content['group_prerequisites']['field_prerequisites'])); ?></div>
			<?php }; ?>

	 <?php //Online Learning standin
				 // field_online_learning ?>
	 			<?php if(isset($content['group_details']['group_more']['field_online_learning'][0])) { ?>
	 				<div><b><?php print ("Online learning:"); ?></b>
	 			<?php
				if(sizeof($content['group_details']['group_more']['field_online_learning']['#items']) > 1 ){
					// if ther eis multiples do regular render
					print(render($content['group_details']['group_more']['field_online_learning']));

				}else{ // if it's a single just do the single no list field
					print(render($content['group_details']['group_more']['field_online_learning']));

				}?>
				</div>
		 		<?php }; // end check for existence of online learning field ?>

	    <?php
		// Special expenses standin
     	// field_special_expenses ?>
     	<?php if(isset($content['group_details']['group_more']['field_special_expenses'][0])) { ?>
				<div><b><?php print ("Special expenses:")?></b>
					<?php print(render($content['group_details']['group_more']['field_special_expenses'])); ?></div>
	    <?php }; ?>

			<?php
			// Fees standin
			// field_fees (can be 0?) TODO fix p tags?>
			<?php if(isset($content['group_details']['group_more']['field_fees'][0])) { ?>
				<div><b>Fees: </b><!--
					--><?php print(render($content['group_details']['group_more']['field_fees'])); ?></div>
	    <?php }; ?>

	    <?php
			// Upper division science credit standin
			// field_upper_division (field_upper_division_boolean seems to be 1 on classes without upper credit too?) ?>
			<?php if(isset($content['field_upper_division'][0])) { ?>
				<p><b><?php print ("Upper division science credit:") // also getting rid of annoying p tags below?></b>
					 <?php print(render($content['field_upper_division'])); ?></p>
	    <?php }; ?>

			<?php
			// Website field standin
			// field_websites ?>
			<?php if(isset($content['group_details']['field_websites'][0])) { ?>
				<div><b><?php print ("Website:")?></b> <?
					print(render($content['group_details']['field_websites']));?>
					</div>
				<?php }; ?>

			<?php
			// Internship op field standin
			// field_internship_opportunities ?>
			<?php if(isset($content['field_internship_opportunities'][0])) { ?>
				<div><b><?php print ("Internship Opportunities:")?></b>
					<?php print(render($content['field_internship_opportunities'])); ?></div>
			<?php }; ?>
			<?php
			// Website field standin
			// field_websites ?>
			<?php if(isset($content['field_research_opportunities'][0])) { ?>
				<div><b><?php print ("Research Opportunities:")?></b>
					<?php print(render($content['field_research_opportunities'])); ?></div>
			<?php }; ?>





		</div> <!-- end #listing-property-body -->
	</div> <!-- end #listing-property (credits) -->


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
					print("<b>Class Standing: </b>");
					print(render($content['field_class_standing'][0]));
					// display class size
					if(isset($content['field_maximum_enrollment'])){
						print("<br/>" . "<b>Class Size: </b>") . render($content['field_maximum_enrollment'][0]);
					}?>
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
						print("<b>Class Standing: </b>");
						print_r(render($content['field_class_standing'][0]));
						// if our eldest class standing is not also the same thing as our youngest, put a dash and display the range ex: freshman-senior
					if(end($content['field_class_standing']) != ($content['field_class_standing'][0]) ){
						print("–");
						print_r( render(end($content['field_class_standing'])));
					}else{
						print(" Only");
					};
				}
					// display class size
					if(isset($content['field_maximum_enrollment'])){
						print("<br/>" . "<b>Class Size: </b>") . render($content['field_maximum_enrollment'][0]);
					}
					// if there is a % freshmen, display it
					if(isset($content['field_percent_freshman'])){
						print("<br/> " . render($content['field_percent_freshman'][0]) . " Reserved for Freshmen");
					} ?>
			</div>
		<?php	}?>
	</div>

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
							<p><b>Scheduled for:</b> <?php print(render($content['group_details']['group_location_schedule']['field_time_offered'])); ?>
						<?php }; ?>
						<?php if(isset($content['group_details']['group_location_schedule']['field_final_schedule'])) { ?>
						<p><b>Final schedule and room assignments:</b></p>
						<?php print(render(($content['group_details']['group_location_schedule']['field_final_schedule']))); ?>
						<?php }; ?>

						<?php if(isset($content['group_details']['group_location_schedule']['field_advertised_schedule'])) { ?>
							<p><b>Advertised schedule:</b></p>
							<?php print(render($content['group_details']['group_location_schedule']['field_advertised_schedule'])); ?>
						<?php }; ?>

						<?php if(isset($content['group_details']['group_location_schedule']['field_additional_schedule_detail'])) { ?>
							<p><b>Additional details:</b></p>
							<?php print(render($content['group_details']['group_location_schedule']['field_additional_schedule_detail'])); ?>
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
						</p>
						</div>
						<div class="listing-property-body">
							<p><b>Located in:</b> <?php print(render($content['group_details']['group_location_schedule']['field_location'])); ?></p>
							<?php // Off-campus location standin - FYI, no programs in 2017–18 and ’18–19 have this flag set, so it’s kinda hard to test right now. —jkm
								if(isset($content['group_details']['group_location_schedule']['field_off_campus_location'])) { ?>
								<p><b>Off-campus location:</b> <?php print(render($content['group_details']['group_location_schedule']['field_off_campus_location'])); ?></p>
							<?php }; ?>
						</div>
				</div>

			<!--The “May be offered again” standin here. -->

				<?php if(isset($content['group_details']['group_more']['field_next_offered'])) { ?>
				<div class="box note">
					<p>
						<?php print(render($content['group_details']['group_more']['field_next_offered'])); ?>
					</p>
					</div>
				<?php }; ?>


		</div> <!-- /.program-description -->

		<?php
		/**
		 * Revisions
		 */
		?>
		<?php // revisions, do we want these in the new design? ?>
		<?php print(render($content['field_revisions'])); ?>

	</div> <!-- /.content -->

</div>
