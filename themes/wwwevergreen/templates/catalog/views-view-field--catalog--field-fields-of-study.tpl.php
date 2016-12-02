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
		?>
		<li><a href="<?php print $fos['rendered']['#href'] ?>"><?php print $fos['rendered']['#title'] ?></a></li>	 
		<?php   
    };
};    
?>
	</ul>
</div>
