<?php

/**
display office information as a "contact block" usually on a page.
 */
?>

<div class="content">
    <h2>Contact Information</h2>
    <div class="extended-address">
        <div><?php print render($content['field_building_alt']) ?> <?php print render($content['field_room']) ?> </div>
        <span class="field-label">Mailstop:</span>
        <span class="field-mailstop"><?php print render($content['field_mailstop']) ?></span>
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
	        
	        if (isset($content['field_members'])) { print render($content['field_members']); };  
	        
	        
	        ?>
    
<!--   <hr/> 

  <h3 class="field-label">Related Offices</h3>
  <div class="field-related-offices">
    <a href="/directory/offices/admissionsstudent-visitor-program">Admissions/Student Visitor Program</a>
  </div>
  <div class="field-related-offices">
    <a href="/directory/offices/evening-and-weekend-studies-outreach">Evening and Weekend Studies Outreach</a>
  </div>
  <div class="field-related-offices">
    <a href="/directory/offices/graduate-admissions">Graduate Admissions</a>
  </div>
  <div class="field-body">
    <h3>Request Info</h3>
    <p>Add your name and address to receive our publications, timely reminders and invitations to special events through the mail.</p>
    <ul>
        <li>
            <a href="https://evergreenstatecollege.hobsonsradius.com/ssc/iform/C68670N68670x6700…" title="Future Freshman or Transfer">Future Freshman or Transfer Student</a>
          </li>
            <li>
                <a href="http://www.evergreen.edu/admissions/graduate.htm" title="Future Graduate Student">Future Graduate Student</a>
            </li>
        </ul>
        <h3>Mailing Address</h3>
        <p>
            The&nbsp;Evergreen State College<br/>
            Office of Admissions<br/>
            2700&nbsp;Evergreen Pkwy&nbsp;NW<br/>
            Olympia, WA&nbsp;98505
        </p>
    </div>
    <div class="group-social field-group-html-element">
        <h3>Connect With Us</h3>
        <ul>
            <li>
                <a href="https://www.facebook.com/TheEvergreenStateCollege" class="link-icon link-icon-alt icon-facebook">Facebook</a>
            </li>
            <li>
                <a href="http://twitter.com/EvergreenStCol" class="link-icon link-icon-alt icon-twitter">Twitter</a>
            </li>
        </ul>
    </div>
    <table>
        <caption>People in this Office</caption>
        <thead>
            <tr>
                <th>Name and Title</th>
                <th>Email</th>
                <th>Location</th>
                <th>Mailstop</th>
                <th>Phone</th>
            </tr>
        </thead>
        <tbody>
            <tr class="h-card">
                <td>
                    <b class="p-name">Beaulieu, Angela</b>,
                    <span class="p-job-title">Credentials Evaluator 2</span>
                </td>
                <td>
                    <div class="field-email">
                        <a class="u-email" href="mailto:beauliea@evergreen.edu">beauliea@evergreen.edu</a>
                    </div>
                </td>
                <td>
                    <div class="p-exteneded-address">
                        <span class="field-building-alt">Lib</span>
                        <span class="field-room">1204D</span>
                    </div>
                </td>
                <td>
                    <div class="field-mailstop">LIB 1200</div>
                </td>
                <td>
                    <span class="p-tel">
                        (360)&nbsp;867-<b>6166</b>
                    </span>
                </td>
            </tr>
        </tbody>
    </table>-->
</div> 

<?php /*

    <section class="h-card site-info">
        <h2>Contact</h2>

        <p><b class="p-name"><?php print $title; ?></b><br>
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
	        $staffURL = $base_path . "/node/" . trim(render($content['field_staff_page']));
	    ?>
        <p><a href="<?php print $staffURL ?>">Our staff.</a></p>
        
        <?php if ($content['field_hours'] or $content['body'] or $content['field_facebook'] or $content['field_twitter']) { ?>
        	<dl>
	    <?php if ($content['field_hours']) { ?>
	        <dt>Hours</dt><dd><?php print render($content['field_hours']) ?></dd>
	    
	    <?php
		    }; //end check for hours
			if ($content['body']) { ?>
	        <dd><?php print render($content['body']) ?></dd>
	    <?php
		    }; //end check for additional
		    if($content['field_facebook'] or $content['field_twitter']) {  
		?>
	        <dt>Connect With Us</dt>
	        <dd><ul class="tertiary-nav-list">
		    <?php if($content['field_facebook']) { ?>
			    <li><?php print render($content['field_facebook']) ?></li>
		    <?php }; ?>
		    <?php if($content['field_twitter']) { ?>
			    <li><?php print render($content['field_twitter']) ?></li>
		    <?php }; ?>
		        
		        </ul></dd>
		<?php
			};
		?>
		</dl>
		<?php }; //end check for dl contents ?>
		
		<!-- what about other social media? -->
		
    </section>
    */