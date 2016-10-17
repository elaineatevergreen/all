<?php
//need a function to implement hook_migrate_api()
function learning_community_directory_migrate_api() {
	return array(
		'api' => 2,
		'groups' => array(
			'sites' => array(
				'title' => t('Site Content'),
			),
		),
		'migrations' => array(
			//site content
			'SiteContent' => array( 
				'class_name' => 'SiteContentMigration',
				'group_name' => 'sites',
			), //end of the SiteContent migration
		), //end of the migrations array
	); //end of the main array
};