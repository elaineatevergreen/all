<?php
/**
 * @file
 * Migration for Names schema data. 
 */

class SubjectsMigration extends ArchivesMigration {

	public function __construct($arguments) {
		parent::__construct($arguments);

		$this->description = t('Import subjects information from the Archives database.');

		//Create the source object
		$query = Database::getConnection('default', 'for_migration')
			->select('Subjects', 's');

		$query->leftJoin('ArchDescriptionSubjects', 'a', 'a.subjectId=s.subjectId');

	    $query->fields('s', array('subjectId', 'subjectTerm', 'subjectTermType', 'subjectSource', 'subjectScopeNote'));
		$query->fields('a', array('archDescriptionSubjectsId', 'accessionId', 'resourceId', 'digitalObjectId', 'resourceComponentId', 'subjectId'));

		//Concatenates all of the ids that are connected to each subject id into a list 
		$query->addExpression('GROUP_CONCAT(DISTINCT a.accessionId)', 'accId');
		$query->addExpression('GROUP_CONCAT(DISTINCT a.resourceId)', 'resId');
		$query->addExpression('GROUP_CONCAT(DISTINCT a.digitalObjectId)', 'digObjId');
		$query->addExpression('GROUP_CONCAT(DISTINCT a.resourceComponentId)', 'resCompId');

		//Orders the list by subject ID
		$query->orderBy('s.subjectId');

		//Gives a single comma-separated list of related terms
		$query->groupBy('s.subjectId');

		$this->source = new MigrateSourceSQL($query);

		//Create the destination object
		$this->destination = new MigrateDestinationNode('subject');

		//Create the map object
		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'subjectId' => array(
					'type' => 'int',
					'size' => 'big',
					'length' => 20,
					'not null' => TRUE,
					'alias' => 's',
					'description' => t('Subject ID'),				)
			),
			MigrateDestinationNode::getKeySchema(), 
			'default'
		);

		//Set owner
		$this->addFieldMapping('uid')->defaultValue('1');
		
		//Title field mappings
		$this->addFieldMapping('title', 'subjectTerm')
			->defaultValue('No Subject Term Available.');

		//Other field mappings
		$this->addFieldMapping('field_subject_id', 'subjectId');
		$this->addFieldMapping('field_term_type', 'subjectTermType');
		$this->addFieldMapping('field_source', 'subjectSource');
		$this->addFieldMapping('field_scope_note', 'subjectScopeNote');

		$this->addFieldMapping('field_related_accessions', 'accId')
			->separator(',')
			->sourceMigration(array('ArchivesAccessions'));

		$this->addFieldMapping('field_related_resources', 'resId')
			->separator(',')
			->sourceMigration(array('ArchivesResources'));

		$this->addUnmigratedDestinations(array(
			'created',
			'changed',
			'log',
			'status',
			'promote',
			'sticky',
			'revision',
			'language',
			'tnid',
			'translate',
			'revision_uid',
			'is_new',
			'path',
			'comment',
			)
		);
	}

	function prepareRow($row) {
		//drush_print_r($row); //prints row to terminal
	}

	//Creates a stub so that we can avoid the chicken-and-egg dilemma when importing related nodes
	protected function createStub(Migration $migration, array $source_id){
		$node = new stdClass();
		$node->title = t('Stub for subject @id', array('@id' => $source_id[0]));
		$node->type = 'subject';
		node_save($node);
		if (isset($node->nid)){
			return array($node->nid);
		} else {
			return FALSE;
		}
	}
}




















