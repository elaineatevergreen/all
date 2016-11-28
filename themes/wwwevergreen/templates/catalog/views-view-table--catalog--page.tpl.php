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
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label):
	        if($field != 'field_maximum_credits' and $field != 'field_academic_year' and $field != 'field_quarters_open') {
	        
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
	        
	        //CREDITS: show as a range of values instead of two separate fields.
	        //does field_minimum_credits == field_maximum_credits?
	        if($row['field_minimum_credits'] == $row['field_maximum_credits']) { 
		        $creditrange = $row['field_minimum_credits']; 
		        //offerings that say 0 credits *actually* offer variable credit. GOOD TIMES.
		        if($creditrange == 0) { $creditrange = 'V'; };
		    } else { 
			    $creditrange = $row['field_minimum_credits'] . '–' . $row['field_maximum_credits']; 
			};
	        
	        //QUARTERS: add the year to the end of the quarter name
	        
			//ACADEMIC YEAR: math it up!
			$academicyear = ($row['field_academic_year']-1) . '–' . substr($row['field_academic_year'], 2,2);
			
			//OPEN FOR REGISTRATION
			$openreg = $row['field_quarters_open'];
	        
	        
	        foreach ($row as $field => $content):
	        if($field != 'field_maximum_credits' and $field != 'field_academic_year' and $field != 'field_quarters_open') {
		        
	        
	         ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php 
	            if($field == 'field_minimum_credits') { 
		            print $creditrange; 
		        } elseif ($field == 'field_quarters_offered') {
			        ?>
			     	<p><?php print $academicyear ?>
			     	<?php print $content; ?>
			     	<p><small>Registration open: <?php print $openreg ?></small></p>
			     	<?php
			    
		        } else {
		           print $content; //print_r($field); 
	            };
	             ?>
          </td>
        <?php 
	        };
	        endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
