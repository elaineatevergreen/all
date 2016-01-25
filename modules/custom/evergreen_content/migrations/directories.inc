<?php
/**
	* @file
	* Imports site content from XML
	* some of this code is cribbed from the Wine migration example.
*/

class IndividualMigration extends XMLMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports individual staff directory from XML.');
    	
    	// There isn't a consistent way to automatically identify appropriate
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'name' => t('full name'),
      'first_name' => t('first name'),
      'last_name' => t('last name'),
      'title' => t('job title'),
      'location' => t('location'), //needs to be massaged into building and room
      'mailstop' => t('mailstop'),
      'email' => t('CAS username'),
      'email_addressable' => t('email address'),
      'phone' => t('phone'),
      'phone_alt' => t('alternative phone'),
      'fax' => t('fax'),
      'url' => t('url'),
      
      /*
	      A single XML element as seen in the directory information.
	      <name>Ackley, Kristina</name><title>Faculty</title><location>Lab I 1011</location><mailstop>LAB 1020</mailstop><email>ackleyk</email><email_addressable>ackleyk@evergreen.edu</email_addressable><phone>3608676020</phone>	      
	  */

    );
    	
    	//find the correct folder and get the XML
    	//currently location created thru Cascade
        //$xml_location = 'http://www.evergreen.edu/directory/xml/people.xml';
        //this is the location that Cascade actually gets it from!
        $xml_location = 'http://adminweb.evergreen.edu/banner/forena/xml/banner.directory.person_export';
        
    // This is the xpath identifying the items to be migrated, relative to the document.
    $item_xpath = '/people/person';
    // This is the xpath relative to the individual items - thus the full xpath of an ID will be /positions/position/sourceid.
    $item_ID_xpath = 'email';
        
    $items_class = new MigrateItemsXML($xml_location, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    	
    	//set which node content type to use
    	$this->destination = new MigrateDestinationNode('directory_individual');
    	
    	//the unique id is the URL, I think.
    	//what does this comment even MEAN? (and I think it's one I wrote.)
    	
    	//maps a thing
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'cas_name' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'CAS name (except WSIPP staff)',
                          )
        ),
        MigrateDestinationNode::getKeySchema()
      );
      
      /*
	      field mappings:
	      field_first_name
	    field_last_name
	    field_job_title
	    field_cas_name
	    field_phone
	    field_alternate_phone
	    field_fax
	    field_email
	    field_mailstop
	    field_building
	    field_building_alt
	    field_room
	    field_location_off_campus
	    #these are in the faculty directory
	    field_headshot
	    field_background
	    field_expertise
	    field_interests
		*/
		
		$this->addFieldMapping('title', 'name')->xpath('name');
		
		
		$this->addFieldMapping('field_job_title', 'title')->xpath('title');
		$this->addFieldMapping('field_cas_name', 'email')->xpath('email');
		
		$this->addFieldMapping('field_website', 'url')->xpath('url');
		
		//email has validation issue (specifically maldonaf @evergreen.edu) addressed in prepareRow
		//validation should be added to adminweb application.
		$this->addFieldMapping('field_email', 'email_addressable');
		
		//phone has validation issues addressed in prepareRow
		$this->addFieldMapping('field_phone', 'phone');
		$this->addFieldMapping('field_alternate_phone', 'phone_alt')->xpath('phone_alt');
		$this->addFieldMapping('field_fax', 'fax')->xpath('fax');
		$this->addFieldMapping('field_mailstop', 'mailstop')->xpath('mailstop');
		
		//Goes through prepareRow to separate first and last name.
		$this->addFieldMapping('field_first_name', 'first_name');
		$this->addFieldMapping('field_last_name', 'last_name');
		
		//location needs to go thru prepareRow.
		//using "building_alt" until I work out bugs with list vs text
		$this->addFieldMapping('field_building_alt', 'building_alt');
		$this->addFieldMapping('field_room', 'room');
		
		$this->addFieldMapping('uid')->defaultValue('1'); //because I don't like migrated items belonging to Anon.
		
		$this->addUnmigratedDestinations(
			array(
				"status",
				"promote",
				"sticky",
				"revision",
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
	    
	    $names = explode(',',$row->xml->name);
	    $row->last_name = trim($names[0]);
	    $row->first_name = trim($names[1]);
	    
	    $row->email_addressable = preg_replace('/\s+/', '', $row->xml->email_addressable);
	    
	    $row->phone = trim($row->xml->phone);
	    if(strlen($row->phone) == 8) {
		    $row->phone = '360-' . $row->phone;
	    };
	    
	    /* buildings
		    Lib
		    CAB
		    Com
		    CRC
		    CUP?
		    Sem
		    Sem II
		    Lab I
		    Lab II
		    Tacoma
		    
		    Issues:
		    Duplicated building names
		    110 Fifth Ave SE, STE 214
WSIPP Box 40999
			Grays Harbor CC
		*/
		
		if(!strpos($row->xml->location,'WSIPP')) {
			$location = explode(' ',$row->xml->location);
			$row->room = array_pop($location);
			if($location[1] == 'I' or $location[1] == 'II') {
				$row->building_alt = implode(' ', $location);
			} else {
				$row->building_alt = $location[0];
			};
		};

    } //end prepareRow
    
} // end individual migration

