<?php
	
//this is just used on the catalog node page
//we should find a way to use standard Drupal rendering to get the correct effect instead, thanks
function printEach($passedcontent, $put_front = "", $put_after= "")
		//takes a content (not yet rendered) renderable array and prints all the items out
		// put_front will be put in front of each element, and put after, after
		// front and after are optional parameters and default to ""
		// this function does not print the key, only the elements recursively.
		{
			for($i = 0; $i < sizeof($passedcontent['#items']); ++$i){
				if(isset($passedcontent[$i])){
					print($put_front);
					print(render($passedcontent[$i]));
					print($put_after);
				}
			}
		}
	
// allow per-node-type and panel page template files
// rewrite directory pages titles
function wwwevergreen_preprocess_page(&$variables) {
	
	//	  dsm($variables);
	
  if (isset($variables['node']->type)) {
    // If the content type's machine name is "my_machine_name" the file
    // name will be "page--my-machine-name.tpl.php".
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
    
    //some rewriting of page titles!
    //this rewrites individual directory people pages for a nicer title (Elaine Nelson vs Nelson, Elaine)
    if ($variables['node']->type === 'directory_individual') {
	  //$temptitle = explode(',', check_plain($variables['node']->title));
	  //$temptitle = $temptitle[1] . ' ' . $temptitle[0];
	  $temptitle = $variables['node']->field_first_name['und'][0]['safe_value'] . ' ' . $variables['node']->field_last_name['und'][0]['safe_value'];
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
  //custom pages for taxonomy terms, specifically used for fields of study.
  if(arg(0) == 'taxonomy' && arg(1) == 'term') {
        $tid = (int)arg(2);
        $term = taxonomy_term_load($tid);
        if(is_object($term)) {
           $variables['theme_hook_suggestions'][] = 'page__'.$term->vocabulary_machine_name;
        }
  }
  // allows for special template pages for panel pages.
  if (module_exists('page_manager') && $panel_page = page_manager_get_current_page()) {
        $variables['theme_hook_suggestions'][] = 'page__panels';
        if($panel_page['name'] == 'page-home') {
	        $variables['theme_hook_suggestions'][] = 'page__panels__nativecases';
        };
        $variables['theme_hook_suggestions'][] = 'page__panels__'  . $panel_page['name']; //this line doesn't seem to work?
  };
  // only do this for page-type nodes and only if Path module exists
  if (module_exists('path') && isset($variables['node']) && $variables['node']->type == 'basic_page') {
    // look up the alias from the url_alias table
    $source = 'node/' .$variables['node']->nid;
    $alias = db_query("SELECT alias FROM {url_alias} WHERE source = '$source'")->fetchField();
    if ($alias != '')  {
      // build a suggestion for every possibility
      $parts = explode('/', $alias);
      $suggestion = '';
      foreach ($parts as $part) {
        if ($suggestion == '') {
          // first suggestion gets prefaced with 'page--'
          $suggestion .= "page__$part";
        } else {
          // subsequent suggestions get appended
          $suggestion .= "__$part";
        }
        // add the suggestion to the array
        $variables['theme_hook_suggestions'][] = $suggestion;
      }
    }
  }
  
  // Add JavaScript files
  drupal_add_js(drupal_get_path('theme', 'wwwevergreen') . '/js/dist/scripts.min.js', array('group' => JS_THEME, 'defer' => true, 'type' => 'file'));

}

//similar to the directory function above, this rewrites people's names to be easier to read.
//I have no idea if this is actually used anywhere. GOOD TIMES.
function wwwevergreen_field__field_display_name(&$variables) {
	$output = '';
	
	foreach ($variables['items'] as $delta => $item) {
		$name = explode(',', drupal_render($item));
		$name = $name[1] . ' ' . $name[0];
		$output .= $name;
	};
	return $output;
}

//adds class="image" to headshot images, and in fact any image field where the display style is set to "Image Class"
//also adds classes on square and rectangular thumbnails
function wwwevergreen_preprocess_image(&$variables) {
  if(isset($variables['style_name'])) {
	if($variables['style_name'] == 'image_class') {
      $variables['attributes']['class'][] = "image";
    };
    if($variables['style_name'] == 'portrait_thumbnail2') {
      $variables['attributes']['class'][] = "u-photo";
    };
    if($variables['style_name'] == 'portrait_thumbnail') {
      $variables['attributes']['class'][] = "program-faculty";
    };
  };
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


//NOTE: in Drupal 8, probably need to redo this from scratch. This is a particularly weird and verbose way to get all the non-breaking spaces and extension bolding in various phone numbers. And it also strips out all the markup, which is maybe not always the right solution?
//this reformats the field so that the last four digits are bolded if it's an evergreen number.
//people like that for some reason. :)
function wwwevergreen_field__field_phone(&$variables) {
	$output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  foreach ($variables['items'] as $delta => $item) {
	  $phone = drupal_render($item);
	  $phone = str_replace(' ', '&nbsp;', $phone);
	  	if(substr($phone, -8,3) == '867') { 
			$ext = substr($phone, -4,4);
			$phone = str_replace($ext, "<strong>$ext</strong>", $phone);
		};
    $output = $phone;
  }

  return $output;
}
function wwwevergreen_field__field_alternate_phone(&$variables) {
	$output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  foreach ($variables['items'] as $delta => $item) {
	  $phone = drupal_render($item);
	  $phone = str_replace(' ', '&nbsp;', $phone);
	  	if(substr($phone, -8,3) == '867') { 
			$ext = substr($phone, -4,4);
			$phone = str_replace($ext, "<strong>$ext</strong>", $phone);
		};
    $output = $phone;
  }

  return $output;
}
//no bolding in fax numbers, because that would be weird.
function wwwevergreen_field__field_fax(&$variables) {
	$output = '';
  foreach ($variables['items'] as $delta => $item) {
	  $phone = drupal_render($item);
	  $phone = str_replace(' ', '&nbsp;', $phone);	
	  $output = $phone;
  }
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
 * Adds jquery ui to the catalog for overlay filters
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
    
    if($vars['view']->name == 'catalog') {
	    drupal_add_library('system', 'ui');
		drupal_add_library('system', 'ui.dialog');
    }; //end check for catalog view
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

function staticblocks($b) {
	
	$imagepath = base_path() . path_to_theme() . '/images/';
	//$siteurl = base_url();
	
	include_once("pseudoblocks/$b.php");
	
	
}