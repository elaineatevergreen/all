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
		
		//stolen from the migration examples, as usual
		$this->addFieldMapping('field_background_image', 'Background');
    // The file_class determines how the 'image' value is interpreted, and what
    // other options are available. In this case, MigrateFileUri indicates that
    // the 'image' value is a URI.
    $this->addFieldMapping('field_background_image:file_class')
         ->defaultValue('MigrateFileUri');
    // Here we specify the directory containing the source files.
    $this->addFieldMapping('field_background_image:source_dir')
         ->defaultValue(DRUPAL_ROOT . '/sites/default/files/backgrounds');
    $this->addFieldMapping('field_background_image:destination_dir')
    	->defaultValue('public://images/backgrounds');
    $this->addFieldMapping('field_background_image:file_replace')
         ->defaultValue(FILE_EXISTS_REUSE);




		
		$this->addUnmigratedDestinations(
			array(
				"description",
				"parent",
				"parent_name",
				"format",
				"weight",
				"path",
				"field_section_contact_info",
				"field_background_image:title",
				"field_background_image:alt",
				"field_background_image:urlencode",
				"pathauto"
				)
		);
    }
}