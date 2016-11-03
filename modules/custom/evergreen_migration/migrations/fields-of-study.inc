<?php
	
include_once("functions.inc");
	
	/* cribbed from my work on SiteContentMigration */

class FieldsOfStudyMigration extends XMLMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports site content from XML.');
    	
    	// There isn't a consistent way to automatically identify appropriate
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      
      /*
      'created' => t('created'),
      'changed' => t('changed'),
      'lastmodifiedby' => t('lastmodifiedby'),
      'metadescription' => t('metadescription'),
      'url' => t('url'),
      */
      'intro'=> t('intro'),
      'sample'=>t('sample'),
      'after'=>t('after'),
      'resources'=>t('resources'),
      'projects'=>t('projects'),
      'directorycode'=>t('directorycode'),
      'facultybios'=>t('facultybios'),
    );
    	
    	//find the correct location and get the XML
    	$folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_migration') . '/migrations/';
        $xml_location = $folder . 'fields-migration-combined.xml';
		
        
        // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/pages/page';
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /positions/position/sourceid.
    $item_ID_xpath = 'title';
        
        
    $items_class = new MigrateItemsXML($xml_location, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    	
    	//set which taxonomy vocabulary to use
    	$this->destination = new MigrateDestinationTerm('fields_of_study');
    	
    	//the unique id is the URL, I think.
    	
    	//map the CSV to the taxonomy
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'title' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'Title of this field of study',
                          )
        ),
        MigrateDestinationTerm::getKeySchema()
      );
      
      /*
	      field mappings.
		*/
		
		$this->addFieldMapping('name', 'title');
		/*
			I just can't get the hierarchy working!
			if(!is_null('parentfield')) {
			$this->addFieldMapping('parent_name', 'parentfield');
		};*/
		
		$this->addFieldMapping('field_related_subjects_directory', 'directorycode')->xpath('directorycode');
		
		/* all of these text fields need cleanup before they can be imported */
		$this->addFieldMapping('description', 'intro')->callbacks('tidyBlobs');
		$this->addFieldMapping('format')->defaultValue('basic_tags');
		
		$this->addFieldMapping('field_after_graduation', 'after')->callbacks('tidyBlobs');
		$this->addFieldMapping('field_after_graduation:format')->defaultValue('basic_tags');
		
		$this->addFieldMapping('field_facilities_resources', 'resources')->callbacks('tidyBlobs');
		$this->addFieldMapping('field_facilities_resources:format')->defaultValue('basic_tags');
		
		$this->addFieldMapping('field_sample_program_description', 'sample')->callbacks('tidyBlobs');
		$this->addFieldMapping('field_sample_program_description:format')->defaultValue('basic_tags');
		
		$this->addFieldMapping('field_recent_student_projects', 'projects')->callbacks('tidyBlobs');
		$this->addFieldMapping('field_recent_student_projects:format')->defaultValue('basic_tags');
		
		$this->addFieldMapping('field_faculty_bios', 'facultybios')->callbacks('tidyBlobs');
		$this->addFieldMapping('field_faculty_bios:format')->defaultValue('basic_tags');
		
		/*
		$this->addFieldMapping('title', 'title')->xpath('title');
		
		$this->addFieldMapping('created', 'created')->xpath('created');
		$this->addFieldMapping('changed', 'changed')->xpath('changed');
		
		$this->addFieldMapping('metatag_description', 'metadescription')->xpath('metadescription');
		$this->addFieldMapping('metatag_og:description', 'metadescription')->xpath('metadescription');
		$this->addFieldMapping('metatag_twitter:description', 'metadescription')->xpath('metadescription');
		
		$this->addFieldMapping('uid')->defaultValue('1'); //because I don't like migrated items belonging to Anon, and I can't match up with Cascade users. 
		
		$this->addFieldMapping('log','changelog');
		*/
		
		$this->addUnmigratedDestinations(
			array(
				"parent",
				"parent_name",
				"weight",
				"field_related_subjects_directory:source_type",
				"field_related_subjects_directory:create_term",
				"field_related_subjects_directory:ignore_case",
				"field_sample_program",
				"path",
				"pathauto"
			)
		);
    }
    
    function prepareRow($row) {
	    //drush_print_r($row);
	    
	    //title case term name and parent term name
	    $row->title = strtolower($row->xml->title);
	    //$row->parentfield = ucwords($row->xml->parentfield);
	    
	    //extract complex HTML
	    $row->intro = $row->xml->intro->asXML();
	    $row->after = $row->xml->after->asXML();
	    $row->resources = $row->xml->resources->asXML();
	    $row->sample = $row->xml->sample->asXML();
	    $row->projects = $row->xml->projects->asXML();
	}
	
	//if a parent term doesn't exist yet (this happens about half a dozen times), create a stub!
   /* function createStub($migration, array $source_id) {
    	$term = new stdClass();
		$term->name = $source_id[0];
		$term->vocabulary_machine_name = 'fields_of_study';
		taxonomy_term_save($term);
		if (isset($term->tid)) {
			return array($term->tid);
    	}
		else {
			return FALSE;
    	}
  	}*/
  	
  	public function createStub(Migration $migration, array $source_id) {
    	print_r($source_id); // This never fires
		static $vid = NULL;
		$vocab = taxonomy_vocabulary_machine_name_load('fields_of_study');
		$vid = $vocab->vid;
		$term = (object) array(
			'vid' => $vid,
			'vocabulary_machine_name' => 'fields_of_study',
			'name' => $source_id[0],
		);
		taxonomy_term_save($term);
		return array($term->name);
  	}
    
    /*function prepareRow($row) {
	    //drush_print_r($row);
	    
	    //generate the intro paragraph
	    //some issues with those few intro paragraphs that have 
	    //this doesn't do the character entities correctly
	    //not actually using this (yet), partially because I'm not (yet) stripping the intro paragraph from primary
	    $row->intro = html_entity_decode(str_replace("&amp;", "&", $row->xml->intro));
	    
		  
	    //gets the XML out of the content fields (can't do this in tidyBlobs for some reason?
	    $row->primary = $row->xml->primary->asXML();
	    $row->secondary = $row->xml->secondary->asXML();
	    
	    //strip the first slash out of the url
	    $alteredURL = $row->xml->url;
	    $alteredURL = substr($alteredURL, 1);
	    
	    //the site section is the first part of the URL.
	    $row->sitesection = substr($alteredURL,0,strpos($alteredURL,'/'));
	    
	    //if the page is a home page, set the URL to be the site section shortname.
	    if(substr($alteredURL, -4) == 'home') { $alteredURL = substr($alteredURL, 0, -5); };
	    
	    //then set the url
	    $row->url = $alteredURL;
	    
	    
	    
	    $row->changelog = "Imported via Migrate, Fall 2016. Last updated in Cascade Server on " . $row->xml->changed . " by " . $row->xml->lastmodifiedby . ".";

    } //end prepareRow */
    

    
};

