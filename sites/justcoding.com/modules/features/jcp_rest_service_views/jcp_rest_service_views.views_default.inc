<?php

/**
 * @file
 * jcp_rest_service_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jcp_rest_service_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rest_service';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'REST Service';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '200';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'type';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'url';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'author_name';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nodeID';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'summary';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_news_categories']['id'] = 'field_news_categories';
  $handler->display->display_options['fields']['field_news_categories']['table'] = 'field_data_field_news_categories';
  $handler->display->display_options['fields']['field_news_categories']['field'] = 'field_news_categories';
  $handler->display->display_options['fields']['field_news_categories']['label'] = 'categories';
  $handler->display->display_options['fields']['field_news_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_news_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_news_categories']['delta_offset'] = '0';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_resource_category']['id'] = 'field_resource_category';
  $handler->display->display_options['fields']['field_resource_category']['table'] = 'field_data_field_resource_category';
  $handler->display->display_options['fields']['field_resource_category']['field'] = 'field_resource_category';
  $handler->display->display_options['fields']['field_resource_category']['label'] = 'category';
  $handler->display->display_options['fields']['field_resource_category']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_resource_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_resource_category']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['field_published']['id'] = 'field_published';
  $handler->display->display_options['fields']['field_published']['table'] = 'field_data_field_published';
  $handler->display->display_options['fields']['field_published']['field'] = 'field_published';
  $handler->display->display_options['fields']['field_published']['label'] = 'published_date';
  $handler->display->display_options['fields']['field_published']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
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
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'nodeID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nodeID';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    8 => 0,
    10 => 0,
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'query';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    8 => 0,
    10 => 0,
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'author';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'author';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    8 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '<=';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created_before';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    8 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'poll' => 'poll',
    'quiz' => 'quiz',
    'resource' => 'resource',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    8 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created_1']['id'] = 'created_1';
  $handler->display->display_options['filters']['created_1']['table'] = 'node';
  $handler->display->display_options['filters']['created_1']['field'] = 'created';
  $handler->display->display_options['filters']['created_1']['operator'] = '>=';
  $handler->display->display_options['filters']['created_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created_1']['expose']['operator_id'] = 'created_1_op';
  $handler->display->display_options['filters']['created_1']['expose']['label'] = 'Post date';
  $handler->display->display_options['filters']['created_1']['expose']['operator'] = 'created_1_op';
  $handler->display->display_options['filters']['created_1']['expose']['identifier'] = 'created_after';
  $handler->display->display_options['filters']['created_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    8 => 0,
    10 => 0,
  );
  /* Filter criterion: publoshed_before */
  $handler->display->display_options['filters']['field_published_value']['id'] = 'field_published_value';
  $handler->display->display_options['filters']['field_published_value']['table'] = 'field_data_field_published';
  $handler->display->display_options['filters']['field_published_value']['field'] = 'field_published_value';
  $handler->display->display_options['filters']['field_published_value']['ui_name'] = 'publoshed_before';
  $handler->display->display_options['filters']['field_published_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_published_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_published_value']['expose']['operator_id'] = 'field_published_value_op';
  $handler->display->display_options['filters']['field_published_value']['expose']['label'] = 'published_before';
  $handler->display->display_options['filters']['field_published_value']['expose']['operator'] = 'field_published_value_op';
  $handler->display->display_options['filters']['field_published_value']['expose']['identifier'] = 'published_before';
  $handler->display->display_options['filters']['field_published_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    8 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_published_value']['form_type'] = 'date_text';
  /* Filter criterion: published_after */
  $handler->display->display_options['filters']['field_published_value_1']['id'] = 'field_published_value_1';
  $handler->display->display_options['filters']['field_published_value_1']['table'] = 'field_data_field_published';
  $handler->display->display_options['filters']['field_published_value_1']['field'] = 'field_published_value';
  $handler->display->display_options['filters']['field_published_value_1']['ui_name'] = 'published_after';
  $handler->display->display_options['filters']['field_published_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_published_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_published_value_1']['expose']['operator_id'] = 'field_published_value_1_op';
  $handler->display->display_options['filters']['field_published_value_1']['expose']['label'] = 'Published (field_published)';
  $handler->display->display_options['filters']['field_published_value_1']['expose']['operator'] = 'field_published_value_1_op';
  $handler->display->display_options['filters']['field_published_value_1']['expose']['identifier'] = 'published_after';
  $handler->display->display_options['filters']['field_published_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    7 => 0,
    4 => 0,
    8 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_published_value_1']['form_type'] = 'date_text';

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'type';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'url';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'author_name';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nodeID';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'summary';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_news_categories']['id'] = 'field_news_categories';
  $handler->display->display_options['fields']['field_news_categories']['table'] = 'field_data_field_news_categories';
  $handler->display->display_options['fields']['field_news_categories']['field'] = 'field_news_categories';
  $handler->display->display_options['fields']['field_news_categories']['label'] = 'categories';
  $handler->display->display_options['fields']['field_news_categories']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_news_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_news_categories']['delta_offset'] = '0';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_resource_category']['id'] = 'field_resource_category';
  $handler->display->display_options['fields']['field_resource_category']['table'] = 'field_data_field_resource_category';
  $handler->display->display_options['fields']['field_resource_category']['field'] = 'field_resource_category';
  $handler->display->display_options['fields']['field_resource_category']['label'] = 'category';
  $handler->display->display_options['fields']['field_resource_category']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_resource_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_resource_category']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['field_published']['id'] = 'field_published';
  $handler->display->display_options['fields']['field_published']['table'] = 'field_data_field_published';
  $handler->display->display_options['fields']['field_published']['field'] = 'field_published';
  $handler->display->display_options['fields']['field_published']['label'] = 'published_date';
  $handler->display->display_options['fields']['field_published']['alter']['text'] = '2016-01-01';
  $handler->display->display_options['fields']['field_published']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_published']['settings'] = array(
    'format_type' => 'short_custom_',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'origin';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Justcoding';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'site_url';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'http://www.justcoding.com';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'content';
  $export['rest_service'] = $view;

  return $export;
}
