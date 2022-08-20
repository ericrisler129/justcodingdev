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
  //Free quizzes only
  ->fieldCondition('field_quiz_type', 'tid', '547', '=')
  //->range(1, 1)
  ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

$quizzes_result = $quizzes->execute();
$quiz_nids = array_keys($quizzes_result['node']);
$quiz_nodes = node_load_multiple($quiz_nids);


// Load Questions
$questions = new EntityFieldQuery();

$day_start = strtotime(date('Y-m-d 00:00:00'));
$day_end = strtotime(date('Y-m-d 23:59:59'));

$questions->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'multichoice')
  // just questions added today
  ->propertyCondition('created', array($day_start, $day_end), 'BETWEEN')
  //->range(0, 3)
  ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');

$questions_result = $questions->execute();
$question_nids = array_keys($questions_result['node']);
$question_nodes = node_load_multiple($question_nids);


// Map questions to quizzes
foreach($quiz_nodes as $quiznode) {
  $quizLegacyID = $quiznode->field_legacy_quiz_id['und'][0]['value'];
  $quizNid = $quiznode->nid;
  $quizVid = $quiznode->vid;

  foreach($question_nodes as $questionnode) {
    $questionLegacyID = $questionnode->field_legacy_quiz_id['und'][0]['value'];
    $questionNid = $questionnode->nid;
    $questionVid = $questionnode->vid;

    if ($quizLegacyID == $questionLegacyID) {
      echo "Match: " . $quizLegacyID . " " . $questionLegacyID;

      $addAssociations = db_insert('quiz_node_relationship')
        ->fields(array(
          'parent_nid' => $quizNid,
          'parent_vid' => $quizVid,
          'child_nid' => $questionNid,
          'child_vid' => $questionVid,
          'question_status' => '1',
          'weight' => '0',
          'max_score' => '1',
          'auto_update_max_score' => '0',
        ))
        ->execute();
    }
  }
}
