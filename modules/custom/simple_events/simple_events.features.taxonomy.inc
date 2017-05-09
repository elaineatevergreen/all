<?php
/**
 * @file
 * simple_events.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function simple_events_taxonomy_default_vocabularies() {
  return array(
    'site_sections' => array(
      'name' => 'Site Sections',
      'machine_name' => 'site_sections',
      'description' => 'Each section of the website that may be referred to as a "site". This sets the navigation, title, contact info, and background.',
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
