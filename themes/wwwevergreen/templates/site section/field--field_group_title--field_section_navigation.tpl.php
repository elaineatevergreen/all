<?php
/**
	
	Themes the header for each navigation accordion.
	Includes the checkbox, h4, and labels.
	
 */
?>					
<!-- Accordion head -->
<?php 

foreach ($items as $delta => $item): 
	
	//create the unique ID for the input and the header.
	$collapse_id = render($item);
	$collapse_id = str_replace(' ', '-', strtolower($collapse_id));
?>
	<input id="collapse-<?php print $collapse_id ?>" name="accordion-group" type="radio"/>
	
	<h4 class="accordion-h tertiary-nav-h">
		<label class="accordion-dismiss" for="collapse-all"><?php print trim(render($item)); ?></label><!-- Triggers #collapse-all radio button, above. -->
		<label class="accordion-toggle" for="collapse-<?php print $collapse_id ?>"><?php print trim(render($item)); ?></label><!-- Opens this section. -->
	</h4>
<?php endforeach; ?>