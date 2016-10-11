<?php


class EventMigration extends EvergreenMigration {
	public function __construct($arguments) {
    	parent::__construct($arguments);
    	
    	$this->description = t('Imports individual events from CSV.');
    	
    	$options = array(
	    	'header_rows' => '1',	
    	);
    	
    	//find the correct folder and get the CSV	
    	$folder = DRUPAL_ROOT . '/' .  drupal_get_path('module', 'evergreen_migration') . '/migrations/';
        $csv_location = $folder . 'events.csv';
    	$this->source = new MigrateSourceCSV($csv_location, array(),$options);
    	
    	//set which taxonomy vocabulary to use
    	$this->destination = new MigrateDestinationNode('event');
    	
    	//map the CSV to the taxonomy
    	$this->map = new MigrateSQLMap($this->machineName,
        array(
          'nid' => array('type' => 'varchar',
                           'length' => 255,
                           'not null' => TRUE,
                           'description' => 'nid from collab.evergreen.edu/calendar',
                          )
        ),
        MigrateDestinationTerm::getKeySchema()
      );
		
		$this->addFieldMapping('title', 'title');
		$this->addFieldMapping('body', 'body');
		$this->addFieldMapping('body:format')->defaultValue("basic_tags");
		$this->addFieldMapping('field_academic_quarter', 'quarter');
		$this->addFieldMapping('field_building', 'building');
		$this->addFieldMapping('field_room', 'room');
		$this->addFieldMapping('field_sponsored_by', 'sponsor');
		$this->addFieldMapping('promote', 'promote');
		
		$this->addFieldMapping('log')
			->defaultValue('imported from collab.evergreen.edu/calendar');
		//eventually this should belong to a specific user in Cascade...
		$this->addFieldMapping('uid')->defaultValue('1'); //because I don't like migrated items belonging to Anon.
		$this->addFieldMapping('status')->defaultValue('1'); //does this cause Workbench issues?
		
		/* date-related fields */
		$this->addFieldMapping('created', 'created');
		$this->addFieldMapping('field_event_date', 'Start Date');
		$this->addFieldMapping('field_event_date:to', 'End Date');
		$this->addFieldMapping('field_event_date:rrule', 'repeat');


		
		$this->addUnmigratedDestinations(
			array(
				
				)
		);
    }
}