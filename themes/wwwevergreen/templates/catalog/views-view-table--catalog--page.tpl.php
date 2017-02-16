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
 
$hiddenfields = array('field_academic_year','field_quarters_open','field_quarters_signature','field_quarters_closed','field_summer_session');
 
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
			//$academicyear = ($row['field_academic_year']-1) . '–' . substr($row['field_academic_year'], 2,2);
			//$threequarters = substr($row['field_academic_year'],0,-2);
			//hilariously, because I did some formatting in another template file, I now have to do slightly different munging than before.
			//data comes over in format 2016–17 vs raw value 2017. also, needs trimming!
			$fall = substr(trim($row['field_academic_year']),0,4);
			$threequarters = $fall+1;
			
			/*
				for each quarter offered...
				add on S if signature required
				add on C if closed entirely
				add on the calendar year	
			*/
			
			$quartersoffered = explode(',', $row['field_quarters_offered']);
			$quarterssig = explode(',', $row['field_quarters_signature']);
			$quartersopen = explode(',', $row['field_quarters_open']);
			$quartersclosed = explode(',', $row['field_quarters_closed']);
			
			/* original working code 
			
			foreach($quartersoffered as $key => $value) {
				if(in_array($value, $quarterssig)) { 
					$quartersoffered[$key] = '<abbr title="signature required">' . $value . '&nbsp;(S)</abbr>';
				};
				if(in_array($value, $quartersclosed)) { 
					$quartersoffered[$key] = '<abbr title="enrollment closed">' . $value . '&nbsp;(C)</abbr>'; 
				};
			};
			
			$printquarters = '<ul>';
			foreach($quartersoffered as $q) {
				$printquarters .= "<li>" . trim($q);
				//if this is summer, add the session info.
				if($row['field_summer_session'] != '') {
					$printquarters .= " (" . trim($row['field_summer_session']) . "&nbsp;Session)";
				}
				$printquarters .= "</li>";
			};
			$printquarters .= '</ul>';
			*/
			
			
			
			
			/* experimental code */
			
			$quarters = array('Fall','Winter','Spring');
			$printquarters = '<div class="quarter-indicator-group">';
			foreach($quarters as $q) {
				$classname = strtolower($q);
				
				//open
				if(in_array($q,$quartersopen)) { 
					$printquarters .= "<div class='qi qi-$classname'><abbr title='$q quarter'>$q quarter</abbr></div>"; 
				}
				//signature
				elseif(in_array($q, $quarterssig)) { 
					$printquarters .= "<div class='qi qi-signature qi-$classname'><abbr title='$q quarter, signature required'>$q quarter, signature required</abbr></div>";
				}
				//closed
				elseif(in_array($q, $quartersclosed)) { 
					$printquarters .= "<div class='qi qi-closed qi-$classname'><abbr title='$q quarter, enrollment closed'>$value quarter, enrollment closed</abbr></div>";
				}
				else {
					$printquarters .= "<div class='qi qi-signature qi-$classname'></div>";  
				};
				
				
			};
			
			
			/* summer is special! */
			
			//still needs signature info :(
			
			$printquarters .= '<div class="summer-indicator-group">';
			if(trim($row['field_summer_session']) == 'Full') {
					$printquarters .= '<div class="qi qi-summer-session1'; 
					if(in_array('Summer',$quarterssig)) { $printquarters .= ' qi-signature '; };
					$printquarters .= '"><abbr title="Summer Session 1">Summer Session 1</abbr></div><div class="qi qi-summer-session2';
					if(in_array('Summer',$quarterssig)) { $printquarters .= ' qi-signature '; };
					$printquarters .= '"><abbr title="">Summer Session 2 (continued)</abbr></div>';
			}
			elseif(trim($row['field_summer_session']) == 'First') {
					$printquarters .= '<div class="qi qi-summer-session1"><abbr title="Summer Session 1">Summer Session 1</abbr></div><div class="qi qi-summer-session2 qi-na"></div>';
			}
			elseif(trim($row['field_summer_session']) == 'Second') {
					$printquarters .= '<div class="qi qi-summer-session1 qi-na"></div><div class="qi qi-summer-session2"><abbr title="Summer Session 2">Summer Session 2</abbr></div>';
			} else {
				//blank entry for non-Summer offerings
				$printquarters .= '<div class="qi qi-summer-session1 qi-na"></div><div class="qi qi-summer-session2 qi-na"></div>';
			};
			$printquarters .= '</div>';

			
			//end the whole goddamn div
			$printquarters .= "</div>";
		
			//add in the calendar year associated with this quarter
			$printquarters = str_replace('Fall', 'Fall&nbsp;' . $fall, $printquarters);
			
			$printquarters = str_replace('Winter', 'Winter&nbsp;' . $threequarters, $printquarters);
			$printquarters = str_replace('Spring', 'Spring&nbsp;' . $threequarters, $printquarters);
			$printquarters = str_replace('Summer', 'Summer&nbsp;' . $threequarters, $printquarters);
	        
	        
	        foreach ($row as $field => $content):
	        if(!in_array($field,$hiddenfields)) {
		        
	        
	         ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php 
	            if ($field == 'field_quarters_offered') {
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
