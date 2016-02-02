<?php
/**
 * @file
 * Default theme implementation for beans.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>


<?php
//this is the part where we get all the raw values of the variables. Because that's all we need.
	
$classes = field_get_items('bean', $bean, 'field_classes');
$classes = $classes[0]['safe_value'];

//for the hero images, we need the rendered URL.
//someday it might be nice to make these relative instead of absolute.
$field_hero_image_small = field_get_items('bean', $bean, 'field_hero_image_small');	
$small_hero = file_create_url($field_hero_image_small[0]['uri']);

$field_hero_image_medium = field_get_items('bean', $bean, 'field_hero_image_medium');	
$medium_hero = file_create_url($field_hero_image_medium[0]['uri']);

$field_hero_image_large = field_get_items('bean', $bean, 'field_hero_image_large');	
$large_hero = file_create_url($field_hero_image_large[0]['uri']);

$field_hero_image = field_get_items('bean', $bean, 'field_hero_image');	
$xl_hero = file_create_url($field_hero_image[0]['uri']);


	?>
<div class="row">
	<div class="homepage-hero <?php print $classes ?>">  
		
		<picture class="homepage-hero-picture">
  		    <source media="(min-width: 70em)" srcset="<?php echo $xl_hero; ?>"/>
			<source media="(min-width: 43em)" srcset="<?php echo $large_hero; ?>"/>
			<source media="(min-width: 32em)" srcset="<?php echo $medium_hero; ?>"/>
			<source srcset="<?php echo $small_hero; ?>"/>
			<img alt="Go beyond majors, classes, and grades and experience your education the way you imagine. Learn more." srcset="[uri_1]" />
		</picture>
		
		<div class="wrapper">
			<a href="/academics">
				<div class="homepage-hero-content">
					<div class="box caption-box">
						<p class="caption">Photo: <?php print render($title) ?></p>
					</div>
					<div class="homepage-hero-copy">
						<h1>
                            <picture>
                                <source media="(min-width: 43em)" srcset="http://evergreen.edu/_inc/images/go-beyond/slogan-wide.svg"/>
                                <source srcset="http://evergreen.edu/_inc/images/go-beyond/slogan-mobile.svg"/>
							    <img alt="Go beyond majors, classes, &amp; grades and experience your education the way you imagine" src="http://evergreen.edu/_inc/images/go-beyond/slogan-mobile.svg"/>
                            </picture>
						</h1>
						<p class="call-to-action">See for yourself →</p>
					</div>
				</div>
			</a>
		</div>
	</div>
</div>