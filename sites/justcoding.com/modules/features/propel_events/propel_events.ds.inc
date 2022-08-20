<?php

/**
 * @file
 * propel_events.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function propel_events_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|propel_events|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'propel_events';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
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
    'field_propel_event_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Event Type',
        ),
      ),
    ),
    'field_generic_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Important links',
          'lb-el' => 'b',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|propel_events|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function propel_events_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|propel_events|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'propel_events';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'group_details',
        2 => 'field_propel_event_type',
        3 => 'field_presenter',
        4 => 'field_participants',
        5 => 'field_propel_event_date',
        6 => 'field_time_zone',
        7 => 'field_location',
        8 => 'field_generic_link',
        9 => 'body',
        10 => 'group_buttons',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'group_details' => 'ds_content',
      'field_propel_event_type' => 'ds_content',
      'field_presenter' => 'ds_content',
      'field_participants' => 'ds_content',
      'field_propel_event_date' => 'ds_content',
      'field_time_zone' => 'ds_content',
      'field_location' => 'ds_content',
      'field_generic_link' => 'ds_content',
      'body' => 'ds_content',
      'group_buttons' => 'ds_content',
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
  $export['node|propel_events|full'] = $ds_layout;

  return $export;
}
