<?php

/**
theme for individual person pages

 */
//dpm($variables['content']['group_contact']['field_location_off_campus']);
?>

<div id="node-<?php print $node->nid; ?>" class="content <?php print $classes; ?>"<?php print $attributes; ?>>
	
	
<?php 

//check whether this is a real entry
if(isset($content['field_reference'])) { ?>

<p>See <?php print render($content['field_reference']); ?>.</p>
<?php	
		
	} else {
?>
    
    <div class="p-job-title"><?php print render($content['field_job_title']) ?></div>
    <?php if(isset($content['field_department'])) { ?>
    <p><?php print render($content['field_department']) ?></p>
    <?php }; ?>
    
    <?php 
	    if(isset($content['field_headshot'])) {
		    
		    print render($content['field_headshot']);
		    
	    }; ?>
	    
	    <?php
	    
	    //show all the faculty details
	    print render($content['body']);
	    if(isset($content['field_background'])) {
		    print "<p>" . render($content['field_background']) . "</p>";
		};
		if(isset($content['field_expertise'])) {
			print "<p>" . render($content['field_expertise']) . "</p>";
		};
		if(isset($content['field_interests'])) {
			print "<p>" . render($content['field_interests']) . "</p>";
		};
   
		if (isset($content['field_related_subjects_directory'])) { 
?>
	    <h2>Related Subject Areas</h2>
	    
	    <?php 
		    print render($content['field_related_subjects_directory']); 
		}; ?>
    
<div>    
<?php 
	
	//only show contact information for individuals if user is logged in
	//or if this person has chosen to make their contact info public (currently just faculty)
  
	  
	  //but do all this stuff only if there's any contact info to speak of
	  if(isset($content['group_contact']['field_email']) or isset($content['group_contact']['field_phone']) or isset($content['group_contact']['field_mailstop']) or isset($content['group_contact']['field_location_off_campus'])) { ?>
    <h2><span>Contact Information</span></h2>
	  
<?php
		//now check to see if we should show the stuff
		if($promote == TRUE or user_is_logged_in()) {
?>
  
    <?php 
	    if(isset($content['field_website'])) {
		?>
        <div>
          <span class="field-label">Website:</span>
          <span class="field-website"><?php print render($content['field_website']) ?></span>
      </div>
      <?php };
	    
	    if (isset($content['group_contact']['field_email'])) { ?>
    <div>
      <span class="field-label">Email:</span>
      <span class="field-email">
        <?php print render($content['group_contact']['field_email']) ?>
      </span>
    </div>
    <?php }; ?>
    <div class="p-tel">
      <?php if (isset($content['group_contact']['field_phone'])) {
	        ?><span class="p-tel"><?php print render($content['group_contact']['field_phone']) ?> </span><?php
        }; ?>
        <?php if (isset($content['group_contact']['field_fax'])) {
	        ?><br><i>Fax:</i> <?php print render($content['group_contact']['field_fax']) ?><?php
        }; ?>
        <?php if (isset($content['group_contact']['field_alternate_phone'])) {
	        ?><br><i>Alt:</i> <?php print render($content['group_contact']['field_alternate_phone']) ?><?php
        }; ?>
    </div>
    
    <?php 
	    //because everyone has their country set via feeds, we actually need to check for the existence of state ("administrative area" in Address Field parlance)
	    if(isset($content['group_contact']['field_location_off_campus']['#items'][0]['administrative_area']) and strlen($content['group_contact']['field_location_off_campus']['#items'][0]['administrative_area']) > 0) { ?>
		<div><?php print render($content['group_contact']['field_location_off_campus']); ?></div>
	<?php	}; 	?>
    
    <div class="extended-address">
	    <?php if (isset($content['group_contact']['field_building_alt'])) { ?>
      <div>
        <span class="field-label">Building:</span>
        <span class="field-building-alt"><?php print render($content['group_contact']['field_building_alt']) ?></span>
      </div>
      	<?php
	      	};
	      	if(isset($content['group_contact']['field_room'])) {
		?>
      <div>
        <span class="field-label">Room:</span>
        <span class="field-room"><?php print render($content['group_contact']['field_room']) ?></span>
      </div>
      <?php
	      	};
	      	if(isset($content['group_contact']['field_mailstop'])) {
		?>
        <div>
          <span class="field-label">Mailstop:</span>
          <span class="field-mailstop"><?php print render($content['group_contact']['field_mailstop']) ?></span>
      </div>
      <?php }; ?>
    </div>

    
  </div>
  
  <?php 
	  
	  //display message for non-authenticated users
	  } else { ?>
	  
	  <p>You must <a href="/user/login?destination=node/<?php print $node->nid; ?>">log in</a> to see contact information for this person.</p>
		  
	  <?php 
		}; //end check for authentication
	}; //end check for *any* contact information 
}; //end check for reference type
?>
  
</div>