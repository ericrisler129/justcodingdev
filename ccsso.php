<?php

define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$query = drupal_get_query_parameters();
$auth_token = $query['token'];

global $base_url;

if ($auth_token) {
  blr_webauth_get_sso_authorization_session($auth_token);
}

else {
  drupal_goto($base_url);
}
