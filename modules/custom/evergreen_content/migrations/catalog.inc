<?php
/**
	* @file
	* Imports site content from XML
	* some of this code is cribbed from the Wine migration example.
*/

class CatalogMigration extends XMLMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports college catalog from XML. (currently only undergrad)');
    	
    	//Catalog migration is dependent on the Individual directory migration
    	//Could add more in the future for fields, etc.
    	//Commented out because I'm not using it yet.
    	$this->dependencies = array('Individual');
    	
    	// There isn't a consistent way to automatically identify appropriate
    // "fields" from an XML feed, so we pass an explicit list of source fields
      
    $fields = array(
      'title' => t('Title'),
      'curr_area' => t('Grad or undergrad'),
      'id' => t('ID'),
      'offering_type' => t('Offering type'),
      'location' => t('Location'),
      'percent_freshman' => t('Percent freshman'),
      'max_enrollment' => t('Maximum enrollment'),
      'preparatory_for' => t('Preparatory for'),
      'description' => t('Description'),
      
      //these need some help to get into Drupal
      'status_date' => t('Status date'), //needs to be transformed for import
      'time_of_day_code' => t('Time of day code'), //needs to be transformed
      'min_standing' => t('Minimum standing'),
      'max_standing' => t('Maximum standing'), //these will get munged to add all possible standings
      'online_instruction' => t('Online instruction'), //munge for quarters with different values
      
      'faculty_members' => t('Faculty members'),
      
	  //these are all the options. In Drupal, they're separate fields.
	  'advertised_schedule' => t('Advertised schedule'),
	  'prerequisites' => t('Prerequisites'),
	  'variable_credit' => t('Variable credit'),
	  'special_expenses' => t('Special expenses'),
	  'off_campus' => t('Off campus location'),
	  'upper_division' => t('Upper division science credit'),
	  'offered_again' => t('Offered again'),
	  'study_abroad' => t('Study abroad'),
	  
      
      /*
	      
	      <name>Ackley, Kristina</name><title>Faculty</title><location>Lab I 1011</location><mailstop>LAB 1020</mailstop><email>ackleyk</email><email_addressable>ackleyk@evergreen.edu</email_addressable><phone>3608676020</phone>
	    
	    
	    
	      
	  */

    );
    	
    	//find the correct folder and get the XML
    	//I would like to figure out how to combine old and new content in a single XML file
    	//or how to iterate over two XML files?	
    	//$folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_content') . '/migrations/';
        //$xml_location = $folder . 'all-content-simple-combined.xml';
        $xml_location = 'http://www.evergreen.edu/catalog/2015-16/all.xml';
        
        // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/programs/program';
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /positions/position/sourceid.
    $item_ID_xpath = '@id';
        
        
    	$items_class = new MigrateItemsXML($xml_location, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    	
    	//set which taxonomy vocabulary to use
    	$this->destination = new MigrateDestinationNode('catalog_entry');
    	
    	//the unique id is the URL, I think.
    	
    	//maps a thing
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'sql_map' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'Mapping a thing',
                          )
        ),
        MigrateDestinationNode::getKeySchema()
      );
      
      /*
	      field mappings:
	    
		*/
		
		$this->addFieldMapping('title', 'title')->xpath('title');
		//didn't work the first time, went into prepareRow to just get "asXML"
		$this->addFieldMapping('body', 'description');
		$this->addFieldMapping('body:format')->defaultValue('basic_tags');
		$this->addFieldMapping('field_cmd_id', 'id')->xpath('@id');
		$this->addFieldMapping('field_grad_or_undergrad', 'curr_area')->xpath('@curr_area');
		$this->addFieldMapping('field_offering_type', 'offering_type')->xpath('@offering_type');
		$this->addFieldMapping('field_location', 'location')->xpath('location');
		$this->addFieldMapping('field_percent_freshman', 'percent_freshman')->xpath('percent_freshman');
		$this->addFieldMapping('field_maximum_enrollment', 'max_enrollment')->xpath('max_enrollment');
		$this->addFieldMapping('field_preparatory_for', 'preparatory_for')->xpath('preparatory_for/*');
		$this->addFieldMapping('field_offering_type', 'offering_type')->xpath('@offering_type');
		
		//see prepareRow, also adds multiple values
		$this->addFieldMapping('field_time_offered', 'time_offered')->separator(',');
		$this->addFieldMapping('field_class_standing', 'class_standing')->separator(',');
		
		//"options" fields
		//not working yet!
		//$this->addFieldMapping('field_off_campus_location', 'off_campus')->xpath('options/option[@code="Off Campus Location"]');
		
		//this gets the faculty members out of the migration of people into the directory, using the XML info as a key
		$this->addFieldMapping('field_faculty','faculty_members')->xpath('faculty_members/faculty/email')->sourceMigration(array('Individual'));
		
		
		$this->addFieldMapping('uid')->defaultValue('1'); //because I don't like migrated items belonging to Anon.
		
		$this->addUnmigratedDestinations(
			array(
				"status",
				"promote",
				"sticky",
				"revision", //might actually want to add this?
				"log",
				"language",
				"tnid",
				"translate",
				"revision_uid",
				"is_new",
				"comment",
				"totalcount",
				"daycount",
				"timestamp"
			)
		);
    }
    
    function prepareRow($row) {
	    //drush_print_r($row);
	    
	    //just get the HTML out of the XML.
	    $row->description = $row->xml->description->asXML();
	    $row->options = $row->xml->options->option->asXML();
	    drush_print_r($row->options);
	    
	    /*
		    this code handles the time of day that an entry is offered
		    in the originating XML, there's codes to show different combinations,
		    but in Drupal we're doing it as a field with multiple values.
D = Day
E = Evening
W = Weekend
A = Day and Weekend
C = Evening and Weekend
B = Day and Evening
Z = Day, Evening and Weekend
			
			there's probably a more stylish way to do the PHP for this.
			OTOH, this actually works.
		*/
	    $row->time_offered = $row->xml->time_of_day_code;
	    switch ($row->time_offered) {
		    case 'D':
		    	$row->time_offered = "Day";
		    	break; 
		    case 'E':
		    	$row->time_offered = "Evening";
		    	break; 
		    case 'W':
		    	$row->time_offered = "Weekend";
		    	break; 
		    case 'A':
		    	$row->time_offered = "Day,Weekend";
		    	break; 
		    case 'C':
		    	$row->time_offered = "Evening,Weekend";
		    	break; 
		    case 'B':
		    	$row->time_offered = "Day,Evening";
		    	break; 
		    case 'Z':
		    	$row->time_offered = "Day,Evening,Weekend";
		    	break; 
		    default:
		    	$row->time_offered = "";
	    }
	    
	    $min = $row->xml->min_standing;
	    $max = $row->xml->max_standing;
	    switch ($min) {
		    case 'FR': 
		    	switch($max) {
			    	case 'FR':
			    		$row->class_standing = 'FR';
			    	break;
			    	case 'SO':
			    		$row->class_standing = 'FR,SO';
			    	break;
			    	case 'JR':
			    		$row->class_standing = 'FR,SO,JR';
			    	break;
			    	case 'SR':
			    		$row->class_standing = 'FR,SO,JR,SR';
			    	break;
		    	};
		    break;
		    case 'SO': 
		    	switch($max) {
			    	case 'SO':
			    		$row->class_standing = 'SO';
			    	break;
			    	case 'JR':
			    		$row->class_standing = 'SO,JR';
			    	break;
			    	case 'SR':
			    		$row->class_standing = 'SO,JR,SR';
			    	break;
		    	};
		    break;
		    case 'JR': 
		    	switch($max) {
			    	case 'JR':
			    		$row->class_standing = 'JR';
			    	break;
			    	case 'SR':
			    		$row->class_standing = 'JR,SR';
			    	break;
		    	};
		    break;
		    case 'SR': 
		    	$row->class_standing = 'SR';
		    break;
	    } // end switch statement for minimum standing
	    unset($min);
	    unset($max);
	    
	    
    } //end prepareRow
    
}

