<?php
/**
 * Catalog Listing Page
 *
 * IMPORTANT: This catalog listing page is still missing details that
 * were not accounted for in the comp. These details must be accounted
 * for before this page goes live. Stephen Meaney put them in a
 * supplementary “cutoff.php” file, so go looking for that first.
 */
/**
 * @file
 */
//dpm($content['field_summer_session']);
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
		$quarters_intro .= $quarters[0] . ' and ' . $quarters[1];
	}elseif(count($quarters) == 3) {
		$quarters_intro .= $quarters[0] . ', ' . $quarters[1] . ', and ' . $quarters[2];
	}elseif(count($quarters) == 4) {
		$quarters_intro .= $quarters[0] . ', ' . $quarters[1]  . ', ' . $quarters[2] . ', and ' . $quarters[3] ;
	};
	if(render($content['field_summer_session']) != '') {
		$quarters_intro .= " (" . trim(hide($content['field_summer_session'])) . " Session)";
	};?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
	<?php print $user_picture; ?>
	
	
	
	
	
	<?php // TESTING HEADER ZONE ?>
	<header class="catalog-listing-header">
		<?php // Month/Year standin ?>
		<div class="catalog-listing-header-item">
			<div class="compound">
				<div class="compound-img">
					<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/fall.svg"/>
				</div>
				<div class="compound-body">
					<?php print render($quarters_intro) ?>
				</div>
			</div>
		</div>

		<div class="catalog-listing-header-item">
			<?php // Campus location standin ?>
			<div class="compound">
				<div class="compound-img">
					<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/olympia.svg"/>
					<?php // Study abroad standin with additional details ?>
					<?php // Include Study Abroad icon, if relevant
						if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) { ?>
						<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/study-abroad.svg"/>
					<?php }; ?>
				</div>
				<div class="compound-body">
					<?php print render($content['group_details']['group_location_schedule']['field_location']); ?>
					<?php // Include Study Abroad label, if relevant
						if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) {
							print " + " render($content['group_details']['group_location_schedule']['field_study_abroad']); ?>
						};
					?>
				</div>
			</div>
		</div>

		<div class="catalog-listing-header-item">
			<?php // Time offered standin ?>
			<div class="compound">
				<div class="compound-img">
					<img alt="" src="/sites/all/themes/wwwevergreen/images/directory/_blank-square.png"/>
				</div>
				<div class="compound-body">
					<?php if(isset($content['group_details']['group_location_schedule']['field_time_offered'])) { ?>
						<?php print render($content['group_details']['group_location_schedule']['field_time_offered']); ?>
					<?php }; ?>
				</div>
			</div>
		</div>

		<div class="catalog-listing-header-item">
			<?php // Class standing standin ?>
			<div class="compound">
				<div class="compound-img">
					<img alt="" src="/sites/all/themes/wwwevergreen/images/directory/_blank-square.png"/>
				</div>
				<div class="compound-body">
					<!-- [bug] This does not appear to be working. The content is left blank. -->
					<?php // Printing youngest class standing, putting the dash and oldest class standing, if applicable ?>
					<?php if(isset($content['field_class_standing'][0])) { ?>
					  <?php print_r(render($content['field_class_standing'][0]));
					  	if(isset($content['field_class_standing'][3])) {
					 			print("– ");
								print_r( render($content['field_class_standing'][3]));
							}elseif(isset($content['field_class_standing'][2])) {
					  		print("– ");
								print_r( render($content['field_class_standing'][2]));
						  }elseif(isset($content['field_class_standing'][1])) {
								print("– ");
								print_r( render($content['field_class_standing'][1]));
					}else{ }; } ?>
				</div>
			</div>
		</div>
		
		<div class="catalog-listing-header-item">
			<?php // Credits amount standin ?>
			<div class="compound">
				<div class="compound-img">
					<img alt="" src="/sites/all/themes/wwwevergreen/images/directory/_blank-square.png"/>
				</div>
				<div class="compound-body">
					<!-- [bug] It looks like this always prints out “No credit available.” —jkm -->
					<?php if(isset($content['field_credits'][0])) {
							// check to see if credit data value is 0, and if set, display v credits
					    if(render($content['field_credits'][0]) == '0'){
								print(
									"Variable credit.
									<br/><small class='small'>See below for more info.</small>"
								);
								// if it's 1 credit, say "credit" and not "credits"
							}elseif(render($content['field_credits'][0]) !== '1'){
								print_r( render($content['field_credits'][0]));
								print "Credit per quarter";
							
							}else {  // printing plural credits
								print_r( render($content['field_credits'][0]));
								print "Credits per quarter";
							}
					  }else{  // If the value isn't set, print no credit Available
						    print "No credit available.
						    <br/><small class='small'>See below for more info.</small>";
					}?>
				</div>
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
	/**
	 * [bug] What is This?
	 *
	 * Someone describe to me what I’m seeing here. —jkm
	 */
	?>
  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

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
			} elseif((time()-(60*60*24*30)) < strtotime($content['field_status_date']['#items'][0]['value'])) {
				$updatestatus = 'NEW';
			} elseif((time()-(60*60*24*30)) < strtotime($content['field_revision_date']['#items'][0]['value'])) {
				$updatestatus = 'REVISED';
			};
	
			if($updatestatus != '') {
		?>
		<div class="box note program-status">
			<p class="program-status-revised"><?php print $updatestatus ?></p>
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
			 */
			?>
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
			?>
			<?php // changed $content to now just print the body content without the save link attached
			print render($content['body'][0]); ?>
			
			<?php
			/**
			 * Additional Program Details
			 */
			?>
			
			<?php // Study abroad standin with additional details ?>
			<?php if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) { ?>
				<div class="compound">
					<div class="compound-img">
						<img alt="" src="/sites/all/themes/wwwevergreen/images/icons/catalog/study-abroad.svg"/>
					</div>
					<div class="compound-body">
						<p><b>Study Abroad:</b></p>
						<?php print render($content['group_details']['group_location_schedule']['field_study_abroad']); ?>
					</div>
				</div>
			<?php }; ?>
			
			<?php // Fields of study standin
			// field_fields_of_study (NEED TO TEST WITH ONE THAT ACTUALLY HAS THIS FIELD) ?>
     	<?php if(isset($content['group_details']['field_fields_of_study'][0])) { ?>
	     	<!-- [bug] It looks like this is only printing out one field of study. See the catalog index for a good example on how this kind of thing is structured in HTML. -->
				<p><b><?php print ("Fields of Study:")?></b> <?php print_r(render($content['group_details']['field_fields_of_study'][0])); ?></p>
	    <?php }; ?>
	    
	    <?php // Preparatory Fields standin
			// field_preparatory_for ?>
			<?php if(isset($content['group_details']['field_preparatory_for'][0])) { ?>
				<p><b><?php print ("This offering will prepare you for careers and advanced study in:")?></b> <?php print_r(render($content['group_details']['field_preparatory_for'][0])); ?></p>
			<?php }; ?>
			
			<?php // Maximum enrollment standin
			// field_maximum_enrollment ?>
			<?php if(isset($content['field_maximum_enrollment'][0])) { ?>
				<p><b><?php print ("Maximum enrollment:")?></b> <?php print_r(render($content['field_maximum_enrollment'][0])); ?></p>
	    <?php }; ?>
	    
			<?php // Online Learning standin
			// field_online_learning ?>
			<?php if(isset($content['group_details']['group_more']['field_online_learning'][0])) { ?>
				<div><b><?php print ("Online learning:")?></b> <?php print_r(render($content['group_details']['group_more']['field_online_learning'][0])); ?></div>
	    <?php }; ?>
	    
	    <?php // Special expenses
     	// field_special_expenses ?>
     	<?php if(isset($content['group_details']['group_more']['field_special_expenses'][0])) { ?>
				<div><b><?php print ("Special expenses:")?></b> <?php print_r(render($content['group_details']['group_more']['field_special_expenses'][0])); ?></div>
	    <?php }; ?>

			<?php // Fees standin
			// field_fees (can be 0?) ?>
			<?php if(isset($content['group_details']['group_more']['field_fees'][0])) { ?>
				<div><b><?php print ("Fees:") // have to do a substr to get rid of annoying paragraph tabs below ?></b> <?php print (substr(render($content['group_details']['group_more']['field_fees'][0]), 3, -4)); ?></div>
	    <?php }; ?>

	    <?php // Upper Div Sci credit standin
			// field_upper_division (field_upper_division_boolean seems to be 1 on classes without upper credit too?) ?>
			<?php if(isset($content['field_upper_division'][0])) { ?>
				<p><b><?php print ("Upper Division Science Credit:") // also getting rid of annoying p tags below?></b> <?php print (substr(render($content['field_upper_division'][0]), 3, -4)); ?></p>
	    <?php }; ?>

			<section class="catalog-listing-registration">
				<?php
				/**
				 * Registration
				 */
				?>
				<h2>Register for this offering</h2>
				<?php // Variable credit
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
				<!-- variable for dropping the H4 signature required to a nice italics version with a colon if needed-->
				<?php $sig_required_h4 = "<h4>Signature Required</h4>"?>
				<?php $sig_required_h4_italics = "<p><i>Signature Required:</i>"?>
	
				<!-- Fall Registration -->
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
				 
				<!-- Winter Registration -->
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
	
				<!-- Spring Registration -->
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
	
				<!-- Summer Registration -->
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
			</section><!-- /.catalog-listing-registration -->
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
