<?php
	
	/* there is some severly hacky template code here, sorry. Nov 2016. emn */

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
 
$hiddenfields = array('field_academic_year','field_summer_session');
 
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label):
	        if(!in_array($field,$hiddenfields)) {
	        
	         ?>
          <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?> scope="col">
            <?php print $label; ?>
          </th>
        <?php 
	        };
	        endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): 
	    
	    //add class="cancelled" for cancelled offerings.
	    if(strstr($row['title'],'Cancelled')) { $row_classes[$row_count][] = 'cancelled'; };
    ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php 
	        
	        /* this is maybe not ideal, but it works to build the complex markup that we want to display on the catalog */
	        
			//ACADEMIC YEAR: math it up!
			//hilariously, because I did some formatting in another template file, I now have to do slightly different munging than before.
			//data comes over in format 2016–17 vs raw value 2017. also, needs trimming!
			$fall = substr(trim($row['field_academic_year']),0,4);
			$threequarters = $fall+1;
			

			//dpm($row['field_quarters']);
			//now format all the quarters!
			$quarters = explode(',', $row['field_quarters']);
			
			$printquarters = '<div class="quarter-indicator-group">';
			foreach($quarters as $q) {
				$classes = explode(' ', $q);
				$quarterclass = strtolower($classes[0]);
				$statusclass = strtolower($classes[1]);
				
				//if this is summer, show the session info
				if($row['field_summer_session'] != '') {
					//do something here.
					//$printquarters .= " (" . trim($row['field_summer_session']) . "&nbsp;Session)";
					
					$printquarters .= '<div class="summer-indicator-group">';
					$summer = trim($row['field_summer_session']);
					if($summer == 'Full' or $summer == 'First') {
						$printquarters .= "<div class='qi qi-summer-session1 qi-$statusclass'>Summer Session 1</div>";
					} else {
						$printquarters .= "<div class='qi qi-summer-session1 qi-na'></div>";
					};
					if($summer == 'Full' or $summer == 'Second') {
						$printquarters .= "<div class='qi qi-summer-session2 qi-$statusclass'>Summer Session 2</div>";
					} else {
						$printquarters .= '<div class="qi qi-summer-session2 qi-na"></div>';
					};
					$printquarters .= '</div>'; //end of group
					
					
				} else {
					
					$printquarters .= "<div class='qi qi-$quarterclass qi-$statusclass'><abbr title='$q'>$q</abbr></div>";
				}; //end check for summer
			}; //end foreach
			$printquarters .= '</div>';
			
			
			//add year to each quarter
			$printquarters = str_replace('Fall', 'Fall&nbsp;' . $fall, $printquarters);
			$printquarters = str_replace('Winter', 'Winter&nbsp;' . $threequarters, $printquarters);
			$printquarters = str_replace('Spring', 'Spring&nbsp;' . $threequarters, $printquarters);
			$printquarters = str_replace('Summer', 'Summer&nbsp;' . $threequarters, $printquarters);
			
			//format status text
			$printquarters = str_replace('Open', '', $printquarters);
			$printquarters = str_replace('Conditional', '', $printquarters);
			$printquarters = str_replace('Signature', ' signature required', $printquarters);
			$printquarters = str_replace('Closed', ' enrollment closed', $printquarters);
			
	        
	        
	        foreach ($row as $field => $content):
	        if(!in_array($field,$hiddenfields)) {
		        
	        
	         ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php 
	            if ($field == 'field_quarters') {
		            print($printquarters);
		        
		        } else {
		           print $content; 
	            };
	            //print_r($field);
	             ?>
          </td>
        <?php 
	        };
	        endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
