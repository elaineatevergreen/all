<?php

/**
Formatting for the fields of study in the catalog entry nodes
 */?>

	<div class="fos keyword-list">
		<b><?php print ("Fields of study:")?></b> 
		<ul class="field-fields-of-study element-list">

	<?php foreach ($items as $delta => $item){ ?>
		<li>
			<?php print(render($item));?>
		</li>
		<?php }; // end iterate through all elements ?>
		</ul>
	</div>
