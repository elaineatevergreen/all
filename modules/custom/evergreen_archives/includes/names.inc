<?php
/**
 * @file
 * Migration for Names schema data. 
 */

class NamesMigration extends ArchivesMigration {

	public function __construct($arguments) {
		parent::__construct($arguments);

		$this->description = t('Import names information from the Archives database.');

		//Create the source object
		$query = Database::getConnection('default', 'for_migration')
			->select('Names', 'n')
			->fields('n', array('nameId', 'sortName', 'salutation', 'nameType', 'descriptionNote', 'personalDates'));

		$query->leftJoin('ArchDescriptionNames', 'a', 'n.nameId=a.primaryNameId');
		$query->fields('a', array('archDescriptionNamesId', 'nameLinkFunction', 'primaryNameId', 'accessionId', 'resourceId'));

		//Concatenate information for each name id
		$query->addExpression('GROUP_CONCAT(DISTINCT a.archDescriptionNamesId)', 'archDescId');
		$query->addExpression('GROUP_CONCAT(DISTINCT a.nameLinkFunction)', 'function');
		$query->addExpression('GROUP_CONCAT(DISTINCT a.accessionId)', 'accId');
		$query->addExpression('GROUP_CONCAT(DISTINCT a.resourceId)', 'resId');

		//Gives a single comma-separated list of related terms
		$query->groupBy('n.nameId');

		//Orders the list by name ID
		$query->orderBy('n.nameId');

		$this->source = new MigrateSourceSQL($query);

		//Create the destination object
		$this->destination = new MigrateDestinationNode('name');

		//Create the map object
		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'nameId' => array(
					'type' => 'int',
					'size' => 'big',
					'length' => 20,
					'not null' => TRUE,
					'alias' => 'n',
					'description' => t('Name ID'),
				)
			),
			MigrateDestinationNode::getKeySchema(), 
			'default'
		);

		//Set owner
		$this->addFieldMapping('uid')->defaultValue('1');

		//Title field mappings
		$this->addFieldMapping('title', 'titleInfo')
			->defaultValue('No Salutation Available.');

		//Other field mappings
		$this->addFieldMapping('field_name_id');
		$this->addFieldMapping('field_type', 'nameType');
		$this->addFieldMapping('body', 'descriptionNote');

		$this->addFieldMapping('field_name_related_accessions', 'accId')
			->separator(',')
			->sourceMigration(array('ArchivesAccessions'));

		$this->addFieldMapping('field_name_related_resources', 'resId')
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

		//If personalDates is null, this returns the salutation for the title field. 
		//Otherwise, it concatenates salutation with personalDates for the title field. 
		if (empty($row->personalDates)) {
			$row->titleInfo = $row->sortName;
		} else {
			$row->titleInfo = $row->sortName . ', ' . $row->personalDates;
		}
	}

	//Creates a stub so that we can avoid the chicken-and-egg dilemma when importing related nodes
	protected function createStub(Migration $migration, array $source_id){
		$node = new stdClass();
		$node->title = t('Stub for name @id', array('@id' => $source_id[0]));
		$node->type = 'name';
		node_save($node);
		if (isset($node->nid)){
			return array($node->nid);
		} else {
			return FALSE;
		}
	}

}

