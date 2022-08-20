<?php

/**
 * @file
 * propel_resource.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function propel_resource_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|propel_resource|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'propel_resource';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'wistia_embed' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'post_date' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'ds_post_date_article',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_file_download' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'styled-download',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|propel_resource|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function propel_resource_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|propel_resource|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'propel_resource';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_file_download',
        2 => 'group_details',
        3 => 'body',
        4 => 'field_embed_code',
        5 => 'wistia_embed',
        6 => 'group_buttons',
        7 => 'post_date',
        8 => 'field_propel_type',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_file_download' => 'ds_content',
      'group_details' => 'ds_content',
      'body' => 'ds_content',
      'field_embed_code' => 'ds_content',
      'wistia_embed' => 'ds_content',
      'group_buttons' => 'ds_content',
      'post_date' => 'ds_content',
      'field_propel_type' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|propel_resource|full'] = $ds_layout;

  return $export;
}
