<?php

/**
 * @file
 * Short description.
 */

/**
 * Implements hcpro_get_path().
 *
 * This will control the debug/release output of there files.
 */
function hcpro_theme_sub_get_path() {
  if (variable_get('use_debug_theme')) {
    return drupal_get_path('theme', $GLOBALS['theme']) . '/debug';
  }
  else {
    return drupal_get_path('theme', $GLOBALS['theme']) . '/release';
  }
}

/**
 * Implements hook_preprocess_html().
 */
function hcpro_theme_preprocess_html(&$variables) {

  drupal_add_css(hcpro_theme_sub_get_path() . '/styles/css/screen.css', array('group' => CSS_THEME, 'preprocess' => FALSE));

  drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/js/hcpro_theme.behaviors.js',
  array(
    'type' => 'file',
    'every_page' => TRUE,
    'scope' => 'footer',
    'preprocess' => TRUE,
  ));

  $variables['theme_name'] = $GLOBALS['theme'];
}
