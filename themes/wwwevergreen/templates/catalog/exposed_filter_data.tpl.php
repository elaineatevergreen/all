<?php
/**
 * @file
 * Basic template file
 */
 
 /*
filters:
	year - Academic Year
	type: Offering Type
	offered: Quarters Offered
	quarters: Quarters Open to New Students (if "All" don't show info)
	standing: Class Standing (if "All" don't show info)
	credit_range: Credits Offered (rework to have range with dash)
	subject: Fields of Study (if "All" don't show info)
	location: Location (if "All" don't show info)
	internship: Internship Opportunities (if "All" don't show info)
	research: Research Opportunities  (if "All" don't show info)
	studyabroad: Study Abroad (if "All" don't show info)
	upperdivision: Upper Division Science Opportunities (if "All" don't show info)
*/

//debug values
dpm($exposed_filters);
 
?>
<?php 
//first of all, only show if there's anything here	
if (isset($exposed_filters)): 

	//go through all the values once to get some nice formatting
	foreach ($exposed_filters as $filter => $value):  
		//only show if there's a value
		//but don't show some of the default values
		if ($value and $value != 'All' and $value != '0, 16'): 
			//then make the filter name look nice
			$printlabel = ucwords(str_replace('_',' ',$filter));
			if (is_array($value)):
				$printfilters[$printlabel] = implode(', ', $value); 
			else:
				if($filter == 'year') { 
					$value1 = 2015+$value;
					$value2 = 16+$value; //this one is probably hella fragile?
					$printvalue = $value1 . '–' . $value2;
				} elseif($filter = 'quarters_accepting_new_students') {
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
				} elseif($filter == 'credit_range') {
					$printvalue = str_replace(', ', '–', $value);
				} elseif($filter == 'field_of_study') {
					$term = taxonomy_term_load($value); 
					$printvalue = $term->name;
				} elseif($filter == 'internship_opportunities' or $filter == 'research_opportunities' or $filter == 'study_abroad' or $filter == 'upper_division_science_options') {
					if($value == 1) {
						$printvalue = 'Yes';
					} elseif($value == 0) {
						$printvalue = 'No';
					};	
				} else {
					$printvalue = $value;
				}; //end check for specially formatted values
				$printfilters[$printlabel] = $printvalue; 
			endif; //end check for array value
		endif; //end check for printable value
	endforeach; //end run through array


//and THEN we print everything
?>
  <div class="exposed_filter_data">
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
<?php endif; //end check for filters ?>
