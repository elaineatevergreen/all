<?php
/**
 * @file
 * Migration for Resources data
 */

class ResourcesMigration extends ArchivesMigration {

	public function __construct($arguments) {
		parent::__construct($arguments);

		$this->description = t('Import Resources information from the Archives database.');

		//Create the source 
		$query = Database::getConnection('default', 'for_migration')
			->select('Resources', 'r')
			->fields('r', array('resourceId', 'title', 'resourceLevel', 'displayCreator', 'dateBegin', 'dateEnd', 'dateExpression', 'extentNumber', 'containerSummary', 'extentType', 'languageOfFindingAid', 'resourceIdentifier1', 'resourceIdentifier2', 'resourceIdentifier3', 'sponsorNote'));

		//Additional data from the ArchDescriptionRepeatingData table
		$query->leftJoin('ArchDescriptionRepeatingData', 'adr', 'r.resourceId=adr.resourceId');
		$query->fields('adr', array('title', 'sequenceNumber', 'notesEtcTypeId', 'noteContent'));
		$query->addExpression("GROUP_CONCAT(DISTINCT CONCAT_WS(':::', adr.notesEtcTypeId, adr.noteContent) SEPARATOR '###')", "notes");

		//Additional data from the ResourcesComponents table
		$query->leftJoin('ResourcesComponents', 'rc', 'r.resourceId=rc.resourceId');
		$query->fields('rc', array('resourceComponentId', 'title', 'dateBegin', 'dateEnd', 'sequenceNumber'));
		$query->addExpression("GROUP_CONCAT(DISTINCT rc.resourceComponentId)", "components");       

		//Related materials
		$query->leftJoin('ArchDescriptionNames', 'n', 'r.resourceId=n.resourceId');
		$query->fields('n', array('primaryNameId'));
		$query->addExpression('GROUP_CONCAT(DISTINCT primaryNameId)', 'name');
		$query->groupBy('r.resourceId');

		$query->leftJoin('ArchDescriptionSubjects', 's', 'r.resourceId=s.resourceId');
		$query->fields('s', array('subjectId'));
		$query->addExpression('GROUP_CONCAT(DISTINCT subjectId)', 'subject');
		$query->groupBy('r.resourceId');

		$query->leftJoin('AccessionsResources', 'ar', 'r.resourceId=ar.resourceId');
		$query->fields('ar', array('accessionId'));
		$query->addExpression('GROUP_CONCAT(DISTINCT ar.accessionId)', 'accession');



		//Create the source object
		$this->source = new MigrateSourceSQL($query);

		//Create the destination object
		$this->destination = new MigrateDestinationNode('resource');

		//Create the map object
		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'resourceId' => array(
					'type' => 'int',
					'size' => 'big',
					'length' => 20,
					'not null' => TRUE,
					'alias' => 'r',
					'description' => t('Resource ID'),
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

		//Field mappings
		$this->addFieldMapping('field_resource_id', 'resourceId');
		$this->addFieldMapping('field_resource_level', 'resourceLevel');
		$this->addFieldMapping('field_resource_creator', 'displayCreator');
		$this->addFieldMapping('field_resource_dates', 'date');
		$this->addFieldMapping('field_resource_quantity', 'quantity');
		$this->addFieldMapping('field_resource_collection_number', 'resourceIdentifier');
		$this->addFieldMapping('field_languages', 'languageOfFindingAid');
		$this->addFieldMapping('field_sponsor', 'sponsorNote');

		//Related materials field mappings
		$this->addFieldMapping('field_res_related_accessions', 'accession')
			->separator(',')
			->sourceMigration(array('ArchivesAccessions'));

		$this->addFieldMapping('field_res_related_names', 'name')
			->separator(',')
			->sourceMigration(array('ArchivesNames'));

		$this->addFieldMapping('field_res_related_subjects', 'subject')
			->separator(',')
			->sourceMigration(array('ArchivesSubjects'));

		//Detailed Description (ResourcesComponents table) field mappings
		$this->addFieldMapping('field_detailed_description', 'components')
				 ->arguments(array('format'=> 'full_html'));
		// $this->addFieldMapping('field_detailed_description:format', 'full_html');

		// Field mappings from notes
		// NOTE: Default values for various notes are hardcoded using values from the "RepositoryNotesDefaultValues" table
		$this->addFieldMapping('field_resource_summary', 'summary'); // 1
		$this->addFieldMapping('field_accruals', 'accruals'); // 2
		// $this->addFieldMapping('field_appraisal', 'appraisal'); // 3
		$this->addFieldMapping('field_arrangement', 'arrangement'); // 4
		$this->addFieldMapping('field_bibliography', 'bibliography'); // 5
		$this->addFieldMapping('field_historical_note', 'historical'); // 6
		$this->addFieldMapping('field_chronology', 'chronology'); // 7
		$this->addFieldMapping('field_res_access_restrictions', 'accessRestrictions') // 8
			 ->defaultValue("Collection is open to the public.");
		$this->addFieldMapping('field_restrictions_on_use', 'useRestrictions') // 9
			 ->defaultValue('Duplication of archival materials in no way transfers either copyright or property right, nor does it constitute permission to publish in excess of "fair use" or to display the materials.');
		$this->addFieldMapping('field_custodial_history', 'custodialHistory'); // 10
		$this->addFieldMapping('field_dimensions', 'dimensions'); // 11
		$this->addFieldMapping('field_other_copies', 'otherCopies'); // 12
		$this->addFieldMapping('field_existence_of_originals', 'existenceAndLocationOfOriginals'); // 13
		$this->addFieldMapping('field_file_plan', 'filePlan'); // 14
		$this->addFieldMapping('field_general', 'general'); // 15
		$this->addFieldMapping('field_physical_description', 'physicalDescription'); // 16
		$this->addFieldMapping('field_source_of_acquisition', 'sourceOfAcquisition'); // 17
		$this->addFieldMapping('field_index', 'index'); // 18
		$this->addFieldMapping('field_language_of_materials', 'languageOfMaterials'); // 19
		$this->addFieldMapping('field_legal_status', 'legalStatus'); // 20
		// 21 (List: definition) and 22 (List: ordered) omitted
		$this->addFieldMapping('field_location_of_collection', 'locationOfCollection'); // 23
		$this->addFieldMapping('field_material_specific_details', 'materialSpecificDetails'); // 24
		$this->addFieldMapping('field_other_finding_aids', 'otherFindingAids'); // 25
		// $this->addFieldMapping('field_tech_requirements', 'technicalRequirements'); // 26
		$this->addFieldMapping('field_physical_facet', 'physicalFacet'); // 27
		$this->addFieldMapping('field_preferred_citation', 'preferredCitation') // 28
			 ->defaultValue('In all cases, publication or display of our materials must carry the credit line: "From The Evergreen State College Archives". Citations of specific materials should include the accession number, provenance and series title, file folder heading (if any) followed by the specific item\'s identification (title or description).');
		$this->addFieldMapping('field_processing_information', 'processingInformation'); // 29
		$this->addFieldMapping('field_related_archival_materials', 'relatedArchivalMaterials'); // 30
		$this->addFieldMapping('field_scope_and_contents', 'contentDescription'); // 31
		// 32 (Separated Materials) omitted

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
		// This prints the row to the terminal --
		//drush_print_r($row);

		// Construct detailed description
		if(!function_exists('getAllResourceComponents')){
			function getAllResourceComponents(){
				db_set_active('for_migration');
				$rcquery = db_query("SELECT * FROM ResourcesComponents");
				db_set_active('default');
				$results = $rcquery->fetchAll();
				return $results;
			}
		}

		if(!function_exists('getComponentObject')){
			function getComponentObject($component){
				db_set_active('for_migration');
				$rcquery = db_query("SELECT * FROM ResourcesComponents WHERE resourceComponentId=$component");
				db_set_active('default');
				return $rcquery->fetchAll();
			}
		}

		if(!function_exists('getChildren')){
			function getChildren($component){
				db_set_active('for_migration');
				$rcquery = db_query("SELECT * FROM ResourcesComponents WHERE parentResourceComponentId=$component");
				db_set_active('default');
				return $rcquery->fetchAll();
			}
		}

		if(!function_exists('getNote')){
			function getNote($resCompId){
				db_set_active('for_migration');
				$rcquery = db_query("SELECT * FROM ArchDescriptionRepeatingData WHERE resourceComponentId=$resCompId");
				db_set_active('default');
				$result = $rcquery->fetchAll();
				return $result[0]->noteContent;
			}
		}

		if(!function_exists('addDate')){
			function addDate($parent){
				if($parent->dateExpression){
					$date.=$parent->dateExpression;
				}else if($parent->dateBegin){
					if($parent->dateEnd){
						$date.=$parent->dateBegin."&ndash;".$parent->dateEnd;
					}else{
						$date.=$parent->dateBegin;
					}
				}
			return $date;
			}
		}

		if(!function_exists('addTopLevelItem')){
			function addTopLevelItem($parent){
				$item.="<h3>".$parent->title;
				if($parent->dateExpression || $parent->dateBegin){
					$item.=", ".addDate($parent);
				}
				if($parent->extentNumber){
					$item.=", ".$parent->extentNumber." ".$parent->extentType;
				}
				$item.="</h3>";
				if($parent->hasNotes==1){
					$item.="<p>".getNote($parent->resourceComponentId)."</p>";
				}
				return $item;
			}
		}

		if(!function_exists('addItem')){
			function addItem($parent, $level){
				if($level==0){
					$item.=addTopLevelItem($parent);
				}else{
					$item.="<tr><td>";
					$item.=addDate($parent);
					$item.="</td>";
					$item.="<td><p>".$parent->title."</p>";
					if($parent->extentNumber){
						$item.="<p>".$parent->extentNumber." ".$parent->extentType."</p>";
					}
					if($parent->hasNotes==1){
						$item.="<p>".getNote($parent->resourceComponentId)."</p>";
					}
					$item.="</td></tr>";
				}
				return $item;				
			}
		}

		//$results = getAllResourceComponents();

		$html = "";

		if(!function_exists('buildComponents')){
			function buildComponents($value, $level){
				$component = getComponentObject($value);
				$parent=$component[0];

				if($parent){
					//drush_print_r($parent->title);
					if($parent->hasChild==1){
						$html.=addItem($parent, $level);
						$html.='<table><thead><tr><th width="145">Dates</th><th>Description</th></tr></thead><tbody>';

						$children = getChildren($value);

						foreach($children as $obj){
							$html.=buildComponents($obj->resourceComponentId, $level+1);
						}

						$html.="</tbody></table>";

					}else{

						$html.=addItem($parent, $level);

					}
				}
				return $html;
			}
		}

		// $comps is our components for this Resource as an array
		$comps = explode(',', $row->components);
		//drush_print_r($comps);

		$genhtml="<ul>";

		foreach($comps as $key=>$value){
			$genhtml .= buildComponents($value, 0);
		}

		$genhtml.="</ul>";

		$row->components = $genhtml;


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

		//Sets up collection number
		$row->resourceIdentifier = $row->resourceIdentifier1 . "." . $row->resourceIdentifier2 . "." . $row->resourceIdentifier3;

		// Get data from notes table using regex
		preg_match('~(###)?1:::([^###]+)(###)?~', $row->notes, $matches);
		$row->summary = $matches[2];

		preg_match('~(###)?2:::([^###]+)(###)?~', $row->notes, $matches);
		$row->accruals = $matches[2];

		// preg_match('~(###)?3:::([^###]+)(###)?~', $row->notes, $matches);
		// $row->appraisal = $matches[2];

		preg_match('~(###)?4:::([^###]+)(###)?~', $row->notes, $matches);
		$row->arrangement = $matches[2];

		preg_match('~(###)?5:::([^###]+)(###)?~', $row->notes, $matches);
		$row->bibliography = $matches[2];		

		preg_match('~(###)?6:::([^###]+)(###)?~', $row->notes, $matches);
		$row->historical = $matches[2];

		preg_match('~(###)?7:::([^###]+)(###)?~', $row->notes, $matches);
		$row->chronology = $matches[2];		

		preg_match('~(###)?8:::([^###]+)(###)?~', $row->notes, $matches);
		$row->accessRestrictions = $matches[2];

		preg_match('~(###)?9:::([^###]+)(###)?~', $row->notes, $matches);
		$row->useRestrictions = $matches[2];

		preg_match('~(###)?10:::([^###]+)(###)?~', $row->notes, $matches);
		$row->custodialHistory = $matches[2];

		preg_match('~(###)?11:::([^###]+)(###)?~', $row->notes, $matches);
		$row->dimensions = $matches[2];

		preg_match('~(###)?12:::([^###]+)(###)?~', $row->notes, $matches);
		$row->otherCopies = $matches[2];

		preg_match('~(###)?13:::([^###]+)(###)?~', $row->notes, $matches);
		$row->existenceAndLocationOfOriginals = $matches[2];

		preg_match('~(###)?14:::([^###]+)(###)?~', $row->notes, $matches);
		$row->filePlan = $matches[2];

		preg_match('~(###)?15:::([^###]+)(###)?~', $row->notes, $matches);
		$row->general = $matches[2];

		preg_match('~(###)?16:::([^###]+)(###)?~', $row->notes, $matches);
		$row->physicalDescription = $matches[2];

		preg_match('~(###)?17:::([^###]+)(###)?~', $row->notes, $matches);
		$row->sourceOfAcquisition = $matches[2];

		preg_match('~(###)?18:::([^###]+)(###)?~', $row->notes, $matches);
		$row->index = $matches[2];		

		preg_match('~(###)?19:::([^###]+)(###)?~', $row->notes, $matches);
		$row->languageOfMaterials = $matches[2];

		preg_match('~(###)?20:::([^###]+)(###)?~', $row->notes, $matches);
		$row->legalStatus = $matches[2];

		// 21 (List: definition) and 22 (List: ordered) omitted

		preg_match('~(###)?23:::([^###]+)(###)?~', $row->notes, $matches);
		$row->locationOfCollection = $matches[2];

		preg_match('~(###)?24:::([^###]+)(###)?~', $row->notes, $matches);
		$row->materialSpecificDetails = $matches[2];

		preg_match('~(###)?25:::([^###]+)(###)?~', $row->notes, $matches);
		$row->otherFindingAids = $matches[2];

		preg_match('~(###)?26:::([^###]+)(###)?~', $row->notes, $matches);
		$row->technicalRequirements = $matches[2];

		preg_match('~(###)?27:::([^###]+)(###)?~', $row->notes, $matches);
		$row->physicalFacet = $matches[2];

		preg_match('~(###)?28:::([^###]+)(###)?~', $row->notes, $matches);
		$row->preferredCitation = $matches[2];

		preg_match('~(###)?29:::([^###]+)(###)?~', $row->notes, $matches);
		$row->processingInformation = $matches[2];

		preg_match('~(###)?30:::([^###]+)(###)?~', $row->notes, $matches);
		$row->relatedArchivalMaterials = $matches[2];

		preg_match('~(###)?31:::([^###]+)(###)?~', $row->notes, $matches);
		$row->contentDescription = $matches[2];

		// 32 (Separated Materials) omitted

	}

		//Creates a stub so that we can avoid the chicken-and-egg dilemma when importing related nodes
	protected function createStub(Migration $migration, array $source_id){
		$node = new stdClass();
		$node->title = t('Stub for resource @id', array('@id' => $source_id[0]));
		$node->type = 'resource';
		node_save($node);
		if (isset($node->nid)){
			return array($node->nid);
		} else {
			return FALSE;
		}
	}



}
