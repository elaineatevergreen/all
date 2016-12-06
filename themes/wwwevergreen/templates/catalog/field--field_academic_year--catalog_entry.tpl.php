<?php

/**
Formatting for the Revision Date (turns it into a chunk of text)
 */
?>

<?php 
//dpm($items);
foreach ($items as $delta => $item):
	$year = $item['#markup'];
	$prior = $year-1;
	//print $area . " Offerings for " . $prior . "–" . substr($year, -2);
	print $prior . "–" . substr($year, -2);
 	
endforeach; 
?>   



