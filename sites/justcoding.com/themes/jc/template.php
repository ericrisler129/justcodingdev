<?php
/***
 * Implements hook_form_alter().
 */
function jc_form_alter(&$form, &$form_state, $form_id) {
  if($form_id == 'poll_view_voting') {
    $form['vote']['#value'] = "Submit Poll";
    $form['vote']['#attributes']['class'][] = 'button-input';
    $form['vote']['#attributes']['class'][] = 'button-input-brand1';
  }

  if($form_id == 'poll_cancel_form') {
    $form['actions']['submit']['#attributes']['class'][] = 'button-input';
    $form['actions']['submit']['#attributes']['class'][] = 'button-input-brand1';
    unset($form['actions']);
  }

  if($form_id == 'views_exposed_form') {
    if(($form['#id'] == 'views-exposed-form-resources-page-1') || ($form['#id'] == 'views-exposed-form-propel-resource-block-4')) {
      $form['title']['#attributes'] = array(
        'placeholder' => 'Keywords',
      );
    }
  }

  if($form_id == 'webform_client_form_11778') {
    $form['actions']['submit']['#attributes']['class'][] = 'button-input';
    $form['actions']['submit']['#attributes']['class'][] = 'button-input-brand1';
  }
}

/**
 * Hook to set 'no title' for the pages.
 * As all page nodes are using 'title' to display this function was written.
 * This function can be deleted if page content type is not showing title for all nodes.
 */

function jc_breadcrumb($variables) {
  $title = drupal_get_title();
  $request_uri = $_SERVER['REQUEST_URI'];

  $output = '<ul class="breadcrumb">';

  if (stripos($request_uri, '/propel-resources') === 0) {
    if (!empty($title)) {
      $output .= "<li>{$title}</li>";
    }
  }

  $output .= '</ul>';

  return $output;
}


function jc_file_link($variables) {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    // Get the nid
    $nid = arg(1);
    // Load the node if you need to
    $node = node_load($nid);
    $target = '';


    if(isset($node->field_new_window['und'][0]['value']) && $node->field_new_window['und'][0]['value'] ==1 ) {
      $target = "_blank";
    }

    $node = node_load($nid);

    $file = $variables['file'];
    $icon_directory = $variables['icon_directory'];

    $url = file_create_url($file->uri);
    $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

    // Set options as per anchor format described at
    // http://microformats.org/wiki/file-format-examples
    $options = array(
      'attributes' => array(
        'type' => $file->filemime . '; length=' . $file->filesize,
        'target' => $target,
      ),
    );

    // Use the description as the link text if available.
    if (empty($file->description)) {
      $link_text = $file->filename;
    }
    else {
      $link_text = $file->description;
      $options['attributes']['title'] = check_plain($file->filename);
    }

    return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';


  }
}

function jc_preprocess_node(&$variables) {
  if ($variables['view_mode'] == 'full' && $variables['type'] == 'article' && isset($variables['field_publication'][0]['tid'] )) {
    $publication = $variables['field_publication'][0]['tid'];
    $pages = array(1,2);
    if (in_array($publication, $pages)) {
      $variables['jc_pdf_print'] = build_pdf_print();
    }
  }
}

function build_pdf_print() {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    // Get the nid
    $nid = arg(1);
    $node = node_load($nid);
    $pubTitle = $node->field_publication[LANGUAGE_NONE][0]['taxonomy_term']->name;
    $link = '<div class="pdf-print"><a href="/entityprint/node/' .$nid. '" style=" margin-bottom: 10px; display: block; font-size: 20px; color:#116798;margin-bottom: 4px;" download="'. $pubTitle .' volume '.$node->field_volume[LANGUAGE_NONE][0]['value'].' issue '. $node->field_issue[LANGUAGE_NONE][0]['value'] .'.pdf"><i class="fa fa-print"></i></a></div>';
    if(isset($node->field_article_position[LANGUAGE_NONE][0]['value']) && $node->field_article_position[LANGUAGE_NONE][0]['value'] == 0) {
     return '' ;
    } else {
      return($link);
    }
  }
}
function jc_entity_print_pdf_alter(WkHtmlToPdf $pdf, $entity_type, $entity) {
    $iss = $entity->field_volume_and_issue['und'][0]['tid'];
  $vol = taxonomy_get_parents($iss);
  $vol = reset($vol);
  $issue = taxonomy_term_load($iss);

  $created = date('n/j/Y', strtotime($entity->field_published[LANGUAGE_NONE][0]['value'])). " | Volume " . $vol->name . " | Issue " . $issue->name;
    $pdf->setOptions(array(
      'margin-left' => '5mm',
      'margin-right' => '5mm',
      'margin-top' => '20mm',
      'margin-bottom' => '25mm',
      'footer-spacing' => '5',
      'header-spacing' => '5',
      'footer-center' => '[page]/[toPage]',
      'footer-html' => 'sites/justcoding.com/themes/jc/templates/article-footer.html',
      'header-right' => $created,
    ));
}
/**
 * Implements hook_preprocess_entity_print().
 */
function jc_preprocess_entity_print(&$vars, $hook) {
  if (isset($vars['entity']->type)) {
    $vars['theme_hook_suggestions'][] = "entity_print__{$vars['entity']->type}";
  }
}

function jc_entity_print_pdf_views_alter(WkHtmlToPdf $pdf, $view) {
  $uri_path = current_path();
  $uri_segments = explode('/', $uri_path);
  $date = get_issue_pdf_date($uri_segments[2], $uri_segments[1]);
  $iss = $uri_segments[2];
  $vol = taxonomy_get_parents($iss);
  $vol = reset($vol);
  $issue = taxonomy_term_load($iss);
  //date('F, Y',$_GET['date'])

  $header = $date['date'] . ' | ' .  'Volume ' . $vol->name  .  ' | Issue '  .  $issue->name;
  $pdf->setOptions(array(
    'margin-left' => '5mm',
    'margin-right' => '5mm',
    'margin-top' => '20mm',
    'margin-bottom' => '25mm',
    'footer-spacing' => '5',
    'header-spacing' => '5',
    'footer-center' => '[page]/[toPage]',
    'footer-html' => 'sites/justcoding.com/themes/jc/templates/article-footer.html',
    'header-right' => $header,
  ));
}

