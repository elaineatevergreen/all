<?php

/**
 * @file
 * Concatenates flagged nids into a link that can be shared.
 *
 * @ingroup views_templates
 */
?>
<?php 

//get and clean up all of the node IDs of the flagged items	
foreach ($rows as $id => $row): 
	$nids[] = trim($row);
 endforeach; 
 
 //build a URL 
 $url = base_path() . request_path() . "/" . implode('+', $nids);

 
 ?>
<p><a href="<?php print($url) ?>">Share your saved list</a>
</p>