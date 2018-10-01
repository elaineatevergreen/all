<?php

/**
 * @file

 */
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
		//hide amount and due date if this scholarship has not yet been funded.  
		if(!strstr(render($content['field_funding_status']),'Not yet funded')) { ?>
	  <p><strong>Amount</strong>: <?php print render($content['field_amount']) ?><br/>
	  <strong>Due Date</strong>: <?php print render($content['field_deadline']) ?></p>
	  
	   <?php
		    if (trim(render($content['field_tuition_award'])) == 'Yes') {  ?>
	   <p><strong>Important Information: </strong> this is a tuition award. Tuition Awards listed are a waiver of a student’s tuition. A recipient of a tuition award cannot receive funding in excess of the cost of full-time undergraduate tuition. In addition, a recipient of a tuition award cannot use the funding for any of the study abroad consortium agreements.</p>
	    <?php }; ?>
	    <?php }; ?>
	    
	<?php 
		//add the donation box if this scholarship is seeking funding
		if(isset($content['field_funding_status'])) {
			//MOST scholarships use a default donation link, but a few (ONE as of Oct 2018) use special donation form pages
			//this checks which is which
			if(isset($content['field_donation_link'])) { 
				$donationURL = render($content['field_donation_link']; 
			} else { 
				$donationURL = 'http://3897.thankyou4caring.org/pages/givescholarships'; 
			};
	?>
	<div class="box supplement"><p>
	<?php
			//switch out language depending on whether scholarship is fully funded.
			if(strstr(render($content['field_funding_status']),'Not yet funded')) {  print "This scholarship is not yet fully funded."; } 
			elseif(strstr(render($content['field_funding_status']),'Seeking donors')) { print "Keep this scholarship funded for future generations."; };
	?>
	</p><p><a href="<?php print $donationURL; ?>">Please donate today.</a></p></div>
	<?php
		};
		?>  
	    
	  
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      //print render($content);
      
      print render($content['body']);
    ?>
  </div>


</div>
