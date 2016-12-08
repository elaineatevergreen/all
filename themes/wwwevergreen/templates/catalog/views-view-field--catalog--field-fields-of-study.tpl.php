<?php

/**
Formatting for the fields of study in the catalog index.
 */
?>
<div class="fos keyword-list">
	<ul class="element-list">
<?php 
	//print $output;
if($output) {
    //dpm($row->field_field_fields_of_study);
    foreach($row->field_field_fields_of_study as $fos) {
	    
	    //line below links to the field of study page
	    //for now(?) instead, links to listing of offerings in that subject
	    //print $fos['rendered']['#href']
		?>
		<li><a href="?subject=<?php print $fos['rendered']['#title'] ?>"><?php print $fos['rendered']['#title'] ?></a></li>	 
		<?php   
    };
};    
?>
	</ul>
</div>
