<?php

/**
 * @file
 * propel_ask_the_expert.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function propel_ask_the_expert_taxonomy_default_vocabularies() {
  return array(
    'propel_ate_type' => array(
      'name' => 'Propel ATE Type',
      'machine_name' => 'propel_ate_type',
      'description' => '',
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
