<?php
/**
 * @file
 * Basic template file
 */
 
/*
	Basic structure of this template:
	* go through the list of exposed filters
	* do some work to labels and values readable
	* go through again, this time just dropping those into some markup
	
	filter values get set to something readable starting around line 40
	filter names/labels only get underscores replaced with spaces and then Title Case
		to find the filter names, go to /admin/structure/views/view/catalog/edit/page?destination=catalog/index
		find the exposed filter
		click "more" and that machine name is the filter name
		I've updated the ones that I think aren't used as links anywhere
		DO NOT change without talking to Elaine
	markup starts around line 100
*/

//debug values as they come in
//dpm($exposed_filters);
 
?>
<?php 
//first of all, only do any of this if there's anything here	
if (isset($exposed_filters)): 

	//go through all the values once to get some nice formatting
	foreach ($exposed_filters as $filter => $value): 
		//unset for safety (this might not've been what was wrong tbh)
		unset($printlabel);
		unset($printvalue);
		//only show if there's a value
		//but don't show some of the default values
		if ($value and $value != 'All' and $value != '0, 16'): 
			//then make the filter name look nice
			$printlabel = ucwords(str_replace('_',' ',$filter));
			//it doesn't look like the values ever are an array
			//but this was in the default template for this module
			//so better safe than sorry
			if (is_array($value)):
				$printfilters[$printlabel] = implode(', ', $value); 
			//values that are strings then get handled as needed
			else:
				//this one is probably hella fragile?
				//I dislike the entire way that academic years are handled
				if($filter == 'year') { 
					$value1 = 2015+$value;
					$value2 = 16+$value; 
					$printvalue = $value1 . '–' . $value2;
				//why are these quarters numbers and not words?
				} elseif($filter =='quarters_accepting_new_students') {
					switch($value) {
						case 1:
							$printvalue = 'Fall';
							break;
						case 2:
							$printvalue = 'Winter';
							break;
						case 3:
							$printvalue = 'Spring';
							break;
						case 4:
							$printvalue = 'Summer';
							break;
					}; //end switch
				//does exactly what it looks like
				} elseif($filter == 'credit_range') {
					$printvalue = str_replace(', ', '–', $value);
				//gets the term name for the field of study taxonomy term id
				} elseif($filter == 'field_of_study') {
					$term = taxonomy_term_load($value); 
					$printvalue = $term->name;
				//turn boolean into words
				} elseif($filter == 'internship_opportunities' or $filter == 'research_opportunities' or $filter == 'study_abroad' or $filter == 'upper_division_science_options') {
					if($value == 1) {
						$printvalue = 'Yes';
					} elseif($value == 0) {
						$printvalue = 'No';
					};
				//everything else is fine the way it is	
				} else {
					$printvalue = $value;
				}; //end check for specially formatted values
				
				//add to the new array
				$printfilters[$printlabel] = $printvalue;
			endif; //end check for array value
		endif; //end check for printable value
		
	endforeach; //end run through array

//debugging the printable values
//dpm($printfilters);


//and THEN we print everything
?>
  <div class="box note exposed_filter_data">
	  <div class="compound">
		  <div class="compound-img">
		  </div>
		  <div class="compound-body">
		    <div class="title"><?php print t('Current Catalog Filter'); ?></div>
		    <div class="content">
		<?php 
			//now go thru all the filters with the rewritten display
			foreach ($printfilters as $label => $contents):  
		?>
		        <div class="filter">
			    	<div class="name"><?php print $label; ?>: </div>
		            <div class="value"><?php print $contents; ?></div>
		        </div>
		      <?php endforeach; //end iteration through the array ?>
		    </div>
		  </div>
	  </div>
  </div>
<?php endif; //end check for filters ?>
