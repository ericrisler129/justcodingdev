<?php
/**
 * @file
 * hcpro_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hcpro_roles_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: basic.
  $roles['basic'] = array(
    'name' => 'basic',
    'weight' => 4,
  );

  // Exported role: corporate.
  $roles['corporate'] = array(
    'name' => 'corporate',
    'weight' => 6,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  // Exported role: platinum.
  $roles['platinum'] = array(
    'name' => 'platinum',
    'weight' => 5,
  );

  return $roles;
}
