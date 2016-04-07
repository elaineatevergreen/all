<?php
/**
 * @file
 * evergreen_content.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function evergreen_content_taxonomy_default_vocabularies() {
  return array(
    'calendar_categories' => array(
      'name' => 'Calendar Categories',
      'machine_name' => 'calendar_categories',
      'description' => 'These terms are used to organize the college\'s events calendar.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'database_of_databases' => array(
      'name' => 'Database of Databases',
      'machine_name' => 'database_of_databases',
      'description' => 'Categories for library database resources',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'faculty_directory_categories' => array(
      'name' => 'Faculty Directory Categories',
      'machine_name' => 'faculty_directory_categories',
      'description' => 'These categories can be used to organize both faculty and fields of study.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'site_sections' => array(
      'name' => 'Site Sections',
      'machine_name' => 'site_sections',
      'description' => 'These are the names of sections of the college\'s website. May be referred to as "sites."',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
