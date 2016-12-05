<?php

/**
Formatting for the Status Date (turns it into a chunk of text for display)
 */
?>

<?php 
//dpm($items);
foreach ($items as $delta => $item):
 	if((time()-(60*60*24*30)) < strtotime($item['#markup'])) {
		print (' <span class="message">New</span>');
	};
endforeach; 
?>   


