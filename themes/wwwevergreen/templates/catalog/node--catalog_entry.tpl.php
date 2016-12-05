<?php

/* fun with catalog entries */


/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
 
  //dpm($content['group_details']['group_location_schedule']);
 
 
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
	    
	    
	    <?php 
	    
	     
      print render($content['group_details']['group_more']);
    ?>
    
	 </div>
	 
	 <?php print render($content['field_revisions']); ?>
	 
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
