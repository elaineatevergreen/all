<?php

/**
theme for individual person pages

 */
?>

<!-- need to add back faculty information -->
    
    <div class="p-job-title"><?php print render($content['field_job_title']) ?></div>
    
    <?php 
	    if(isset($content['field_headshot'])) {
		    
		    print render($content['field_headshot']);
		    
	    }; ?>
    
    <?php if (isset($content['field_is_faculty']) and render($content['field_is_faculty']) == 1) { ?>
	    
	    
	    
	    <?php print render($content['field_background']) ?>
	    
	    <?php print render($content['field_expertise']) ?>
	    
	    
	    <?php print render($content['field_interests']) ?>
	    
	    <h2>Related Subject Areas</h2>
	    
	    <?php print render($content['field_related_subjects_directory']) ?>
	    
	    
	<?php }; ?>
    
    
  <?php if(isset($content['group_contact']['field_email']) or isset($content['group_contact']['field_phone']) or isset($content['group_contact']['field_mailstop'])) { ?>

  <div>
    <h2><span>Contact Information</span></h2>
    <?php if (isset($content['group_contact']['field_email'])) { ?>
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
  
  <?php }; //end check for *any* contact information ?>