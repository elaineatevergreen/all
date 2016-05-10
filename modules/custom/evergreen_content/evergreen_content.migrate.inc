<?php
//need a function to implement hook_migrate_api()
function evergreen_content_migrate_api() {
	return array(
		'api' => 2,
		'groups' => array(
			'sites' => array(
				'title' => t('Sites'),
			),
			'directories' => array(
				'title' => t('Directories'),
			),
			'catalog' => array(
				'title' => t('Catalog'),
			),
		), //end of the groups array
		'migrations' => array(
			//site content
			'SiteSections' => array( 
				'class_name' => 'SiteSectionMigration',
				'group_name' => 'sites',
			), //end of the SiteSection migration
			'SiteContent' => array( 
				'class_name' => 'SiteContentMigration',
				'group_name' => 'sites',
			), //end of the SiteContent migration
			'News' => array( 
				'class_name' => 'NewsMigration',
				'group_name' => 'sites',
			), //end of the News migration
			
			//directories
			'Individual' => array( 
				'class_name' => 'IndividualMigration',
				'group_name' => 'directories',
			), //end of the individual directory migration 
			'Faculty' => array( 
				'class_name' => 'FacultyMigration',
				'group_name' => 'directories',
			), //end of the individual directory migration 
			'Offices' => array( 
				'class_name' => 'OfficeMigration',
				'group_name' => 'directories',
			), //end of the office directory migration 
			
			//catalog
			'Catalog' => array( 
				'class_name' => 'CatalogMigration',
				'group_name' => 'catalog',
			),
			'CatalogTerms' => array( 
				'class_name' => 'CatalogTermMigration',
				'group_name' => 'catalog',
			),

		), //end of the migrations array
	); //end of the main array
};