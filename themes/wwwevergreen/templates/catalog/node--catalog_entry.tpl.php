<?php

/* fun with catalog entries */


/**
 * @file

 */
 
  //dpm($content['field_summer_session']);
 
 
 //for catalog entries, let's make a nice-looking description of the quarters offered!

	$threequarters = $content['field_academic_year']['#items'][0]['safe_value'];
	$fall = $threequarters-1;
	  
	  
	 
	foreach($content['field_quarters_offered']['#items'] as $q) {
		  
		$quarter = $q['value'];
		if($quarter == 'Fall') { 
			$quarters[] = 'Fall ' . $fall; 
		} else {
			$quarters[] = $quarter . ' ' . $threequarters;
		};		  
	}
	
	if(count($quarters) == 1) {
		$quarters_intro = $quarters[0] . ' quarter';
	}
	elseif(count($quarters) == 2) {
		$quarters_intro .= $quarters[0] . ' and ' . $quarters[1] . " quarters";
	}
	elseif(count($quarters) == 3) {
		$quarters_intro .= $quarters[0] . ', ' . $quarters[1] . ', and ' . $quarters[2] . " quarters";
	}
	elseif(count($quarters) == 4) {
		$quarters_intro .= $quarters[0] . ', ' . $quarters[1]  . ', ' . $quarters[2] . ', and ' . $quarters[3] . " quarters";
	};
	if(render($content['field_summer_session']) != '') {
		$quarters_intro .= " (" . trim(render($content['field_summer_session'])) . " Session)";
	}
	//$variables['quarters_intro'] = $quarters_intro;
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

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
	
	 <p class="intro"><?php print($quarters_intro); ?></p>
	 
	 <div class="program-description">
		 
		 <p>Taught by</p>
		 <div class="grid">
			 <?php print render($content['field_faculty']); ?>
		 </div>
     
     <?php 
      print render($content);
      
      //because I can't find a quick and easy way to make these nested headers into H4s....
      ?>
      <h3>Location and Schedule</h3>
      <?php if(isset($content['group_details']['group_location_schedule']['field_final_schedule'])) { ?>
    <h4>Final Schedule and Room Assignment</h4>
    <?php print render($content['group_details']['group_location_schedule']['field_final_schedule']); ?>
    <?php }; ?>
   
	<h4>Campus Location</h4>
	<p><?php print render($content['group_details']['group_location_schedule']['field_location']); ?></p>
	
	<?php if(isset($content['group_details']['group_location_schedule']['field_off_campus_location'])) { ?>
	<h4>Off-Campus Location</h4>
	<p><?php print render($content['group_details']['group_location_schedule']['field_off_campus_location']); ?></p>	
	<?php }; ?>
	
	<?php if(isset($content['group_details']['group_location_schedule']['field_study_abroad'])) { ?>
	<h4>Study Abroad</h4>
	<?php print render($content['group_details']['group_location_schedule']['field_study_abroad']); ?>	
	<?php }; ?>
	
	<?php if(isset($content['group_details']['group_location_schedule']['field_time_offered'])) { ?>
	<h4>Time Offered</h4>
	<?php print render($content['group_details']['group_location_schedule']['field_time_offered']); ?>	
	<?php }; ?>
	
	<?php if(isset($content['group_details']['group_location_schedule']['field_advertised_schedule'])) { ?>
	<h4>Advertised Schedule</h4>
	<?php print render($content['group_details']['group_location_schedule']['field_advertised_schedule']); ?>	
	<?php }; ?>
	
	<?php if(isset($content['group_details']['group_location_schedule']['field_additional_schedule_detail'])) { ?>
	<h4>Additional Schedule Details</h4>
	<?php print render($content['group_details']['group_location_schedule']['field_additional_schedule_detail']); ?>	
	<?php }; ?>
	    
	    
	    <?php 
	    
	     
      print render($content['group_details']['group_more']);
    ?>
    
	 </div>
	 
	 <?php print render($content['field_revisions']); ?>
	 
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
