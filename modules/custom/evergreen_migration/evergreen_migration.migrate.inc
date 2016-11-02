<?php
//need a function to implement hook_migrate_api()
function evergreen_migration_migrate_api() {
	return array(
		'api' => 2,
		'groups' => array(
			'sites' => array(
				'title' => t('Site Sections'),
			),
			'customContent' => array(
				'title' => t('Other Content Types'),
			),
			'files' => array(
				'title' => t('Files'),
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
				'group_name' => 'files',
			), //end of the SiteFiles migration
			'News' => array( 
				'class_name' => 'NewsMigration',
				'group_name' => 'customContent',
			), //end of the News migration
			'Fields' => array(
				'class_name' => 'FieldsOfStudyMigration',
				'group_name' => 'customContent',
			),
			/*'Headshots' => array(
				'class_name' => 'HeadshotMigration',
				'group_name' => 'files',
			),*/
		), //end of the migrations array
	); //end of the main array
};