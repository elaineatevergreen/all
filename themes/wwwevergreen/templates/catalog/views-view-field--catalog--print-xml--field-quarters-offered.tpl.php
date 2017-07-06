<?php

/**
Formatting for quarters in the print export XML

I couldn't find an elegant programmatic way to handle this, so I just wrote a plain ol' switch statement
This should cover all the options.
Needs to be updated by hand each year.

Fall
Fall 2018 quarter

Fall Winter
Fall 2018 and Winter 2019 quarters

Fall Winter Spring
Fall 2018, Winter 2019, and Spring 2019 quarters

Winter
Winter 2019 quarter

Winter Spring
Winter 2019 and Spring 2019 quarters

Spring
Spring 2019 quarter


 */
?>

<?php 
	//print $output;
if($output) {
    foreach($row->field_field_quarters_offered as $r => $quarters) {
	    
	    $q = trim($quarters['rendered']);
	    //fun fact! there's extra spaces in between each value!
		switch($q) {
			case 'Fall':
				print "Fall 2018 quarter";
				break;
			case 'Fall  Winter':
				print "Fall 2018 and Winter 2019 quarters";
				break;
			case 'Fall  Winter  Spring':
				print "Fall 2018, Winter 2019, and Spring 2019 quarters";
				break;
			case 'Winter':
				print "Winter 2019 quarter";
				break;
			case 'Winter  Spring':
				print "Winter 2019 and Spring 2019 quarters";
				break;
			case 'Fall  Winter':
				print "Fall 2018 and Winter 2019 quarters";
				break;
		};
	};
};   
?>