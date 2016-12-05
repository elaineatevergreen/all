<?php

/**
Formatting for the Revision Date (turns it into a chunk of text)
 */
?>

<?php 
//dpm($items);
foreach ($items as $delta => $item):
 	if((time()-(60*60*24*30)) < strtotime($item['#markup'])) {
		print (' <span class="message">Revised</span>');
	};
endforeach; 
?>   


