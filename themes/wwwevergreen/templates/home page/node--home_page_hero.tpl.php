<?php

/**
 * @file
 * Renders the markup for the home page hero image
 * @file
 * Default theme implementation to display a node.
 *
 *
 * @ingroup themeable
 */

?>

<?php
	//this is the part where we get all the raw values of the variables. Because that's all we need.
		
	$classes = field_get_items('node', $node, 'field_classes');
	$classes = $classes[0]['safe_value'];
	//$classes = '';
	
	//for the hero images, we need the rendered URL.
	//someday it might be nice to make these relative instead of absolute.
	$field_hero_image_small = field_get_items('node', $node, 'field_hero_image_small');	
	$small_hero = file_create_url($field_hero_image_small[0]['uri']);
	
	$field_hero_image_medium = field_get_items('node', $node, 'field_hero_image_medium');	
	$medium_hero = file_create_url($field_hero_image_medium[0]['uri']);
	
	$field_hero_image_large = field_get_items('node', $node, 'field_hero_image_large');	
	$large_hero = file_create_url($field_hero_image_large[0]['uri']);
	
	$field_hero_image = field_get_items('node', $node, 'field_hero_image');	
	$xl_hero = file_create_url($field_hero_image[0]['uri']);
	
	$field_home_page_version = field_get_items('node', $node, 'field_home_page_version');
	$field_home_page_version = $field_home_page_version[0]['value'];
	//dsm($field_home_page_version);
	
	switch($field_home_page_version) {
		case 'graduation':
			$destination = "/graduation";
			$content_class = "homepage-hero-content-grad";
			$hero_alt = "'Grats Greener grads. Watch live.";
			$slogan_svg_wide = "grats-greener-grads/grats-long";
			$slogan_svg_mobile = "grats-greener-grads/grats-stacked";
			$slogan_alt = "'Grats Greener grads.";
			$call_to_action = "Watch the event";
			break;
		case 'orientation':
			$destination = "/orientation";
			$content_class = "";
			$hero_alt = "Welcome Greeners! It’s O-Week. Learn how to succeed at Evergreen and have some fun along the way.";
			$slogan_svg_wide = "orientation/slogan-wide";
			$slogan_svg_mobile = "orientation/slogan-mobile";
			$slogan_alt = "Welcome Greeners! It’s O-Week. Learn how to succeed at Evergreen and have some fun along the way.";
			$call_to_action = "See the Schedule";
			break;
		//this covers both "Normal" and for older hero images, any blank value
		default:
			$destination = "/academics";
			$content_class = "";
			$hero_alt = "Go beyond majors, classes, and grades and experience your education the way you imagine. Learn more.";
			$slogan_svg_wide = "go-beyond/slogan-wide";
			$slogan_svg_mobile = "go-beyond/slogan-mobile";
			$slogan_alt = "Go beyond majors, classes, &amp; grades and experience your education the way you imagine.";
			$call_to_action = "See for yourself";
			break;
	};

?>

<div class="row">
	<div class="homepage-hero <?php print $classes ?>">  
		
		<picture class="homepage-hero-picture">
  		    <source media="(min-width: 70em)" srcset="<?php echo $xl_hero; ?>"/>
			<source media="(min-width: 43em)" srcset="<?php echo $large_hero; ?>"/>
			<source media="(min-width: 32em)" srcset="<?php echo $medium_hero; ?>"/>
			<source srcset="<?php echo $small_hero; ?>"/>
			<img alt="<?php print $hero_alt ?>" src="<?php echo $xl_hero; ?>" />
		</picture>
		
		<div class="wrapper">
			<a href="<?php print $destination ?>">
				<div class="homepage-hero-content <?php print $content_class ?>">
					<?php 
						/* the caption shouldn't appear on the graduation page */
						if($field_home_page_version != 'graduation') { 
						?>
					<div class="box caption-box">
						<p class="caption">Photo: <?php print render($title) ?></p>
					</div>
					<?php }; //end check for graduation ?>
					<div class="homepage-hero-copy">
						<h1>
							<picture>
								<source media="(min-width: 43em)" srcset="<?php print base_path() . path_to_theme() ?>/images/homepage/<?php print $slogan_svg_wide ?>.svg"/>
								<source srcset="<?php print base_path() . path_to_theme() ?>/images/homepage/<?php print $slogan_svg_mobile ?>.svg"/>
								<img alt="<?php print $slogan_alt ?>" src="<?php print base_path() . path_to_theme() ?>/images/homepage/<?php print $slogan_svg_mobile ?>.svg"/>
							</picture>
						</h1>
						<p class="call-to-action"><?php print $call_to_action ?> →</p>
					</div>
				</div>
			</a>
		</div>
	</div>
</div>