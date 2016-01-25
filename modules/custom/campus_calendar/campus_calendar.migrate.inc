<?php
//need a function to implement hook_migrate_api()
function campus_calendar_migrate_api() {
	return array(
		'api' => 2,
		'groups' => array(
			'events' => array(
				'title' => t('Events'),
			),
		), //end of the groups array
		'migrations' => array(
			'Categories' => array( 
				'class_name' => 'CategoryMigration',
				'group_name' => 'events',
			), //end of the Categories migration
		), //end of the migrations array
	); //end of the main array
};