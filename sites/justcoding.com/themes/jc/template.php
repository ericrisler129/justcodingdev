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

  if($form_id == 'user_login') {
    $form['#suffix'] = '<p><strong>Unable to log in?</strong></p><p>Click <a href="https://accounts.blr.com/account/forgot" target="_blank">here</a> to reset your password or unlock your account.</p><p><strong>Forgot your username?</strong></p><p>Contact customer care at <a href="mailto:customerservice@hcpro.com" target="_blank">customerservice@hcpro.com</a> or call 800-727-5257, between 8 AM - 5 PM CT.</p></div>';
    $user_login_final_validate_index = array_search('user_login_final_validate', $form['#validate']);
    if ($user_login_final_validate_index >= 0) {
      $form['#validate'][$user_login_final_validate_index] = '_user_login_final_validate';
    }
  }
}

function _user_login_final_validate($form, &$form_state) {
  if (empty($form_state['uid'])) {
    // Always register an IP-based failed login event.
    flood_register_event('failed_login_attempt_ip', variable_get('user_failed_login_ip_window', 3600));
    // Register a per-user failed login event.
    if (isset($form_state['flood_control_user_identifier'])) {
      flood_register_event('failed_login_attempt_user', variable_get('user_failed_login_user_window', 21600), $form_state['flood_control_user_identifier']);
    }

    if (isset($form_state['flood_control_triggered'])) {
      if ($form_state['flood_control_triggered'] == 'user') {
        form_set_error('name', format_plural(variable_get('user_failed_login_user_limit', 5), 'Sorry, there has been more than one failed login attempt for this account. It is temporarily blocked. Try again later or <a href="@url">request a new password</a>.', 'This account is locked. Click <a href="@url">here</a> to reset your password and unlock your account. Please contact Customer Service at 800-727-5257 if you need further assistance.', array('@url' => url('user/password'))));
        module_invoke_all('user_flood_control', ip_address(), $form_state['values']['name']);
      }
      else {
        form_set_error('name', t('Sorry, too many failed login attempts from your IP address. This IP address is temporarily blocked. Try again later or <a href="@url">request a new password</a>.', array('@url' => url('user/password'))));
        module_invoke_all('user_flood_control', ip_address());
      }
      drupal_add_http_header('Status', '403 Forbidden');
    }
    else {
      $query = isset($form_state['input']['name']) ? array('name' => $form_state['input']['name']) : array();
      form_set_error('name', t('Sorry, unrecognized username or password. <a href="@password">Have you forgotten your password?</a>', array('@password' => url('user/password', array('query' => $query)))));
      watchdog('user', 'Login attempt failed for %user.', array('%user' => $form_state['values']['name']));
    }
  }
  elseif (isset($form_state['flood_control_user_identifier'])) {
    flood_clear_event('failed_login_attempt_user', $form_state['flood_control_user_identifier']);
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

