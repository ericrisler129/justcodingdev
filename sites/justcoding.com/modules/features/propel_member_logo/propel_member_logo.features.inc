<?php

/**
 * @file
 * propel_member_logo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function propel_member_logo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function propel_member_logo_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function propel_member_logo_image_default_styles() {
  $styles = array();

  // Exported image style: propel_logo_short.
  $styles['propel_logo_short'] = array(
    'label' => 'Propel Logo Short (300x250)',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => 250,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: propel_logos.
  $styles['propel_logos'] = array(
    'label' => 'Propel Logos (300x300)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => 300,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function propel_member_logo_node_info() {
  $items = array(
    'propel_member_logo' => array(
      'name' => t('Propel Member Logo'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
