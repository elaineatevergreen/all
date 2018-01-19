<?php

 /**
 * Implements hook_migrate_api().
 */
 function evergreen_archives_migrate_api() {
 	return array(
 		'api' => 2,
 		'groups' => array(
 			'archives' => array(
 				'title' => t('Archives'),
 			),
 		),
 		'migrations' => array(
 			'ArchivesAccessions' => array(
 				'class_name' => 'AccessionsMigration',
 				'group_name' => 'archives',
 			),
 			'ArchivesNames' => array(
 				'class_name' => 'NamesMigration',
 				'group_name' => 'archives',
 			),
 			'ArchivesSubjects' => array(
 				'class_name' => 'SubjectsMigration',
 				'group_name' => 'archives',
 			),
 			'ArchivesResources' => array(
 				'class_name' => 'ResourcesMigration',
 				'group_name' => 'archives',
 			),
 		),
 	);
 }