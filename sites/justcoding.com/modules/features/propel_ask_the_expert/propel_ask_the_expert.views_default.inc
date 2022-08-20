<?php

/**
 * @file
 * propel_ask_the_expert.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function propel_ask_the_expert_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'propel_ate';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Propel ATE';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_propel_ate_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Propel Type */
  $handler->display->display_options['fields']['field_propel_type']['id'] = 'field_propel_type';
  $handler->display->display_options['fields']['field_propel_type']['table'] = 'field_data_field_propel_type';
  $handler->display->display_options['fields']['field_propel_type']['field'] = 'field_propel_type';
  $handler->display->display_options['fields']['field_propel_type']['label'] = '';
  $handler->display->display_options['fields']['field_propel_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_propel_type']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_propel_type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'collapse-tile';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_class'] = 'collapse-body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'propel_ate_summary' => 'propel_ate_summary',
  );
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if(isset($_SESSION)){
  $company = $_SESSION[\'webauth\'][\'owner_company\'];

  if(isset($company)){
    $length = count($data->field_field_owner_company);
    for ($i=0; $i < $length; $i++) { 
      $term = $data->field_field_owner_company[$i][\'rendered\'][\'#markup\'];
      if($company == $term) {
        return FALSE;
      }
    }
  }
}
return TRUE;';

  /* Display: Propel ATE Page */
  $handler = $view->new_display('page', 'Propel ATE Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Propel ATE Type */
  $handler->display->display_options['fields']['field_propel_ate_type']['id'] = 'field_propel_ate_type';
  $handler->display->display_options['fields']['field_propel_ate_type']['table'] = 'field_data_field_propel_ate_type';
  $handler->display->display_options['fields']['field_propel_ate_type']['field'] = 'field_propel_ate_type';
  $handler->display->display_options['fields']['field_propel_ate_type']['label'] = '';
  $handler->display->display_options['fields']['field_propel_ate_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_propel_ate_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_propel_ate_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a id="n[nid]">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['path'] = 'propel-ate#n[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'collapse-tile';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_class'] = 'collapse-field';
  $handler->display->display_options['fields']['created']['element_label_class'] = 'collapse-label';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'standard';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Expert Name */
  $handler->display->display_options['fields']['field_expert_name']['id'] = 'field_expert_name';
  $handler->display->display_options['fields']['field_expert_name']['table'] = 'field_data_field_expert_name';
  $handler->display->display_options['fields']['field_expert_name']['field'] = 'field_expert_name';
  $handler->display->display_options['fields']['field_expert_name']['label'] = '';
  $handler->display->display_options['fields']['field_expert_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_expert_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_expert_name']['type'] = 'text_plain';
  /* Field: Field: Generic Link */
  $handler->display->display_options['fields']['field_generic_link']['id'] = 'field_generic_link';
  $handler->display->display_options['fields']['field_generic_link']['table'] = 'field_data_field_generic_link';
  $handler->display->display_options['fields']['field_generic_link']['field'] = 'field_generic_link';
  $handler->display->display_options['fields']['field_generic_link']['label'] = '';
  $handler->display->display_options['fields']['field_generic_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_generic_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_generic_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_generic_link']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<b>Posted Date:</b> [created]<br>
<b>Expert Name:</b> [field_expert_name]<br>
<b>Reference URL\'s:</b> [field_generic_link]<br>
<br>
[body]
<br>';
  $handler->display->display_options['fields']['body']['element_class'] = 'collapse-body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Company */
  $handler->display->display_options['fields']['field_owner_company']['id'] = 'field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['table'] = 'field_data_field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['field'] = 'field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['label'] = '';
  $handler->display->display_options['fields']['field_owner_company']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_owner_company']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_owner_company']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_owner_company']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'propel_ask_the_expert' => 'propel_ask_the_expert',
  );
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if(isset($_SESSION[\'webauth\'])){
  $company = $_SESSION[\'webauth\'][\'owner_company\'];

  if(isset($company)){
    $length = count($data->field_field_owner_company);
    for ($i=0; $i < $length; $i++) { 
      $term = $data->field_field_owner_company[$i][\'rendered\'][\'#label\'];
      if($company == $term) {
        return FALSE;
      }
    }
  }
}
return TRUE;';
  $handler->display->display_options['path'] = 'propel-ate';

  /* Display: ATE Block */
  $handler = $view->new_display('block', 'ATE Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div> <b>MY <i>PROPEL</i> EXPERT Q&As</b></div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="group-buttons"><div class="button"><a href="propel-ate" class="button-grey">View More</a></div></div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = 'propel-ate#n[nid]';
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'p';
  /* Field: Content: Company */
  $handler->display->display_options['fields']['field_owner_company']['id'] = 'field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['table'] = 'field_data_field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['field'] = 'field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['label'] = '';
  $handler->display->display_options['fields']['field_owner_company']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_owner_company']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_owner_company']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_owner_company']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Featured (field_featured) */
  $handler->display->display_options['filters']['field_featured_value']['id'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['table'] = 'field_data_field_featured';
  $handler->display->display_options['filters']['field_featured_value']['field'] = 'field_featured_value';
  $handler->display->display_options['filters']['field_featured_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_featured_value']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'propel_ask_the_expert' => 'propel_ask_the_expert',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['group'] = 1;
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if(isset($_SESSION[\'webauth\'])){
  $company = $_SESSION[\'webauth\'][\'owner_company\'];

  if(isset($company)){
    $length = count($data->field_field_owner_company);
    for ($i=0; $i < $length; $i++) { 
      $term = $data->field_field_owner_company[$i][\'rendered\'][\'#label\'];
      if($company == $term) {
        return FALSE;
      }
    }
  }
}
return TRUE;';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '250';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Company */
  $handler->display->display_options['fields']['field_owner_company']['id'] = 'field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['table'] = 'field_data_field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['field'] = 'field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['label'] = '';
  $handler->display->display_options['fields']['field_owner_company']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_owner_company']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_owner_company']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_owner_company']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'propel_ate_summary' => 'propel_ate_summary',
  );
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if(isset($_SESSION[\'webauth\'])){
  $company = $_SESSION[\'webauth\'][\'owner_company\'];

  if(isset($company)){
    $length = count($data->field_field_owner_company);
    for ($i=0; $i < $length; $i++) { 
      $term = $data->field_field_owner_company[$i][\'rendered\'][\'#label\'];
      if($company == $term) {
        return FALSE;
      }
    }
  }
}
return TRUE;';
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
    'page' => 0,
  );
  $export['propel_ate'] = $view;

  $view = new view();
  $view->name = 'propel_ate_summary';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Propel ATE Summary';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Propel ATE Summary';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'propel_ate_summary' => 'propel_ate_summary',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Company */
  $handler->display->display_options['fields']['field_owner_company']['id'] = 'field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['table'] = 'field_data_field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['field'] = 'field_owner_company';
  $handler->display->display_options['fields']['field_owner_company']['label'] = '';
  $handler->display->display_options['fields']['field_owner_company']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_owner_company']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_owner_company']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_owner_company']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'propel_ate_summary' => 'propel_ate_summary',
  );
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'if(isset($_SESSION[\'webauth\'])){
  $company = $_SESSION[\'webauth\'][\'owner_company\'];

  if(isset($company)){
    $length = count($data->field_field_owner_company);
    for ($i=0; $i < $length; $i++) { 
      $term = $data->field_field_owner_company[$i][\'rendered\'][\'#label\'];
      if($company == $term) {
        return FALSE;
      }
    }
  }
}
return TRUE;';
  $export['propel_ate_summary'] = $view;

  return $export;
}
