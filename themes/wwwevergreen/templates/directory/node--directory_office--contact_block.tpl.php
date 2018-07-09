<?php

/**
display office information as a "contact block" usually on a page.
 */
?>


    <section class="h-card site-info">
        <h2>Contact</h2>

        <p><b class="p-name"><?php print $title; ?></b><br>
        <?php 
	        if(isset($content['field_subtitle'])) {
		        print render($content['field_subtitle']); 
		?>
			<br>
		<?php 
	        };
	    ?>
        <span class="p-adr"><?php print render($content['field_building_alt']) ?> <?php print render($content['field_room']) ?> </span>
        <?php if (isset($content['field_email'])) {
	        ?><br>
        <?php print render($content['field_email']) ?><?php
        }; ?>
        <?php if (isset($content['field_phone'])) {
	        ?><br><span class="p-tel"><?php print render($content['field_phone']) ?> </span><?php
        }; ?>
        <?php if (isset($content['field_fax'])) {
	        ?><br><i>Fax:</i> <?php print render($content['field_fax']) ?><?php
        }; ?>
        <?php if (isset($content['field_alternate_phone'])) {
	        ?><br><i>Alternate Phone:</i> <?php print render($content['field_alternate_phone']) ?><?php
        }; ?>
        </p>
        
        

        <?php
	        if(isset($content['field_staff_page']) or render($content['field_staff_page']) != '') {
	        	$staffURL = $base_path . "/node/" . trim(render($content['field_staff_page']));
	    ?>
        <p><a href="<?php print $staffURL ?>">Our staff.</a></p>
        
        <?php 
	        };
	        
	        if (isset($content['field_hours']) or isset($content['body']) or isset($content['field_facebook']) or isset($content['field_twitter'])) { ?>
        	<dl>
	    <?php if ($content['field_hours']) { ?>
	        <dt>Hours</dt><dd><?php print render($content['field_hours']) ?></dd>
	    
	    <?php
		    }; //end check for hours
			if ($content['body']) { ?>
	        <dd><?php print render($content['body']) ?></dd>
	    <?php
		    }; //end check for additional
		    if($content['field_facebook'] or $content['field_twitter'] or $content['field_linkedin'] or $content['field_instagram']) {  
		?>
	        <dt>Connect With Us</dt>
	        <dd><ul class="tertiary-nav-list">
		    <?php if($content['field_facebook']) { ?>
			    <li><?php print render($content['field_facebook']) ?></li>
		    <?php }; ?>
		    <?php if($content['field_twitter']) { ?>
			    <li><?php print render($content['field_twitter']) ?></li>
		    <?php }; ?>
		    <?php if($content['field_linkedin']) { ?>
			    <li><?php print render($content['field_linkedin']) ?></li>
		    <?php }; ?>
		    <?php if($content['field_instagram']) { ?>
			    <li><?php print render($content['field_instagram']) ?></li>
		    <?php }; ?>
		        
		        </ul></dd>
		<?php
			};
		?>
		</dl>
		<?php }; //end check for dl contents ?>
		
		<!-- what about other social media? -->
		
    </section>