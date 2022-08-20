<?php

define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$legacy_request = strip_tags($_GET['request']);
$legacy_request_array = explode('/', $legacy_request);

if ($_GET['type'] == 'article') {
  $legacy_id = "E" . $legacy_request_array[1];
  $bundle = "article";
  $field = "field_legacy_content_id";
} elseif ($_GET['type'] == 'quiz') {
  $legacy_id = $legacy_request_array[2];
  $bundle = "quiz";
  $field = "field_legacy_quiz_id";
}

$node = new EntityFieldQuery();
$node->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', $bundle)
  ->fieldCondition($field, 'value', $legacy_id)
  ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
$result = $node->execute();

if ($result) {
  $node = array_keys($result['node']);
  $nid = $node[0];
  $new_url = drupal_get_path_alias("/node/{$nid}");
  drupal_goto($new_url, array(), 301);
} else {
  if ($legacy_request == '/2021member') {
    drupal_goto('https://hcmarketplace.com/justcoding-com?code=PMHIM1ZA3&utm_source=HCPro&utm_medium=DM&utm_campaign=CodingBrochure', array(), 301);
  }
  drupal_not_found();
}