class FacultyMigration extends XMLMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports faculty information from XML into their directory entry.');
    	
    	//needs the individuals to be added before the faculty info can be added to it.
    	$this->dependencies = array('Individual');
    	
		//this will update the record instead of creating new
    	//important note: in this case, faculty will only be added via the phone directory!
    	$this->systemOfRecord = Migration::DESTINATION;
    	
    	// There isn't a consistent way to automatically identify appropriate
		// "fields" from an XML feed, so we pass an explicit list of source fields
		$fields = array(
			'user_name' => t('CAS username'),
			'expertise' => t('expertise'),
			'interest' => t('interests'),
			'bio' => t('academic degrees'),
			'planning_unit' => t('planning unit'),
			'fields' => t('associated fields'),
      //the contact information exists in the XML, but I'd rather not use it.
      //'name' => t('full name'),
      //'first_name' => t('first name'),
      //'last_name' => t('last name'),
      //'title' => t('job title'),
      //'location' => t('location'), //needs to be massaged into building and room
      //'mailstop' => t('mailstop'),
      //'email_addressable' => t('email address'),
      //'phone' => t('phone'),
      //'phone_alt' => t('alternative phone'),
      //'fax' => t('fax'),
      //but I'm keeping url just in case it needs to be overwritten?
      		'url' => t('url'),
      
      
      /*
	      A single XML element as seen in the faculty directory information.
	      <faculty user_name="ackleyk"><name>Ackley, Kristina</name><expertise>Native American studies</expertise><interest>Indigenous people's studies, museum studies, Native American studies, research methods, U.S. history</interest><bio>B.A., History and Political Science, University of Wisconsin-Madison, 1993; M.A., American Indian Law and Policy, University of Arizona, 1995; Ph.D., American Studies, State University of New York at Buffalo, 2001.</bio><planning_unit>NP</planning_unit><title>Faculty</title><mail_stop>LAB 1020</mail_stop><email>ackleyk@evergreen.edu</email><location>Lab I 1011</location><phone>(360) 867-6020</phone><fields><field stub="culturalstudies">Cultural Studies</field><field stub="history">History</field><field stub="ethnicstudies">Ethnic Studies</field></fields></faculty>	      
	  */

		); //end fields listing
    	
    	//find the correct folder and get the XML
    	//currently location created thru Cascade
        $xml_location = 'http://www.evergreen.edu/faculty/all.xml';
        //this is the location that Cascade actually gets it from!
        //although at the moment I'm getting a 404 error?
        //$xml_location = 'http://adminweb.evergreen.edu/banner/public/program/faculty/faculty.xml';
        
		// This is the xpath identifying the items to be migrated, relative to the document.
		$item_xpath = '/instructors/faculty';
		// This is the xpath relative to the individual items - thus the full xpath of an ID will be /positions/position/sourceid.
		$item_ID_xpath = '@user_name';
        
		$items_class = new MigrateItemsXML($xml_location, $item_xpath, $item_ID_xpath);
		$this->source = new MigrateSourceMultiItems($items_class, $fields);
    	
    	//set which node content type to use
    	$this->destination = new MigrateDestinationNode('directory_individual');
    	
    	//the unique id is the URL, I think.
    	//what does this comment even MEAN? (and I think it's one I wrote.)
    	
    	//maps a thing
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'cas_name' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'CAS name',
                          )
        ),
        MigrateDestinationNode::getKeySchema()
      );
      
      /*
	      field mappings:
		#this should be the unique map?
	    field_cas_name
	    #these are in the faculty directory
	    field_headshot
	    field_background
	    field_expertise
	    field_interests
	    
	    #still need to add: Planning Unit, Fields (not the same as the catalog's fields of study!)
		*/
		
		//$this->addFieldMapping('title', 'name')->xpath('name');
		
		//I'm not sure which of these is right. :(
		$this->addFieldMapping('nid', 'user_name')->xpath('@user_name')->sourceMigration('Individual');
		//$this->addFieldMapping('nid', 'user_name')->sourceMigration('Individual');
		
		//need to create node or stub or something if the person isn't in the phone directory
		
		//is this how to do this?
		$this->addFieldMapping('field_cas_name', 'user_name')->xpath('@user_name');
		
		//fields specific to faculty
		$this->addFieldMapping('field_background', 'bio')->xpath('bio');
		$this->addFieldMapping('field_expertise', 'expertise')->xpath('expertise');
		$this->addFieldMapping('field_interests', 'interest')->xpath('interest');
		
		//for some reason the source XML contains two identical URL elements? which makes Migrate sad.
		$this->addFieldMapping('field_website', 'url')->xpath('url');
		
		$this->addFieldMapping('field_is_faculty')->defaultValue('1'); //makes sure that anyone in this file is set as faculty.
		$this->addFieldMapping('uid')->defaultValue('1'); //because I don't like migrated items belonging to Anon.
		
		$this->addUnmigratedDestinations(
			array(
				"status",
				"promote",
				"sticky",
				"revision",
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
	    
	    $names = explode(',',$row->xml->name);
	    $row->last_name = trim($names[0]);
	    $row->first_name = trim($names[1]);
	    
	    $row->email_addressable = preg_replace('/\s+/', '', $row->xml->email_addressable);
	    
	    $row->phone = trim($row->xml->phone);
	    if(strlen($row->phone) == 8) {
		    $row->phone = '360-' . $row->phone;
	    };
	    
	    /* buildings
		    Lib
		    CAB
		    Com
		    CRC
		    CUP?
		    Sem
		    Sem II
		    Lab I
		    Lab II
		    Tacoma
		    
		    Issues:
		    Duplicated building names
		    110 Fifth Ave SE, STE 214
WSIPP Box 40999
			Grays Harbor CC
		*/
		
		if(!strpos($row->xml->location,'WSIPP')) {
			$location = explode(' ',$row->xml->location);
			$row->room = array_pop($location);
			if($location[1] == 'I' or $location[1] == 'II') {
				$row->building_alt = implode(' ', $location);
			} else {
				$row->building_alt = $location[0];
			};
		};

    } //end prepareRow
    
} //end faculty migration

