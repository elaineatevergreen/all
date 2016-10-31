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
    );
    	
    	//find the correct location and get the XML
    	$folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_migration') . '/migrations/';
        $xml_location = $folder . 'fields-simplified.xml';

        
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
		
		$this->addFieldMapping('name', 'title')->xpath('title');
		
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
		
		$this->addFieldMapping('field_related_subjects_directory', 'directorycode')->xpath('directorycode');
		
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
				
			)
		);
    }
    
    function prepareRow($row) {
	    //drush_print_r($row);
	    
	    $row->intro = $row->xml->intro->asXML();
	    $row->after = $row->xml->after->asXML();
	    $row->resources = $row->xml->resources->asXML();
	    $row->sample = $row->xml->sample->asXML();
	    $row->projects = $row->xml->projects->asXML();
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

