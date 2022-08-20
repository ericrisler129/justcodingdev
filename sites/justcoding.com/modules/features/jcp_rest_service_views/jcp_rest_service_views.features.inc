<?php

/**
 * @file
 * jcp_rest_service_views.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jcp_rest_service_views_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function jcp_rest_service_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
