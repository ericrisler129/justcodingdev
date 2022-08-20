<?php
/**
 * @file
 * propel_resource.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function propel_resource_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'propel_resources';
  $context->description = '';
  $context->tag = 'Section Header';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'propel-resource' => 'propel-resource',
        'propel-resource/*' => 'propel-resource/*',
        'propel-resources' => 'propel-resources',
      ),
    ),
  );
  $context->reactions = array(
    'theme' => array(
      'title' => 'My Propel Library',
      'subtitle' => '<i class="fa fa fa-book fa-2x"></i>',
    ),
    'theme_html' => array(
      'class' => 'propel-breadcrumb',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Section Header');
  $export['propel_resources'] = $context;

  return $export;
}
