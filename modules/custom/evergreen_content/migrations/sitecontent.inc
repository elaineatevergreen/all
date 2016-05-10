<?php
/**
	* @file
	* Imports site content from XML
	* some of this code is cribbed from the Wine migration example.
*/

class SiteContentMigration extends XMLMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports site content from XML.');
    	
    	// There isn't a consistent way to automatically identify appropriate
    // "fields" from an XML feed, so we pass an explicit list of source fields
    $fields = array(
      'title' => t('title'),
      'primary' => t('primary'),
      'secondary' => t('secondary'),
      'sitesection' => t('sitesection'),
      'url' => t('url'),
      'intro'=> t('intro') //yes, even tho this isn't even a proper element in the XML
    );
    	
    	//find the correct folder and get the XML
    	//I would like to figure out how to combine old and new content in a single XML file
    	//or how to iterate over two XML files?	
    	//$folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_content') . '/migrations/';
        //$xml_location = $folder . 'all-content-simple-combined.xml';
        $xml_location = 'http://www.evergreen.edu/_inc/inventory/combined.xml';
        
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
    	
    	//map the CSV to the taxonomy
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'url' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'URL of the page in Cascade',
                          )
        ),
        MigrateDestinationTerm::getKeySchema()
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
		
		//the primary and secondary content have to go through prepareRow to appear properly.
		$this->addFieldMapping('body', 'primary');
		$this->addFieldMapping('body:format')->defaultValue('basic_tags');
		$this->addFieldMapping('field_secondary_content','secondary');
		$this->addFieldMapping('field_secondary_content:format')->defaultValue('basic_tags');
		
		//don't actually do this right now, since I can't figure out how to remove the intro from primary content
		//$this->addFieldMapping('field_intro','intro');
		
		//site section seems to work as is without any need to use sourcemigration
		//which is weird but I won't argue.
		//we get the site section by grabbing the 1st chunk of the URL in prepareRow
		$this->addFieldMapping('field_site_section','sitesection');
		
		//this needs to have the first slash removed to work properly!
		$this->addFieldMapping('path','url');
		
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
	    
	    //generate the intro paragraph
	    //some issues with those few intro paragraphs that have 
	    //this doesn't do the character entities correctly
	    $row->intro = html_entity_decode(str_replace("&amp;", "&", $row->xml->intro));
	    
	    //this converts all the content of primary and secondary into actual HTML
	    //need to find a way to remove the intro paragraph!
	    //things that need to be stripped
	    $replace[] = array('//evergreen.edu - old design','http://evergreen.edu');
	    //$replace[] = array('//evergreen.edu','http://evergreen.edu');
	    $replace[] = array('site://','http://');
	    $row->primary = str_replace("//evergreen.edu - old design","http://evergreen.edu",str_replace("&amp;", "&", $row->xml->primary->asXML()));
	    $row->secondary = str_replace("&amp;", "&", $row->xml->secondary->asXML());
	    
	    //strip the first slash out of the url
	    //for some reason this needs to go AFTER the HTML/XML stuff.
	    $alteredURL = $row->xml->url;
	    $alteredURL = substr($alteredURL, 1);
	    
	    $row->sitesection = substr($alteredURL,0,strpos($alteredURL,'/'));
	    
	    $row->url = $alteredURL;
	    
	    //drush_print_r($row);
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
      'startdate' => t('startdate'),
      'primary' => t('primary'),
      'summary' => t('summary'),
      'url' => t('url'),
      'featureimage' => t('featureimage'),
    );
    	
    	//find the correct folder and get the XML
    	//I would like to figure out how to combine old and new content in a single XML file
    	//or how to iterate over two XML files?	
    	//$folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_content') . '/migrations/';
        //$xml_location = $folder . 'all-content-simple-combined.xml';
        $xml_location = 'http://www.evergreen.edu/news/inventory.xml';
        
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
        MigrateDestinationTerm::getKeySchema()
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
		
		$this->addFieldMapping('created', 'startdate')->xpath('startdate');
		
		//the primary content and blurb have to go through prepareRow to appear properly.
		$this->addFieldMapping('body', 'primary');
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
	    
	    //generate the intro paragraph
	    //some issues with those few intro paragraphs that have 
	    //this doesn't do the character entities correctly
	    $row->intro = html_entity_decode(str_replace("&amp;", "&", $row->xml->intro));
	    
	    //this converts all the content of primary and secondary into actual HTML
	    //need to find a way to remove the intro paragraph!
	    //things that need to be stripped
	    $replace[] = array('//evergreen.edu - old design','http://evergreen.edu');
	    //$replace[] = array('//evergreen.edu','http://evergreen.edu');
	    $replace[] = array('site://','http://');
	    $row->primary = str_replace("//evergreen.edu - old design","http://evergreen.edu",str_replace("&amp;", "&", $row->xml->primary->asXML()));
	    $row->summary = str_replace("&amp;", "&", $row->xml->summary->asXML());
	    
	    //strip the first slash out of the url
	    //for some reason this needs to go AFTER the HTML/XML stuff.
	    $alteredURL = $row->xml->url;
	    $alteredURL = substr($alteredURL, 1);
	    
	    $row->sitesection = substr($alteredURL,0,strpos($alteredURL,'/'));
	    
	    $row->url = $alteredURL;
	    
	    //drush_print_r($row);
    } //end prepareRow
    
}