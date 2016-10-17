<?php
//need a function to implement hook_migrate_api()
function evergreen_content_migrate_api() {
	return array(
		'api' => 2,
		'groups' => array(
			'sites' => array(
				'title' => t('Sites'),
			),
		),
		'migrations' => array(
			//site content
			'Sections' => array( 
				'class_name' => 'SiteSectionMigration',
				'group_name' => 'sites',
			), //end of the SiteSection migration
			'SectionNav' => array(
				'class_name' => 'SiteSectionNavMigration',
				'group_name' => 'sites',
			),
			'SiteContent' => array( 
				'class_name' => 'SiteContentMigration',
				'group_name' => 'sites',
			), //end of the SiteContent migration
			'SiteFiles' => array( 
				'class_name' => 'FileImportMigration',
				'group_name' => 'sites',
			), //end of the SiteFiles migration
			'News' => array( 
				'class_name' => 'NewsMigration',
				'group_name' => 'sites',
			), //end of the News migration
		), //end of the migrations array
	); //end of the main array
};