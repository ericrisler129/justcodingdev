<?php

/**
 * @file
 * Contains default importer for quiz questions
 */

/**
 * Implements hook_ctools_plugin_api()
 */
function qq_import_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == 'feeds' && $api == 'feeds_importer_default') {
    return array('version' => 1);
  }
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function qq_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'multichoice';
  $feeds_importer->config = array(
  'name' => 'Multichoice',
  'description' => '',
  'fetcher' => array(
    'plugin_key' => 'FeedsFileFetcher',
    'config' => array(
      'direct' => FALSE,
      'allowed_extensions' => 'txt csv tsv xml opml',
      'directory' => 'public://feeds',
      'allowed_schemes' => array(
        0 => 'public',
      ),
    ),
  ),/*
  'parser' => array(
    'plugin_key' => 'FeedsCSVParser',
    'config' => array(
      'delimiter' => ',',
      'no_headers' => 0,
    ),
  ),*/
  'parser' => array(
    'plugin_key' => 'FeedsXPathParserXML',
  ),
  'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'bundle' => 'multichoice',
      'update_existing' => '0',
      'expire' => '-1',
      'mappings' => array(
        0 => array(
          'source' => 'xpathparser:0',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'xpathparser:1',
          'target' => 'title',
          'unique' => FALSE,
        ),
        2 => array(
          'source' => 'xpathparser:2',
          'target' => 'body',
          'unique' => FALSE,
        ),
        3 => array(
          'source' => 'xpathparser:3',
          'target' => 'multichoice_alternative_correct',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'xpathparser:4',
          'target' => 'multichoice_alternative_incorrect',
          'unique' => FALSE,
        ),
        5 => array(
          'source' => 'xpathparser:5',
          'target' => 'multichoice_alternative_incorrect',
          'unique' => FALSE,
        ),
        6 => array(
          'source' => 'xpathparser:6',
          'target' => 'multichoice_alternative_incorrect',
          'unique' => FALSE,
        ),
      ),
      'input_format' => 'html',
      'author' => 1,
      'authorize' => 0,
      'skip_hash_check' => 0,
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '-1',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => FALSE,
  );

  $export['multichoice'] = $feeds_importer;

  return $export;
}
