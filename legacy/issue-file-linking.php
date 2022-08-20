<?php
// Bootstrap Drupal
define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$legacy_ids = array(
  "E274237",
  "E275434",
  "E276423",
  "E277259",
  "E278366",
  "E279815",
  "E280717",
  "E281772",
  "E282774",
  "E284228",
  "E285025",
  "E285800",
  "E287108",
  "E298774",
  "E287914",
  "E288795",
  "E289769",
  "E290608",
  "E291614",
  "E292644",
  "E293741",
  "E294589",
  "E295757",
  "E296826",
  "E297818",
  "E299889",
  "E300472",
  "E301559",
  "E303367",
  "E303974",
  "E304901",
  "E306003",
  "E307118",
  "E307881",
  "E308749",
  "E309813",
  "E274767",
  "E275763",
  "E276988",
  "E277438",
  "E277808",
  "E278844",
  "E280021",
  "E281004",
  "E282088",
  "E283096",
  "E284263",
  "E285475",
  "E286485",
  "E310818",
  "E311708",
  "E312686",
  "E313827",
  "E314971",
  "E316015",
  "E316952",
  "E318308",
  "E319293",
  "E320424",
  "E321215",
  "E322301",
  "E287513",
  "E288299",
  "E289385",
  "E290245",
  "E291136",
  "E292154",
  "E293392",
  "E293994",
  "E295175",
  "E296223",
  "E297336",
  "E298404",
  "E323065",
  "E299411",
  "E300469",
  "E301278",
  "E303206",
  "E303655",
  "E304652",
  "E305671",
  "E306381",
  "E307511",
  "E308606",
  "E309357",
  "E310398",
  "E311806",
  "E312372",
  "E313409",
  "E314495",
  "E315555",
  "E316747",
  "E317808",
  "E318858",
  "E319925",
  "E320770",
  "E321647",
  "E322489",
);

foreach ($legacy_ids as $legacy_id) {
  $pos0 = new EntityFieldQuery();

  $pos0->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->fieldCondition('field_legacy_content_id', 'value', $legacy_id)
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

  $pos0_result = $pos0->execute();
  $pos0_nid = array_keys($pos0_result['node']);

  if (isset($pos0_nid)) {
    $file_path = "private://issues/{$legacy_id}.pdf";

    if (file_exists($file_path)) {
      $node = node_load($pos0_nid);

      $file = new stdClass;
      $file->uid = $node->uid;
      $file->filename = pathinfo($file_path, PATHINFO_BASENAME);
      $file->uri = $file_path;
      $file->filemime = file_get_mimetype($file_path);
      $file->display = 1;
      $file->description = '';
      $file->status = FILE_STATUS_PERMANENT;

      file_save($file);
      $destination = 'private://issues/';
      file_prepare_directory($destination, FILE_CREATE_DIRECTORY);

      $node->field_file[$node->language][0] = (array) $file;
      node_save($node);
    }
  }
}
