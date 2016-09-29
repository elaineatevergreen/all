<?php
	
// allow per-node-type and panel page template files
// rewrite directory pages titles
function wwwevergreen_preprocess_page(&$variables) {
  if (isset($variables['node']->type)) {
    // If the content type's machine name is "my_machine_name" the file
    // name will be "page--my-machine-name.tpl.php".
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
    
    //some rewriting of page titles!
    //this rewrites individual directory people pages for a nicer title (Elaine Nelson vs Nelson, Elaine)
    if ($variables['node']->type === 'directory_individual') {
	  $temptitle = explode(',', check_plain($variables['node']->title));
	  $temptitle = $temptitle[1] . ' ' . $temptitle[0];
	  $variables['title'] = $temptitle;
	  drupal_set_title($temptitle);
  	} 
  	// adds abbreviation to the end of a location name
  	elseif ($variables['node']->type === 'location') {
		$abbr = field_get_items('node', $variables['node'], 'field_abbreviated_building_name');
		$abbr = $abbr[0]['value'];
		$temptitle = check_plain($variables['node']->title);
		$temptitle = $temptitle . " ($abbr)";
		$variables['title'] = $temptitle;
		drupal_set_title($temptitle);
  	}
  };
  // allows for special template pages for panel pages.
  if (module_exists('page_manager') && $panel_page = page_manager_get_current_page()) {
        $variables['theme_hook_suggestions'][] = 'page__panels';
        $variables['theme_hook_suggestions'][] = 'page__'  . $panel_page['name']; //this line doesn't seem to work?
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

//rewriting the submitted by/date line
//good tips here https://www.drupal.org/node/1072640#comment-6295608
//also http://drupal.stackexchange.com/questions/11215/how-to-load-a-user-field-in-template-preprocess-comment
function wwwevergreen_preprocess_node(&$variables) {
  if ($variables['submitted']) {
	//check for all the possible alternate names
	//get the node's byline field
	$node_byline = field_get_items('node', $variables['node'], 'field_byline');
	$byline = $node_byline[0]['value'];
	//get the author's display name
	$author = user_load($variables['node']->uid);
	$author_display_name = field_get_items('user', $author, 'field_display_name');
	$display_name = $author_display_name[0]['value'];
	//a future improvement: link the author display name to the profile and then show all the articles on that page
	
	//decide which name to use
	if($byline != '') { 
		$posted_name = $byline; 
	} elseif($display_name != '') {
		$posted_name = $display_name;
	} else { 
		$posted_name = $variables['name']; //if none of those things exist, just use the normal username
	};
	
	//build the submitted by text
    $variables['submitted'] = t('Written by !username on !datetime', array('!username' => $posted_name, '!datetime' => format_date($variables['node']->created, 'custom', 'F j, Y \a\t g:i a')));
  }
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
  //$output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
	  $phone = drupal_render($item);
	  $phone = str_replace(' ', '&nbsp;', $phone);
	  	if(substr($phone, -8,3) == '867') { 
			$ext = substr($phone, -4,4);
			$phone = str_replace($ext, "<strong>$ext</strong>", $phone);
		};
	//$classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    //$output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . $phone . '</div>';
    $output = $phone;
  }
  //$output .= '</div>';

  // Render the top-level DIV.
  //$output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}

/**
 * Returns HTML for a managed file element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: A render element representing the file.
 *
 * @ingroup themeable
 */
/* note: this doesn't actually work.
function wwwevergreen_theme_media_element($variables) {
  $element = $variables['element'];

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'form-media';

  // This wrapper is required to apply JS behaviors and CSS styling.
  $output = '';
  $output .= '<span' . drupal_attributes($attributes) . '>';
  $output .= drupal_render_children($element);
  $output .= ' (hello world)</span>';
  return $output;
}
*/

/**
 * THEME_PREPROCESS_VIEWS_VIEW
 * @param type $vars
 * Adds category to title for the calendar. I hope. Taken from https://www.drupal.org/node/658566#comment-8278349
 * 
 */
function wwwevergreen_preprocess_views_view(&$vars) {
	if ($vars['view']->name == 'calendar' and in_array('category', $_GET)) {
    // get var from GET
    	$categories = $_GET['category'];
    	if(is_array($categories)){
	    	foreach($categories as $category) {
			$cat_names[]=taxonomy_term_load($category)->name;
      	}; //end foreach
	  	if(count($cat_names) == 1) { 
	      	$nice_cat_names = $cat_names[0]; 
		  	$s = 'y';
	    } else {
		    $nice_cat_names = implode(', ', $cat_names);
			$s = 'ies';
		} // end pluralizing
		$vars['view']->build_info['title'] = "Events by Categor$s: $nice_cat_names";
    	}
	        	
    }; //end if view and category set
}

/**
 * Implements hook_form_alter().
   Stupid Views bug. https://www.drupal.org/node/339384#comment-10588874
 */
function wwwevergreen_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {

    case 'views_exposed_form':
      // Temporarily fix BUG: https://www.drupal.org/node/339384
      foreach($form AS $key => $element) {
        if (is_array($element) && isset($element['#description'])) {
          unset($form[$key]['#description']);
        }
      };
     break;

  }
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