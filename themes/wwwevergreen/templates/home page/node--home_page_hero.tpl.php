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


	?>
<div class="alert-alt box row">
	<div class="wrapper">
			<h2>News Update</h2>
			<p>
				Read a statement from the Board of Trustees:
				<a href="/news/post/renewing-our-commitment-tolerance-and-respect-evergreen-statement-board-trustees">Renewing Our Commitment to Tolerance and Respect at Evergreen</a>.
			</p>
			<p>
				Find the latest news from the college:
				<a href="/news/update-safety-equity-and-free-speech-evergreen">Safety, Equity, and Free Speech at Evergreen</a>.
			</p>
		</div>
	</div>
</div>

<div class="row">
	<div class="homepage-hero <?php print $classes ?>">  
		<a class="homepage-hero-link" href="/academics">
			<picture class="homepage-hero-picture">
	  		<source media="(min-width: 70em)" srcset="<?php echo $xl_hero; ?>"/>
				<source media="(min-width: 43em)" srcset="<?php echo $large_hero; ?>"/>
				<source media="(min-width: 32em)" srcset="<?php echo $medium_hero; ?>"/>
				<source srcset="<?php echo $small_hero; ?>"/>
				<img alt="Experience more." srcset="<?php echo $xl_hero; ?>" />
			</picture>
			
			<div class="homepage-hero-caption">
				<div class="box caption-box">
					<p class="caption">Photo: <?php print render($title) ?></p>
				</div>
			</div>
			
			<!--<div class="wrapper">-->
				<div class="homepage-hero-slogan-wrapper">
				<!--<div class="homepage-hero-content">-->
					<div class="homepage-hero-slogan">
						<h1>
							<picture>
								<source media="(min-width: 43em)" srcset="<?php print base_path() . path_to_theme() ?>/images/homepage/experience-more/experience-more-main-lg.svg"/>
								<source srcset="<?php print base_path() . path_to_theme() ?>/images/homepage/experience-more/experience-more-main-sm.svg"/>
								<img alt="Experience more." src="<?php print base_path() . path_to_theme() ?>/images/homepage/experience-more/experience-more-main-sm.svg"/>
							</picture>
						</h1>
						<div class="homepage-hero-slogan-keywords">
							<img alt="" src="<?php print base_path() . path_to_theme() ?>/images/homepage/experience-more/experience-more-keywords.svg"/><br/>
							<img alt="" src="<?php print base_path() . path_to_theme() ?>/images/homepage/experience-more/experience-more-keywords.svg"/><br/>
							<img alt="" src="<?php print base_path() . path_to_theme() ?>/images/homepage/experience-more/experience-more-keywords.svg"/>
						</div>
						<!--<p class="call-to-action">Learn how →</p>-->
					</div>
				<!--</div>-->
				
			</div>
		</a>
	</div>
</div>