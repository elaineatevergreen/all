<?php
	
// some fun things that happen on nodes
function wwwevergreen_preprocess_page(&$variables) {
  if (isset($variables['node']->type)) {
    // If the content type's machine name is "my_machine_name" the file
    // name will be "page--my-machine-name.tpl.php".
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
      //this rewrites individual directory people pages for a nicer title (Elaine Nelson vs Nelson, Elaine)
      if ($variables['node']->type === 'directory_individual') {
	  	$temptitle = explode(',', check_plain($variables['node']->title));
	  	$temptitle = $temptitle[1] . ' ' . $temptitle[0];
	  	$variables['title'] = $temptitle;
	  	drupal_set_title($temptitle);
  	};
  }
}

//similar to the directory function above, this rewrites people's names to be easier to read.
function wwwevergreen_field__field_display_name(&$variables) {
	$output = '';
	
	foreach ($variables['items'] as $delta => $item) {
		$name = explode(',', drupal_render($item));
		$name = $name[1] . ' ' . $name[0];
		$output .= $name;
	};
	
	return $output;
}

//makes sure headshots appearing in content have the right class.
//function wwwevergreen_field__field_headshot(&$variables){
	
//};

//this reformats the field so that the last four digits are bolded if it's an evergreen number.
//people like that for some reason. :)
function wwwevergreen_field__field_phone(&$variables) {
	$output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
	  $phone = drupal_render($item);
	  	if(substr($phone, -8,3) == '867') { 
			$ext = substr($phone, -4,4);
			$phone = str_replace($ext, "<strong>$ext</strong>", $phone);
		};
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . $phone . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * THEME_PREPROCESS_VIEWS_VIEW
 * @param type $vars
 * Adds category to title for the calendar. I hope. Taken from https://www.drupal.org/node/658566#comment-8278349
 * 
 */
function wwwevergreen_preprocess_views_view(&$vars) {
	if ($vars['view']->name == 'calendar') {
    // get var from GET
    	$categories = $_GET['category'];
		if (isset($categories)) {
	    	foreach($categories as $category) {
			// obj_type is the taxonomy term, get taxonomy term name
				$cat_names[]=taxonomy_term_load($category)->name;
				//update title
				//$vars['view']->build_info['title'] = $cat_name;
      		}; //end foreach
      		if(count($cat_names) == 1) { 
	      		$nice_cat_names = $cat_names[0]; 
	      		$s = 'ies';
	      	} else {
		      	$nice_cat_names = implode(', ', $cat_names);
		      	$s = 'y';
	      	}
      		$vars['view']->build_info['header'] = "Categor$s: $nice_cat_names";
    	}; //end if set
    }; //end if view
}

//this combines the building and room fields in Directory Office into a single field
//see http://drupal.stackexchange.com/questions/59770/what-is-best-way-to-combine-multiple-fields-in-template-preprocess
/*function wwwevergreen_preprocess_node(&$variables) {
  if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {      
    $building = strip_tags($variables['content']['field_building_alt']['#markup']);
    $room = strip_tags($variables['content']['field_room']['#markup']);

    // remove individual fields
    unset($variables['content']['field_building_alt']);
    unset($variables['content']['field_room']);

    // combine those fields in a tag
    $variables['content']['field_location_combined'] = array(
        '#markup' => '<dd>'.$building. ' ' . $room.'</dd>',
        '#weight' => 2
    );
  }
}*/