class OfficeMigration extends XMLMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports office directory from XML.');
    	
    	//needs the individuals to be added before people can be added to an office.
    	$this->dependencies = array('Individual');
    	
    	// There isn't a consistent way to automatically identify appropriate
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'name' => t('office name'),
      'location' => t('location'), //needs to be massaged into building and room
      'mailstop' => t('mailstop'),
      //'email' => t('CAS username'),
      'email_addressable' => t('email address'),
      'phone' => t('phone'),
      'phone_alt' => t('alternative phone'),
      'fax' => t('fax'),
      'url' => t('url'),
      'members' => t('members'),
      
      /*
	      A single XML element as seen in the directory information.
	      <name>Ackley, Kristina</name><title>Faculty</title><location>Lab I 1011</location><mailstop>LAB 1020</mailstop><email>ackleyk</email><email_addressable>ackleyk@evergreen.edu</email_addressable><phone>3608676020</phone>	      
	  */

    );
    	
    	//find the correct folder and get the XML
    	//currently location created thru Cascade
        //$xml_location = 'http://www.evergreen.edu/directory/xml/offices.xml';
        //this is the location that Cascade actually gets it from!
        $xml_location = 'http://adminweb.evergreen.edu/banner/forena/xml/banner.directory.office_export';
        
    // This is the xpath identifying the items to be migrated, relative to the document.
    $item_xpath = '/offices/office';
    // This is the xpath relative to the individual items - thus the full xpath of an ID will be /positions/position/sourceid.
    $item_ID_xpath = '@id';
        
    $items_class = new MigrateItemsXML($xml_location, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    	
    	//set which node content type to use
    	$this->destination = new MigrateDestinationNode('directory_office');

    	
    	//maps a thing
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'id' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'Office ID generated out of Banner (?)',
                          )
        ),
        MigrateDestinationNode::getKeySchema()
      );
      
      /*
	      field mappings:
	    field_phone
	    field_alternate_phone
	    field_fax
	    field_email
	    field_mailstop
	    field_building
	    field_building_alt
	    field_room
	    field_location_off_campus
	    field_members

		*/
		
		//clean up on aisle "space at the front of a name.
		//I still don't quite know what to do with an entirely empty item
		$this->addFieldMapping('title', 'name');

		$this->addFieldMapping('field_websites', 'url')->xpath('url');
		
		//email has validation issue (specifically maldonaf @evergreen.edu) addressed in prepareRow
		//validation should be added to adminweb application.
		$this->addFieldMapping('field_email', 'email_addressable');
		
		//phone has validation issues addressed in prepareRow
		$this->addFieldMapping('field_phone', 'phone');
		$this->addFieldMapping('field_alternate_phone', 'phone_alt')->xpath('phone_alt');
		$this->addFieldMapping('field_fax', 'fax')->xpath('fax');
		$this->addFieldMapping('field_mailstop', 'mailstop')->xpath('mailstop');
		
		//location needs to go thru prepareRow.
		//using "building_alt" until I work out bugs with list vs text
		$this->addFieldMapping('field_building_alt', 'building_alt');
		$this->addFieldMapping('field_room', 'room');
		
		//this gets the office members out of the migration of people into the directory, using the XML info as a key
		$this->addFieldMapping('field_members','members')->xpath('members/people/person/email')->sourceMigration(array('Individual'));
		
		$this->addFieldMapping('uid')->defaultValue('1'); //because I don't like migrated items belonging to Anon.
		
		$this->addUnmigratedDestinations(
			array(
				"status",
				"promote",
				"sticky",
				"revision",
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
	    
	    //clean up spaces at the front of office names
	    $row->name = trim($row->xml->name);
	    
	    //remove spaces from emails (!!!!)
	    $row->email_addressable = preg_replace('/\s+/', '', $row->xml->email_addressable);
	    
	    //add area code. (why isn't this check in the actual application?)
	    $row->phone = trim($row->xml->phone);
	    if(strlen($row->phone) == 8) {
		    $row->phone = '360-' . $row->phone;
	    };
	    
	    /* buildings
		    Lib
		    CAB
		    Com
		    CRC
		    CUP?
		    Sem
		    Sem II
		    Lab I
		    Lab II
		    Tacoma
		    
		    Issues:
		    Duplicated building names
		    110 Fifth Ave SE, STE 214
WSIPP Box 40999
			Grays Harbor CC
		*/
		
		if(!strpos($row->xml->location,'WSIPP')) {
			$location = explode(' ',$row->xml->location);
			$row->room = array_pop($location);
			if($location[1] == 'I' or $location[1] == 'II') {
				$row->building_alt = implode(' ', $location);
			} else {
				$row->building_alt = $location[0];
			};
		};

    } //end prepareRow
    
} // end individual migration