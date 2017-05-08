<?php

/**
In this entity view mode, we get a name, a tiny headshot, and their expertise. for faculty only.
 */
 

 
?>
<div class="unit-1-2">
<div class="h-card compound">
	<div class="compound-img">
<?php 
	/* this goes thru all the options for photos... */
//square portrait is the best option
if(isset($content['field_square_portrait'])) {
	
	print render($content['field_square_portrait']);
} 
//second best: the rectangular headshot, which gets CSS-shrunk
elseif(isset($content['field_headshot'])) {
	print render($content['field_headshot']);
} 
//finally, if no photo use the small square "no photo" image
else { ?>
<img src="<?php print base_path() . path_to_theme() ?>/images/directory/_blank-square.png" alt="" class="program-faculty"/>
<?php	
};
?>
	</div>
	
	<div class="compound-body">
		<!-- Faculty name -->
		<div class="p-name">
			<a class="u-email" href="<?php print $node_url; ?>"><?php print render($content['field_first_name']) . ' ' . render($content['field_last_name']); ?></a>
		</div>
		
		<?php if(isset($content['field_expertise'])) { ?>
		<!-- Faculty keywords -->
		<div class="details"><?php print render($content['field_expertise']); ?></div>
		<?php }; ?>
	</div><!-- /.media-body -->
</div>
</div>