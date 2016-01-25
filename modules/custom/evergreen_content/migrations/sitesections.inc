<?php
/**
	* @file
	* Imports site section list with names and long names from CSV
*/

class SiteSectionMigration extends EvergreenMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports site section names/long names from CSV.');
    	
    	$options = array(
	    	'header_rows' => '1',	
    	);
    	
    	//find the correct folder and get the CSV	
    	$folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_content') . '/migrations/';
        $csv_location = $folder . 'sitesections.csv';
    	$this->source = new MigrateSourceCSV($csv_location, array(),$options);
    	
    	//set which taxonomy vocabulary to use
    	$this->destination = new MigrateDestinationTerm('site_sections');
    	
    	//map the CSV to the taxonomy
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'Term name' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'Short site section name (URL)',
                          )
        ),
        MigrateDestinationTerm::getKeySchema()
      );
		
		$this->addFieldMapping('name', 'Term name');
		$this->addFieldMapping('field_long_name', 'Long name');
		
		$this->addUnmigratedDestinations(
			array(
				"description",
				"parent",
				"parent_name",
				"format",
				"weight",
				"path"
				)
		);
		$this->addUnmigratedSources(
			array("Template")
		);
    }
}