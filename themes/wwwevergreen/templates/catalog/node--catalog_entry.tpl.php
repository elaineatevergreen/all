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

// edge cases being thought about:
// Tribal MPA classes
// graduate courses in general need to be added



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
};
if(render($content['field_summer_session']) != '') {
	$quarters_intro .= " (" . render($content['field_summer_session']) . " Session)";
};?>

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
			<?php if (strlen(strstr($quarters_intro,"Fall"))>0) {?>
				<img alt="" class="listing-icon-fall" src="/sites/all/themes/wwwevergreen/images/icons/catalog/fall.svg" title="Fall"/>
			<?php } ?>
			<?php if (strlen(strstr($quarters_intro,"Winter"))>0) { ?>
				<img alt="" class="listing-icon-winter" src="/sites/all/themes/wwwevergreen/images/icons/catalog/winter.svg" title="Winter"/>
			<?php } ?>
			<?php if (strlen(strstr($quarters_intro,"Spring"))>0) { ?>
				<img alt="" class="listing-icon-spring" src="/sites/all/themes/wwwevergreen/images/icons/catalog/spring.svg" title="Spring"/>
			<?php } ?>
			<?php if (strlen(strstr($quarters_intro,"Summer"))>0) { ?>
				<img alt="" class="listing-icon-summer" src="/sites/all/themes/wwwevergreen/images/icons/catalog/summer.svg" title="Summer"/>
			<?php } ?>
		</div>
		<div class="listing-property-body">
			<?php
			if(render($content['field_summer_session']) != '') {
				print(render($quarters_intro)); // print "summer"
				print(" (");
				//getting the summer session variable without the mystical leading ghost space
				print_r($content['field_summer_session']['#items'][0]["value"]);
				print(")");
			}else{
				print render($quarters_intro);
			} ?>
		</div>
	</div>

	<div class="listing-property">
	<?php // Campus location standin ?>
		<div class="listing-property-img">
			<!-- Printing the location based on where we are -->
			<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Olympia"))>0) {?>
					<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/olympia.svg" title="Olympia"/>
			<?php } ?>
			<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tacoma"))>0) {?>
					<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/tacoma.svg" title="Tacoma"/>
			<?php } ?>
			<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Grays Harbor"))>0) {?>
					<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/grays-harbor.svg" title="Grays Harbor"/>
			<?php } ?>
			<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal"))>0) {?>
					<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg" title="Tribal"/>
			<?php } ?>
			<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal MPA"))>0) {?>
					<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg" title="Tribal MPA"/>
			<?php } ?>
			<?php // Study abroad standin with additional details ?>
			<?php // Include Study Abroad icon, if relevant
			if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) { ?>
				<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/study-abroad.svg" title="Study Abroad"/>
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

	<div class="listing-property">
	<?php // Time offered, This can have multiple properties, for example, Day, Evening, and Weekend. ?>
		<div class="listing-property-img">
			<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_time_offered']),"Day"))>0) {?>
					<img alt=""
					class="listing-icon-time-offered listing-icon-day"
					src="/sites/all/themes/wwwevergreen/images/icons/catalog/daytime.svg" title="Daytime"/>
		  <?php } ?>
			<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_time_offered']),"Evening"))>0) {?>
					<img alt=""
					class="listing-icon-time-offered listing-icon-evening"
					src="/sites/all/themes/wwwevergreen/images/icons/catalog/evening.svg" title="Evening"/>
			<?php } ?>
			<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_time_offered']),"Weekend"))>0) {?>
					<img alt=""
					class="listing-icon-time-offered listing-icon-weekend"
					src="/sites/all/themes/wwwevergreen/images/icons/catalog/weekend.svg" title="Weekend"/>
			<?php } ?>
		</div>

		<div class="listing-property-body">
			<?php if(isset($content['group_details']['group_location_schedule']['field_time_offered'])) { ?>
				<?php print render($content['group_details']['group_location_schedule']['field_time_offered']); ?>
			<?php }; ?>
		</div>
	</div>

	<div class="listing-property">
	<?php
		/**
		 * [bug][blocking] -- fixed stevenm
		 *       This is showing up as MiT in the undergraduate catalog. See:
		 *       http://wwwdev.evergreen.edu/catalog/offering/greece-and-italy-artistic-and-literary-odyssey-15978
		 */
		// Class standing standin
		//Translating our curricular area into our image path name for grad courses
		$grad_img_name = "";
		$field_curr_area = (render($content['field_curricular_area'][0]));
		if($field_curr_area == "Master in Teaching"){
			$grad_img_name = "mit"; }
		if($field_curr_area == "Master of Environmental Studies"){
			$grad_img_name = "mes"; }
		if($field_curr_area == "Master of Public Administration"){
			$grad_img_name = "mpa"; }?>

		<div class="listing-property-img">
		 <?php // if graduate
		 if (render($content['field_class_standing'][0]) == "Graduate"){ // rendering our grad image + title?>
		 	  <img alt="<?php print($field_curr_area)?>"src="/sites/all/themes/wwwevergreen/images/icons/catalog/<?php print($grad_img_name);?>.svg" />
		</div>
				<div class="listing-property-body">
			 	<?php // printing our word Graduate
		 		print(render($content['field_class_standing'][0])); ?>
				</div>
		 <?php
		 } else {
				// if it's an undergrad course
			  // take the first element and the last element, and use them to make the file name for the class standing range
			  // Render our undergrad image and title?>
			  <img alt=""
			  	src="/sites/all/themes/wwwevergreen/images/icons/catalog/<?php print(render($content['field_class_standing'][0]));?>-<?php print(render(end($content['field_class_standing'])));?>.svg"
			  	title="<?php print(render($content['field_class_standing'][0]));?>-<?php print(render(end($content['field_class_standing'])));?>" />

		</div>

		<div class="listing-property-body">
			<?php // Printing youngest class standing, putting the dash and oldest class standing, if applicable
			if(isset($content['field_class_standing'])) {
				print_r(render($content['field_class_standing'][0]));
			if(isset($content['field_class_standing'][3])) {
				print("–");
				print_r( render($content['field_class_standing'][3]));
			}elseif(isset($content['field_class_standing'][2])) {
				print("–");
				print_r( render($content['field_class_standing'][2]));
			}elseif(isset($content['field_class_standing'][1])) {
				print("–");
				print_r( render($content['field_class_standing'][1]));
			}else{ }; }

			if(isset($content['field_percent_freshman'])){
				$test = (render($content['field_percent_freshman'][0]));
				print("<br/><small class='small'> " . $test . " Reserved for Freshmen</small>");
			}
		}?>
		</div>
	</div>

	<div class="listing-property">
	<?php
		// Credits amount standin ?>
		<div class="listing-property-img">
		<?php if(render($content['group_details']['field_credits'][0]) == '0'){?>
			<img alt="0" src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-variable.svg"/>
		<?php }else{ ?>
			<img alt="<?php print(render($content['group_details']['field_credits'][0]))?>" src="/sites/all/themes/wwwevergreen/images/icons/catalog/credits-<?php print(render($content['group_details']['field_credits'][0]))?>.svg"/>
		<?php } ?>

		</div>
		<div class="listing-property-body"> <?php
			if(isset($content['group_details']['field_credits'][0])) {
				// check to see if credit data value is 0, and if set, display v credits
				if(render($content['group_details']['field_credits'][0]) == '0'){
					print("Variable credit. <br/><small class='small'>See below for more info.</small>");
				// if it's 1 credit, say "credit" and not "credits"
				}elseif(render($content['group_details']['field_credits'][0]) == '1'){
					//print_r( render($content['group_details']['field_credits'][0]));
					print " Credit per quarter";
				// printing plural credits
				}else {
					//print_r( render($content['group_details']['field_credits'][0]));
					print " Credits per quarter";
				}
			}else{  // If the value isn't set, print no credit Available
				print ("Credit information not available.<br/><small class='small'>See below for more info.</small>");
			}?>
		</div>
	</div>
