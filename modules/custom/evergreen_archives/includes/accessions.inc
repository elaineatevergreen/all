<?php
/**
 * @file
 * Migration for basic Accessions data
 */

class AccessionsMigration extends ArchivesMigration {

	public function __construct($arguments) {
		parent::__construct($arguments);

		$this->description = t('Import Accessions information from the Archives database.');

		//Create the source object
		$query = Database::getConnection('default', 'for_migration')
			->select('Accessions', 'a')
			->fields('a', array('accessionId', 'title', 'dateExpression', 'dateBegin', 'dateEnd', 'extentNumber', 'extentType', 'containerSummary', 'accessionDate', 'accessionNumber1', 'accessionNumber2', 'accessionNumber3', 'accessionNumber4', 'description', 'accessRestrictionsNote', 'useRestrictionsNote'));

		$query->leftJoin('ArchDescriptionNames', 'n', 'a.accessionId=n.accessionId');
		$query->fields('n', array('primaryNameId'));
		$query->addExpression('GROUP_CONCAT(DISTINCT primaryNameId)', 'name');

		$query->leftJoin('ArchDescriptionSubjects', 's', 'a.accessionId=s.accessionId');
		$query->fields('s', array('subjectId'));
		$query->addExpression('GROUP_CONCAT(DISTINCT subjectId)', 'subject');

		$query->leftJoin('AccessionsResources', 'ar', 'a.accessionId=ar.accessionId');
		$query->fields('ar', array('resourceId'));
		$query->addExpression('GROUP_CONCAT(DISTINCT ar.resourceId)', 'resources');

		$query->groupBy('a.accessionId');
		$query->orderBy('a.accessionId');

		$this->source = new MigrateSourceSQL($query);

		//Create the destination object
		$this->destination = new MigrateDestinationNode('accession');

		//Create the map object
		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'accessionId' => array(
					'type' => 'int',
					'size' => 'big',
					'length' => 20,
					'not null' => TRUE,
					'alias' => 'a',
					//'default' => 'None',
					'description' => t('Accession ID'),
				)
			),
			MigrateDestinationNode::getKeySchema(),
			'default'
		);

		//Set owner
		$this->addFieldMapping('uid')->defaultValue('1');		

		//Title field mappings
		 $this->addFieldMapping('title', 'title')
			 ->defaultValue('No Title Available');

		//Other field mappings
		$this->addFieldMapping('field_accession_id', 'accessionId');
		//$this->addFieldMapping('field_creator', '???');
		$this->addFieldMapping('field_dates', 'date');
		$this->addFieldMapping('field_quantity', 'quantity');
		$this->addFieldMapping('field_accession_date', 'accessionDate');
		$this->addFieldMapping('field_collection_number', 'accessionNumber');
		$this->addFieldMapping('field_summary', 'description');
		//$this->addFieldMapping('field_collection_location', ???);
		$this->addFieldMapping('field_access_restrictions', 'accessRestrictionsNote');
		$this->addFieldMapping('field_use_restrictions', 'useRestrictionsNote');

		$this->addFieldMapping('field_related_names', 'name')
			->separator(',')
			->sourceMigration(array('ArchivesNames'));

		$this->addFieldMapping('field_related_subjects', 'subject')
			->separator(',')
			->sourceMigration(array('ArchivesSubjects'));

		$this->addFieldMapping('field_acc_related_resources', 'resources')
			->separator(',')
			->sourceMigration(array('ArchivesResources'));

		$this->addUnmigratedDestinations(array(
			'uid',
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
		//drush_print_r($row);  //prints row to terminal

		//Sets up the date row
		if (empty($row->dateBegin) && empty($row->dateExpression)){
			$row->null;
		} else if (empty($row->dateExpression)){
			$row->date =$row->dateBegin . "–" . $row->dateEnd;
		} else {
			$row->date = $row->dateExpression;
		}

		//Sets up the quantity row
		if (empty($row->extentNumber) && empty($row->containerSummary)) {
			$row->null;
		} else if(empty($row->containerSummary)){
			$row->quantity = $row->extentNumber . " " . $row->extentType . ".";
		}else {
			$row->quantity = $row->extentNumber . " " . $row->extentType . ". " . $row->containerSummary . ".";
		}

		if(empty($row->accessionNumber4)){
			$row->accessionNumber = $row->accessionNumber1 . "." . $row->accessionNumber2 . "." . $row->accessionNumber3;
		}else{
			$row->accessionNumber = $row->accessionNumber1 . "." . $row->accessionNumber2 . "." . $row->accessionNumber3 . "." . $row->accessionNumber4;
		}
	}

	//Creates a stub so that we can avoid the chicken-and-egg dilemma when importing related nodes
	protected function createStub(Migration $migration, array $source_id){
		$node = new stdClass();
		$node->title = t('Stub for accession @id', array('@id' => $source_id[0]));
		$node->type = 'accession';
		node_save($node);
		if (isset($node->nid)){
			return array($node->nid);
		} else {
			return FALSE;
		}
	}



}
