<?php
/**
	* @file
	* Imports site content from XML
	* some of this code is cribbed from the Wine migration example.
*/

include_once("functions.inc");

class SiteContentMigration extends XMLMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports site content from XML.');
    	
    	// There isn't a consistent way to automatically identify appropriate
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'created' => t('created'),
      'changed' => t('changed'),
      'lastmodifiedby' => t('lastmodifiedby'),
      'metadescription' => t('metadescription'),
      'primary' => t('primary'),
      'secondary' => t('secondary'),
      'sitesection' => t('sitesection'),
      'url' => t('url'),
      'intro'=> t('intro') //yes, even tho this isn't even a proper element in the XML
    );
    	
    	//find the correct location and get the XML
    	//use the local location post-migration so that there isn't a timeout.
    	$folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_migration') . '/migrations/';
        $xml_location = $folder . 'combined.xml';
        //note that if this is being run directly on sobek, then sobek needs real DNS
        //OR we go back to the previously commented method
        //$xml_location = 'http://www.evergreen.edu/_inc/inventory/combined.xml';
        
        // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/pages/page';
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /positions/position/sourceid.
    $item_ID_xpath = 'url';
        
        
    $items_class = new MigrateItemsXML($xml_location, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    	
    	//set which taxonomy vocabulary to use
    	$this->destination = new MigrateDestinationNode('basic_page');
    	
    	//the unique id is the URL, I think.
    	
    	//
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'url' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'URL of the page in Cascade',
                          )
        ),
        MigrateDestinationNode::getKeySchema()
      );
      
      /*
	      field mappings:
	      - url (path)
	      - title (title)
	      - sitesection (site section short name)
	      - can field_intro be inferred from the first/class="intro" paragraph of primary?
	      - primary (body)
	      - secondary (field_secondary_content)
		*/
		
		$this->addFieldMapping('title', 'title')->xpath('title');
		
		$this->addFieldMapping('created', 'created')->xpath('created');
		$this->addFieldMapping('changed', 'changed')->xpath('changed');
		
		$this->addFieldMapping('metatag_description', 'metadescription')->xpath('metadescription');
		$this->addFieldMapping('metatag_og:description', 'metadescription')->xpath('metadescription');
		$this->addFieldMapping('metatag_twitter:description', 'metadescription')->xpath('metadescription');
		
		//the primary and secondary content have to go through prepareRow to appear properly.
		$this->addFieldMapping('body', 'primary')->callbacks('tidyBlobs');
		$this->addFieldMapping('body:format')->defaultValue('basic_tags');
		$this->addFieldMapping('field_secondary_content','secondary')->callbacks('tidyBlobs');
		$this->addFieldMapping('field_secondary_content:format')->defaultValue('basic_tags');
		
		//don't actually do this right now, since I can't figure out how to remove the intro from primary content
		$this->addFieldMapping('field_intro','intro')->xpath('intro');
		
		//site section seems to work as is without any need to use sourcemigration
		//which is weird but I won't argue.
		//we get the site section by grabbing the 1st chunk of the URL in prepareRow
		$this->addFieldMapping('field_site_section','sitesection');
		
		//this needs to have the first slash removed to work properly!
		$this->addFieldMapping('path','url');
		//and this way it doesn't also create a pathauto version
		$this->addFieldMapping('pathauto')->defaultValue('0');
		
		$this->addFieldMapping('uid')->defaultValue('1'); //because I don't like migrated items belonging to Anon, and I can't match up with Cascade users. 
		
		$this->addFieldMapping('log','changelog');
		
		$this->addUnmigratedDestinations(
			array(
				"status",
				"promote",
				"sticky",
				"revision",
				"language",
				"tnid",
				"translate",
				"revision_uid",
				"is_new",
				"body:summary",
				"field_site_section:source_type",
				"field_site_section:create_term",
				"field_site_section:ignore_case",
				"comment",
				"totalcount",
				"daycount",
				"timestamp"
			)
		);
    }
    
    function prepareRow($row) {
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

    } //end prepareRow

    
};

class NewsMigration extends XMLMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports press releases (news items) from XML.');
    	
    	// There isn't a consistent way to automatically identify appropriate
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'created' => t('created'),
      'primary' => t('primary'),
      'summary' => t('summary'),
      'url' => t('url'),
      'featureimage' => t('featureimage'),
    );
    	
    	//find the correct folder and get the XML
    	//I would like to figure out how to combine old and new content in a single XML file
    	//or how to iterate over two XML files?	
    	$folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_migration') . '/migrations/';
        $xml_location = $folder . 'news.xml';
        //$xml_location = 'http://www.evergreen.edu/news/inventory.xml';
        
        // This is the xpath identifying the items to be migrated, relative to the
    // document.
    $item_xpath = '/pages/page';
    // This is the xpath relative to the individual items - thus the full xpath
    // of an ID will be /positions/position/sourceid.
    $item_ID_xpath = 'url';
        
        
    $items_class = new MigrateItemsXML($xml_location, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    	
    	//set which node type to use
    	$this->destination = new MigrateDestinationNode('article');
    	
    	//the unique id is the URL, I think.
    	
    	//map the CSV to the taxonomy
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'url' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'URL of the page in Cascade',
                          )
        ),
        MigrateDestinationNode::getKeySchema()
      );
      
      /*
	      field mappings:
	      - url (path)
	      - title (title)
	      - sitesection (site section short name)
	      - can field_intro be inferred from the first/class="intro" paragraph of primary?
	      - primary (body)
	      - secondary (field_secondary_content)
		*/
		
		$this->addFieldMapping('title', 'title')->xpath('title');
		
		$this->addFieldMapping('created', 'created')->xpath('created');
		
		//the primary content and blurb have to go through prepareRow to appear properly.
		$this->addFieldMapping('body', 'primary')->callbacks('tidyBlobs');
		$this->addFieldMapping('body:format')->defaultValue('basic_tags');
		$this->addFieldMapping('field_blurb','summary');
		
		//featured image
		$this->addFieldMapping('field_image', 'featureimage')->xpath('featureimage');
		

		/* site set by default for news items */
		$this->addFieldMapping('field_site_section')->defaultValue('news');
		$this->addFieldMapping('field_byline')->defaultValue('Evergreen Communications Office');
		
		//this needs to have the first slash removed to work properly!
		$this->addFieldMapping('path','url');
		$this->addFieldMapping('pathauto')->defaultValue('0');
		
		//eventually this should belong to a specific user in Cascade...
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
				"body:summary",
				"field_site_section:source_type",
				"field_site_section:create_term",
				"field_site_section:ignore_case",
				"comment",
				"totalcount",
				"daycount",
				"timestamp"
			)
		);
    }
    
    function prepareRow($row) {
	    //drush_print_r($row);
	    
	    $row->primary = $row->xml->primary->asXML();
	    $row->summary = str_replace("&amp;", "&", $row->xml->summary->asXML());
	    
	    //strip the first slash out of the url
	    $alteredURL = $row->xml->url;
	    $alteredURL = substr($alteredURL, 1);
	    $row->url = $alteredURL;
	    
	    $row->sitesection = substr($alteredURL,0,strpos($alteredURL,'/'));

    } //end prepareRow
    
}



