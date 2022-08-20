<?php
/***
 * Map quiz questions to quizzes
 */

// Bootstrap Drupal
define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Load Quizzes
$quizzes = new EntityFieldQuery();

$quizzes->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'quiz')
  //->range(0, 50)
  ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

$quizzes_result = $quizzes->execute();
$quiz_nids = array_keys($quizzes_result['node']);
$quiz_nodes = node_load_multiple($quiz_nids);
$quiz_page = node_load(11781, 11809);

foreach($quiz_nodes as $quiznode) {
  $qNodes = array();
  $quiz_question_relationships = array();
  $loaded_questions = quiz_build_question_list($quiznode);
  $qID_object = new stdClass();
  foreach ($loaded_questions as $key => $question) {
    foreach($question as $k => $v) {
      $qID_object->$k = $v;
    }

    $qNodes[$qID_object->nid] = node_load($qID_object->nid, $qID_object->vid);
    $qNodes[$qID_object->nid]->qnr_id = $qID_object->qnr_id;
    $qNodes[$quiz_page->nid] = $quiz_page;
    $qNodes[$quiz_page->nid]->qnr_id = 0;
  }

  db_delete('quiz_node_relationship')
    ->condition('parent_nid', $quiznode->nid)
    ->condition('parent_vid', $quiznode->vid)
    ->execute();
  //dpm("Deleted qnr nid: " . $quiznode->nid . " vid: " . $quiznode->vid);

  foreach ($qNodes as $qqr) {
    $old_qnr_id = $qqr->qnr_id;
    unset($qqr->qnr_id);
    $qqr->parent_nid = $quiznode->nid;
    $qqr->parent_vid = $quiznode->vid;
    $qqr->child_nid = $qqr->nid;
    $qqr->child_vid = $qqr->vid;
    entity_save('quiz_question_relationship', $qqr);
    //dpm("Saved qqr nid: " . $qqr->nid . " vid: " . $qqr->vid);
    $qqr->old_qnr_id = $old_qnr_id;
    $quiz_question_relationships[] = $qqr;

    if ($qqr->nid == $quiz_page->nid) {
      $qqr->old_qnr_id = null;
    }
  }

  foreach ($quiz_question_relationships as $qqr) {
    db_update('quiz_node_relationship')
      ->condition('qnr_pid', $qqr->old_qnr_id)
      ->condition('parent_vid', $quiznode->vid)
      ->condition('parent_nid', $quiznode->nid)
      ->condition('child_nid', $quiz_page->nid, '!=')
      ->fields(array('qnr_pid' => $qqr->qnr_id))
      ->execute();
  }

  //dpm($qNodes);
}
