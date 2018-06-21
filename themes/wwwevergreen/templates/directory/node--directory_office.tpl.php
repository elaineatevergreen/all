<?php

/**
display office information as a "contact block" usually on a page.
 */
?>

<div class="content">
	
	<?php 

//check whether this is a real entry
if(isset($content['field_reference'])) { ?>

<p>See <?php print render($content['field_reference']); ?></p>
<?php	
		
	} else {
?>	
	<h5><?php print render($content['field_subtitle']) ?></h5>
    <h2>Contact Information</h2>
    <div class="extended-address">
	    <?php if (isset($content['field_building_alt']) or isset($content['field_room'])) { ?>
        <div><?php print render($content['field_building_alt']) ?> <?php print render($content['field_room']) ?> </div>
        <?php }; ?>
        
        <?php if (isset($content['field_mailstop'])) { ?>
        <span class="field-label">Mailstop:</span>
        <span class="field-mailstop"><?php print render($content['field_mailstop']) ?></span>
        <?php }; ?>
        
        
        <?php 
	    //because everyone has their country set via feeds, we actually need to check for the existence of state ("administrative area" in Address Field parlance)
	    if(isset($content['field_location_off_campus']['#items'][0]['administrative_area']) and strlen($content['field_location_off_campus']['#items'][0]['administrative_area']) > 0) { ?>
		<div><?php print render($content['field_location_off_campus']); ?></div>
	<?php	}; 	?>
        
    </div>
    
    
    
    
    <div class="required-fields group-phone field-group-html-element">
        <?php if (isset($content['group_phone']['field_phone'])) {
	        ?>
	        <div class="p-tel">
            <?php print render($content['group_phone']['field_phone']) ?>
        </div>
		<?php
        }; ?>
        <?php if (isset($content['group_phone']['field_fax'])) {
	    ?>
	        <div class="p-tel">
            <span class="field-label">Fax:</span>
            <span class="value"><?php print render($content['group_phone']['field_fax']) ?></span>
        </div>
	    <?php
        }; ?>
        <?php if (isset($content['group_phone']['field_alternate_phone'])) {
	        ?> <div class="p-tel">
            <span class="field-label">Alternate:</span>
            <span class="value"><?php print render($content['group_phone']['field_alternate_phone']) ?></span>
        </div><?php
        }; ?>
        
        
    </div>
    
    <?php if (isset($content['field_email'])) {
	        ?>
	        <div>
        <span class="field-label">Email:</span>
      <?php print render($content['field_email']) ?>
    </div>
        <?php
        }; ?>
    
    <?php if (isset($content['group_social']['field_websites'])) {
	        ?>
	        <div>
        <span class="field-label">Website</span>
      <?php print render($content['group_social']['field_websites']) ?>
    </div>
        <?php
        }; ?>
        
        <?php 
	        if (isset($content['field_hours'])) { print render($content['field_hours']); };  
	        if (isset($content['field_related_offices'])) { print render($content['field_related_offices']); };  
	        if (isset($content['field_facilities'])) { print render($content['field_facilities']); };  
	        
	        if (isset($content['body'])) { print render($content['body']); }; 
	        if (isset($content['group_social']['field_facebook'])) { print render($content['group_social']['field_facebook']); }; 
	        if (isset($content['group_social']['field_twitter'])) { print render($content['group_social']['field_twitter']); };
	        if (isset($content['group_social']['field_linkedin'])) { print render($content['group_social']['field_linkedin']); }; 
	        
	        if (isset($content['field_members'])) { print render($content['field_members']); };  
	        
	        
}; //end check for if this is a reference or a real entry

	        ?>
    

</div> 