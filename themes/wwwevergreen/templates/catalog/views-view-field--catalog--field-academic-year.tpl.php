<?php

/**
Formatting for the academic year in table captions in the catalog index.
 */
?>

<?php 
	//print $output;
if($output) {
    //dpm($row->field_field_curricular_area);
    foreach($row->field_field_academic_year as $r => $year) {
		//update this after changing from filter to contextual filter
		//$area = $row->field_field_curricular_area[$r]['rendered']['#markup'];
		$year = $year['rendered']['#markup'];
		$prior = $year-1;
		//print $area . " Offerings for " . $prior . "–" . substr($year, -2);
		print $prior . "–" . substr($year, -2);
    };
};   
?>