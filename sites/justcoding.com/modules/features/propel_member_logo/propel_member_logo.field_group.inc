<?php

/**
 * @file
 * propel_member_logo.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function propel_member_logo_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categorization|node|propel_member_logo|form';
  $field_group->group_name = 'group_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'propel_member_logo';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '3',
    'children' => array(
      0 => 'field_owner_company',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-categorization field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_categorization|node|propel_member_logo|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Categorization');

  return $field_groups;
}
