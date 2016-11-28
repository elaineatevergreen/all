<?php

/**
In this entity view mode, we get a name, a tiny headshot, and their expertise. for faculty only.
 */
 

 
?>

<div class="h-card media">
	<div class="media-img">
<?php if(isset($content['field_headshot'])) {
	print render($content['field_headshot']);
} ?>
	</div>
	
	<div class="media-body">
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