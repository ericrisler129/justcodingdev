<?php
/**
 * Implements hook_preprocess_page().
 */
function jc_preprocess_page(&$variables) {
  if (isset($_GET['field_news_categories_tid'])) {
    $category = $_GET['field_news_categories_tid'];

    if ($category != "All") {
      $term = taxonomy_term_load($category);
      $variables['section_subtitle'] = $term->name;
    }
  }

  if (isset($variables['node']->field_news_categories[LANGUAGE_NONE][0]['tid'])) {
    $category = $variables['node']->field_news_categories[LANGUAGE_NONE][0]['tid'];
    $term = taxonomy_term_load($category);
    $publication = $variables['node']->field_publication[LANGUAGE_NONE][0]['taxonomy_term']->name;

    $variables['section_subtitle'] = $publication." > ".$term->name;
  }

  if (isset($_GET['field_publication_tid'])) {
    $publication = $_GET['field_publication_tid'];

    if ($publication != "All") {
      $term = taxonomy_term_load($publication);
      $variables['section_subtitle'] = $term->name . " Archives";
    }
  }


  //hide ads if url starts with /quiz/ or is /quiz
  $pos = strpos($_SERVER['REQUEST_URI'], '/quiz/');
  if ( $pos === 0 || $_SERVER['REQUEST_URI'] === '/quiz') {
    if( isset($variables['page']['top']['block_6'])) {
      unset($variables['page']['top']['block_6']);
    }
    if( isset($variables['page']['bottom']['block_7'])) {
      unset($variables['page']['bottom']['block_7']);
    }
    if( isset($variables['page']['sidebar_second']['block_8'])) {
      unset($variables['page']['sidebar_second']['block_8']);
    }

  }
}