class CatalogTermMigration extends XMLMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports college catalog term details from XML. (currently only undergrad)');
    	$this->dependencies = array('Catalog');
    	
    	//remember, XML migrations need their fields manually declared!
    	$fields = array(
	    	'offeringid' => t('Offering ID'),
	    	'credits' => t('Credits'),
	    	'entry_code' => t('Entry Code (Open/Closed, etc)'),
	    	'schedule_url' => t('Schedule URL in R25'),
	    	'term' => t('Term Name'),
	    	'term_code' => t('Term Code'),
	    	'conditions' => t('Conditions'),
	    	'crns' => t('CRNs'),
	    );
	    
	    //this will need to be updated for post-Cascade.
	    //$xml_location = 'http://www.evergreen.edu/catalog/2015-16/all.xml';
	    
	    $folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_content') . '/migrations/';
        $xml_location = $folder . 'dummy-quarters.xml';
	    
	    // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/terms/termwrap';
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /positions/position/sourceid.
    $item_ID_xpath = '@termid';
        
        
    	$items_class = new MigrateItemsXML($xml_location, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    	
    	//set which taxonomy vocabulary to use
    	$this->destination = new MigrateDestinationNode('catalog_entry');
    	
    	//the unique id is the URL, I think.
    	
    	//maps a thing
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'sql_map' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'Mapping a thing',
                          )
        ),
        MigrateDestinationFieldCollection::getKeySchema()
      );
      
      $this->destination = new MigrateDestinationFieldCollection(
      'field_terms',
      array('host_entity_type' => 'node')
    );
      
      $this->addFieldMapping('host_entity_id', 'offeringid')->xpath('@offeringid')->sourceMigration('Catalog');
      
      $this->addFieldMapping('field_credits', 'credits')->xpath('term/@credits')->separator(',');
      $this->addFieldMapping('field_entry_code', 'entry_code')->xpath('term/@entry_code');
      $this->addFieldMapping('field_schedule_url', 'schedule_url')->xpath('term/@schedule_url');
      $this->addFieldMapping('field_term_name', 'term')->xpath('term/@term');
      $this->addFieldMapping('field_term_code', 'term_code')->xpath('term/@term_code');
      $this->addFieldMapping('field_conditions', 'conditions')->xpath('term/conditions'); //this might need prepareRow?
      $this->addFieldMapping('field_crns', 'location')->xpath('term/crns/crn');
      
      
      
    	
    }
}