</header>

<?php
	/**
	 * Call to Action (Save to List)
	 */
?>

<?php // Save class standin ?>
<div class="box action-box">
	<div class="action-item-1-2">
		<?php print render($content['links']); ?>
		<?php print("<p><small class='small'>Compare offerings and share your lists with others.</small></p>");?>
	</div>
	<div class="action-item-2-2">
		<?php // Make sure this link is actually correct… ?>
		<p><a href="/catalog/index?flagged=1">See all saved items</a></p>
	</div>
</div>

<?php // END TESTING HEADER ZONE ?>

<?php
//* - $title_prefix (array): An array containing additional output populated by
//*   modules, intended to be displayed in front of the main title tag that
//*   appears in the template. ?>
<?php print render($title_prefix); ?>

<?php
//* - $title: The page title, for use in the actual HTML content. ?>
<?php if (!$page){ ?>
	<h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
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
						<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/study-abroad.svg"/>
					</div>
					<div class="listing-property-body">
						<p><b>Study abroad:</b></p>
						<?php print render($content['group_details']['group_location_schedule']['field_study_abroad']); ?>
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
						<?php for($i = 0; $i < count($content['group_details']['field_fields_of_study'][0]); ++$i){?>
							<li><?php print(render($content['group_details']['field_fields_of_study'][$i])); ?> </li>
						<?php } ?>
					</ul>
				</div>
	    <?php }; ?>

	    <?php
			// Preparatory Fields standin
			// field_preparatory_for ?>
			<?php if(isset($content['group_details']['field_preparatory_for'][0])) { ?>
				<p><b><?php print ("This offering will prepare you for careers and advanced study in:")?></b> <?php print_r(render($content['group_details']['field_preparatory_for'][0])); ?></p>
			<?php }; ?>

			<?php // Maximum enrollment standin
			// field_maximum_enrollment ?>
			<?php if(isset($content['field_maximum_enrollment'][0])) { ?>
				<p><b><?php print ("Maximum enrollment:")?></b> <?php print_r(render($content['field_maximum_enrollment'][0])); ?></p>
	    <?php }; ?>

			<?php
				/**
				 * Online Learning standin
				 * [bug][blocking? - fix blocking bug below to see] ---> is now actually displaying the working behaviors -stevenm
				 *       This can be multiple values, different for each quarter,
				 *       but currently this standin doesn’t support that.
				 *
				 *       See http://wwwdev.evergreen.edu/catalog/offering/native-pathways-program-rebuilding-native-nations-strategies-governance-and
				 *       for a potential example, although this is, in fact, broken
				 *       on the live server, as well.
				 *
				 *       The online learning value should be listed as follows:
				 *        * Fall: Hybrid Online Learning < 25% Delivered Online
				 *        * Winter and Spring: Enhanced Online Learning
				 *      —jkm
				 *
				 * Options:
				 *  * No Required Online Learning
				 *  * Hybrid Online Learning < 25% Delivered Online
				 *  * Hybrid Online Learning 25 - 49% Delivered Online
				 *  * Enhanced Online Learning
				 *
				 * [bug][blocking] --> fixed, works for both multi-option and non-special cases -stevenm
				 *       Furthermore, this looks like it’s maybe not working. See
				 *       this page for what I’m talking about:
				 *       http://wwwdev.evergreen.edu/catalog/offering/greece-and-italy-artistic-and-literary-odyssey-15978
				 *      —jkm
				 */
				 // field_online_learning ?>
	 			<?php if(isset($content['group_details']['group_more']['field_online_learning'][0])) { ?>
	 				<div><b><?php print ("Online learning:"); ?></b>
	 				<?php $ol_format_flag = False; //using a flag to find if we've applied any of our custom formatting rules?>
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
	 						print(render($content['group_details']['group_more']['field_online_learning'][0]));
	 					} ?>
	 			<?php }; ?></div>

	    <?php
			// Special expenses standin
     	// field_special_expenses ?>
     	<?php if(isset($content['group_details']['group_more']['field_special_expenses'][0])) { ?>
				<div><b><?php print ("Special expenses:")?></b> <?php print_r(render($content['group_details']['group_more']['field_special_expenses'][0])); ?></div>
	    <?php }; ?>

			<?php
			// Fees standin
			// field_fees (can be 0?) ?>
			<?php if(isset($content['group_details']['group_more']['field_fees'][0])) { ?>
				<div><b><?php print ("Fees:") // have to do a substr to get rid of annoying paragraph tabs below ?></b> <?php print (substr(render($content['group_details']['group_more']['field_fees'][0]), 3, -4)); ?></div>
	    <?php }; ?>

	    <?php
			// Upper division science credit standin
			// field_upper_division (field_upper_division_boolean seems to be 1 on classes without upper credit too?) ?>
			<?php if(isset($content['field_upper_division'][0])) { ?>
				<p><b><?php print ("Upper division science credit:") // also getting rid of annoying p tags below?></b> <?php print (substr(render($content['field_upper_division'][0]), 3, -4)); ?></p>
	    <?php }; ?>

			<?php
			// Website field standin
			// field_websites ?>
			<?php if(isset($content['group_details']['field_websites'][0])) { ?>
				<div><b><?php print ("Special expenses:")?></b> <?php print_r(render($content['group_details']['field_websites'][0])); ?></div>
			<?php }; ?>
			<?php
			// Internship op field standin
			// field_internship_opportunities ?>
			<?php if(isset($content['field_internship_opportunities'][0])) { ?>
				<div><b><?php print ("Internship Opportunities:")?></b> <?php print(render($content['field_internship_opportunities'][0])); ?></div>
			<?php }; ?>
			<?php
			// Website field standin
			// field_websites ?>
			<?php if(isset($content['field_research_opportunities'][0])) { ?>
				<div><b><?php print ("Research Opportunities:")?></b> <?php print(render($content['field_research_opportunities'][0])); ?></div>
			<?php }; ?>
			<?php
			// prereq field standin
			// field_prerequisites ?>
			<?php if(isset($content['group_prerequisites']['field_prerequisites'][0])) { ?>
				<div><b><?php print ("Prerequisites:")?></b> <?php print(render($content['group_prerequisites']['field_prerequisites'][0])); ?></div>
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
						<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_time_offered']),"Day"))>0) {?>
								<img alt=""
								class="listing-icon-time-offered listing-icon-day"
								src="/sites/all/themes/wwwevergreen/images/icons/catalog/daytime.svg" title="Daytime"/>
					  <?php } ?>
						<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_time_offered']),"Evening"))>0) {?>
								<img alt=""
								class="listing-icon-time-offered listing-icon-evening"
								src="/sites/all/themes/wwwevergreen/images/icons/catalog/evening.svg" title="Evening"/>
						<?php } ?>
						<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_time_offered']),"Weekend"))>0) {?>
								<img alt=""
								class="listing-icon-time-offered listing-icon-weekend"
								src="/sites/all/themes/wwwevergreen/images/icons/catalog/weekend.svg" title="Weekend"/>
						<?php } ?>
					</div>

					<div class="listing-property-body">
						<?php if(isset($content['group_details']['group_location_schedule']['field_time_offered'])) { ?>
							<p><b>Scheduled for:</b> <?php print render($content['group_details']['group_location_schedule']['field_time_offered']); ?>
						<?php }; ?>
						</div>
					</div>
					<div class="listing-property">
						<div class="listing-property-img">
							<!-- Printing the location based on where we are -->
							<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Olympia"))>0) {?>
									<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/olympia.svg" title="Olympia"/>
							<?php } ?>
							<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tacoma"))>0) {?>
									<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/tacoma.svg" title="Tacoma"/>
							<?php } ?>
							<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Grays Harbor"))>0) {?>
									<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/grays-harbor.svg" title="Grays Harbor"/>
							<?php } ?>
							<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal"))>0) {?>
									<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg" title="Tribal"/>
							<?php } ?>
							<?php if (strlen(strstr(render($content['group_details']['group_location_schedule']['field_location'][0]),"Tribal MPA"))>0) {?>
									<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/tribal.svg" title="Tribal MPA"/>
							<?php } ?>
						</div>
						<div class="listing-property-body">
							<p><b>Located in:</b> <?php print render($content['group_details']['group_location_schedule']['field_location']); ?></p>
							<?php // Off-campus location standin - FYI, no programs in 2017–18 and ’18–19 have this flag set, so it’s kinda hard to test right now. —jkm
								if(isset($content['group_details']['group_location_schedule']['field_off_campus_location'])) { ?>
								<p><b>Off-campus location:</b> <?php print render($content['group_details']['group_location_schedule']['field_off_campus_location']); ?></p>
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
					<?php print render($content['group_details']['group_location_schedule']['field_final_schedule']); ?>
				<?php }; ?>

				<?php if(isset($content['group_details']['group_location_schedule']['field_advertised_schedule'])) { ?>
					<p><b>Advertised schedule:</b></p>
					<?php print (render($content['group_details']['group_location_schedule']['field_advertised_schedule'])); ?>
				<?php }; ?>

				<?php if(isset($content['group_details']['group_location_schedule']['field_additional_schedule_detail'])) { ?>
					<p><b>Additional details:</b></p>
					<?php print render($content['group_details']['group_location_schedule']['field_additional_schedule_detail']); ?>
				<?php }; ?>


			</div>
		</div>
			<!--The “May be offered again” standin here. -->
			<div class="box note">
				<?php if(isset($content['group_details']['group_more']['field_next_offered'])) { ?>
					<p>
						<?php print render($content['group_details']['group_more']['field_next_offered']); ?>
					</p>
				<?php }; ?>
			</div>
      <!-- cutout of all content that is in the sidebar for now.

      <section class="catalog-listing-registration">
        <?php
        /**
         * Registration
         */
        ?>
        <h2>Register for this offering</h2>
        <?php
        // Variable credit
        // field_variable_credit_options (field_upper_division_boolean seems to be 1 on classes without upper credit too?)
        ?>
        <?php if(isset($content['field_variable_credit_options'][0])) { ?>
          <h3>Variable Credit Options</h3>
          <?php print_r(render($content['field_variable_credit_options'][0])); ?>
        <?php }; ?>
        <h3>How to Register</h3>
        <ol>
          <li>
            <p>Copy the course reference number (CRN) for your class standing and desired number of credits.</p>
          </li>
          <li>
            <p>Use your CRN at <a href="https://my.evergreen.edu">my.evergreen.edu</a> during your registration window. Check the academic calendar for <a href="/calendar/academic">upcoming registration deadlines</a>.</p>
          </li>
        </ol>
        <p>Learn more about <a href="/registration/how-to">how to register</a>, including information about registering as a non-admitted (special) student.</p>

        <?php
        /**
         * Course Reference Numbers
         */
        ?>
        <?php // Course Reference Numbers Standin
        // sidebar stuff here ?>
        <h3>Course Reference Numbers</h3>
        <?php //variable for dropping the H4 signature required to a nice italics version with a colon if needed?>
        <?php $sig_required_h4 = "<h4>Signature Required</h4>"?>
        <?php $sig_required_h4_italics = "<p><i>Signature Required:</i>"?>

        <?php //Fall Registration ?>
        <?php if(isset($content['field_fall_registration'])) { ?>
          <div class="compound">
            <div class="compound-img">
            </div>
            <div class="compound-body">
              <h4>Fall quarter</h4>
              <?php
                $fallref = (str_replace("<h4>Course Reference Numbers</h4>","",render($content['field_fall_registration'][0])));
                // find out if our post actually has <p> tags in it at all
                if ((strpos($fallref, "<p>")) !== false) {
                  // if it does, we're just going to remove the first <p> tag since we put it in front of "Signature Required"
                  $fallref = substr_replace($fallref, "", (intval(strpos($fallref, "<p>"))), 3);
                } else { // else we have a quarter description that doesn't have any <p> tags, and we need to add a closing one now
                  // that we added an opening one when we put our italics at the front of the paragraph
                  $fallref = $fallref . "</p>";
                };
                if (strpos($fallref , $sig_required_h4) !== false) {
                  $fallref = str_replace($sig_required_h4,$sig_required_h4_italics,$fallref);
                };
                // finally, print our result
                print($fallref)
              ?>
            </div>
          </div>
        <?php }; ?>

        <?php //Winter Registration ?>
        <?php if(isset($content['field_winter_registration'])) { ?>
          <div class="compound">
            <div class="compound-img">
            </div>
            <div class="compound-body">
              <h4>Winter quarter</h4>
              <?php
                $winterref = (str_replace("<h4>Course Reference Numbers</h4>","",render($content['field_winter_registration'][0])));
                // find out if our post actually has <p> tags in it at all
                if ((strpos($winterref, "<p>")) !== false) {
                  // if it does, we're just going to remove the first <p> tag since we put it in front of "Signature Required"
                  $winterref = substr_replace($winterref, "", (intval(strpos($winterref, "<p>"))), 3);
                } else { // else we have a quarter description that doesn't have any <p> tags, and we need to add a closing one now
                  // that we added an opening one when we put our italics at the front of the paragraph
                  $winterref = $winterref . "</p>";
                };
                if (strpos($winterref , $sig_required_h4) !== false) {
                  $winterref = str_replace($sig_required_h4,$sig_required_h4_italics,$winterref);
                };
                //finally print our result
                print($winterref)?>
            </div>
          </div>
        <?php }; ?>

        <?php //Spring Registration ?>
        <?php if(isset($content['field_spring_registration'])) { ?>
          <div class="compound">
            <div class="compound-img">
            </div>
            <div class="compound-body">
              <h4>Spring quarter</h4>
              <?php $springref = (str_replace("<h4>Course Reference Numbers</h4>","",render($content['field_spring_registration'][0])));
              // find out if our post actually has <p> tags in it at all
              if ((strpos($springref, "<p>")) !== false) {
                // if it does, we're just going to remove the first <p> tag since we put it in front of "Signature Required"
                $springref = substr_replace($springref, "", (intval(strpos($springref, "<p>"))), 3);
              } else { // else we have a quarter description that doesn't have any <p> tags, and we need to add a closing one now
                // that we added an opening one when we put our italics at the front of the paragraph
                $springref = $springref . "</p>";
              };
              if (strpos($springref , $sig_required_h4) !== false) {
                  $springref = str_replace($sig_required_h4,$sig_required_h4_italics,$springref);
              };
              //finally print our result
              print($springref)?>
            </div>
          </div>
        <?php }; ?>

        <?php //Summer Registration ?>
        <?php if(isset($content['field_summer_registration'])) { ?>
          <div class="compound">
            <div class="compound-img">
            </div>
            <div class="compound-body">
              <h4>Summer quarter</h4>
              <?php $summerref = (str_replace("<h4>Course Reference Numbers</h4>","",render($content['field_summer_registration'][0])));
              // find out if our post actually has <p> tags in it at all
              if ((strpos($summerref, "<p>")) !== false) {
                // if it does, we're just going to remove the first <p> tag since we put it in front of "Signature Required"
                $summerref = substr_replace($summerref, "", (intval(strpos($summerref, "<p>"))), 3);
              } else { // else we have a quarter description that doesn't have any <p> tags, and we need to add a closing one now
                // that we added an opening one when we put our italics at the front of the paragraph
                $summerref = $summerref . "</p>";
              };
              if (strpos($summerref , $sig_required_h4) !== false) {
                $summerref = str_replace($sig_required_h4,$sig_required_h4_italics,$summerref);
              };
              //finally print our result
              print($summerref)?>
            </div>
          </div>
        <?php }; ?>
      </section><?php ///.catalog-listing-registration ?>

      end cutout for duplicate content in sidebar for now-->

		</div> <!-- /.program-description -->

		<?php
		/**
		 * Revisions
		 */
		?>
		<?php // revisions, do we want these in the new design? ?>
		<?php print render($content['field_revisions']); ?>
	</div> <!-- /.content -->
	<?php // do we even need this? ?>
	<?php // print render($content['comments']); ?>
</div>
